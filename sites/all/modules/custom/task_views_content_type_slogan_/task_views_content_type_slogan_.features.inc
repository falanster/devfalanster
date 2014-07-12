<?php
/**
 * @file
 * task_views_content_type_slogan_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function task_views_content_type_slogan__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function task_views_content_type_slogan__views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function task_views_content_type_slogan__node_info() {
  $items = array(
    'slogan' => array(
      'name' => t('Slogan'),
      'base' => 'node_content',
      'description' => t('Тип материала для слоганов falanster\'a'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
