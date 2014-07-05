<?php
/**
 * @file
 * role_editor.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function role_editor_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 1,
  );

  return $roles;
}
