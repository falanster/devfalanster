<?php
/**
 * @file
 * blocks_money_ipay.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function blocks_money_ipay_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'money_ipay';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'money_ipay';
  $fe_block_boxes->body = '<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="height: 40px; width: 30px;" />&nbsp;<a href="/ru/node/662">people</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="width: 30px; height: 30px;" /><a href="/en/donations">money</a></h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="height: 25px; width: 24px;" />&nbsp;<a href="/en/node/653">feedback</a></h2>
';

  $export['money_ipay'] = $fe_block_boxes;

  return $export;
}
