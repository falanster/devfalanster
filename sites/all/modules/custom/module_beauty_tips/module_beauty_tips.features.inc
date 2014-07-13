<?php
/**
 * @file
 * module_beauty_tips.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function module_beauty_tips_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
