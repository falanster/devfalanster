<?php
/**
 * @file
 * menus_project_and_clubs.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_project_and_clubs_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu
  $menu_links['management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-mobile-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Mobile Menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Mobile Menu');


  return $menu_links;
}
