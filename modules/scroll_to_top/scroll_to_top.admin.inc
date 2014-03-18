<?php

/**
 * @file
 * Administration page for scroll to top module
 *
 */

function scroll_to_top_settings() {
$form = array();
  
  $form['scroll_to_top_position'] = array(
    '#title' => t('Position'),
    '#description' => t('Sroll to top button position'),
    '#type' => 'select',
    '#options' => array(
      1 => t('right'),
      2 => t('left'),
      3 => t('middle'),
    ),
    '#default_value' => variable_get('scroll_to_top_position', 0.5),
  );
  $form['scroll_to_top_bg_color_hover'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color on mouse over'),
    '#description' => t('Button background color on mouse over default #777777'),
    '#default_value' => variable_get('scroll_to_top_bg_color_hover', '#777777'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  $form['scroll_to_top_bg_color_out'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color on mouse out'),
    '#description' => t('Button background color on mouse over default #CCCCCC'),
    '#default_value' => variable_get('scroll_to_top_bg_color_out', '#CCCCCC'),
    '#size' => 10,
    '#maxlength' => 7,
  );
  $form['scroll_to_top_display_text'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display label'),
    '#description' => t('Display "BACK TO TOP" text under the button'),
    '#default_value' => variable_get('scroll_to_top_display_text', TRUE),
  );

  return system_settings_form($form);
}

