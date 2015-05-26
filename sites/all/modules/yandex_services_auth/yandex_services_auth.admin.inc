<?php
/**
 * @file
 * Admin pages for the Yandex Services Authorization API module.
 */

/**
 * Menu callback; the application authorization form.
 */
function yandex_services_auth_admin_settings() {

  // Show instructions from hook_help() in case system help block is disabled
  // for the current theme.
  if (!_yandex_services_auth_is_system_help_block_enabled()) {
    $form['help'] = array(
      '#markup' => module_invoke('yandex_services_auth', 'help', 'admin/config/system/yandex_services_auth', drupal_help_arg()),
    );
  }

  $auth_token = variable_get('yandex_services_auth_token', '');
  $auth_timestamp = variable_get('yandex_services_auth_timestamp', '');

  switch (yandex_services_auth_status()) {
    case 'not authorized':
      $auth_status = '<span style="color:red;">' . t('The application is not authorized yet.') . '</span>';
      break;
    case 'authorized':
      $auth_status = '<span style="color:green;">' . t('The application is already authorized.') . '</span>';
      break;
    case 'expiring':
      $auth_status = '<span style="color:yellow;">' . t('The application authorization is expiring.') . '</span>';
      break;
    case 'expired':
      $auth_status = '<span style="color:red;">' . t('The application authorization has expired.') . '</span>';
      break;
  }

  $form['yandex_services_auth_text'] = array(
    '#type' => 'item',
    '#markup' => $auth_status,
  );
  $form['yandex_services_auth_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#description' => t('Your application client ID.'),
    '#required' => TRUE,
    '#default_value' => variable_get('yandex_services_auth_client_id', ''),
  );
  $form['yandex_services_auth_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#description' => t('Your application secret.'),
    '#default_value' => variable_get('yandex_services_auth_client_secret', ''),
  );
  $form['yandex_services_auth_timestamp'] = array(
    '#type' => 'item',
    '#title' => t('Expiration time'),
    '#markup' => $auth_timestamp ? format_date($auth_timestamp) : t('Not available'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => !empty($auth_token) ? t('Re-Authorize') : t('Authorize'),
  );

  return $form;
}

/**
 * Form submit callback for yandex_services_auth_admin_settings form.
 */
function yandex_services_auth_admin_settings_submit($form, &$form_state) {
  $client_id = $form_state['values']['yandex_services_auth_client_id'];
  variable_set('yandex_services_auth_client_id', $form_state['values']['yandex_services_auth_client_id']);
  variable_set('yandex_services_auth_client_secret', $form_state['values']['yandex_services_auth_client_secret']);

  $request_url = 'https://oauth.yandex.ru/authorize';
  $params = array(
    'response_type' => 'code',
    'client_id' => $client_id,
  );

  // Check for the overlay.
  if (module_exists('overlay') && overlay_get_mode() == 'child') {
    overlay_close_dialog($request_url, array('query' => $params, 'external' => TRUE));
    overlay_deliver_empty_page();
  }
  else {
    drupal_goto($request_url, array('query' => $params));
  }
}

/**
 * Menu callback. Perform auth token request by code parameter from url.
 * More information at (Russian):
 * http://api.yandex.ru/oauth/doc/dg/reference/obtain-access-token.xml
 */
function yandex_services_auth_oauth_callback() {
  if (empty($_GET['code'])) {
    watchdog('yandex_services_auth', 'The "code" parameter is empty.', array(), WATCHDOG_WARNING);
    drupal_set_message(t('An error has occurred. Please try again.'), 'error');
    drupal_goto('admin/config/system/yandex_services_auth');
  }

  $client_id = variable_get('yandex_services_auth_client_id', '');
  $client_secret = variable_get('yandex_services_auth_client_secret', '');

  $data = 'grant_type=authorization_code&client_id=' . $client_id . '&code=' . $_GET['code'];
  if (!empty($client_secret)) {
    $data .= '&client_secret=' . $client_secret;
  }

  $result = drupal_http_request('https://oauth.yandex.ru/token', array('method' => 'POST', 'data' => $data));

  if (isset($result->error)) {
    watchdog('yandex_services_auth', 'Token request failed with error "%error".', array('%error' => $result->code . ' ' . $result->error), WATCHDOG_WARNING);
    drupal_set_message(t('An error has occurred. Please try again.'), 'error');
    drupal_goto('admin/config/system/yandex_services_auth');
  }

  $response = json_decode($result->data);
  variable_set('yandex_services_auth_token', $response->access_token);
  if (isset($response->expires_in)) {
    variable_set('yandex_services_auth_timestamp', REQUEST_TIME + $response->expires_in);
  }
  else {
    // If no 'expires_in' returned - then there is no expiration.
    variable_del('yandex_services_auth_timestamp');
  }

  watchdog('yandex_services_auth', 'Token request is successful.');
  drupal_set_message(t('Congratulations! Your application has been authorized by Yandex.'));
  drupal_goto('admin/config/system/yandex_services_auth');
}
