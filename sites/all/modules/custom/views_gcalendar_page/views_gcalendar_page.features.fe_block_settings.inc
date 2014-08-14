<?php
/**
 * @file
 * views_gcalendar_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function views_gcalendar_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-gcalendar-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'gcalendar-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'alpha' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'alpha',
        'weight' => 0,
      ),
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
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
