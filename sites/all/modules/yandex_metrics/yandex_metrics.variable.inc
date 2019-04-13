<?php

/**
 * @file
 * Variable integration for Yandex.Metrics module.
 */

/**
 * Implements hook_variable_group_info().
 */
function yandex_metrics_variable_group_info() {
  $groups['yandex_metrics'] = array(
    'title' => t('Yandex.Metrics'),
    'description' => t('Variables for Yandex.Metrics configuration.'),
    'access' => 'administer Yandex.Metrics settings',
    'path' => array('admin/config/system/yandex_metrics'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function yandex_metrics_variable_info($options) {
  $variables['yandex_metrics_counter_code'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Yandex.Metrics Counter Code', array(), $options),
    'description' => t('Paste Yandex.Metrica counter code for your site here.', array(), $options),
    'type' => 'text',
    'default' => '',
    'required' => TRUE,
    'multidomain' => TRUE,
  );
  $variables['yandex_metrics_visibility'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Add code to specific pages', array(), $options),
    'type' => 'enable',
    'options' => array(
      t('Add to every page except the listed pages.'),
      t('Add to the listed pages only.'),
    ),
    'default' => 0,
    'multidomain' => TRUE,
  );
  $variables['yandex_metrics_pages'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Pages', array(), $options),
    'type' => 'text',
    'default' => YANDEX_METRICS_PAGES,
    'multidomain' => TRUE,
  );
  $variables['yandex_metrics_visibility_roles'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Add tracking for specific roles', array(), $options),
    'options' => array(
      t('Add to the selected roles only'),
      t('Add to every role except the selected ones'),
    ),
    'type' => 'enable',
    'default' => 0,
    'multidomain' => TRUE,
  );

  $roles = user_roles();
  $role_options = array();
  foreach ($roles as $rid => $name) {
    $role_options[$rid] = $name;
  }
  $variables['yandex_metrics_roles'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Roles', array(), $options),
    'type' => 'options',
    'options' => $role_options,
    'default' => array(),
    'multidomain' => TRUE,
  );
  $variables['yandex_metrics_reports_counter_id'] = array(
    'group' => 'yandex_metrics',
    'title' => t('Yandex.Metrics Reports counter id (internal)', array(), $options),
    'description' => t('This is internal setting. Please do not change it unless you know what you are doing.', array(), $options),
    'type' => 'string',
    'multidomain' => TRUE,
  );

  return $variables;
}
