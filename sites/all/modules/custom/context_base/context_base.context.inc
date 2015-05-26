<?php
/**
 * @file
 * context_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'base';
  $context->description = 'base sitewide set of blocks';
  $context->tag = 'sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'logo',
          'weight' => '-10',
        ),
        'menu-menu-first-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-first-menu',
          'region' => 'menu_first',
          'weight' => '-10',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'language',
          'weight' => '-10',
        ),
        'views-slogan-block' => array(
          'module' => 'views',
          'delta' => 'slogan-block',
          'region' => 'slogan',
          'weight' => '-10',
        ),
        'menu-menu-second-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-second-menu',
          'region' => 'menu_second',
          'weight' => '-10',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'login',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('base sitewide set of blocks');
  t('sitewide');
  $export['base'] = $context;

  return $export;
}
