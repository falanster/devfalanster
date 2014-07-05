<?php
/**
 * @file
 * task_block_titlelink_module_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function task_block_titlelink_module_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_titlelink_views_afishi-block_1';
  $strongarm->value = array(
    'url' => 'afishy',
    'display' => 1,
    'title' => '',
  );
  $export['block_titlelink_views_afishi-block_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_titlelink_views_headernews-block';
  $strongarm->value = array(
    'url' => 'news',
    'display' => 1,
    'title' => '',
  );
  $export['block_titlelink_views_headernews-block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_titlelink_views_headernews_english-block';
  $strongarm->value = array(
    'url' => 'news_anounce',
    'display' => 1,
    'title' => '',
  );
  $export['block_titlelink_views_headernews_english-block'] = $strongarm;

  return $export;
}
