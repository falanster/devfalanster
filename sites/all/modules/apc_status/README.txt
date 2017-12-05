APC Status
==========

Requirements:
 - Libraries API - http://drupal.org/project/libraries
 - apc.php - This third-party file is required for APC Status. It may already
   be present on your computer (e.g. in /usr/share/doc/php-apc) or may be
   extracted from the APC source (http://pecl.php.net/package/APC).

Installation:
 - Create a directory named "APC" somewhere Libraries API can find it, e.g.,
   sites/all/libraries/APC. (Note the capitalization -- the directory name is
   case sensitive).
 - Rename apc.php to apc.php.inc and place it in the APC directory.

   For example:
       $ mkdir -p sites/all/libraries/APC
       $ cd sites/all/libraries/APC
       $ curl http://svn.php.net/viewvc/pecl/apc/trunk/apc.php?view=co \
              > apc.php.inc

Usage:
 - Log in to your Drupal site as an administrator and visit
   admin/reports/status/apc.

Security Considerations
=======================

Since APC is host based allowing access to the status page is a very bad idea.
Why? Because if the drupal site gets compromised, you compromise all other sites
running on the same host. Imagine someone playing with the Clean OpCode Cache
button. How will the host and other sites react? It can make all sites on the
host unresponsive.

Caveat emptor.
