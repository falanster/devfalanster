<?php
/**
 * @file
 * task_views_content_type_slogan_.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function task_views_content_type_slogan__default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-slogan-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'slogan-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
