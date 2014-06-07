<?php
/**
 * @file
 * organization_and_contact_helpus_pages.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function organization_and_contact_helpus_pages_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'in_page';
  $ds_view_mode->label = 'in_page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['in_page'] = $ds_view_mode;

  return $export;
}
