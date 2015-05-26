<?php
/**
 * @file
 * views_taxonomy.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_taxonomy_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'taxonomy_view';
  $view->description = 'выводит таксономию ячейками (grid) по 3 в ряд';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Taxonomy view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'болей';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скінуць';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Вид для таксономии */
  $handler = $view->new_display('page', 'Вид для таксономии', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'grid-page taxonomy-page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'grid-cell';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'white-title grid-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p> <br> <a> <i>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_2']['id'] = 'field_image_2';
  $handler->display->display_options['fields']['field_image_2']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_2']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_2']['label'] = '';
  $handler->display->display_options['fields']['field_image_2']['element_class'] = 'grid-image';
  $handler->display->display_options['fields']['field_image_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_2']['settings'] = array(
    'image_style' => 'internal_view_square',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image_2']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_news_1']['id'] = 'field_image_news_1';
  $handler->display->display_options['fields']['field_image_news_1']['table'] = 'field_data_field_image_news';
  $handler->display->display_options['fields']['field_image_news_1']['field'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_news_1']['element_class'] = 'grid-image';
  $handler->display->display_options['fields']['field_image_news_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_news_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_news_1']['settings'] = array(
    'image_style' => 'internal_view_square',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image_news_1']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-title white-title">[title]</div>
<div class="grid-teaser white-text">[body]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'grid-pad';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth, translated) */
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['id'] = 'term_node_tid_depth_i18n';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['field'] = 'term_node_tid_depth_i18n';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['exception']['title'] = 'Усе';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth_i18n']['depth'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'tag/%';
  $export['taxonomy_view'] = $view;

  return $export;
}
