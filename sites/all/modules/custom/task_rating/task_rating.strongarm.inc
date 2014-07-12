<?php
/**
 * @file
 * task_rating.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function task_rating_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_bot_botscout_key';
  $strongarm->value = '';
  $export['rate_bot_botscout_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_bot_hour_threshold';
  $strongarm->value = '250';
  $export['rate_bot_hour_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_bot_minute_threshold';
  $strongarm->value = '25';
  $export['rate_bot_minute_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'voting_place',
      'tag' => 'vote',
      'title' => 'Vote-1',
      'node_types' => array(
        0 => 'afishi',
        1 => 'gallery',
        2 => 'news',
      ),
      'comment_types' => array(
        0 => 'gallery',
        1 => 'news',
      ),
      'options' => array(
        0 => array(
          0 => 1,
          1 => '+1',
        ),
        1 => array(
          0 => -1,
          1 => '-1',
        ),
      ),
      'template' => 'number_up_down',
      'node_display' => '1',
      'teaser_display' => TRUE,
      'comment_display' => '0',
      'node_display_mode' => '2',
      'teaser_display_mode' => '2',
      'comment_display_mode' => '2',
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => '',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '1',
      'use_source_translation' => TRUE,
      'value_type' => 'points',
      'theme' => 'rate_template_number_up_down',
      'css' => 'sites/all/modules/rate/templates/number-up-down/number-up-down.css',
      'translate' => TRUE,
      'expiration' => '-1',
      'expiration_allow_override' => FALSE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
