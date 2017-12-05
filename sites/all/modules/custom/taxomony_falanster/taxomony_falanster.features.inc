<?php
/**
 * @file
 * taxomony_falanster.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function taxomony_falanster_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
