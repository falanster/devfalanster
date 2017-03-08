<?php

/**
 * @file
 * Admin page callbacks for the content_theme module.
 */


/**
 * Menu callback; configures content node themes.
 */
function content_theme_admin_content_node($form, &$form_state) {

  $destination = drupal_get_destination();
  $options = array();

  $header = array();
  $header['title'] = array('data' => t('Title'), 'field' => 'n.title');
  $header['type'] = array('data' => t('Type'), 'field' => 'n.type');
  $header['changed'] = array('data' => t('Updated'), 'field' => 'n.changed', 'sort' => 'desc');
  $header['edit_theme'] = t('Editing theme');
  $header['view_theme'] = t('Viewing theme');
  $header['op'] = t('Operations');

  $query = db_select('node', 'n')
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->fields('n', array('nid', 'title', 'type', 'changed'))
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  foreach ($query as $result) {

    $theme = db_query('SELECT theme FROM {content_theme_node} WHERE nid = :nid AND action = :action', array(':nid' => $result->nid, ':action' => 'edit'))->fetchField();
    $edit_theme = $theme !== FALSE ? $theme : '-content_type-';
    $theme = db_query('SELECT theme FROM {content_theme_node} WHERE nid = :nid AND action = :action', array(':nid' => $result->nid, ':action' => 'view'))->fetchField();
    $view_theme = $theme !== FALSE ? $theme : '-content_type-';

    $row = array();
    $row['title'] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => $result->title,
        '#href' => 'node/' . $result->nid,
      ),
    );
    $row['type'] = check_plain(node_type_get_name($result));
    $row['changed'] = format_date($result->changed, 'short');
    $row['edit_theme'] = content_theme_get_theme_name($edit_theme);
    $row['view_theme'] = content_theme_get_theme_name($view_theme);
    $row['op'] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => t('edit'),
        '#href' => 'node/' . $result->nid . '/edit',
        '#options' => array('query' => $destination),
      ),
    );

    $options[$result->nid] = $row;
  }

  $form['update'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update content node themes'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['update']['content_theme_edit'] = array(
    '#type' => 'select',
    '#title' => t('Editing theme'),
    '#description' => t('Choose which theme the content creating and editing pages should display in. Content wide theme: %content_wide_theme; system default theme: %system_default_theme.', array('%content_wide_theme' => content_theme_get_info_theme_name('content_wide', 'edit'), '%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => '-no_update-',
    '#options' => array('-no_update-' => '<' . t('No update') . '>') + content_theme_get_content_node_options(),
  );
  $form['update']['content_theme_view'] = array(
    '#type' => 'select',
    '#title' => t('Viewing theme'),
    '#description' => t('Choose which theme the content viewing pages should display in. Content wide theme: %content_wide_theme; system default theme: %system_default_theme.', array('%content_wide_theme' => content_theme_get_info_theme_name('content_wide', 'view'), '%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => '-no_update-',
    '#options' => array('-no_update-' => '<' . t('No update') . '>') + content_theme_get_content_node_options(),
  );
  $form['update']['actions'] = array(
    '#type' => 'actions',
  );
  $form['update']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update themes'),
  );
  $form['nodes'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content nodes available.'),
  );
  $form['pager'] = array(
    '#markup' => theme('pager'),
  );

  return $form;
}

function content_theme_admin_content_node_validate($form, &$form_state) {

  $nodes = array_filter($form_state['values']['nodes']);
  if (count($nodes) == 0) {
    form_set_error('', t('No content nodes selected.'));
  }
}

function content_theme_admin_content_node_submit($form, &$form_state) {

  $edit_theme = $form_state['values']['content_theme_edit'];
  $view_theme = $form_state['values']['content_theme_view'];

  foreach ($form_state['values']['nodes'] as $nid) {

    if (!empty($nid)) {

      if ($edit_theme != '-no_update-') {
        db_delete('content_theme_node')
          ->condition('nid', $nid)
          ->condition('action', 'edit')
          ->execute();
        if ($edit_theme != '-content_type-') {
          db_insert('content_theme_node')
            ->fields(array('nid' => $nid, 'action' => 'edit', 'theme' => $edit_theme))
            ->execute();
        }
      }
      if ($view_theme != '-no_update-') {
        db_delete('content_theme_node')
          ->condition('nid', $nid)
          ->condition('action', 'view')
          ->execute();
        if ($view_theme != '-content_type-') {
          db_insert('content_theme_node')
            ->fields(array('nid' => $nid, 'action' => 'view', 'theme' => $view_theme))
            ->execute();
        }
      }
    }
  }

  drupal_set_message(t('The themes have been updated.'));
  cache_clear_all();
}


/**
 * Menu callback; configures content type themes.
 */
function content_theme_admin_content_type($form, &$form_state) {

  $destination = drupal_get_destination();
  $options = array();

  $header = array();
  $header['type'] = array('data' => t('Type'), 'field' => 'nt.type', 'sort' => 'asc');
  $header['edit_theme'] = t('Creating & editing theme');
  $header['view_theme'] = t('Viewing theme');
  $header['op'] = t('Operations');

  $query = db_select('node_type', 'nt')
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->fields('nt', array('type', 'name'))
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  foreach ($query as $result) {

    $edit_theme = variable_get('content_theme_content_type_edit_' . $result->type, '-content_wide-');
    $view_theme = variable_get('content_theme_content_type_view_' . $result->type, '-content_wide-');

    $row = array();
    $row['type'] = check_plain($result->name);
    $row['edit_theme'] = content_theme_get_theme_name($edit_theme);
    $row['view_theme'] = content_theme_get_theme_name($view_theme);
    $row['op'] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => t('edit'),
        '#href' => 'admin/structure/types/manage/' . str_replace('_', '-', $result->type),
        '#options' => array('query' => $destination),
      ),
    );

    $options[$result->type] = $row;
  }

  $form['update'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update content type themes'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['update']['content_theme_edit'] = array(
    '#type' => 'select',
    '#title' => t('Creating & editing theme'),
    '#description' => t('Choose which theme the content creating and editing pages should display in. Content wide theme: %content_wide_theme; system default theme: %system_default_theme.', array('%content_wide_theme' => content_theme_get_info_theme_name('content_wide', 'edit'), '%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => '-no_update-',
    '#options' => array('-no_update-' => '<' . t('No update') . '>') + content_theme_get_content_type_options(),
  );
  $form['update']['content_theme_view'] = array(
    '#type' => 'select',
    '#title' => t('Viewing theme'),
    '#description' => t('Choose which theme the content viewing pages should display in. Content wide theme: %content_wide_theme; system default theme: %system_default_theme.', array('%content_wide_theme' => content_theme_get_info_theme_name('content_wide', 'view'), '%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => '-no_update-',
    '#options' => array('-no_update-' => '<' . t('No update') . '>') + content_theme_get_content_type_options(),
  );
  $form['update']['actions'] = array(
    '#type' => 'actions',
  );
  $form['update']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update themes'),
  );
  $form['types'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content types available.'),
  );
  $form['pager'] = array(
    '#markup' => theme('pager'),
  );

  return $form;
}

function content_theme_admin_content_type_validate($form, &$form_state) {

  $types_select = array_filter($form_state['values']['types']);
  if (count($types_select) == 0) {
    form_set_error('', t('No content types selected.'));
  }
}

function content_theme_admin_content_type_submit($form, &$form_state) {

  $edit_theme = $form_state['values']['content_theme_edit'];
  $view_theme = $form_state['values']['content_theme_view'];

  foreach ($form_state['values']['types'] as $type) {

    if (!empty($type)) {
      if ($edit_theme != '-no_update-') {
        variable_set('content_theme_content_type_edit_' . $type, $edit_theme);
      }
      if ($view_theme != '-no_update-') {
        variable_set('content_theme_content_type_view_' . $type, $view_theme);
      }
    }
  }

  drupal_set_message(t('The themes have been updated.'));
}


/**
 * Menu callback; configures content wide themes.
 */
function content_theme_admin_content_wide($form, &$form_state) {

  $form['update'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update content wide themes'),
  );
  $form['update']['content_theme_edit'] = array(
    '#type' => 'select',
    '#title' => t('Creating & editing theme'),
    '#description' => t('Choose which theme the content creating and editing pages should display in. System default theme: %system_default_theme.', array('%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => variable_get('content_theme_content_wide_edit', '0'),
    '#options' => content_theme_get_content_wide_options(),
  );
  $form['update']['content_theme_view'] = array(
    '#type' => 'select',
    '#title' => t('Viewing theme'),
    '#description' => t('Choose which theme the content viewing pages should display in. System default theme: %system_default_theme.', array('%system_default_theme' => content_theme_get_info_theme_name())),
    '#default_value' => variable_get('content_theme_content_wide_view', '0'),
    '#options' => content_theme_get_content_wide_options(),
  );
  $form['update']['actions'] = array(
    '#type' => 'actions',
  );
  $form['update']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update themes'),
  );

  return $form;
}

function content_theme_admin_content_wide_submit($form, &$form_state) {

  $edit_theme = $form_state['values']['content_theme_edit'];
  $view_theme = $form_state['values']['content_theme_view'];

  variable_set('content_theme_content_wide_edit', $edit_theme);
  variable_set('content_theme_content_wide_view', $view_theme);

  drupal_set_message(t('The themes have been updated.'));
}


/**
 * Menu callback; configures the content_theme module.
 */
function content_theme_admin_settings($form, &$form_state) {

  // Content node
  $form['content_node'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content node themes'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['content_node']['content_theme_content_node_list'] = array(
    '#type' => 'radios',
    '#title' => t('Drop-down list options'),
    '#default_value' => variable_get('content_theme_content_node_list', 'enabled'),
    '#options' => array(
      'enabled' => t('Only enabled themes.'),
      'all' => t('All themes.'),
    ),
  );
  // Content node
  $form['content_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type themes'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['content_type']['content_theme_content_type_list'] = array(
    '#type' => 'radios',
    '#title' => t('Drop-down list options'),
    '#default_value' => variable_get('content_theme_content_type_list', 'enabled'),
    '#options' => array(
      'enabled' => t('Only enabled themes.'),
      'all' => t('All themes.'),
    ),
  );
  // Content wide
  $form['content_wide'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content wide themes'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['content_wide']['content_theme_content_wide_list'] = array(
    '#type' => 'radios',
    '#title' => t('Drop-down list options'),
    '#default_value' => variable_get('content_theme_content_wide_list', 'enabled'),
    '#options' => array(
      'enabled' => t('Only enabled themes.'),
      'all' => t('All themes.'),
    ),
  );

  return system_settings_form($form);
}
