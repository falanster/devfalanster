<?php

/**
 * @file
 * APC Status menu callbacks.
 */

/**
 * Menu callback; Display the APC status page.
 */
function apc_status_apc() {
  // apc.php is broken without clean URLs.
  if (!variable_get('clean_url', '0')) {
    return t('<a href="@clean-url">Clean URLs</a> are required to access the APC status page.', array('@clean-url' => url('admin/settings/clean-urls')));
  }

  // Locate apc.php.inc.
  $apc = libraries_get_path('APC') . '/apc.php.inc';
  if (!is_file($apc)) {
    $output = t('<code>apc.php.inc</code> not found.  Please download and extract <a href="@apc-url">APC</a>, rename <code>apc.php</code> to <code>apc.php.inc</code> and place the file in a directory named <code>APC</code> (case-sensitive) that <a href="@libraries-api-url">Libraries API</a> can find (i.e., in <code>sites/all/libraries/APC</code>).', array('@apc-url' => "http://pecl.php.net/package/APC", '@libraries-api-url' => "http://drupal.org/project/libraries"));
    return $output;
  }

  // Hacks to get the apc.php file working.
  define('USE_AUTHENTICATION', 0);
  $_SERVER['PHP_SELF'] = url('admin/reports/status/apc');
  global $MYREQUEST, $MY_SELF, $MY_SELF_WO_SORT, $AUTHENTICATED;
  global $time, $col_black;

  // We cannot use module_load_include as otherwise the above variables
  // will not be in the global scope in the included PHP file.
  require_once $apc;
  exit();
}
