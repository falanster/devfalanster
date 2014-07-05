<?php
/**
 * @file
 * task_project_and_clubs.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function task_project_and_clubs_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Clubs and projects menu';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'clubs_and_projects_menu';
  $fe_block_boxes->body = '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-19">Clubs</a><a class="light-grey-text" href="#block-block-20">Projects</a></h1>
</div>
';

  $export['clubs_and_projects_menu'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Projects and clubs menu';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'projects_and_clubs_menu';
  $fe_block_boxes->body = '<div class="projects-and-clubs-menu">
	<h1>
		<a class="grey-text" href="#block-block-20">Projects</a><a class="light-grey-text" href="#block-block-19">Clubs</a></h1>
</div>
';

  $export['projects_and_clubs_menu'] = $fe_block_boxes;

  return $export;
}
