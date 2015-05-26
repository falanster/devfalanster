<?php
/**
 * @file
 * menus_top_bottom_second.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_top_bottom_second_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-contact-us.
  $menus['menu-contact-us'] = array(
    'menu_name' => 'menu-contact-us',
    'title' => 'Contact us',
    'description' => 'for contact page  (webform  + adres)',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-hor-bottom-menu.
  $menus['menu-hor-bottom-menu'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'title' => 'Hor Bottom Menu',
    'description' => 'Нижнее горизонтальное меню',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-hot-pages.
  $menus['menu-hot-pages'] = array(
    'menu_name' => 'menu-hot-pages',
    'title' => 'Menu hot pages',
    'description' => 'размещается снизу внутренней страницы',
    'language' => 'und',
    'i18n_mode' => 5,
  );
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
  t('Contact us');
  t('Hor Bottom Menu');
  t('Menu hot pages');
  t('Second main menu');
  t('for contact page  (webform  + adres)');
  t('Нижнее горизонтальное меню');
  t('размещается снизу внутренней страницы');


  return $menus;
}
