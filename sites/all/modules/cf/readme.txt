
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Sub Modules
 * Contributers


INTRODUCTION
------------

Provides a collection of commonly needed functionality not in drupal core.

The reasons for adding each functionality could be any of the following:
 - Drupal removed support for some functionality.
 - The requested functionality is notably arguable, many users or developers
   agree and disagree.
 - The existing module does not support this functionality, such as backports
   from the core module of a later drupal version.
 - Snippets of code that are used often, but not often enough to make it into
   core.
 - Experimental (but production ready) or new functionality that is either
   generic or not complicated enough to have an entire module of its own.
 - Needs to act as a library and provide integration with (but not
   implementation of) other modules or third party resources.
 - Provides a solution (or workaround) for common problems encountered by
   drupal users and developers.

The reasons for not adding functionality here:
 - Large or complicated projects.
 - Implementing functionality already provided by an existing module.
 - Providing something for purposes other than for being used as a library or
   as code snippets.
 - Implementing third part resources.
 - Is experimental and not intended to be used in production.
 - Providing a solution (or workaround) for common problems that already have
   valid solutions already provided at drupal.org.

The common functionality module should be thought of as a toolkit and not as
a solution itself. However, because some solutions and workarounds can be
solved with nothing more than a snippet of code, some solutions may be found
here.

To ensure that a reduce the need for including modules and functionality that
is not needed, most of the functions provided by the common functionality
module will be provided in its own sub-module.

Each function (and sub-module) added to this project must have an argument
attached to each comment as to why it is considered needed. Sited urls are
requested but not required.


SUB MODULES
-----------
cf_settings
  cf settings provides a registry for managing php ini directives, default.php
  settings, and drupal variables. This serves two purposes. The first is to
  provide a means to prevent multiple modules from defining the same variables
  and the second is to provide a way to safely install or uninstall variables.
  The registry can be used to prevent a module from installing a variable that
  is already defined by another module.

  This also provides a means of dynamically changing php ini directives based
  on user or role. For example, for security and performance reasons, the
  anonymous user might have a memory_limit of 96M and a max_execution_time of 20
  seconds. Registered users, however, might need more resources and time, so
  they might have a memory limit of 128M and a max_execution_time of 30 seconds.

cf_error
  This submodule provides error reporting for runtime data integrity purposes.
  The goals are to provide sanity checking to ensure data integrity while
  reporting the errors without ruining the end-user experience.

  The cf module does utilize this, but it is utilized as a soft-dependency in
  such a way that if a user does not want to enable this module, then they do
  not have to.

cf_db_options
  cf database options provides a centralized and standardized way to manage a
  certain database design strategy. This database design strategy is built
  around the concept that using string-based primary keys is inefficient and
  costly. Instead, tables are expected to use numeric primary keys.

  This module further expands upon the mentioned strategy by providing a
  strategy for mapping drupal's machine_name strategy with this numeric id
  strategy for options. Options are defined as a collection of choices that may
  be associated with something, usually another table. These options are
  usually turned into select lists, radio buttons, or check boxes.

cf_http
  This submodule provides an alternative to iframes. Instead of having the
  clients load and embed remote pages into a given site, the server loads the
  remote site onto itself. One such advantage of doing this is caching the
  remote site locally so that even if the remote site disappears, a local copy
  will always be available.

cf_menu
  This submodule provides various menu related functionality. In particular,
  it provides a standardized content accessibility administration page.

cf_menu_view_unpublished
  cf menu view unpublished provides a way to make unpublished nodes in a menu
  visible to appropriately privileged users. This is not a perfect solution
  because it requires a patch to drupal core. This used to be part of cf_menu.
  It was separated from cf_menu because it requires a custom patch to drupal
  core to properly function.

cf_node
  This submodule provides of node-specific functions. In particular, this
  provides a means to initialize node objects and also load node form objects.

cf_theme
  cf theme provides a collection of theme-specific functions for themes to use.
  It provides theme template management and safe css string that allows for
  more forms of valid css syntax than allowed by drupal core.

cf_user
  This submodule provides common user-specific functions that depend on the user
  module. Some of the functionality provided is getting role ids for a user,
  checking to see if a user has a given role, and getting users who are
  associated with a given role id.


CONTRIBUTERS
------------
Kevin Day
