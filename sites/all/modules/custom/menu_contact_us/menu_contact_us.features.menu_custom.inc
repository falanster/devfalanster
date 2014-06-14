<?php
/**
 * @file
 * menu_contact_us.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_contact_us_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-contact-us.
  $menus['menu-contact-us'] = array(
    'menu_name' => 'menu-contact-us',
    'title' => 'Contact us',
    'description' => 'for contact page  (webform  + adres)',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact us');
  t('for contact page  (webform  + adres)');


  return $menus;
}
