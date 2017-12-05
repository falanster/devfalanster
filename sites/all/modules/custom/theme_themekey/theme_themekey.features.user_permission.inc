<?php
/**
 * @file
 * theme_themekey.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function theme_themekey_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer theme assignments'.
  $permissions['administer theme assignments'] = array(
    'name' => 'administer theme assignments',
    'roles' => array(),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themekey settings'.
  $permissions['administer themekey settings'] = array(
    'name' => 'administer themekey settings',
    'roles' => array(),
    'module' => 'themekey',
  );

  // Exported permission: 'assign node themes'.
  $permissions['assign node themes'] = array(
    'name' => 'assign node themes',
    'roles' => array(),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign path alias themes'.
  $permissions['assign path alias themes'] = array(
    'name' => 'assign path alias themes',
    'roles' => array(),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign theme to own nodes'.
  $permissions['assign theme to own nodes'] = array(
    'name' => 'assign theme to own nodes',
    'roles' => array(),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'select different theme'.
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(),
    'module' => 'themekey_user_profile',
  );

  return $permissions;
}
