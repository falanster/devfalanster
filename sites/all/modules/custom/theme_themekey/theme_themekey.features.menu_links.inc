<?php
/**
 * @file
 * theme_themekey.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function theme_themekey_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_themekey:admin/config/user-interface/themekey
  $menu_links['management_themekey:admin/config/user-interface/themekey'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/themekey',
    'router_path' => 'admin/config/user-interface/themekey',
    'link_title' => 'ThemeKey',
    'options' => array(
      'attributes' => array(
        'title' => 'Set up rules to switch the site\'s appearance (theme) dynamically, depending on Drupal paths or different properties.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_themekey:admin/config/user-interface/themekey',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ThemeKey');


  return $menu_links;
}
