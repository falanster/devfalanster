<?php

/**
 * @file
 * Hooks provided by the cf module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Define user permissions associated with the CF module.
 *
 * Normally other modules can implement their own hook_permission.
 * However, in order to help improve organization of the permission page,
 * this hook is provided so that all sub-modules may have their permissions
 * appear under the parent group.
 * This is provided for structural organizational purposes and its usage is
 * not required.
 *
 * @see hook_permission()
 */
function hook_cf_permission(&$permissions) {
  if (!is_array($permissions)) $permissions = array();

  $permissions['example cf permission'] = array(
    'title' => t("Example CF Permission"),
    'description' => t("Specify whether or not a user or role is allowed to access something."),
  );
}

/**
 * @} End of "@addtogroup hooks".
 */
