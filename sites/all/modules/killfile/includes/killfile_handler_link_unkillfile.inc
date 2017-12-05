<?php

/**
 * Field handler to present unsoft delete a node.
 */
class killfile_handler_link_unkillfile extends views_handler_field_node_link {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function access() {
    return user_access('undelete killfiled content');
  }

  function render_link($data, $values) {
    if (!killfile_can_undelete($values, NULL)) {
      return;
    }

    $results = killfile_get_node_delete_settings(array($values));

    if (count($results) == 0){
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'node/' . $values->nid . '/undelete';
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t("undelete");

    return $text;
  }
}
