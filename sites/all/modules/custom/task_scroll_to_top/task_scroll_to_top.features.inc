<?php
/**
 * @file
 * task_scroll_to_top.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function task_scroll_to_top_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
