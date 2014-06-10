<?php
/**
 * @file
 * organization_and_contact_helpus_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function organization_and_contact_helpus_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function organization_and_contact_helpus_pages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function organization_and_contact_helpus_pages_node_info() {
  $items = array(
    'static_pages' => array(
      'name' => t('Static pages'),
      'base' => 'node_content',
      'description' => t('Страницы с описанием (например, о нас, миссия, документы)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function organization_and_contact_helpus_pages_weight_features_default_settings() {
  $settings = array();

  $settings['static_pages'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
