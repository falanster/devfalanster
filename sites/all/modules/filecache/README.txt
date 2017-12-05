CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Installation
 * Configuration
  * Cache bins
  * Cache directory
  * Cache prefix
 * Uninstalling
 * Troubleshooting
 * Maintainers


INTRODUCTION
============

This modules allows Drupal cache bins to be stored in files instead of
storing in database.

 * For a full description of the module, visit the project page:
   https://drupal.org/project/filecache

 * To submit bug reports and feature suggestions, or to track changes:
   https://drupal.org/project/issues/filecache


REQUIREMENTS
============

No modules are required but for security reasons File Cache needs private
directory where to store files outside of webserver root.


INSTALLATION
============

Install and enable filecache module as usual. Add the following to site's
settings.php:

$conf['cache_backends'] = array('sites/all/modules/filecache/filecache.inc');
$conf['cache_default_class'] = 'DrupalFileCache';

You may need to adjust filecache.inc path if filecache is not installed globally.

Go to Status report page <admin/reports/status>. Run cron. Confirm that there
are no errors and there is only a warning for using the default location.

SECURITY NOTE: The default location depends on the webserver to deny web access
to directories that start with ".ht". Check if there is HTTP error 403 Forbidden
and if it is not, you MUST NOT LEAVE THE CONFIGURATION AS IS IN THIS CASE.

If directories starting with ".ht" are denied access to, you may safely follow
the instructions in Status report to remove the warning.

Apache webserver usually denies access to files and directories starting with
".ht". To configure the popular nginx webserver to do the same, add the following
lines to the server section:

location ~ /\.ht {
  deny all;
}


CONFIGURATION
=============

All configuration settings reside in settings.php.


CACHE BINS
----------

You can specify which class is used for each cache bin. File Cache class is
named DrupalFileCache and the quickstart configuration in Installation section
uses this class as default for all cache bins. You can set specific classes
for cache bins by using cache_class_CACHEBIN configuration setting. Example:

$conf['cache_default_class'] = 'DrupalFileCache';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

The official documentation is located in
https://api.drupal.org/api/drupal/includes%21cache.inc/interface/DrupalCacheInterface/7.x


CACHE DIRECTORY
---------------

As explained in the Installation section, the cache directory must not be
accessible through the webserver. The configuration setting is named
filecache_directory and in the simple case, it is full path to a directory.
File Cache will try to create the directory for you. If you manually create it,
make sure that its owner is the same user as used by PHP, and its access mode
is 700 (owner can do anything, others are not allowed to access the directory).

If you want to have different directories for different cache bins,
the configuration setting should be array with cache bins as keys and directory
locations as values. The 'default' cache bin is used for all cache bins that
are not explicitly configured. You don't provide the name of the cache bin
as component in the pathname, because File Cache always creates subdirectory
for each cache bin. Example:

$conf['filecache_directory']['default'] = '/tmp/filecache';
$conf['filecache_directory']['cache'] = '/dev/shm/filecache';                                                                                                                                                                                                
$conf['filecache_directory']['cache_bootstrap'] = '/dev/shm/filecache';

Since directories are automatically created by File Cache, cleanup of these
directories on restart will recreate them by File Cache. Note that for some
Drupal sites /tmp may not have enough disk space. As explained in the next
subsection, cache bin directories by default have site-specific prefix and
you can provide the same directory for all your sites in multisite Drupal.


CACHE BIN PREFIX
----------------

File Cache supports the unified cache bin prefix proposal as described in
https://www.drupal.org/node/1324812 . By default, the result of conf_path()
is used with '/' replaced by '_'. For the default website, this means that
'sites_default_' is used as prefix for all cache bin directories inside
filecache_directory setting. Example from the proposal:

// Default prefix (all backends) no prefix if not set or set to FALSE:
$conf['cache_prefix']['default'] = 'someprefix_';
// Sample prefix for cache_page bin:
$conf['cache_prefix']['cache_page'] = 'otherprefix_';
// Force no prefix for the 'cache_bootstrap' bin:
$conf['cache_prefix']['cache_bootstrap'] = FALSE;

Setting global prefix without exceptions, like in filecache_directory, is also
supported:

$conf['cache_prefix'] = 'siteprefix_';

You can also remove the prefix for all cache bins:

$conf['cache_prefix'] = FALSE;


UNINSTALLING
============

File Cache tries its best to avoid problems when it is disabled in settings.php.
Please be sure to run cron after disabling File Cache in settings.php and before
disabling or uninstalling the module.


TROUBLESHOOTING
===============

You should check Status report page for self-checks by File Cache.

If you use Drush, File Cache detects that PHP CLI is used and doesn't allow
creating new files or directories. This is to avoid permission problems with
these created files/directories when they are accessed by webserver.


MAINTAINER
==========

Ognyan Kulev (ogi) - https://www.drupal.org/u/ogi