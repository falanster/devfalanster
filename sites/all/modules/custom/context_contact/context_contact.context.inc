<?php
/**
 * @file
 * context_contact.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_contact_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact_page_2';
  $context->description = 'кантэкст для старонкі кантактаў';
  $context->tag = 'custom';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'kantakt' => 'kantakt',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-contact-us' => array(
          'module' => 'menu',
          'delta' => 'menu-contact-us',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-contact_us-block' => array(
          'module' => 'views',
          'delta' => 'contact_us-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-contact_us-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_us-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('custom');
  t('кантэкст для старонкі кантактаў');
  $export['contact_page_2'] = $context;

  return $export;
}
