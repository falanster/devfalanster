<?php
/**
 * @file
 * menus_project_and_clubs.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_project_and_clubs_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-first-menu.
  $menus['menu-first-menu'] = array(
    'menu_name' => 'menu-first-menu',
    'title' => 'First main menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-mobile-menu.
  $menus['menu-mobile-menu'] = array(
    'menu_name' => 'menu-mobile-menu',
    'title' => 'Mobile Menu',
    'description' => 'меню для мобильной версии',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('First main menu');
  t('Management');
  t('Mobile Menu');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('меню для мобильной версии');


  return $menus;
}
