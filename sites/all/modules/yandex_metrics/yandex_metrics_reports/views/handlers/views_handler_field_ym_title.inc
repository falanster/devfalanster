<?php

/**
 * @file
 * The 'page_title' field handler.
 */

/**
 * Field handler allows linking page title to popular URL from Yandex.Metrica.
 * Definition terms:
 * - link_to_ym_url default: enables checkbox "Link this field to Popular URL" by default.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_ym_title extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby.
    if (!empty($this->options['link_to_ym_url'])) {
      $this->additional_fields['url'] = array('table' => 'yandex_metrics_reports_popular_content', 'field' => 'url');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_ym_url'] = array('default' => isset($this->definition['link_to_ym_url default']) ? $this->definition['link_to_ym_url default'] : FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Add checkbox to the field settings form.
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_ym_url'] = array(
      '#title' => t('Link to Popular URL'),
      '#description' => t("Enable to link this field to the conforming Popular URL."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_ym_url']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render the data as link to the popular URL.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_ym_url']) && !empty($this->additional_fields['url'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = $this->get_value($values, 'url');
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
