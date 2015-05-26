<?php
/**
 * @file
 * context_grid.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_grid_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
