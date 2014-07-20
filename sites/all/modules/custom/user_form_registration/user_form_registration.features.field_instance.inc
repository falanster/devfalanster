<?php
/**
 * @file
 * user_form_registration.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_form_registration_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_subscribe'
  $field_instances['user-user-field_subscribe'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_subscribe',
    'label' => 'Вы хотите подписаться на рассылку Фаланстера?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'user-user-field_what_are_you_interested_to'
  $field_instances['user-user-field_what_are_you_interested_to'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_what_are_you_interested_to',
    'label' => 'Чым вам цікава займацца ў Фаланстэры?',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Вы хотите подписаться на рассылку Фаланстера?');
  t('Чым вам цікава займацца ў Фаланстэры?');

  return $field_instances;
}
