<?php

/**
 * @file
 * Common Functionality - Error Module - Error Reporting Admin Form.
 */

/**
 * Provide the error reporting form.
 *
 * @param $form
 *   The form array as provided by drupal_get_form().
 * @param $form_state
 *   The form state array as provided by drupal_get_form().
 *
 * @see: drupal_get_form()
 */
function cf_error_reporting_form($form, &$form_state) {
  if (!is_array($form)) {
    cf_error::invalid_array('form');
    drupal_access_denied();
    drupal_exit();
  }

  if (!is_array($form_state)) {
    cf_error::invalid_array('form_state');
    drupal_access_denied();
    drupal_exit();
  }

  $form['backtrace_reporting_mode'] = array(
    '#type' => 'select',
    '#title' => t("Backtrace Reporting Mode"),
    '#options' => cf_error::get_backtrace_options_list(),
    '#default_value' => variable_get('cf_error_backtrace_mode', cf_error::BACKTRACE_MODE_SHORT),
    '#description' => t("When errors are reported via the common functionality error module, those reports may contain backtraces. Use this option to select if those backtraces are displayed and how much of a backtrace should be displayed."),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Apply Changes"),
  );

  return $form;
}

/**
 * Submit function for the error reporting form.
 *
 * @param $form
 *   The form array as provided by drupal_get_form().
 * @param $form_state
 *   The form state array as provided by drupal_get_form().
 *
 * @see: cf_error_reporting_form()
 * @see: drupal_get_form()
 */
function cf_error_reporting_form_submit($form, &$form_state) {
  if (!is_array($form)) {
    cf_error::invalid_array('form');
    drupal_access_denied();
    drupal_exit();
  }

  if (!is_array($form_state)) {
    cf_error::invalid_array('form_state');
    drupal_access_denied();
    drupal_exit();
  }

  if (isset($form_state['values']['backtrace_reporting_mode']) && is_numeric($form_state['values']['backtrace_reporting_mode'])) {
    variable_set('cf_error_backtrace_mode', $form_state['values']['backtrace_reporting_mode']);
  }
}
