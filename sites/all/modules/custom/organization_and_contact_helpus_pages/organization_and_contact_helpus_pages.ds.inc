<?php
/**
 * @file
 * organization_and_contact_helpus_pages.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function organization_and_contact_helpus_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|static_pages|in_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'static_pages';
  $ds_layout->view_mode = 'in_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_file',
        2 => 'field_gallery',
        3 => 'field_related_node',
        4 => 'field_audio',
        5 => 'field_video_youtube',
        6 => 'field_target_page',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_file' => 'ds_content',
      'field_gallery' => 'ds_content',
      'field_related_node' => 'ds_content',
      'field_audio' => 'ds_content',
      'field_video_youtube' => 'ds_content',
      'field_target_page' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|static_pages|in_page'] = $ds_layout;

  return $export;
}

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
