<?php
/**
 * @file
 * task_views_content_type_slogan_.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function task_views_content_type_slogan__menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_slogan:node/add/slogan
  $menu_links['navigation_slogan:node/add/slogan'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/slogan',
    'router_path' => 'node/add/slogan',
    'link_title' => 'Slogan',
    'options' => array(
      'attributes' => array(
        'title' => 'Тип материала для слоганов falanster\'a',
      ),
      'alter' => TRUE,
      'identifier' => 'navigation_slogan:node/add/slogan',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Slogan');


  return $menu_links;
}
