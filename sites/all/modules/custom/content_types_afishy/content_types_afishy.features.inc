<?php
/**
 * @file
 * content_types_afishy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_afishy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_types_afishy_node_info() {
  $items = array(
    'afishi' => array(
      'name' => t('Afishi'),
      'base' => 'node_content',
      'description' => t('Добавляем афиши на сайт'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
