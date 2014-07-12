<?php
/**
 * @file
 * blocks_money_ipay.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function blocks_money_ipay_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-money_ipay'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'ru',
    ),
    'i18n_mode' => 1,
    'machine_name' => 'money_ipay',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'falanster' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'falanster',
        'weight' => 0,
      ),
      'omega' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'stark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stark',
        'weight' => 0,
      ),
      'test_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'test_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Support Falanster',
    'visibility' => 0,
  );

  return $export;
}
