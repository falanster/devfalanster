<?php

/**
 * @file
 * Provides the cf_dom handling class.
 */

/**
 * @addtogroup cf_dom
 * @{
 * The cf_dom class assists in setting up and managing the custom dom object.
 */

class cf_dom {
  const PREFIX = 'cf';
  const CONTENT = '<head><meta http-equiv="Content-Type" content="text/html; charset=utf-8"></head><body></body>';
  const DOCTYPE = '<!DOCTYPE html>';

  private $doctype = NULL;
  private $preserve_whitespace = TRUE;
  private $format_output = TRUE;
  private $dom = NULL;
  private $head = NULL;
  private $body = NULL;
  private $content = cf_dom::CONTENT;


  /**
   * Constructor for the cf_dom class.
   *
   * @param string $doctype
   *   (optional) When a document type is passed, a new dom object gets
   *   created. When set to NULL, will use the drupal variable called
   *   'cf_dom_doctype' is used.
   * @param bool $preserve_whitespace
   *   (optional) The default whitespace preservation dom setting.
   * @param bool $format_output
   *   (optional) The default output formatting dom setting.
   * @param string|null $content
   *   (optional) Specify a custom content on initialization.
   *   If specified, then the doctype parameter will be ignored.
   */
  public function __construct($doctype = NULL, $preserve_whitespace = TRUE, $format_output = TRUE, $content = NULL) {
    if (is_bool($preserve_whitespace)) {
      $this->preserve_whitespace = $preserve_whitespace;
    }
    else {
      if (class_exists('cf_error')) {
        cf_error::invalid_bool('preserve_whitespace');
      }
    }

    if (is_bool($format_output)) {
      $this->format_output = $format_output;
    }
    else {
      if (class_exists('cf_error')) {
        cf_error::invalid_bool('format_output');
      }
    }

    if (is_null($content)) {
      if (is_null($doctype)) {
        $this->doctype = variable_get('cf_dom_doctype', cf_dom::DOCTYPE);
      }
      elseif (cf_is_empty_or_non_string('doctype', $doctype)) {
        return;
      }
      else {
        $this->doctype = $doctype;
      }
    }
    else {
      if (is_string($content)) {
        $this->content = $content;
      }
      else {
        if (class_exists('cf_error')) {
          cf_error::invalid_string('content');
        }

        return;
      }
    }

    $this->dom = new DOMDocument();
    $this->dom->preserveWhiteSpace = $this->preserve_whitespace;
    $this->dom->formatOutput = $this->format_output;
    @$this->dom->loadHTML($this->doctype . $this->content);

    $this->head = NULL;
    $elements = $this->dom->getElementsByTagName('head');
    if ($elements->length > 0) {
      $this->head = $elements->item(0);
    }

    $this->body = NULL;
    $elements = $this->dom->getElementsByTagName('body');
    if ($elements->length > 0) {
      $this->body = $elements->item(0);
    }
  }

  /**
   * Returns TRUE if the DOM Document is properly loaded.
   *
   * @return bool
   *   TRUE if the DOM Document is properly loaded, FALSE otherwise.
   */
  public function is_loaded() {
    return $this->dom instanceof DOMDocument;
  }

  /**
   * Assigns the document type.
   *
   * The dom object gets (re)created on doctype change.
   *
   * @param string $doctype
   *   (optional) When a document type is passed, a new dom object gets
   *   created. When set to NULL, will use the drupal variable called
   *   'cf_dom_doctype' is used.
   *
   * @return bool
   *   Returns TRUE on success, FALSE otherwise.
   */
  public function set_doctype($doctype = NULL) {
    if (is_null($doctype)) {
      $doctype = variable_get('cf_dom_doctype', cf_dom::DOCTYPE);
    }
    elseif (cf_is_empty_or_non_string('doctype', $doctype)) {
      return FALSE;
    }

    $this->doctype = $doctype;
    @$this->dom->loadHTML($this->doctype . $this->content);

    $head = $this->head;
    $this->head = NULL;

    if (($head instanceOf DOMNode)) {
      $this->p_remove_elements('head', $head);
      $this->dom->importNode($head, TRUE);
    }

    $element = $this->dom->getElementsByTagName('head');
    if ($element->length > 0) {
      $this->head = $element->item(0);
    }


    $body = $this->body;
    $this->body = NULL;

    if (($body instanceOf DOMNode)) {
      $this->p_remove_elements('body', $body);
      $this->dom->importNode($body, TRUE);
    }

    $element = $this->dom->getElementsByTagName('body');
    if ($element->length > 0) {
      $this->body = $element->item(0);
    }

    return TRUE;
  }

