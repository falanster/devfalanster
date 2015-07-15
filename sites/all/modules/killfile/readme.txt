
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Contributers
 * Credits


INTRODUCTION
------------

Current Maintainer: Kevin Day <thekevinday@gmail.com>

Provides a soft-deletion or trash-bin functionality for drupal node content.
Soft delete can be enabled/disabled on a per content type basis.
Integrates with views api, such as filtering out soft deleted nodes from a view.
Integrates with rules api, such as having a given node be auto-deleted after
some given amount of time.


This is a rewrite of the drupal 6.x killfile for drupal 7.x.
Unlike the 6.x release, this will utilize existing modules to handle tasks
such as time based deleting content. This also works on a per content-type
base instead of on a global basis.

The killfile module was written by Arto Bendiken <http://bendiken.net/>.

For more information on this project please refer to:
  <http://drupal.org/project/killfile>


INSTALLATION
------------

Simply add the module to /sites/all/modules/.

Optional requirements:
  views module
  rules module


CONTRIBUTERS
------------
Drupal 7 version by Kevin Day
Original version Developed and maintained by Arto Bendiken <http://bendiken.net/>


CREDITS
-------
Sponsored by MakaluMedia Group <http://www.makalumedia.com/>
Sponsored by M.C. Dean, Inc. <http://www.mcdean.com/>
Sponsored by SPAWAR <http://www.spawar.navy.mil/>

