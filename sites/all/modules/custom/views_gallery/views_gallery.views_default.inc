<?php
/**
 * @file
 * views_gallery.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function views_gallery_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'gallery';
  $view->description = 'This where all the magic of display is done in Views Gallery. (Teaser, Full Node, Block, etc.)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'gallery';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'full gallery';
  $handler->display->display_options['use_more_text'] = 'View Gallery';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No photos have been added to this gallery.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Gallery (field_gallery) */
  $handler->display->display_options['relationships']['field_gallery_nid']['id'] = 'field_gallery_nid';
  $handler->display->display_options['relationships']['field_gallery_nid']['table'] = 'field_data_field_gallery';
  $handler->display->display_options['relationships']['field_gallery_nid']['field'] = 'field_gallery_nid';
  $handler->display->display_options['relationships']['field_gallery_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_gallery_nid']['delta'] = '-1';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_gallery_image']['id'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['field'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_image']['settings'] = array(
    'image_style' => 'thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Gallery (field_gallery) */
  $handler->display->display_options['arguments']['field_gallery_nid']['id'] = 'field_gallery_nid';
  $handler->display->display_options['arguments']['field_gallery_nid']['table'] = 'field_data_field_gallery';
  $handler->display->display_options['arguments']['field_gallery_nid']['field'] = 'field_gallery_nid';
  $handler->display->display_options['arguments']['field_gallery_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_gallery_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_gallery_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_gallery_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_gallery_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_gallery_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_gallery_nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_gallery_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_gallery_nid']['validate_options']['types'] = array(
    'gallery' => 'gallery',
  );
  $handler->display->display_options['arguments']['field_gallery_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['field_gallery_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_gallery_nid']['not'] = 0;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Full gallery */
  $handler = $view->new_display('entity_view', 'Full gallery', 'entity_view_1');
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'gallery',
  );

  /* Display: Teaser Gallery */
  $handler = $view->new_display('entity_view', 'Teaser Gallery', 'entity_view_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'teaser gallery';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_gallery_nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_gallery_image']['id'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['field'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_gallery_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_image']['settings'] = array(
    'image_style' => 'thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_image']['field_api_classes'] = 0;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'gallery',
  );

  /* Display: Gallery Block */
  $handler = $view->new_display('block', 'Gallery Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
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
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_gallery_image']['id'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['field'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_image']['settings'] = array(
    'image_style' => 'thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_image']['field_api_classes'] = 0;
  $export['gallery'] = $view;

  $view = new view;
  $view->name = 'gallery_list';
  $view->description = 'A teaser list of all galleries.';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Galleries';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'gallery-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Galleries';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['gallery_list'] = $view;

  return $export;
}
