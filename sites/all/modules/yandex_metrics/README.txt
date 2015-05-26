------------------------------------------------------------------------------
                               YANDEX.METRICS
------------------------------------------------------------------------------


The Yandex.Metrica [1] service is European alternative of Google Analytics.

The Yandex.Metrics project helps to integrate a website with the Yandex.Metrica [1].

The project consists of two modules, such as Yandex.Metrics Counter and Yandex.Metrics Reports.

* Yandex.Metrics Counter module
    Features:
        * Installing Yandex.Metrica counter code on site
        * Configuring visibility of the counter
    Dependencies
        * NO DEPENDENCIES! Just enable and use.

* Yandex.Metrics Reports module
    Note:
        The Yandex.Metrica API [2] is used for communication with Yandex.Metrica service.
    Features:
        * Reports and charts:
            * Page Views, Visitors, New Visitors
            * Traffic Sources
            * Popular Search Phrases
            * Popular Content
            * Geography of Visits
            * Hourly Traffic
            * Demography of Visits
        * Block with popular content links (Views module is used)
    Dependencies
        * Yandex.Metrics Counter module
        * Google chart API [3]
        * Yandex Services Authorization API [13]
        * Views [4]
        * [Optional] For support of internationalized domain names
          download idna_convert class [5] of Matthias Sommerfeld and copy it
          into the 'sites/all/libraries/idna_convert/' or 'sites/name_of_your_site/libraries/idna_convert/'
          folder of your Drupal setup.

Interface translations (.po):
Russian
Ukrainian



INSTALLING
------------------------------------------------------------------------------
1. Backup your database.

2. Make sure you resolved dependencies of modules. If you are going to use Yandex.Metrics Reports module
   please install Google chart API [3], Views [4] and Yandex Services Authorization API [13] modules first.

3. If you use internationalized domain name you should download PHP file idna_convert.class.php
   of Matthias Sommerfeld from [5] and copy it into the 'sites/all/libraries/idna_convert/'
   folder of your Drupal setup.

4. Copy the complete 'yandex_metrics/' directory into the 'sites/all/modules/' folder of
   your Drupal setup. 
   More information about installing contributed modules could be found at 
   "Installing contributed modules (Drupal 7)" [14]

5. Enable necessary modules in "Yandex.Metrics" section of module administration page
   (Administration >> Modules).

6. Configure modules (see "CONFIGURATION" below).



UPDATING
------------------------------------------------------------------------------
1. Verify that the version you are going to upgrade contains all the features
   you are using in your Drupal setup. Some features could have been removed
   or replaced by others.

2. Read carefully in the project issue queue [8] about upgrade paths problems
   before you start the upgrade process.

3. Backup your database.

4. Turn on maintenance mode.

5. Update current module code with latest recommended version. Previous versions
   could have bugs already reported and fixed in the last version.

6. Call the update.php script and finish the update operation.
   For more information please go to: http://groups.drupal.org/node/19513

7. Verify your module configuration and check that the features you are using
   work as expected. Also verify that all required modules are enabled, and
   permissions are set as desired.

8. Turn off maintenance mode.

Note: whenever you have the chance, try an update in a local or development
      copy of your site.


CONFIGURATION
------------------------------------------------------------------------------
* Yandex.Metrics Counter module
    1. On the access control administration page ("Administration >> People >> Permissions")
       you need to assign:

        *	"Administer Yandex.Metrics Settings" permission to the roles that are allowed
            to administer the Yandex.Metrics settings.

    2. Create Yandex.Metrica [1] account.

       Please skip this step if you have already had it.

    3. Create Yandex.Metrica counter for your site at Yandex.Metrica admin interface.

       Note: We recommend to create simple counter without any widget
             but counter code with widget is acceptable.

       Generate and save this Javascript code for later usage.

       Please skip this step if you have already created a counter.

    4. Go to the module settings page ("Administration >> Configuration >> System >> Yandex.Metrics")
       Users need the "Administer Yandex.Metrics Settings" permission to access to this page.

       Paste Javascript code of counter from Yandex.Metrica to the Counter Code text field
       on the Counter Code settings page.
       You can also define counter code visibility settings.
       Then submit form.
       By this step you add counter code to the footer of permitted pages of your site.

       Please skip this step if you have already added Yandex.Metrica counter code on your site pages
       through another way.

       Please skip next steps if you need nothing except installation of the counter code.


* Yandex.Metrics Reports module
    1. On the access control administration page ("Administration >> People >> Permissions")
       you need to assign:

        *   "Access Yandex.Metrics report" permission to the roles that are allowed
            to view Yandex.Metrics Summary Report

    2. Register Yandex application and authorize your site following
       Yandex Services Authorization API module [13] documentation.
       Make sure that you granted
       "Яндекс.Метрика" -> "Получение статистики, чтение параметров своих и доверенных счётчиков"
       permission to the Yandex application.

    3. Reports settings
       Go to Reports tab ("Administration >> Configuration >> System >> Yandex.Metrics >> Reports")
       to enable or disable some of the reports.

    4. Check Yandex.Metrics Summary Report content
       ("Administration >> Reports >> Yandex.Metrics Summary Report").
       To access this page users need the "Access Yandex.Metrics report" permission.
       Note:
         Your report can be empty if you have just created Yandex.Metrics counter
         and placed it to your site. Probably statistic information have not been collected yet.
         Please try again later.

    5. After successful module installation and configuration, you will be able to enable "Popular content (Yandex.Metrics)" block.
       This block shows popular content pulled from Yandex.Metrica as a list of links.

       To enable module go to ("Administration >> Structure >> Blocks")

       To configure block settings you can change "Popular content" view ("Administration >> Structure >> Views")

    6. The module uses Cron [7] for fetching data for "Popular Content" view from Yandex.Metrica.
       Go to Cron settings page ("Administration >> Configuration >> System >> Yandex.Metrics >> Cron")
       to change default settings.


DEVELOPMENT
------------------------------------------------------------------------------
Read how to write own plugins for Yandex.Metrics Reports module in yandex_metrics_reports/API.txt.


BUGS AND SHORTCOMINGS
------------------------------------------------------------------------------
* See the list of project issues [8].


CREDITS
------------------------------------------------------------------------------
Maintainers: Konstantin Komelin [9], Kate Marshalkina [10]
Original idea: Konstantin Komelin [9], Alex Sorokin [11]
Committers: [12]
Thanks to all great guys who contributed to the project!


LINKS
------------------------------------------------------------------------------
[1] http://metrika.yandex.ru/
[2] http://api.yandex.ru/metrika/
[3] http://drupal.org/project/chart
[4] http://drupal.org/project/views
[5] http://www.phpclasses.org/browse/file/5845.html
[6] http://api.yandex.ru/oauth/doc/dg/tasks/register-client.xml
[7] http://drupal.org/cron
[8] http://drupal.org/project/issues/yandex_metrics
[9] http://drupal.org/user/1195752
[10] http://drupal.org/user/1399638
[11] http://drupal.org/user/108088
[12] http://drupal.org/node/1180284/committers
[13] https://drupal.org/project/yandex_services_auth
[14] https://drupal.org/documentation/install/modules-themes/modules-7
