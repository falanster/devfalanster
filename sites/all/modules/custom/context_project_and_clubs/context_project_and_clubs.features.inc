<?php
/**
 * @file
 * context_project_and_clubs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_project_and_clubs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
