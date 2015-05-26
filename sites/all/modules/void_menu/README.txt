Void Menu Module
------------------------
Project page: http://drupal.org/sandbox/WillHall/1109702

Description
-----------
Void Menu creates valid link item placeholders for use in the drupal menu system. This module allows you to use items in your links that would previously be rejected by Drupal.

You can assign up to ten void items any HTML value that you desire and have it instantly available as a menu item. Including JavaScript function calls.

This module depends on Menu module.

Features
--------
  - User can create a new menu item and place either "<void>" or "<void[1-9]"> as the path. In the configuration page you can set the value for each void item independently.
  
Installation
------------
1. Copy void_menu folder to your sites/all/modules directory.
2. At Administer -> Site building -> Modules (admin/build/modules) enable the module.
3. Configure the module settings at Administer -> Configuration -> User Interface -> Void Menu (admin/config/user-interface/void_menu).

Upgrading
---------
Just overwrite (or replace) the older void_menu folder with the newer version.

Security
--------
This module allows users to enter javascript and hook it into the Drupal menu system. Any user with "Administer Site Configuration" will have access to this module, and many others that could prove harmful if a malicious user was given free reign over your web site. Always verify which users you are granting access to Administer your site.

Contact
-------
Written by William Hall - www.mrtheme.com
Based off of the work done in special_menu_items and menu_firstchild

You may use the issue tracker on drupal.org at any time, this module will remain under active development. You may also emil me directly at will@mrtheme.com