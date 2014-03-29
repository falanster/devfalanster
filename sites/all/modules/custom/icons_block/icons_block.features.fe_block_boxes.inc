<?php
/**
 * @file
 * icons_block.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function icons_block_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'social network links inner';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'social_network_links_inner';
  $fe_block_boxes->body = '<p><a href="http://www.facebook.com/falanster.by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_fb.png" style="width: 32px; height: 32px;" title="our facebook page" /></a> <a href="https://by.piratenpad.de/falanster" target="_blank"> <img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://vk.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_vk.png" style="width: 32px; height: 32px;" title="our vk page" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
';

  $export['social_network_links_inner'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'social network\'s links main';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'social_networks_links_main';
  $fe_block_boxes->body = '<p><a href="https://by.piratenpad.de/falanster" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_pad2.png" style="width: 32px; height: 32px;" title="our pad" /></a> <a href="http://tinyurl.com/Falanster-forever"><img alt="" src="/sites/default/files/image_theme/ss_skype_0.png" style="width: 32px; height: 32px;" title="our skype group" /></a><a href="http://vk.com/falanster_by" target="_blank"> </a><a href="https://twitter.com/falanster_by" target="_blank"><img alt="" src="/sites/default/files/image_theme/ss_twitter.png" style="width: 32px; height: 32px;" title="our twitter" /></a>&nbsp;<a href="https://trello.com/b/v64HfRMr/falanster"><img alt="" src="/sites/default/files/image_theme/ss_trello.png" style="width: 32px; height: 32px;" title="our working board in trello" /></a> <a href="http://wiki.falanster.info/"><img alt="" src="/sites/default/files/image_theme/ss_wiki.png" style="width: 32px; height: 32px;" title="our wiki" /></a> <a href="http://www.youtube.com/channel/UCbkDkLe_ZSWIMs_RlJDZD4g"><img alt="" src="/sites/default/files/image_theme/ss_utube.png" style="width: 32px; height: 32px;" title="our youtube channel" /></a></p>
';

  $export['social_networks_links_main'] = $fe_block_boxes;

  return $export;
}
