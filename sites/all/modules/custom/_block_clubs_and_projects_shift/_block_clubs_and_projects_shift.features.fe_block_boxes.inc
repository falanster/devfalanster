<?php
/**
 * @file
 * _block_clubs_and_projects_shift.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function _block_clubs_and_projects_shift_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Clubs and projects shift';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'clubs_and_projects_shift';
  $fe_block_boxes->body = '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Clubs</a><a class="light-grey-text" href="#block-block-20">Projects</a></h1>
</div>
';

  $export['clubs_and_projects_shift'] = $fe_block_boxes;

  return $export;
}
