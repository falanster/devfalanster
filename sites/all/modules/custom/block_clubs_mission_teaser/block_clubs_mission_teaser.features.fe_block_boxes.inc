<?php
/**
 * @file
 * block_clubs_mission_teaser.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_clubs_mission_teaser_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Clubs-mission-teaser-block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'clubs_mission_teaser_block';
  $fe_block_boxes->body = '<p><strong>Все перемены начинаются с общения.</strong></p>
<p>Клубы &ndash; это наши лаборатории получения знаний, опыта и первичной закалки. Здесь мы экспериментируем, тестируем новые методы и идеи, обмениваемся знаниями и общаемся.</p>
<p><strong>В клубах мы хотим:</strong><br />
	1. Создавать полезные Фаланстеру и обществу проекты, открывающие знания и возможности, ориентированные на различные группы.<br />
	2. Увеличить круг симпатизирующих нам.<br />
	3. Усилить Фаланстер интересными людьми, актуальной информацией и другими ресурсами.</p>
';

  $export['clubs_mission_teaser_block'] = $fe_block_boxes;

  return $export;
}