  /**
   * Gets the DOMDOcument object.
   *
   * @return DOMDocument|null
   *   The assigned dom document.
   */
  public function get_dom() {
    return $this->dom;
  }

  /**
   * Gets the assigned document type.
   *
   * @return string
   *   The assigned document type.
   */
  public function get_doctype() {
    return $this->doctype;
  }

  /**
   * Gets the preserve whitespace setting
   *
   * @return bool
   *   The preserve whitespace setting.
   */
  public function get_preserve_whotespace() {
    return $this->preserve_whitespace;
  }

  /**
   * Gets the format output setting
   *
   * @return bool
   *   The format output setting.
   */
  public function get_format_output() {
    return $this->format_output;
  }

  /**
   * Gets the loaded head element.
   *
   * @return DOMNode|null
   *   The DomElement for the head element or NULL.
   */
  public function get_head() {
    return $this->head;
  }

  /**
   * Gets the loaded body element.
   *
   * @return DOMNode|null
   *   The DomElement for the body element or NULL.
   */
  public function get_body() {
    return $this->body;
  }

  /**
   * Converts the body or head element into markup
   *
   * @param bool $include_tag
   *   (optional) When TRUE, the head tag itself will be included in the
   *   output. When FALSE, only the contents of the tag will be included
   *   in the output. Defaults to FALSE.
   * @param bool $on_body
   *   If TRUE, operate on body element.
   *   If FALSE, operate on head element.
   *   This defaults to TRUE.
   *
   * @return string|bool
   *   The markup text that the object was converted from.
   *   FALSE on error.
   */
  public function get_markup($include_tag = FALSE, $on_body = TRUE) {
    if ($on_body) {
      if (!($this->body instanceof DOMNode)) {
        if (class_exists('cf_error')) {
          cf_error::invalid_object('this->body');
        }

        return FALSE;
      }

      return $this->p_get_markup($include_tag, $this->body);
    }

    if (!($this->head instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('this->head');
      }

      return FALSE;
    }

    return $this->p_get_markup($include_tag, $this->head);
  }

  /**
   * Converts the selected tag into HTML markup.
   *
   * @param DOMNode $element
   *   The element to convert.
   * @param bool $on_body
   *   If TRUE, operate on body element.
   *   If FALSE, operate on head element.
   *   The supplied tag must be attached to the appropriate head or body.
   *   This defaults to TRUE.
   *
   * @return string|bool
   *   The markup text that the object was converted from.
   *   FALSE on error.
   */
  public function get_tag_markup($element, $on_body = TRUE) {
    if ($on_body) {
      if (!($this->body instanceof DOMNode)) {
        if (class_exists('cf_error')) {
          cf_error::invalid_object('this->body');
        }

        return FALSE;
      }

      return $this->p_get_markup(TRUE, $element);
    }

    if (!($this->head instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('this->head');
      }

      return FALSE;
    }

    return $this->p_get_markup(TRUE, $element);
  }

  /**
   * Changes the element from one type to another.
   *
   * @param DOMNode $element
   *   The element whose type will be changed.
   * @param string $type
   *   The new element type to use.
   *
   * @return DOMNode |bool
   *   The changed element on success, FALSE otherwise.
   */
  public function change_element($element, $type) {
    if (!($this->dom instanceof DOMDocument)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('this->dom');
      }

      return FALSE;
    }

    if (!($element instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('element');
      }

      return FALSE;
    }

    if (cf_is_empty_or_non_string('type', $type)) {
      return FALSE;
    }

