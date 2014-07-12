<?php
/**
 * @file
 * theme_falanster.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function theme_falanster_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
