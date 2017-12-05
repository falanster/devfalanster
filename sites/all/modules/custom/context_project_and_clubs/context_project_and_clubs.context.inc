<?php
/**
 * @file
 * context_project_and_clubs.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_project_and_clubs_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects_and_clubs';
  $context->description = 'контекст для страницы: проекты и клубы';
  $context->tag = 'custom';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'grid_context' => 'grid_context',
      ),
    ),
    'path' => array(
      'values' => array(
        'projects_and_clubs' => 'projects_and_clubs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-22' => array(
          'module' => 'block',
          'delta' => '22',
          'region' => 'content',
          'weight' => '-20',
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'content',
          'weight' => '-19',
        ),
        'views-projects-block_2' => array(
          'module' => 'views',
          'delta' => 'projects-block_2',
          'region' => 'content',
          'weight' => '-18',
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'content',
          'weight' => '-17',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'content',
          'weight' => '-16',
        ),
        'views-clubs-block_2' => array(
          'module' => 'views',
          'delta' => 'clubs-block_2',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'clone_of_other',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('custom');
  t('контекст для страницы: проекты и клубы');
  $export['projects_and_clubs'] = $context;

  return $export;
}
