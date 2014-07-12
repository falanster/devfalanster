<?php
/**
 * @file
 * block_projects_mission_teaser.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_projects_mission_teaser_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Projects-mission-teaser-block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'projects_mission_teaser_block';
  $fe_block_boxes->body = '<p><strong>Проекты</strong> - это точки входа, развития, влияния на социальную, культурную, экономическую и политическую жизнь общества.</p>
<p><strong>Проекты</strong> - это способ донесения и распространения идей, принципов и взглядов.</p>
<p><strong>Проекты</strong> - это долгосрочное взаимодействие с различными сообществами и группами, где мы изучаем общество.</p>
<p>Формы проектов могут быть различными. Сейчас это <a href="turnir_neformalov">футбольный турнир</a>, <a href="drupal_sliot">IT-конференции</a>, кинолектории, выставки и др.</p>
<p>Для активиста - это шанс коснуться <a href="o_nas">Фаланстера</a> в различных ролях: волонтера, активиста, координатора - и стать его частью!</p>
';

  $export['projects_mission_teaser_block'] = $fe_block_boxes;

  return $export;
}
