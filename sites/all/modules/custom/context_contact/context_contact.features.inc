<?php
/**
 * @file
 * context_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
