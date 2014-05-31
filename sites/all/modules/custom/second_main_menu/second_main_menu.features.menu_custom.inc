<?php
/**
 * @file
 * second_main_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function second_main_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-second-menu.
  $menus['menu-second-menu'] = array(
    'menu_name' => 'menu-second-menu',
    'title' => 'Second main menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Second main menu');


  return $menus;
}
