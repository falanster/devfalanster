<?php
/**
 * @file
 * context_main_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_main_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'english_page';
  $context->description = 'Only for main page in english';
  $context->tag = 'groups';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'en' => 'en',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-headernews_english-block' => array(
          'module' => 'views',
          'delta' => 'headernews_english-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-headernews_english-block_1' => array(
          'module' => 'views',
          'delta' => 'headernews_english-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-last_video_or_podcast-block_1' => array(
          'module' => 'views',
          'delta' => 'last_video_or_podcast-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'menu-menu-hor-bottom-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-hor-bottom-menu',
          'region' => 'preface_first',
          'weight' => '-8',
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
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-15' => array(
          'module' => 'block',
          'delta' => '15',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_first',
          'weight' => '-8',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'english_page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Only for main page in english');
  t('groups');
  $export['english_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main-page';
  $context->description = 'Main page profile';
  $context->tag = 'groups';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'be' => 'be',
        'ru' => 'ru',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-headernews-block' => array(
          'module' => 'views',
          'delta' => 'headernews-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-headernews-block_1' => array(
          'module' => 'views',
          'delta' => 'headernews-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-afishi-block_2' => array(
          'module' => 'views',
          'delta' => 'afishi-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-afishi-block_1' => array(
          'module' => 'views',
          'delta' => 'afishi-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
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
        'menu-menu-hor-bottom-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-hor-bottom-menu',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'agenda-1' => array(
          'module' => 'agenda',
          'delta' => '1',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'postscript_first',
          'weight' => '-9',
        ),
        'views-last_video_or_podcast-block' => array(
          'module' => 'views',
          'delta' => 'last_video_or_podcast-block',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'poll-recent' => array(
          'module' => 'poll',
          'delta' => 'recent',
          'region' => 'postscript_third',
          'weight' => '-10',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-15' => array(
          'module' => 'block',
          'delta' => '15',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_first',
          'weight' => '-8',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'main',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main page profile');
  t('groups');
  $export['main-page'] = $context;

  return $export;
}
