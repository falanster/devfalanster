<?php

/**
 * @file
 * Administration interface for the agenda module
 */


/**
 * Admin configuration page
 */
function agenda_admin() {

  // Headers
  $header = array(
    'id'   => t('Block ID'),
    'name' => t('Name'),
    'ops'  => t('Operations'),
  );

  // Rows
  $res = db_query("SELECT id, bid, value FROM {agenda} WHERE name = 'title'");
  $rows = array();
  while ($row = $res->fetchObject()) {
    $actions = array(
      'configure' => l(t('Configure'), sprintf('admin/config/services/agenda/%d/configure', $row->bid)),
      'delete'    => l(t('Delete'), sprintf('admin/config/services/agenda/%d/delete', $row->bid)),
      'debug'     => l(t('Debug'), sprintf('admin/config/services/agenda/%d/debug', $row->bid)),
      'clear'     => l(t('Clear'), sprintf('admin/config/services/agenda/%d/clear', $row->bid)),
    );

    $rows[] = array(
      'id'   => $row->bid,
      'name' => $row->value,
      'ops'  => implode(' | ', $actions),
    );
  }

  $table = '';
  if (!empty($rows)) {
    $table = theme('table', array('header' => $header, 'rows' => $rows));
  }

  return theme('agenda_admin', array('table' => $table));
}


/**
 * Delete agenda
 */
function agenda_admin_delete($form, $form_state, $delta) {
  $form = array();

  $form['agenda_admin_delete_bid'] = array(
    '#type'  => 'hidden',
    '#value' => (int) $delta,
  );

  $form['agenda_admin_delete_markup'] = array(
    '#markup' => '<p>' . t('Are you sure you wish to delete this block?') . '</p>',
  );

  $form['agenda_admin_delete_confirm'] = array(
    '#type'  => 'submit',
    '#value' => t('Delete block'),
  );

  return $form;
}


/**
 * Delete an agenda action
 */
function agenda_admin_delete_submit($form, $form_state) {
  // Clear the agenda variables table
  db_delete('agenda')
    ->condition('bid', $form_state['values']['agenda_admin_delete_bid'])
    ->execute();

  // Also clear the block table
  db_delete('block')
    ->condition('delta', $form_state['values']['agenda_admin_delete_bid'])
    ->condition('module', 'agenda')
    ->execute();

  drupal_set_message('Agenda block was deleted');
  drupal_goto('admin/config/services/agenda');
}


/**
 * Manage agenda
 */
function agenda_admin_configure($form, $form_state, $delta) {

  $form = array();

  $form['agenda_bid'] = array(
    '#type'           => 'hidden',
    '#value'          => (int) $delta,
  );

  $form['agenda_title'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Administrative title'),
    '#default_value'  => agenda_variable_get($delta, 'title', 'New block'),
    '#description'    => t('The Administrative title for this block'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_start'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Agenda start'),
    '#default_value'  => agenda_variable_get($delta, 'start', '-1 day'),
    '#description'    => t('Any events that are older than this are not displayed. For example "-1 day" or "yesterday" will include events that occured yesterday, where as "now" will only include events that have not yet started. You can use any string <a href="http://php.net/strtotime">strtotime</a> can parse.'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_end'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Agenda end'),
    '#default_value'  => agenda_variable_get($delta, 'end', '+2 months'),
    '#description'    => t('Any events newer than this are not displayed. For example, "+2 months" will display any events that occur in the next 2 months. You can use any string <a href="http://php.net/strtotime">strtotime</a> can parse.'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_datelimit'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Dates to display'),
    '#default_value'  => agenda_variable_get($delta, 'datelimit', 4),
    '#description'    => t("The maximum number of unique dates to display."),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_maxevents'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Maximum number of events to fetch'),
    '#default_value'  => agenda_variable_get($delta, 'maxevents', 25),
    '#description'    => t("The maximum number of events to fetch."),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_dateformat'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Date formatting'),
    '#default_value'  => agenda_variable_get($delta, 'dateformat', 'l, F jS'),
    '#description'    => t('Specify the date format.'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_timeformat'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Time formatting'),
    '#default_value'  => agenda_variable_get($delta, 'timeformat', 'h:ia'),
    '#description'    => t('Specify the time format.'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_noeventstext'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Text to display if no events are found'),
    '#default_value'  => agenda_variable_get($delta, 'noeventstext', '<p>No upcoming events</p>'),
    '#description'    => t('Leave blank to have the block hide when no events are found.'),
    '#agenda_setting' => TRUE,
  );

  $form['agenda_linktext'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Calendar link text'),
    '#default_value'  => agenda_variable_get($delta, 'linktext', 'View this event in Google Calendar'),
    '#description'    => t('Text to display when linking to the Google Calendar event.'),
    '#agenda_setting' => TRUE,
  );

  $form['agenda_cachetime'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Amount of time to cache event data'),
    '#default_value'  => agenda_variable_get($delta, 'cachetime', 3600),
    '#description'    => t("How long (in seconds) the module should hold onto the ICS data before re-requesting it from Google."),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_display_keys'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Display fields'),
    '#default_value'  => agenda_variable_get($delta, 'display_keys', 'calendar, start time, description'),
    '#description'    => t("A comma separated list of fields to display in the event summary. The available fields are shown on the <em>Test settings</em> page."),
    '#required'       => FALSE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_hide_labels'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Hide labels'),
    '#default_value'  => agenda_variable_get($delta, 'hide_labels', 'link, description'),
    '#description'    => t("A comma separated list of fields for which the label should not be displayed."),
    '#required'       => FALSE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_calendars'] = array(
    '#type'           => 'textarea',
    '#title'          => t('Google Calendar IDs'),
    '#default_value'  => agenda_variable_get($delta, 'calendars', 'drupalagenda@gmail.com'),
    '#rows'           => 4,
    '#description'    => t("The IDs of each google calendar you want to display, each on a new line. For private calendars, include the access token after the email with a forward slash."),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_timezone'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Timezone'),
    '#default_value'  => agenda_variable_get($delta, 'timezone', variable_get('date_default_timezone', date_default_timezone_get())),
    '#description'    => t('The timezone identifier to be used for this calendar, as described in <a href="http://php.net/timezones">the PHP manual</a>.'),
    '#required'       => TRUE,
    '#agenda_setting' => TRUE,
  );

  $form['agenda_confirm'] = array(
    '#type'           => 'submit',
    '#value'          => t('Save settings'),
  );

  return $form;
}


