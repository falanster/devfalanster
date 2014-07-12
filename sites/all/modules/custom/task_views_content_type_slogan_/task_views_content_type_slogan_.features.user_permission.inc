<?php
/**
 * @file
 * task_views_content_type_slogan_.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function task_views_content_type_slogan__user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create slogan content'.
  $permissions['create slogan content'] = array(
    'name' => 'create slogan content',
    'roles' => array(
      'editor' => 'editor',
      'supereditor' => 'supereditor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any slogan content'.
  $permissions['delete any slogan content'] = array(
    'name' => 'delete any slogan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own slogan content'.
  $permissions['delete own slogan content'] = array(
    'name' => 'delete own slogan content',
    'roles' => array(
      'editor' => 'editor',
      'supereditor' => 'supereditor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'ds_switch slogan'.
  $permissions['ds_switch slogan'] = array(
    'name' => 'ds_switch slogan',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'edit any slogan content'.
  $permissions['edit any slogan content'] = array(
    'name' => 'edit any slogan content',
    'roles' => array(
      'editor' => 'editor',
      'supereditor' => 'supereditor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own slogan content'.
  $permissions['edit own slogan content'] = array(
    'name' => 'edit own slogan content',
    'roles' => array(
      'editor' => 'editor',
      'supereditor' => 'supereditor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
