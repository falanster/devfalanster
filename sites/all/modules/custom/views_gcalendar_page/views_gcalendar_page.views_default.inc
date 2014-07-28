<?php
/**
 * @file
 * views_gcalendar_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_gcalendar_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gcalendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'gCalendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'болей';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скінуць';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  /* Поле: Каляндар: Google Calendar */
  $handler->display->display_options['fields']['gcal']['id'] = 'gcal';
  $handler->display->display_options['fields']['gcal']['table'] = 'fullcalendar';
  $handler->display->display_options['fields']['gcal']['field'] = 'gcal';
  $handler->display->display_options['fields']['gcal']['label'] = '';
  $handler->display->display_options['fields']['gcal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['gcal']['gcal'] = 'https://www.google.com/calendar/feeds/ea7djpk9rt5e1m52m3b4m799a0%40group.calendar.google.com/public/basic';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['weekMode'] = 'liquid';
  $handler->display->display_options['style_options']['left'] = 'prev,next';
  $handler->display->display_options['style_options']['right'] = 'prevYear, nextYear';
  $handler->display->display_options['style_options']['timeformat'] = 'H:mm{ - H:mm}';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Каляндар';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Каляндар: Google Calendar */
  $handler->display->display_options['fields']['gcal']['id'] = 'gcal';
  $handler->display->display_options['fields']['gcal']['table'] = 'fullcalendar';
  $handler->display->display_options['fields']['gcal']['field'] = 'gcal';
  $handler->display->display_options['fields']['gcal']['label'] = '';
  $handler->display->display_options['fields']['gcal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['gcal']['gcal'] = 'https://www.google.com/calendar/feeds/ea7djpk9rt5e1m52m3b4m799a0%40group.calendar.google.com/public/basic';
  $handler->display->display_options['fields']['gcal']['class'] = 'fc-event-red fc-event-gcal';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Змест: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['value']['min'] = '2000';
  $handler->display->display_options['filters']['created']['value']['max'] = '2020';
  $handler->display->display_options['path'] = 'agenda';
  $export['gcalendar'] = $view;

  return $export;
}
