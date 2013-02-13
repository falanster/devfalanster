<?php
/**
 * @file
 * Variable hooks.
 */

/**
 * Implements hook_variable_realm_info() {
 */
function variable_realm_variable_realm_info() {
  $realm['global'] = array(
    'title' => t('Global'),
    'keys' => array(
      'default' => t('All variables')
    ),
  );
  return $realm;
}