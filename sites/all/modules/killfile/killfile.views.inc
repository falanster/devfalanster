<?php

/**
 * Implementation of hook_views_handlers().
 */
function killfile_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'killfile') . '/includes',
    ),
    'handlers' => array(),
  );
}

/**
 * Implements hook_views_data()
 */
function killfile_views_data() {
  $data['killfile_nodes']['table']['group'] = t("Killfile");

  $data['killfile_nodes']['table']['join'] = array(
    'node'  => array('left_field' => 'nid', 'field' => 'nid', 'type' => 'LEFT'),
    'node_revision'  => array('left_field' => 'vid', 'field' => 'vid', 'type' => 'LEFT'),
    'users' => array('left_field' => 'uid', 'field' => 'uid', 'type' => 'INNER'),
  );

  $data['killfile_nodes']['table']['entity type'] = 'node';

  $data['killfile_nodes']['nid'] = array(
    'title'    => t("Node"),
    'help'     => t("The killfiled node."),
    'relationship' => array(
      'base'       => 'node',
      'base field' => 'nid',
      'field'      => 'nid',
      'handler'    => 'views_handler_relationship',
      'label'      => t("Killfiled Node"),
    ),
  );

  $data['killfile_nodes']['vid'] = array(
    'title'    => t("Node Revision"),
    'help'     => t("The killfiled node revision."),
    'relationship' => array(
      'base'       => 'node_revision',
      'base field' => 'vid',
      'field'      => 'vid',
      'handler'    => 'views_handler_relationship',
      'label'      => t("Killfiled Revision"),
    ),
  );

  $data['killfile_nodes']['uid'] = array(
    'title'    => t("User ID"),
    'help'     => t("The id of the user who killfile the node."),
    'field'    => array('handler' => 'views_handler_field_user', 'click sortable' => TRUE),
    'argument' => array('handler' => 'views_handler_argument_user_uid'),
    'filter'   => array('handler' => 'views_handler_filter_user_name', 'title' => t("User ID")),
    'sort'     => array('handler' => 'views_handler_sort'),
    'relationship' => array(
      'base'       => 'users',
      'base field' => 'uid',
      'field'      => 'uid',
      'handler'    => 'views_handler_relationship',
      'label'      => t("User ID"),
    ),
  );

  $data['killfile_nodes']['timestamp'] = array(
    'title'  => t("Date"),
    'help'   => t("The date when the node was killfiled."),
    'field'  => array('handler' => 'views_handler_field_date'),
    'sort'   => array('handler' => 'views_handler_sort_date'),
    'filter' => array('handler' => 'views_handler_filter_date'),
  );

  $data['killfile_nodes']['unkillfile_node'] = array(
    'field' => array(
      'title' => t("Undelete Link"),
      'help' => t("Provide a simple link to un-killfile the node."),
      'handler' => 'killfile_handler_link_unkillfile',
      'path' => drupal_get_path('module', 'killfile') . '/includes',
    ),
  );

  return $data;
}
