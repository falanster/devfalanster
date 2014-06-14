<?php
/**
 * @file
 * organization_and_contact_helpus_pages.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function organization_and_contact_helpus_pages_menu_default_menu_custom() {
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
