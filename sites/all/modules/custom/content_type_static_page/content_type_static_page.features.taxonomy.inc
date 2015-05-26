<?php
/**
 * @file
 * content_type_static_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function content_type_static_page_taxonomy_default_vocabularies() {
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
    'open_vocabulary' => array(
      'name' => 'Website open vocabulary',
      'machine_name' => 'open_vocabulary',
      'description' => 'можно добавлять новый тег(и) при создании узла',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
