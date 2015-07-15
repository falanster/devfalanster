<?php

/**
 * @file
 * This file defines the menu page functions used by hook_menu().
 */

/**
 * Displays the content accessibility menu page.
 *
 * This page presents links to content accessibility management pages.
 *
 * @see cf_menu_menu()
 */
function cf_menu_accessibility_page() {
  drupal_set_title(t("Content Accessibility"), PASS_THROUGH);

  $blocks = cf_menu_blocks_at_path('accessibility');

  if (empty($blocks)) {
    return t("There are no links available on this page.");
  }

  ksort($blocks);
  return theme('admin_page', array('blocks' => $blocks));
}

/**
 * Displays the content accessibility menu page.
 *
 * This page presents links to non-administrative role-specific content
 * management pages.
 *
 * @see cf_menu_menu()
 */
function cf_menu_management_page() {
  drupal_set_title(t("Content Management"), PASS_THROUGH);

  $blocks = cf_menu_blocks_at_path('management');

  if (empty($blocks)) {
    return t("There are no links available on this page.");
  }

  // hide all blocks the user is not allowed to access.
  foreach ($blocks as $key => $block) {
    $access = FALSE;
    $map = array();

    // Determine access callback, which will decide whether or not the current
    // user has access to this path.
    $callback = empty($block['access_callback']) ? 0 : trim($block['access_callback']);
    // Check for a TRUE or FALSE value.
    if (is_numeric($callback)) {
      $access = (bool) $callback;
    }
    else {
      $arguments = menu_unserialize($block['access_arguments'], $map);
      // As call_user_func_array is quite slow and user_access is a very common
      // callback, it is worth making a special case for it.
      if ($callback == 'user_access') {
        $access = (count($arguments) == 1) ? user_access($arguments[0]) : user_access($arguments[0], $arguments[1]);
      }
      elseif (function_exists($callback)) {
        $access = call_user_func_array($callback, $arguments);
      }
    }

    if (!$access) {
      unset($blocks[$key]);
    }
  }

  ksort($blocks);
  return theme('admin_page', array('blocks' => $blocks));
}

/**
 * Loads menu paths at the specified path, gnerating a block array
 *
 * @param string $path
 *   a url path directly under admin/content/.
 *   For example, to get a path of 'admin/content/mine' just specify 'mine'
 *   as this string.
 *
 * @return array
 *   An array of menu link blocks.
 */
function cf_menu_blocks_at_path($path) {
  $blocks = array();

  $query = db_select('menu_router', 'mr');
  $query->innerjoin('menu_links',  'ml', 'mr.path = ml.router_path');

  $query->fields('mr');
  $query->fields('ml');
  $query->orderBy('mr.weight', 'ASC');
  $query->orderBy('ml.link_title', 'ASC');
  $query->distinct();

  $query->condition('mr.path', 'admin/content/' . $path . '/%', 'LIKE');
  $query->condition('mr.path', 'admin/content/' . $path . '/%/%', 'NOT LIKE');
  $query->condition('ml.plid', 0, '<>');

  $executed = $query->execute();

  if ($executed) {
    $available_paths = $executed->fetchAll();

    $prefix_class = "admin-list-item";
    $path_class = drupal_clean_css_identifier($path, array(' ' => '-', '_' => '_', '/' => '-', '[' => '-', ']' => ''));
    $class = $prefix_class . ' ' . $prefix_class . '-' . $path_class;

    $compact = system_admin_compact_mode();

    foreach ($available_paths as $key => $value) {
      $block = get_object_vars($value);

      _menu_link_translate($block);

      // The link description, either derived from 'description' in hook_menu()
      // or customized via menu module is used as title attribute.
      if (!empty($block['block']['attributes']['title'])) {
        $block['description'] = $value['localized_options']['attributes']['title'];
        unset($block['localized_options']['attributes']['title']);
      }

      $block['title'] = l($block['link_title'], $block['router_path']);
      $block['content'] = '';

      if (isset($block['description'])) {
        if ($compact) {
          $class_desc = ' ' . $prefix_class . '-description-compact';
        }
        else {
          $class_desc = ' ' . $prefix_class . '-description-full';
        }

        $block['content'] .= '<div class="' . $class_desc . '">' . filter_xss_admin($block['description']) . '</div>';
      }

      if (!empty($block['content'])) {
        $block['show'] = TRUE;
      }

      // Prepare for sorting as in function _menu_tree_check_access().
      // The weight is offset so it is always positive, with a uniform 5-digits.
      $blocks[(50000 + $block['weight']) . ' ' . $block['title'] . ' ' . $block['mlid']] = $block;
    }
  }

 return $blocks;
}
