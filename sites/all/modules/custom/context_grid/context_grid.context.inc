<?php
/**
 * @file
 * context_grid.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_grid_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'grid_context';
  $context->description = 'промежуточный контекст, который будет выводить сетки';
  $context->tag = 'groups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'projects_and_clubs' => 'projects_and_clubs',
        'news' => 'news',
        'afishy' => 'afishy',
        'gallery' => 'gallery',
        'news_anounce' => 'news_anounce',
        'arganyzacyja' => 'arganyzacyja',
        'udzelnichaj' => 'udzelnichaj',
        'tag/*' => 'tag/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'menu-menu-hot-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-hot-pages',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'views-banner-block' => array(
          'module' => 'views',
          'delta' => 'banner-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'footer_second',
          'weight' => '-9',
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
  t('groups');
  t('промежуточный контекст, который будет выводить сетки');
  $export['grid_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'other-pages';
  $context->description = 'Other page profile ';
  $context->tag = 'groups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~*/admin/*' => '~*/admin/*',
        '~admin/*' => '~admin/*',
        '~node/add/*' => '~node/add/*',
        '~node/*/edit' => '~node/*/edit',
        '~projects_and_clubs' => '~projects_and_clubs',
        '~news' => '~news',
        '~afishy' => '~afishy',
        '~gallery' => '~gallery',
        '~news_anounce' => '~news_anounce',
        '~arganyzacyja' => '~arganyzacyja',
        '~udzelnichaj' => '~udzelnichaj',
        '~tag/*' => '~tag/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-17',
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'content',
          'weight' => '-16',
        ),
        'agenda-1' => array(
          'module' => 'agenda',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => '16',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-twitter_list-block' => array(
          'module' => 'views',
          'delta' => 'twitter_list-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'menu-menu-hot-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-hot-pages',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'views-banner-block' => array(
          'module' => 'views',
          'delta' => 'banner-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'footer_second',
          'weight' => '-9',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'other',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Other page profile ');
  t('groups');
  $export['other-pages'] = $context;

  return $export;
}
