<?php
/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_data().
 */
function yandex_metrics_reports_views_data() {
  $data['yandex_metrics_reports_popular_content']['table']['group'] = t('Yandex.Metrics');

  $data['yandex_metrics_reports_popular_content']['table']['base'] = array(
    'field'       => 'yid',
    'title'       => t('Popular content from Yandex.Metrica') ,
    'help'        => t('Popular content is obtained from Yandex.Metrica'),
    'weight'      => -10
  );

  $data['yandex_metrics_reports_popular_content']['url'] = array(
    'title'       => t('Popular URL'),
    'help'        => t('Popular URL. It is obtained from Yandex.Metrica.'),
    'field'       => array(
      'handler'         => 'views_handler_field',
      // This is use by the table display plugin.
      'click sortable'  => TRUE,
    ),
    'sort'        => array(
      'handler' => 'views_handler_sort',
    ),
    'filter'      => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument'    => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['yandex_metrics_reports_popular_content']['language'] = array(
    'title'       => t('Language'),
    'help'        => t('Language of the page.'),
    'field'       => array(
      'handler'         => 'views_handler_field',
      'click sortable'  => TRUE,
    ),
    'sort'        => array(
      'handler' => 'views_handler_sort',
    ),
    'filter'      => array(
      'handler' => 'views_handler_filter_node_language',
    ),
    'argument'    => array(
      'handler' => 'views_handler_argument_node_language',
    ),
  );

  $data['yandex_metrics_reports_popular_content']['page_title'] = array(
    'title'       => t('Page title'),
    'help'        => t('Page title of the popular URL.'),
    'field'       => array(
      'handler'         => 'views_handler_field_ym_title',
      // This is use by the table display plugin.
      'click sortable'  => TRUE,
    ),
    'sort'        => array(
      'handler' => 'views_handler_sort',
    ),
    'filter'      => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument'    => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['yandex_metrics_reports_popular_content']['page_views'] = array(
    'title'       => t('Number of views'),
    'help'        => t('Number of page views for the popular URL. It is obtained from Yandex.Metrica.'),
    'field'       => array(
      'handler'        => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort'        => array(
      'handler' => 'views_handler_sort',
    ),
    'filter'      => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'argument'    => array(
      'handler' => 'views_handler_argument_numeric'
    ),
  );
  return $data;
}

/**
 * Implements hook_views_default_views().
 */
function yandex_metrics_reports_views_default_views() {
  $view = new view();
  $view->name = 'popular_content';
  $view->description = 'Popular content from Yandex.Metrica';
  $view->tag = 'Yandex.Metrics';
  $view->base_table = 'yandex_metrics_reports_popular_content';
  $view->human_name = 'Popular content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Popular content (Yandex.Metrics)';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Yandex.Metrics: Title for url */
  $handler->display->display_options['fields']['page_title']['id'] = 'page_title';
  $handler->display->display_options['fields']['page_title']['table'] = 'yandex_metrics_reports_popular_content';
  $handler->display->display_options['fields']['page_title']['field'] = 'page_title';
  $handler->display->display_options['fields']['page_title']['label'] = '';
  $handler->display->display_options['fields']['page_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_title']['link_to_ym_url'] = TRUE;
  /* Field: Yandex.Metrics: Count of views */
  $handler->display->display_options['fields']['page_views']['id'] = 'page_views';
  $handler->display->display_options['fields']['page_views']['table'] = 'yandex_metrics_reports_popular_content';
  $handler->display->display_options['fields']['page_views']['field'] = 'page_views';
  $handler->display->display_options['fields']['page_views']['label'] = '';
  $handler->display->display_options['fields']['page_views']['exclude'] = TRUE;
  $handler->display->display_options['fields']['page_views']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['page_views']['separator'] = '';

  /* Filter criterion: Yandex.Metrics: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'yandex_metrics_reports_popular_content';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Popular content (Yandex.Metrics)';

  $translatables['popular_content'] = array(
    t('Popular content (Yandex.Metrics)'),
  );

  $views[$view->name] = $view;

  return $views;
}
