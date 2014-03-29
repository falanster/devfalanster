<?php
/**
 * @file
 * donation_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function donation_blocks_context_default_contexts() {
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'user_second',
          'weight' => '-10',
        ),
        'views-last_video_or_podcast-block_1' => array(
          'module' => 'views',
          'delta' => 'last_video_or_podcast-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-headernews_english-block' => array(
          'module' => 'views',
          'delta' => 'headernews_english-block',
          'region' => 'header_first',
          'weight' => '-31',
        ),
        'views-headernews_english-block_1' => array(
          'module' => 'views',
          'delta' => 'headernews_english-block_1',
          'region' => 'header_first',
          'weight' => '-30',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'preface_first',
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
        'menu-menu-hor-bottom-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-hor-bottom-menu',
          'region' => 'footer_second',
          'weight' => '-37',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'footer_second',
          'weight' => '-36',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'footer_second',
          'weight' => '-35',
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'user_second',
          'weight' => '-34',
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
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'agenda-1' => array(
          'module' => 'agenda',
          'delta' => '1',
          'region' => 'postscript_first',
          'weight' => '-10',
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
        'menu-menu-hor-bottom-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-hor-bottom-menu',
          'region' => 'footer_second',
          'weight' => '-37',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'footer_second',
          'weight' => '-36',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'footer_second',
          'weight' => '-35',
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'user_second',
          'weight' => '-10',
        ),
        'agenda-1' => array(
          'module' => 'agenda',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-37',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => '16',
          'region' => 'sidebar_second',
          'weight' => '-36',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'views-twitter_list-block' => array(
          'module' => 'views',
          'delta' => 'twitter_list-block',
          'region' => 'sidebar_second',
          'weight' => '-34',
        ),
        'simplenews-1' => array(
          'module' => 'simplenews',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-33',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'menu-menu-hot-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-hot-pages',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'postscript_first',
          'weight' => '-9',
        ),
        'views-banner-block' => array(
          'module' => 'views',
          'delta' => 'banner-block',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'postscript_third',
          'weight' => '-10',
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
