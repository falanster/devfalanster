<?php
/**
 * @file
 * task_block_titlelink_module_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function task_block_titlelink_module_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
