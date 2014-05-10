CUSTOM ERROR README.txt
=======================

This module allows the site admin to create custom error pages for
HTTP status codes 403 (access denied) and 404 (not found), without the
need to create nodes for each of them.

Main features:

* Configurable page title and descriptions.
* There are no author and date/time headers as with normal nodes.
* Any HTML formatted text can be be put in the page body.
* The error pages are themeable.
* Users who are not logged in and try to access an area that requires
  login will be redirected to the page they were trying to access after
  they login.
* Allows custom redirects for 404s.

Since the error pages are not real nodes, they do not have a specific
content type, and will not show up in node listings.

At present, the module can be set up to handle 403 and 404
errors. Drupal only allows those two errors to be assigned custom
pages. However, the design of the module is flexible and can
accommodate future error codes easily.


Installation:
-------------

1. Install the customerror module directory in the directory where you
   keep contributed modules (e.g. sites/all/modules/).

2. Go to the Modules page
   - Enable the customerror module.
   - If you want to messages to contain PHP, enable the core
     PHP filter module.
   Click on Save configuration.

3. Configure Error reporting
   - Go to Configuration -> System -> Site information
   - For 403 (access denied), enter the value:
       customerror/403
   - For 404 (not found), enter the value:
       customerror/404
   Click on Save configuration.

4. Configure the module:
   - Go to Configuration -> System -> Custom error
   - Enter any title and description you want for the 404 (not found)
     and 403 (access denied) pages.
   - You can use any HTML tags to format the text.
   Click on Save configuration.

5. Test your error pages.
   - Copy your present admin page url.
   - Try to go to a non-existent Drupal page on your site.
   You should see your custom error page for 404 (not found) page.

   - Log out from your site.
   - Paste the admin page url and try to go there.
   You should see your custom error page for 403 (access denied) page.


Redirecting upon login
----------------------

Here is an example of how to add custom PHP to a 403 to give the user
the option to login:

<?php
global $user;
if ($user->uid == 0) {
  $output = '<p>';
  $output .= t('If your user account has access to this page, please !message.',
    array('!message' =>
      l('log in', 'user'),
    )
  );
  $output .= '</p>';
  print $output;
}
?>

Note that customerror keeps track of what page the user is trying to
access, so after logging in, the user will be redirected to that page.


Custom redirects for 404 errors
-------------------------------

It is possible to set up custom redirects for status code 404 (not
found).

For example if you had a page called foo and a page called xyz, then
you moved them to a page called bar, and abc respectively, you can
setup a redirect pair of:

  ^foo$ bar
  ^xyz$ abc

The first pair will transparently redirect users trying to access
example.com/foo to example.com/bar.  The second pair will
transparently redirect users trying to access example.com/xyz to
example.com/abc.

You can have multiple pairs of redirects. Each must be on a line by
itself.

Note that the first argument is a regexp, and the second argument is a
path. You have to use one space between them, and enter each pattern
on a line by itself. You cannot use variables.

For more flexible URL rewriting, including variables, you may consider
using an external URL rewrite engine, such as Apache mod_rewrite.


FAQ
---

* I want to prevent robots from indexing my custom error pages by
  setting the robots meta tag in the HTML head to NOINDEX.

  - There is no need to. CustomError returns the correct HTTP status
    codes (403 and 404). This will prevent robots from indexing the
    error pages.
	
* I want to customize the custom error template output.

  - In your site's theme, duplicate your page.tpl.php to be 
    page--customerror.tpl.php and then make your modifications there.

* I want to have a different template for my 404 and 403 pages.

  - Duplicate your page.tpl.php page to be page--customerror--404.tpl.php 
    and page--customerror--403.tpl.php. You do not need a 
    page--customerror.tpl.php for this to work.

* Some 403 errors (e.g. "http://example.org/includes") are served by
  the Apache web server and not by CustomError. Isn't that a bug?

  - No. CustomError is only designed to provide a custom error page
    when the page is processed by Drupal.  The .htaccess file that
    comes with Drupal will catch some attempts to access forbidden
    directories before Drupal even see the requests.  These access
    attempts will get the default Apache 403 error document, unless
    you use the Apache ErrorDocument directive to override this, e.g:
      ErrorDocument 403 /error/403.html
    For more information about this, see:
    http://httpd.apache.org/docs/current/custom-error.html


Database
--------

This module does not require any new database tables to be installed.


Bugs/Features/Patches
---------------------

If you want to report a bug, request a feature, or submit a patch,
please do so in the issue queue at the project page on the Drupal web
site:

   http://drupal.org/project/customerror


Online documentation
--------------------

For more documentation, please see:

   https://drupal.org/node/2064843

Author
------

Principal author is Khalid Baheyeldin
(http://baheyeldin.com/khalid and http://2bits.com).

Port to Drupal 7 port has been overseen by Gisle Hannemyr
(https://drupal.org/user/409554).

The authors can be contacted for paid customizations of this module
as well as Drupal consulting, installation, development, and
customizations.
