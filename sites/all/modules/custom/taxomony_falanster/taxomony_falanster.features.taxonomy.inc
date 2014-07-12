<?php
/**
 * @file
 * taxomony_falanster.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function taxomony_falanster_taxonomy_default_vocabularies() {
  return array(
    'falanster' => array(
      'name' => 'Фаланстер',
      'machine_name' => 'falanster',
      'description' => 'Структура сайта',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
