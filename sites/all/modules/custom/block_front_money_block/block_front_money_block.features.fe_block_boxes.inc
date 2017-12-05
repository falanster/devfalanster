<?php
/**
 * @file
 * block_front_money_block.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_front_money_block_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'front_money_block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'front_money_block';
  $fe_block_boxes->body = '<h3 class="grey-title">
	Falanster needs:</h3>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/people.png" style="font-size: 12px; height: 40px; width: 30px;" />&nbsp;<a href="">people</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/money.png" style="font-size: 12px; width: 30px; height: 30px;" /><a href="/en/donations">money</a>&nbsp;&nbsp;</h2>
<h2>
	<img alt="" src="/sites/default/files/image/blocks/feedback.png" style="font-size: 12px; height: 25px; width: 24px;" />&nbsp;<a href="">feedback</a>&nbsp;&nbsp;</h2>
';

  $export['front_money_block'] = $fe_block_boxes;

  return $export;
}
