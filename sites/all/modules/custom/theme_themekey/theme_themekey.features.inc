<?php
/**
 * @file
 * theme_themekey.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function theme_themekey_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
