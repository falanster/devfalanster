------------------------------------------------------------------------------
                       Yandex Services Authorization API
------------------------------------------------------------------------------

This project is the common authorization API for all Yandex [1] services
which support Yandex OAuth [2] method.

Supported services:

    Мой.Круг
    Я.ру
    Яндекс.Вебмастер
    Яндекс.Видео
    Яндекс.Директ
    Яндекс.Диск
    Яндекс.Логин
    Яндекс.Маркет
    Яндекс.Метрика
    Яндекс.Подписки
    Яндекс.Фотки

You should only install this module if another module is instructing you to do so
or if you are an interested developer.

Initially this functionality was carefully extracted from Yandex.Metrics [3] project by Andrew Berezovsky (duozersk) [4].


DEPENDENCIES
------------------------------------------------------------------------------
There are no dependencies! Just enable it and use.


CONFIGURATION
------------------------------------------------------------------------------
1. To authorize your site you should register Yandex application at https://oauth.yandex.ru/client/new.
   Register your Yandex application. Use Yandex step-by-step guide [10] to perform this step.

   Enter Callback URI for your Yandex application.
   Callback URI: http://YOUR_SITE_HOST_NAME/yandex_services_auth/oauth

   Save your application Client ID and Client Secret for later usage.

2. Then go to (Administration >> Configuration >> System >> Yandex Services Authorization) [8]
   and paste application Client ID and Client Secret into the corresponding fields.
   Then press Authorise button to submit form.

   You will be redirected to the special Yandex page.
   You should confirm your application authorization on that page.
   Enter your Yandex login and password if it will be necessary.

   Then your will be redirected back to the settings page on your site and get success message.

   The list of your Yandex applications is located here [9].


API
------------------------------------------------------------------------------
Please read API documentation (API.txt) to learn how to use this module in your own projects.


CREDITS
------------------------------------------------------------------------------
Maintainers: Andrew Berezovsky[4], Konstantin Komelin [5], Kate Marshalkina [6]
Contributor list: [7]


LINKS
------------------------------------------------------------------------------
[1] http://www.yandex.ru/
[2] http://api.yandex.ru/oauth/
[3] http://drupal.org/project/yandex_services_auth
[4] https://drupal.org/user/378397
[5] http://drupal.org/user/1195752
[6] http://drupal.org/user/1399638
[7] https://drupal.org/node/2005928/committers
[8] admin/config/system/yandex_services_auth
[9] https://oauth.yandex.ru/client/my
[10] http://api.yandex.ru/oauth/doc/dg/tasks/register-client.xml
