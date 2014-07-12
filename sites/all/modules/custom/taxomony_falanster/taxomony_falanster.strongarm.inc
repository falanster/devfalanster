<?php
/**
 * @file
 * taxomony_falanster.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function taxomony_falanster_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_vocab_falanster';
  $strongarm->value = '';
  $export['page_title_vocab_falanster'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_vocab_falanster_showfield';
  $strongarm->value = 0;
  $export['page_title_vocab_falanster_showfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_falanster_pattern';
  $strongarm->value = 'tag/[term:tid]';
  $export['pathauto_taxonomy_term_falanster_pattern'] = $strongarm;

  return $export;
}
