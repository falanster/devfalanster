<?php
/**
 * @file
 * social_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function social_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'facebook';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'facebook';
  $fe_block_boxes->body = '<p><iframe allowtransparency="true" frameborder="0" scrolling="no" src="//www.facebook.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Ffalanster.by&amp;width=300&amp;height=270&amp;colorscheme=light&amp;show_faces=true&amp;border_color=%23c2c1c1&amp;stream=false&amp;header=true" style="border:none; overflow:hidden; width:300px; height:270px;"></iframe></p>
';

  $export['facebook'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'vkontakte';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'vkontakte';
  $fe_block_boxes->body = '<script type="text/javascript" src="http://userapi.com/js/api/openapi.js?49"></script><!-- VK Widget -->
<div id="vk_groups">
	&nbsp;</div>
<script type="text/javascript">
VK.Widgets.Group("vk_groups", {mode: 0, width: "300", height: "270"}, 39551574);
</script>';

  $export['vkontakte'] = $fe_block_boxes;

  return $export;
}
