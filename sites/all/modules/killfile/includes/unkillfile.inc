<?php

/**
 * Provides a page to perform undelete operations.
 * This is primarily provided for integration with the views module.
 *
 * @param $form
 *   A form array
 * @param $form_state
 *   A form state
 * @param $node
 *   A node object
 *
 * @return
 *   The unsoft delete form.
 */
function killfile_unkillfile_form($form, &$form_state, $node) {
  if (!is_array($form)){
    if (class_exists('cf_error')) {
      cf_error::invalid_array('form');
    }

    return cf_page_not_accessible($form_state);
  }

  if (!isset($form['#id'])) $form['#id'] = '';

  if (!is_array($form)){
    if (class_exists('cf_error')) {
      cf_error::invalid_array('form');
    }

    return cf_page_not_accessible($form_state, $form['#id']);
  }

  if (cf_is_not_form_state('form_state', $form_state)){
    return cf_page_not_accessible($form_state, $form['#id']);
  }

  if (!is_object($node)){
    if (class_exists('cf_error')) {
      cf_error::invalid_object('node');
    }

    return cf_page_not_accessible($form_state, $form['#id']);
  }

  $node_type_settings_array = array();

  if (!empty($node->type)){
    $node_type_settings_array = killfile_get_node_type_settings(array($node->type));
  }

  if ($node->deleted === FALSE || !is_array($node_type_settings_array) || count($node_type_settings_array) != 1){
    return cf_page_not_accessible($form_state, $form['#id']);
  }

  $form['#node'] = $node;

  // Always provide entity id in the same form key as in the entity edit form.
  $form['nid'] = array('#type' => 'value', '#value' => $node->nid);

  $form['#submit'] = array('killfile_unkillfile_form_submit');

  return confirm_form(
    $form,
    t("Would you like to undelete %title?", array('%title' => $node->title)),
    'node/' . $node->nid,
    t("Would you like to undelete %title?", array('%title' => $node->title)),
    t("Yes"),
    t("No")
  );
}

/**
 * Perform the submit operation if the user selected "yes"
 *
 * @param $form
 *   A form array
 * @param $form_state
 *   A form state
 */
function killfile_unkillfile_form_submit($form, &$form_state) {
  if (!is_array($form)){
    if (class_exists('cf_error')) {
      cf_error::invalid_array('form');
    }
    return;
  }

  if (cf_is_not_form_state('form_state', $form_state)){
    return;
  }

  if (isset($form_state['values']['confirm'])) {
    $result = killfile_undelete_nodes(array($form['#node']), NULL);

    if ($result){
      drupal_set_message(t("The node has been undeleted."));
    }

    if (!isset($form_state['redirect'])){
      $form_state['redirect'] = 'node/' . $form['#node']->nid;
    }
  }

  drupal_redirect_form($form_state);
}
