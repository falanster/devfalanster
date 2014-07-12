<?php
/**
 * @file
 * task_project_and_clubs.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function task_project_and_clubs_image_default_styles() {
  $styles = array();

  // Exported image style: internal_view_square.
  $styles['internal_view_square'] = array(
    'name' => 'internal_view_square',
    'label' => 'internal_view_square',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 270,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
