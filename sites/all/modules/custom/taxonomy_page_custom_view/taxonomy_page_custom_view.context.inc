<?php
/**
 * @file
 * taxonomy_page_custom_view.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function taxonomy_page_custom_view_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clubs';
  $context->description = 'Clubs custom page based on other-pages context';
  $context->tag = 'custom';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'other-pages' => 'other-pages',
      ),
    ),
    'path' => array(
      'values' => array(
        'cluby' => 'cluby',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-clubs-block_2' => array(
          'module' => 'views',
          'delta' => 'clubs-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Clubs custom page based on other-pages context');
  t('custom');
  $export['clubs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects';
  $context->description = '';
  $context->tag = 'custom';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'grid_context' => 'grid_context',
      ),
    ),
    'path' => array(
      'values' => array(
        'proekty' => 'proekty',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-projects-block_2' => array(
          'module' => 'views',
          'delta' => 'projects-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('custom');
  $export['projects'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'taxonomy';
  $context->description = 'выкарыстоўваем для старонкі спісу тэрмінаў таксаманіі';
  $context->tag = 'custom';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'tag/*' => 'tag/*',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'clone_of_other',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('custom');
  t('выкарыстоўваем для старонкі спісу тэрмінаў таксаманіі');
  $export['taxonomy'] = $context;

  return $export;
}
