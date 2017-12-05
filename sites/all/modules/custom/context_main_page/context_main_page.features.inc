<?php
/**
 * @file
 * context_main_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_main_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
