<?php
/**
 * @file
 * first_main_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function first_main_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-first-menu.
  $menus['menu-first-menu'] = array(
    'menu_name' => 'menu-first-menu',
    'title' => 'First main menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('First main menu');


  return $menus;
}
