<?php
/**
 * @file
 * block_clubs_and_project_shift.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_clubs_and_project_shift_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'projects and clubs shift';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'block_project_club_shift';
  $fe_block_boxes->body = '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-20">Projects</a><a class="light-grey-text" href="#block-block-19">Clubs</a></h1>
</div>
';

  $export['block_project_club_shift'] = $fe_block_boxes;

  return $export;
}
