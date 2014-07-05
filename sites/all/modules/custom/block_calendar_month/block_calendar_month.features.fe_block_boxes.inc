<?php
/**
 * @file
 * block_calendar_month.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_calendar_month_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'calendar_month';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_month';
  $fe_block_boxes->body = '<p><a href="/en/agenda">month</a></p>
';

  $export['calendar_month'] = $fe_block_boxes;

  return $export;
}
