Agenda
======

INTRODUCTION
------------
The Agenda module allows you to display a list of upcoming events from Google
Calendar as a block on your website.

The events are automatically downloaded and cached from the Calendar IDs
specified in the Agenda administration page. Unlimited calendars can be added,
and the colours for each calendar can be specified in the CSS file.

The output is fully themeable, and uses jQuery for dynamic effects such as
rounded corners, and click-toggling extra information.

REQUIREMENTS
------------
This module requires the following modules:
 * Block (Drupal core)
 * Libraries API (https://www.drupal.org/project/libraries)

INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.

 * Install the Google API Client Library for PHP:
   * Navigate to https://github.com/google/google-api-php-client
   * Download the 1.1.2 release at
     https://github.com/google/google-api-php-client/releases/tag/1.1.2.
   * Rename the downloaded directory "google-api-php-client" and move it to
     the sites/all/libraries directory.
   * Check admin/reports/status to ensure it is installed properly.

 * Obtain a Google API Developer ID key:
   * Navigate to https://code.google.com/apis/console.
   * Create a project.
   * Navigate to "APIs" in the left menu of the new project and turn on the
     Calendar API (agree to the Terms of Service).
   * Navigate to "Credentials" in the left menu under "APIs & auth".
   * Create a new key (server key) if you don't already have one. You may have
     to (or want to) specify particular IP addresses to accept requests from.
   * Once it's created, it will display on that page. Copy the "API KEY" and
     save it for the next step (see CONFIGURATION below).

CONFIGURATION
-------------
 * Navigate to module settings at admin/config/services/agenda
 * Click the "Settings" tab and add your Google API Key (see "Obtain a
   Google API Developer ID key" under INSTALLATION in this file). The module
   will not work until you have done so.
 * Navigate back to the module settings and configure each block to be used.

TROUBLESHOOTING
---------------
 * If events are not displaying when they should:
   * See INSTALLATION in this file and ensure you have properly installed the
     Google API Client Library for PHP. Check this at admin/reports/status.
   * See INSTALLATION in this file and ensure you have created a project,
     enabled the Calendar API in that project, and obtained an API key. The
     instructions mention a server key, but browser keys may also work.
   * See INSTALLATION and determine whether or not you need to supply a specific
     IP address in your Google API Key configuration.
   * See CONFIGURATION in this file and ensure you have added the Google API Key
     to the module's configuration settings.
   * Check the Calendar ID and other module/block configurations to ensure they
     are accurate.