/**
 * Validate function for the admin configuration
 */
function agenda_admin_configure_validate($form, &$form_state) {
  // clear the cache
  drupal_set_message(t('Cache cleared for agenda block'));
  cache_clear_all('agenda_block_' . $form['agenda_bid']['#value'], 'cache');

  // calendars (has the form of a valid email address and an optional access key)
  $calendars = $form_state['values']['agenda_calendars'];
  $ids = preg_split('@\r\n?|\n@', $calendars);
  if (empty($ids)) {
    form_set_error('agenda_calendars', t('Field can not be left blank'));
  }
  foreach ($ids as $id) {
    if (!_agenda_parse_googleid($id)) {
      form_set_error('agenda_calendars', t('Invalid calendar ID'));
    }
  }

  // start (strtotime parseable)
  $string = $form_state['values']['agenda_start'];
  if (false === strtotime($string)) {
    form_set_error('agenda_start', t('Unable to parse newer-than input with strtotime'));
  }

  // end (strtotime parseable)
  $string = $form_state['values']['agenda_end'];
  if (false === strtotime($string)) {
    form_set_error('agenda_end', t('Unable to parse older-than input with strtotime'));
  }


  // datelimit (positive integer)
  $datelimit = $form_state['values']['agenda_datelimit'];
  if (!is_numeric($datelimit)) {
    form_set_error('agenda_datelimit', t('You must specify a number.'));
  }
  elseif ($datelimit <= 0) {
    form_set_error('agenda_datelimit', t('The number must be positive.'));
  }

  // cachetime (positive integer)
  $cachetime = $form_state['values']['agenda_cachetime'];
  if (!is_numeric($cachetime)) {
    form_set_error('agenda_cachetime', t('You must specify the number of seconds to cache calendar data.'));
  }
  elseif ($cachetime <= 0) {
    form_set_error('agenda_cachetime', t('The cache time must be positive.'));
  }


  // timezone
  if (!@date_default_timezone_set($form_state['values']['agenda_timezone'])) {
    form_set_error('agenda_timezone', t('Invalid timezone.'));
  }
}


/**
 * Save all the settings into our agenda settings table
 */
function agenda_admin_configure_submit($form, $form_state) {

  // Check if we're creating a new block, in which case the delta is 0
  $delta = $form['agenda_bid']['#value'];
  if ($delta == 0) {
    $delta = db_query('SELECT COALESCE(MAX(bid)+1,1) AS count FROM {agenda}')->fetchField();
  }

  // Save the settings
  foreach ($form_state['values'] as $key => $value) {
    if (!isset($form[$key]['#agenda_setting'])) {
      continue;
    }
    $setting = substr($key, 7);
    agenda_variable_set($delta, $setting, $value);
  }

  drupal_set_message('Block settings were saved successfully');
  drupal_goto('admin/config/services/agenda');
}


/**
 * Provide a page to debug a calendar ID that is not working
 */
