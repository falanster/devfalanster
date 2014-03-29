<?php
/**
 * @file
 * preview_main_page.features.inc
 */

/**
 * Implements hook_views_api().
 */
function preview_main_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function preview_main_page_image_default_styles() {
  $styles = array();

  // Exported image style: news_square.
  $styles['news_square'] = array(
    'name' => 'news_square',
    'label' => 'news_square',
    'effects' => array(
      11 => array(
        'label' => 'Focus Crop',
        'help' => 'Crop based on data provided by <em>ImageField Focus</em>.',
        'effect callback' => 'imagefield_focus_crop_effect',
        'form callback' => 'imagefield_focus_crop_form',
        'summary theme' => 'imagefield_focus_crop_summary',
        'module' => 'imagefield_focus',
        'name' => 'imagefield_focus_crop',
        'data' => array(
          'target' => 'focus_rect first',
        ),
        'weight' => -10,
      ),
      18 => array(
        'label' => 'Масштабирование',
        'help' => 'Масштабирование позволяет изменить размеры изображения с сохранением пропорций. Если введён размер только одной стороны, то размер другой будет вычислен автоматически. Если введены два размера, то каждое будет определять максимальный размер по своему направлению и применяться в зависимости от формата изображения.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 415,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function preview_main_page_node_info() {
  $items = array(
    'afishi' => array(
      'name' => t('Afishi'),
      'base' => 'node_content',
      'description' => t('Добавляем афиши на сайт'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Добавляем новости'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
