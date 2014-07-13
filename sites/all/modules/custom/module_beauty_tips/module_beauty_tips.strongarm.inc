<?php
/**
 * @file
 * module_beauty_tips.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function module_beauty_tips_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_defaults';
  $strongarm->value = array(
    'cssStyles' => array(),
  );
  $export['beautytips_defaults'] = $strongarm;

  return $export;
}