function agenda_debug($bid) {
  $output     = array();

  // Date check (http://drupal.org/node/545174)
  $output[]   = t('Checking server time: %date', array('%date' => gmdate('r')));
  $output[]   = t('Checking real UTC time via NTP: %date', array('%date' => gmdate('r', agenda_debug_ntp_time('0.pool.ntp.org'))));
  $output[]   = t('Ensure these values are approximately the same, otherwise your system is incorrectly configured and agenda will be unable to calculate dates properly.');

  // Find calendar sources
  $block      = agenda_settings($bid);
  $output[]   = t('Reading calendar input:');
  $output[]   = '<pre>' . htmlspecialchars($block->calendars) . '</pre>';
  $calendars  = preg_split('@\r\n?|\n@', $block->calendars);
  $calendars  = array_map('trim', $calendars);
  $output[]   = t('Found following calendars:');
  $output[]   = sprintf('<pre>%s</pre>', print_r($calendars, TRUE));
  $googleid   = $calendars[0];
  if (count($calendars) > 1) {
    $output[] = t('Multiple calendars found, debugging with the first calendar: %googleid', array('%googleid' => $googleid));
  }

  // Load the calendar
  list ($address, $token) = _agenda_parse_googleid($googleid);
  $source = _agenda_feed_url($address, $token, $block);
  $output[] = t('Fetching feed from <em>%source</em>', array('%source' => $source));

  // Load the XML
  $calendar = _agenda_load_xml($address, $token, $block);
  if (!$calendar) {
    $output[] = t('<strong>Warning</strong>: Failed to load XML');
    return theme('item_list', $output, NULL, 'ul', array('id' => 'agenda-debug'));
  }
  $output[] = t('Loaded XML successfully');

  // Find the events
  $number_of_events = count($calendar->entry);
  $output[] = t('Found @count events', array('@count' => $number_of_events));
  if ($number_of_events === 0) {
    $output[] = t('<strong>Warning</strong>: Nothing to do with empty calendar, stopping!');
    return theme('item_list', $output, NULL, 'ul', array('id' => 'agenda-debug'));
  }

  // Parse the events
  $i = 0;
  $eventdata = array();
  foreach ($calendar->entry as $event) {
    $output[] = t('Loading event @number which is @size bytes', array('@number' => ++$i, '@size' => strlen($event->asXml())));
    $output[] = sprintf("<pre>%s</pre>", htmlspecialchars($event->asXml()));

    $thisevent = _agenda_parse_event($event, $block);
    if (!$thisevent) {
      $output[] = t('<strong>Warning</strong>: Failed to parse event!');
      continue;
    }

    $output[] = t('Successfully parsed event:');
    $output[] = '<pre>' . print_r($thisevent, TRUE) . '</pre>';
    $eventdata[] = $thisevent;
  }

  $output[] = t('Parsed @success/@total events successfully', array('@success' => count($eventdata), '@total' => $number_of_events));

  $output[] = t('Begin filtering based on date: string provided (@old) which has timestamp (@timestamp) which has date (@date).', array(
    '@old'       => $what_is_old = agenda_variable_get($bid, 'start', '-1 day'),
    '@timestamp' => $what_is_old_ts = strtotime($what_is_old),
    '@date'      => format_date($what_is_old_ts)
    ));

  foreach ($eventdata as $key => $event) {
    if ($event['start timestamp'] < $what_is_old_ts) {
      $output[] = t('&raquo; Discarding %title because %start is older than %old', array(
        '%title' => $event['title'],
        '%start'  => format_date($event['start timestamp'], 'small'),
        '%old'   => format_date($what_is_old_ts, 'small')
        ));
      unset($eventdata[$key]);
    }
  }

  $output[] = t('Finished. Started with @total events, will display @display events', array('@total' => $number_of_events, '@display' => count($eventdata)));


  // Now take all of our debug data and theme it up, starting with the logs
  $debug_log = theme('item_list', array('items' => $output));

  // Build a table of all of the events found
  $event_table = '';
  if (count($eventdata)) {
    $first_row   = array_slice($eventdata, 0, 1);
    $event_table = theme('table', array(
      'header' => array_keys($first_row[0]),
      'rows'   => $eventdata,
      'sticky' => FALSE,
    ));
  }

  // Render
  return array(
    'title'       => array('#markup' => '<h2>' . t('Debugging %calendar block', array('%calendar' => $block->title)) . '</h2>'),
    'debug_log'   => array('#markup' => $debug_log, '#prefix' => '<h3>Log</h3><div id="agenda-debug-log">', '#suffix' => '</div>'),
    'event_table' => array('#markup' => $event_table, '#prefix' => '<h3>Events</h3><div id="agenda-debug-table">', '#suffix' => '</div>'),
    '#attached'   => array('css' => array(drupal_get_path('module', 'agenda') . '/agenda.css')),
  );
}


/**
 * Grab the time from an NTP server
 *
 * @param string $host The NTP server to retrieve the time from
 * @return int The current unix timestamp
 */
function agenda_debug_ntp_time($host) {

  // Create a socket and connect to NTP server
  $sock = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);
  socket_connect($sock, $host, 123);

  // Send request
  $msg = "\010" . str_repeat("\0", 47);
  socket_send($sock, $msg, strlen($msg), 0);

  // Receive response and close socket
  socket_recv($sock, $recv, 48, MSG_WAITALL);
  socket_close($sock);

  // Interpret response
  $data = unpack('N12', $recv);
  $timestamp = sprintf('%u', $data[9]);

  // NTP is number of seconds since 0000 UT on 1 January 1900
  // Unix time is seconds since 0000 UT on 1 January 1970
  $timestamp -= 2208988800;

  return $timestamp;
}


/**
 * Agenda clear cache
 */
function agenda_clear($bid) {
  drupal_set_message(t('Cache cleared for agenda block'));
  cache_clear_all('agenda_block_' . $bid, 'cache');
  drupal_goto('admin/config/services/agenda');
}
