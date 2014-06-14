<?php
/**
 * @file
 * taxonomy_page_custom_view.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function taxonomy_page_custom_view_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_falanster_pattern';
  $strongarm->value = 'tag/[term:tid]';
  $export['pathauto_taxonomy_term_falanster_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_knowledge_base_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_knowledge_base_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_open_vocabulary_pattern';
  $strongarm->value = 'tag/[term:tid]';
  $export['pathauto_taxonomy_term_open_vocabulary_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = 'tag/[term:tid]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tags_pattern';
  $strongarm->value = 'tag/[term:tid]';
  $export['pathauto_taxonomy_term_tags_pattern'] = $strongarm;

  return $export;
}
