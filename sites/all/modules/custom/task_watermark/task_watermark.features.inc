<?php
/**
 * @file
 * task_watermark.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function task_watermark_image_default_styles() {
  $styles = array();

  // Exported image style: watermark.
  $styles['watermark'] = array(
    'name' => 'watermark',
    'label' => 'watermark',
    'effects' => array(
      11 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'right',
          'ypos' => 'bottom',
          'alpha' => 100,
          'path' => 'public://image/watermark/watermark_1.png',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