    return $this->p_change_element($element, $type);
  }

  /**
   * Change all elements of a given element type to another type.
   *
   * @param string $old_type
   *   The old element type to be replaced.
   * @param string $new_type
   *   The new element type to use.
   * @param bool $on_body
   *   If TRUE, operate on body element.
   *   If FALSE, operate on head element.
   *   This defaults to TRUE.
   *
   * @return bool
   *   TRUE on success, FALSE otherwise.
   */
  public function change_elements($old_type, $new_type, $on_body = TRUE) {
    if (cf_is_empty_or_non_string('oldtype', $old_type)) {
      return FALSE;
    }

    if (cf_is_empty_or_non_string('new_type', $new_type)) {
      return FALSE;
    }

    if ($on_body) {
      if (!($this->body instanceof DOMNode)) {
        if (class_exists('cf_error')) {
          cf_error::invalid_object('this->body');
        }

        return FALSE;
      }

      return $this->p_change_elements($old_type, $new_type, $this->head);
    }

    if (!($this->head instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('this->head');
      }

      return FALSE;
    }

    return $this->p_change_elements($old_type, $new_type, $this->head);
  }

  /**
   * Removes the given element from its parent.
   *
   * This preserves child elements.
   * To remove entirely, use removeElement() directly.
   *
   * @param DOMNode $element
   *   The object to convert to markup text.
   * @param bool $preserve_children
   *   (optional) If TRUE, children are re-attached to the parent node to
   *   preserved their location in the markup.
   *   If FALSE, the children remain attached to the removed element.
   *
   * @return bool
   *   The removed element on success, FALSE otherwise.
   */
  public function remove_element($element, $preserve_children = TRUE) {
    if (!($element instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('element');
      }

      return FALSE;
    }

    if (!is_bool($preserve_children)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_bool('preserve_children');
      }

      return FALSE;
    }

    return $this->p_remove_element($element, $preserve_children);
  }

  /**
   * Remove all elements of a given element type.
   *
   * This preserves child elements.
   * To remove elements entirely, use removeElement() directly.
   *
   * @param string $type
   *   The new element type to use.
   * @param bool $on_body
   *   If TRUE, operate on body element.
   *   If FALSE, operate on head element.
   *   This defaults to TRUE.
   * @param bool $preserve_children
   *   (optional) If TRUE, children are re-attached to the parent node to
   *   preserved their location in the markup.
   *   If FALSE, the children remain attached to the removed element.
   *
   * @return bool
   *   TRUE on success, FALSE otherwise.
   */
  public function remove_elements($type, $on_body = TRUE, $preserve_children = TRUE) {
    if (!is_bool($on_body)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_bool('on_body');
      }

      return FALSE;
    }

    if (cf_is_empty_or_non_string('type', $type)) {
      return FALSE;
    }

    if (!is_bool($preserve_children)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_bool('preserve_children');
      }

      return FALSE;
    }

    if ($on_body) {
      if (!($this->body instanceof DOMNode)) {
        if (class_exists('cf_error')) {
          cf_error::invalid_object('this->body');
        }

        return FALSE;
      }

      return $this->p_remove_elements($type, $this->body, $preserve_children);
    }

    if (!($this->head instanceof DOMNode)) {
      if (class_exists('cf_error')) {
        cf_error::invalid_object('this->head');
      }

      return FALSE;
    }

    return $this->p_remove_elements($type, $this->head, $preserve_children);
  }

  /**
   * Converts the element into markup
   *
   * @param bool $include_tag
   *   (optional) When TRUE, the head tag itself will be included in the
   *   output. When FALSE, only the contents of the tag will be included
   *   in the output. Defaults to FALSE.
   * @param DOMNode $parent
   *   The object to operate on.
   *
   * @return string|bool
   *   The markup text that the object was converted from.
   *   FALSE on error.
   */
  public function p_get_markup($include_tag, $parent) {
    if ($include_tag) {
      return $this->dom->saveHTML($parent);
    }

    $markup = '';
    if ($parent->hasChildNodes() > 0) {
      foreach ($parent->childNodes as $child) {
        $markup .= $this->dom->saveHTML($child);
      }
    }

    return $markup;
  }

  /**
   * Changes the element from one type to another.
   *
   * @param DOMNode $element
   *   The element whose type will be changed.
   * @param string $type
   *   The new element type to use.
   *
   * @return bool
   *   The changed element on success, FALSE otherwise.
   */
  private function p_change_element($element, $type) {
    $parent = $element->parentNode;
    $new = $this->dom->createElement($type);

    if (!($new instanceof DOMNode)) {
      return FALSE;
    }

    if ($element->hasAttributes()) {
      foreach ($element->attributes as $attribute) {
        $new->setAttribute($attribute->name, $attribute->value);
      }
    }

    if ($element->hasChildNodes()) {
      foreach ($element->childNodes as $child) {
        $new->appendChild($child->cloneNode(TRUE));
      }
    }

    if ($parent instanceOf DOMNode) {
      $child = $parent->replaceChild($new, $element);
    }
    else {
      $this->dom->appendChild($element);
      $child = $this->dom->replaceChild($new, $element);

      if ($child instanceof DOMNode) {
        $parent = $child->parentNode;

        if ($parent instanceOf DOMNode) {
          $this->dom->removeChild($child);
        }
      }
      else {
        $this->dom->removeChild($element);
      }
    }

    if ($child instanceOf DOMNode) {
      return $child;
    }

    return FALSE;
  }

  /**
   * Change all elements of a given element type to another type.
   *
   * @param string $type
   *   The new element type to operate on.
   * @param DOMNode $parent
   *   The object to operate on.
   *
   * @return bool
   *   TRUE on success, FALSE otherwise.
   */
  private function p_change_elements($type, $parent) {
    $result = TRUE;

    $elements = $parent->getElementsByTagName($type);
    foreach ($elements as $element) {
      $result = $this->change_element($element, $type);

      if (!$result) break;
    }

    return $result;
  }

  /**
   * Removes the given element from its parent.
   *
   * This preserves child elements.
   * To remove entirely, use removeElement() directly.
   *
   * @param DOMNode $element
   *   The object to convert to markup text.
   * @param bool $preserve_children
   *   (optional) If TRUE, children are re-attached to the parent node to
   *   preserved their location in the markup.
   *   If FALSE, the children remain attached to the removed element.
   *
   * @return bool
   *   The removed element on success, FALSE otherwise.
   */
  private function p_remove_element($element, $preserve_children = TRUE) {
    $parent = $element->parentNode;

    if (!($parent instanceof DOMNode)) {
      return FALSE;
    }

    if ($preserve_children && $element->hasChildNodes()) {
      $children = array();

      foreach ($element->childNodes as $child) {
        $children[] = $child;
      }

      foreach ($children as $child) {
        $removed_child = $element->removeChild($child);

        if (is_object($removed_child)) {
          $parent->insertBefore($removed_child, $element);
        }
      }
    }

    $child = $parent->removeChild($element);

    if ($child instanceof DOMNode) {
      return $child;
    }

    return FALSE;
  }

  /**
   * Remove all elements of a given element type.
   *
   * This preserves child elements.
   * To remove elements entirely, use removeElement() directly.
   *
   * @param string $type
   *   The new element type to operate on.
   * @param DOMNode $parent
   *   The object to operate on.
   * @param bool $preserve_children
   *   (optional) If TRUE, children are re-attached to the parent node to
   *   preserved their location in the markup.
   *   If FALSE, the children remain attached to the removed element.
   *
   * @return bool
   *   TRUE on success, FALSE otherwise.
   */
  private function p_remove_elements($type, $parent, $preserve_children = TRUE) {
    $result = TRUE;

    $elements = $parent->getElementsByTagName($type);
    foreach ($elements as $element) {
      $result = $this->p_remove_element($element, $preserve_children);

      if (!$result) break;
    }

    return $result;
  }
}


/**
 * @} End of '@addtogroup cf_dom'.
 */
