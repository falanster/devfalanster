<?php
/**
 * @file
 * block_calendar_month.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function block_calendar_month_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-calendar_month'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'be',
      1 => 'en',
      2 => 'ru',
    ),
    'i18n_mode' => 1,
    'machine_name' => 'calendar_month',
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
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
