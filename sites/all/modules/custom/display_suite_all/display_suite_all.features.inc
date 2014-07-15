<?php
/**
 * @file
 * display_suite_all.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function display_suite_all_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
