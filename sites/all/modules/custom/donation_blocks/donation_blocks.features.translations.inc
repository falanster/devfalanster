<?php
/**
 * @file
 * donation_blocks.features.translations.inc
 */

/**
 * Implements hook_translations_defaults().
 */
function donation_blocks_translations_defaults() {
  $translations = array();
  $translations['be:blocks']['0b2c164631972bf63aca5bdba20dad95'] = array(
    'source' => 'All Our Events',
    'context' => 'views:gcalendar-block:title',
    'location' => 'blocks:views:gcalendar-block:title',
    'translation' => 'Усе падзеі Фаланстэра',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['13ff2ba03d42a84e940f112927cd448d'] = array(
    'source' => '<?php
global $user;
if ($user->uid) {
print t(\'Welcome\').", ";
print l($user->name, \'user/\'.$user->uid);
print " | ";
print l(t(\'Logout\'), \'user/logout\');
} else {
?>
<form >
	<input type="button" value="<?php echo t(\'Sing in for Falangist\')?>" onClick="window.location=\'<?php global $base_url; echo $base_url . \'/en/user\' ?> \'"/>&nbsp;</form>
<?php
}
?>',
    'context' => 'block:7:body',
    'location' => 'blocks:block:7:body',
    'translation' => '<?php
global $user;
if ($user->uid) {
print t(\'Welcome\').", ";
print l($user->name, \'user/\'.$user->uid);
print " | ";
print l(t(\'Logout\'), \'user/logout\');
} else {
?>
<form >
	<input type="button" value="<?php echo t(\'Sing in for Falangist\')?>" onClick="window.location=\'<?php global $base_url; echo $base_url . \'/be/user\' ?> \'"/>&nbsp;</form>
<?php
}
?>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['16e5305d8c83ff640670b130a6399fb3'] = array(
    'source' => 'Subscribe to our news!',
    'context' => 'simplenews:1:title',
    'location' => 'blocks:simplenews:1:title',
    'translation' => 'Падпішыся на навіны Фаланстэра!',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['2b360698600b3311839d61bb86234efe'] = array(
    'source' => '<p><a href="http://www.facebook.com/falanster.by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_fb.png" style="width: 32px; height: 32px;" title="our facebook page" /></a>&nbsp;<a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="make decisions together" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"> <img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://vk.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_vk.png" style="width: 32px; height: 32px;" title="our vk page" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
',
    'context' => 'block:16:body',
    'location' => 'blocks:block:16:body',
    'translation' => '<p><a href="http://www.facebook.com/falanster.by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_fb.png" style="width: 32px; height: 32px;" title="наша старонка ў фейсбуку" /></a>&nbsp;<a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="прымаем рашэнні разам" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"> <img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="наш блакнот" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="наша группа ў скайпе" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="наш твіттэр" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="наша працоўная сцяна ў трэлло" /></a> <a href="http://vk.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_vk.png" style="width: 32px; height: 32px;" title="наша старонка ў вкантакце" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;"  title="наша вікі" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="наш youtube канал" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['30bbf510cafc83aab017fc0123fc2fdd'] = array(
    'source' => 'in internet',
    'context' => 'block:16:title',
    'location' => 'blocks:block:16:title',
    'translation' => 'у інтэрнэце',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['34e2d1989a1dbf75cd631596133ee5ee'] = array(
    'source' => 'Video',
    'context' => 'views:last_video_or_podcast-block:title',
    'location' => 'blocks:views:last_video_or_podcast-block:title',
    'translation' => 'Вiдэа',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['4dadbedfc69ee2670c8acece95218770'] = array(
    'source' => '<p><div id="footer_logo_en"><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_footer_en.png" /></a></div></p>
',
    'context' => 'block:10:body',
    'location' => 'blocks:block:10:body',
    'translation' => '<p><div id="footer_logo_by"><a href="/be"><img alt="" src="/sites/default/files/image_theme/falanster_footer_by.png" /></div></p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['55ee4d9a735b19bc1461303b6593b0a3'] = array(
    'source' => '<h3 class="grey-title">
	Falanster needs:</h3>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">people</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/en/donations">money</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">feedback</a>&nbsp;&nbsp;</h2>
',
    'context' => 'block:15:body',
    'location' => 'blocks:block:15:body',
    'translation' => '<h3 class="grey-title">Фаланстэру патрабуюцца:</h3>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">людзі</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/be/ahviaravanni">грошы</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">водгукі</a>&nbsp;&nbsp;</h2>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['6ce50a6b2c5c635067d482827a29621f'] = array(
    'source' => '<p><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_footer_en.png" style="width: 300px; height: 74px;" /></a></p>
',
    'context' => 'block:12:body',
    'location' => 'blocks:block:12:body',
    'translation' => '<p><a href="/be"><img alt="" src="/sites/default/files/image_theme/falanster_footer_by.png" style="width: 300px; height: 70px;" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['728e106acf44bf7f8e0688e4ee564878'] = array(
    'source' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Clubs</a><a class="light-grey-text" href="#block-block-20">Projects</a></h1>
</div>
',
    'context' => 'block:21:body',
    'location' => 'blocks:block:21:body',
    'translation' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Клубы</a><a class="light-grey-text" href="#block-block-20">Праекты</a></h1>
</div>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['796cb4ffd4ea546f252685ac02e94b5f'] = array(
    'source' => '<p><a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="make decisions together" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
',
    'context' => 'block:5:body',
    'location' => 'blocks:block:5:body',
    'translation' => '<p><a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="прымаем рашэнні разам" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="наш блакнот" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="наша группа ў скайпе" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="наш твіттэр" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="наша працоўная сцяна ў трэлло" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="наша вікі" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="наш youtube канал" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['7d10d3c02a53fb552d88cfc3a5b2ae91'] = array(
    'source' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-20">Projects</a><a class="light-grey-text" href="#block-block-19">Clubs</a></h1>
</div>
',
    'context' => 'block:22:body',
    'location' => 'blocks:block:22:body',
    'translation' => '<div class="projects-and-clubs-menu"><h1><a class="grey-text" href="#block-block-20">Праекты</a><a class="light-grey-text" href="#block-block-19">Клубы</a></h1></div>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['87dde47c3c24ba7cc629ea2dacab3806'] = array(
    'source' => 'Poll',
    'context' => 'poll:recent:title',
    'location' => 'blocks:poll:recent:title',
    'translation' => 'Апытанне',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['8ff922bbcd8ad41cdfc48d3c5163b2ab'] = array(
    'source' => 'Calendar',
    'context' => 'agenda:1:title',
    'location' => 'blocks:agenda:1:title',
    'translation' => 'Каляндар',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['91baca0305f54692496275d482d0ee76'] = array(
    'source' => '<p><a href="/en/agenda">month</a></p>
',
    'context' => 'block:18:body',
    'location' => 'blocks:block:18:body',
    'translation' => '<p><a href="/be/agenda">месяц</a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['933becea64c87396d2627e1d120cbea5'] = array(
    'source' => 'Support Falanster',
    'context' => 'block:1:title',
    'location' => 'blocks:block:1:title',
    'translation' => 'Падтрымай Фаланстэр',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['9a881206ea5b2019d9eaf8f7494f736e'] = array(
    'source' => 'Our twitter channel',
    'context' => 'views:twitter_list-block:title',
    'location' => 'blocks:views:twitter_list-block:title',
    'translation' => 'Наша твітэр-стужка',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['ad223d6dc0da6794f7a912aabb95a0c0'] = array(
    'source' => '<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="height: 40px; width: 30px;" />&nbsp;<a href="">people</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="width: 30px; height: 30px;" /><a href="/en/donations">money</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="height: 25px; width: 24px;" />&nbsp;<a href="">feedback</a></h2>
',
    'context' => 'block:1:body',
    'location' => 'blocks:block:1:body',
    'translation' => '<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">людзі</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/be/ahviaravanni">грошы</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">вогукі</a>&nbsp;&nbsp;</h2>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['dbb68903bd141cbbdb293ad7cf6d64fa'] = array(
    'source' => 'Our Network',
    'context' => 'quicktabs:social_networks:title',
    'location' => 'blocks:quicktabs:social_networks:title',
    'translation' => 'Наша сетка',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['dd1ba1872df91985ed1ca4cde2dfe669'] = array(
    'source' => 'News',
    'context' => 'views:headernews-block:title',
    'location' => 'blocks:views:headernews-block:title',
    'translation' => 'Навіны',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['ed8c6c507391b16ec97fc88afef65cc2'] = array(
    'source' => '<p><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_logo_shapka_en.png" style="width: 256px; height: 46px;" /></a></p>
',
    'context' => 'block:11:body',
    'location' => 'blocks:block:11:body',
    'translation' => '<p><a href="/be"><img alt="" src="/sites/default/files/image_theme/falanster_logo_shapka_by.png" style="width: 256px; height: 46px;" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['be:blocks']['feb4d2dfe1b2a637fdfd9e397cc4735f'] = array(
    'source' => 'Announcement',
    'context' => 'views:afishi-block_1:title',
    'location' => 'blocks:views:afishi-block_1:title',
    'translation' => 'Афiша',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['0b2c164631972bf63aca5bdba20dad95'] = array(
    'source' => 'All Our Events',
    'context' => 'views:gcalendar-block:title',
    'location' => 'blocks:views:gcalendar-block:title',
    'translation' => 'Все События Фаланстера',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['13ff2ba03d42a84e940f112927cd448d'] = array(
    'source' => '<?php
global $user;
if ($user->uid) {
print t(\'Welcome\').", ";
print l($user->name, \'user/\'.$user->uid);
print " | ";
print l(t(\'Logout\'), \'user/logout\');
} else {
?>
<form >
	<input type="button" value="<?php echo t(\'Sing in for Falangist\')?>" onClick="window.location=\'<?php global $base_url; echo $base_url . \'/en/user\' ?> \'"/>&nbsp;</form>
<?php
}
?>',
    'context' => 'block:7:body',
    'location' => 'blocks:block:7:body',
    'translation' => '<?php
global $user;
if ($user->uid) {
print t(\'Welcome\').", ";
print l($user->name, \'user/\'.$user->uid);
print " | ";
print l(t(\'Logout\'), \'user/logout\');
} else {
?>
<form >
	<input type="button" value="<?php echo t(\'Sing in for Falangist\')?>" onClick="window.location=\'<?php global $base_url; echo $base_url . \'/ru/user\' ?> \'"/>&nbsp;</form>
<?php
}
?>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['16e5305d8c83ff640670b130a6399fb3'] = array(
    'source' => 'Subscribe to our news!',
    'context' => 'simplenews:1:title',
    'location' => 'blocks:simplenews:1:title',
    'translation' => 'Подпишись на новости Фаланстера!',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['2b360698600b3311839d61bb86234efe'] = array(
    'source' => '<p><a href="http://www.facebook.com/falanster.by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_fb.png" style="width: 32px; height: 32px;" title="our facebook page" /></a>&nbsp;<a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="make decisions together" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"> <img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://vk.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_vk.png" style="width: 32px; height: 32px;" title="our vk page" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
',
    'context' => 'block:16:body',
    'location' => 'blocks:block:16:body',
    'translation' => '<p><a href="http://www.facebook.com/falanster.by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_fb.png" style="width: 32px; height: 32px;" title="наша страница в фейсбуке" /></a>&nbsp;<a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="принимаем решения вместе" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"> <img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="наш блокнот" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="наша скайп группа" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="наш твиттер" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="наша рабочая трелло-стена" /></a> <a href="http://vk.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_vk.png" style="width: 32px; height: 32px;" title="наша страница в вконтакте" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="наша вики" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="наш youtube канал" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['30bbf510cafc83aab017fc0123fc2fdd'] = array(
    'source' => 'in internet',
    'context' => 'block:16:title',
    'location' => 'blocks:block:16:title',
    'translation' => 'в интернете',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['34e2d1989a1dbf75cd631596133ee5ee'] = array(
    'source' => 'Video',
    'context' => 'views:last_video_or_podcast-block:title',
    'location' => 'blocks:views:last_video_or_podcast-block:title',
    'translation' => 'Видео',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['4dadbedfc69ee2670c8acece95218770'] = array(
    'source' => '<p><div id="footer_logo_en"><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_footer_en.png" /></a></div></p>
',
    'context' => 'block:10:body',
    'location' => 'blocks:block:10:body',
    'translation' => '<p><div id="footer_logo_ru"><a href="/ru"><img alt="" src="/sites/default/files/image_theme/falanster_footer.png" /></div></p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['55ee4d9a735b19bc1461303b6593b0a3'] = array(
    'source' => '<h3 class="grey-title">
	Falanster needs:</h3>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">people</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/en/donations">money</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">feedback</a>&nbsp;&nbsp;</h2>
',
    'context' => 'block:15:body',
    'location' => 'blocks:block:15:body',
    'translation' => '<h3 class="grey-title">Фаланстеру нужны</h3>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">люди</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/ru/pozhertvovania">деньги</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">отзывы</a>&nbsp;&nbsp;</h2>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['6ce50a6b2c5c635067d482827a29621f'] = array(
    'source' => '<p><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_footer_en.png" style="width: 300px; height: 74px;" /></a></p>
',
    'context' => 'block:12:body',
    'location' => 'blocks:block:12:body',
    'translation' => '<p><a href="/ru"><img alt="" src="/sites/default/files/image_theme/falanster_footer.png" style="width: 320px; height: 94px;" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['728e106acf44bf7f8e0688e4ee564878'] = array(
    'source' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Clubs</a><a class="light-grey-text" href="#block-block-20">Projects</a></h1>
</div>
',
    'context' => 'block:21:body',
    'location' => 'blocks:block:21:body',
    'translation' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Клубы</a><a class="light-grey-text" href="#block-block-20">Проекты</a></h1>
</div>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['796cb4ffd4ea546f252685ac02e94b5f'] = array(
    'source' => '<p><a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="make decisions together" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
',
    'context' => 'block:5:body',
    'location' => 'blocks:block:5:body',
    'translation' => '<p><a href="https://www.loomio.org/g/rTfFwpSz/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_loomio.png" style="width: 32px; height: 32px;" title="принимаем решения вместе" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="наш блокнот" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="наша скайп группа" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="наш твиттер" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="наша рабочая трелло-стена" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="наша вики" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="наш youtube канал" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['7d10d3c02a53fb552d88cfc3a5b2ae91'] = array(
    'source' => '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-20">Projects</a><a class="light-grey-text" href="#block-block-19">Clubs</a></h1>
</div>
',
    'context' => 'block:22:body',
    'location' => 'blocks:block:22:body',
    'translation' => '<div class="projects-and-clubs-menu"><h1><a class="grey-text" href="#block-block-20">Проекты</a><a class="light-grey-text" href="#block-block-19">Клубы</a></h1></div>',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['87dde47c3c24ba7cc629ea2dacab3806'] = array(
    'source' => 'Poll',
    'context' => 'poll:recent:title',
    'location' => 'blocks:poll:recent:title',
    'translation' => 'Голосование',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['8ff922bbcd8ad41cdfc48d3c5163b2ab'] = array(
    'source' => 'Calendar',
    'context' => 'agenda:1:title',
    'location' => 'blocks:agenda:1:title',
    'translation' => 'Календарь',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['91baca0305f54692496275d482d0ee76'] = array(
    'source' => '<p><a href="/en/agenda">month</a></p>
',
    'context' => 'block:18:body',
    'location' => 'blocks:block:18:body',
    'translation' => '<p><a href="/ru/agenda">месяц</a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['933becea64c87396d2627e1d120cbea5'] = array(
    'source' => 'Support Falanster',
    'context' => 'block:1:title',
    'location' => 'blocks:block:1:title',
    'translation' => 'Поддержи Фаланстер',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['9a881206ea5b2019d9eaf8f7494f736e'] = array(
    'source' => 'Our twitter channel',
    'context' => 'views:twitter_list-block:title',
    'location' => 'blocks:views:twitter_list-block:title',
    'translation' => 'Наша твиттер-лента',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['ad223d6dc0da6794f7a912aabb95a0c0'] = array(
    'source' => '<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="height: 40px; width: 30px;" />&nbsp;<a href="">people</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="width: 30px; height: 30px;" /><a href="/en/donations">money</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="height: 25px; width: 24px;" />&nbsp;<a href="">feedback</a></h2>
',
    'context' => 'block:1:body',
    'location' => 'blocks:block:1:body',
    'translation' => '<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">люди</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/ru/pozhertvovania">деньги</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">отзывы</a>&nbsp;&nbsp;</h2>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['dbb68903bd141cbbdb293ad7cf6d64fa'] = array(
    'source' => 'Our Network',
    'context' => 'quicktabs:social_networks:title',
    'location' => 'blocks:quicktabs:social_networks:title',
    'translation' => 'Наша сеть',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['dd1ba1872df91985ed1ca4cde2dfe669'] = array(
    'source' => 'News',
    'context' => 'views:headernews-block:title',
    'location' => 'blocks:views:headernews-block:title',
    'translation' => 'Новости',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['ed8c6c507391b16ec97fc88afef65cc2'] = array(
    'source' => '<p><a href="/en"><img alt="" src="/sites/default/files/image_theme/falanster_logo_shapka_en.png" style="width: 256px; height: 46px;" /></a></p>
',
    'context' => 'block:11:body',
    'location' => 'blocks:block:11:body',
    'translation' => '<p><a href="/ru"><img alt="" src="/sites/default/files/image_theme/falanster_logo_shapka.png" style="width: 237px;" /></a></p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translations['ru:blocks']['feb4d2dfe1b2a637fdfd9e397cc4735f'] = array(
    'source' => 'Announcement',
    'context' => 'views:afishi-block_1:title',
    'location' => 'blocks:views:afishi-block_1:title',
    'translation' => 'Афиша',
    'plid' => 0,
    'plural' => 0,
  );
  return $translations;
}
