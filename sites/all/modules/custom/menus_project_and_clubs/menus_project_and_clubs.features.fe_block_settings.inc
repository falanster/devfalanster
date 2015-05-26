<?php
/**
 * @file
 * menus_project_and_clubs.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function menus_project_and_clubs_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-first-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-first-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
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

  $export['menu-menu-mobile-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-mobile-menu',
    'i18n_block_language' => array(
      0 => 'ru',
    ),
    'i18n_mode' => 0,
    'module' => 'menu',
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
