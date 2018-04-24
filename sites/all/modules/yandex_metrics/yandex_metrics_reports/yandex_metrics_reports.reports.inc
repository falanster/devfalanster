<?php
/**
 * @file
 * Report callbacks for Yandex.Metrics Reports module.
 */

/**
 * The function generates content of search phrases table ordered by popularity.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 *
 * @return mixed
 *    Content table.
 */
function yandex_metrics_reports_search_phrases($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  $report_phrases = yandex_metrics_reports_retreive_data('/stat/sources/phrases', $parameters);
  $phrases = json_decode($report_phrases->data);

  if (empty($phrases->data)) {
    return t('There is no information about search phrases for the selected date range.');
  }

  $phrases_totals_visits = $phrases->totals->visits;

  $header = array(t('Visits (%)'), t('Phrase'));

  $data = array();

  $i = 1;
  foreach ($phrases->data as $value) {
    if ($i > YANDEX_METRICS_REPORTS_SEARCH_PHRASES_QUANTITY) {
      break;
    }
    $percentage = round(100 * $value->visits / $phrases_totals_visits, 2);
    $data[] = array($percentage, check_plain($value->phrase));
    $i++;
  }

  return theme('table', array('header' => $header, 'rows' => $data, 'caption' => t("Popular Search Phrases")));
}

/**
 * The function generates pie chart with traffic sources summary.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_sources_chart($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  $results = yandex_metrics_reports_retreive_data('/stat/sources/summary', $parameters);
  $summary = json_decode($results->data);
  if (empty($summary->data)) {
    return t('There is no information about traffic sources for the selected date range.');
  }

  $chart = array(
    'title' => t('Traffic Sources'),
    'type' => 'pie',
    'fields' => array(
      'sources' => array(
        'label' => t('Sources'),
        'enabled' => FALSE,
      ),
      'visits' => array(
        'label' => t('Visits'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'sources',
    ),
  );

  $sum = $summary->totals->visits;

  $i = 1;
  foreach ($summary->data as $value) {
    $name = check_plain($value->name);
    $sources_leneged = $i . '. ' . $name . ' (' . round($value->visits * 100 / $sum) . '%' . ')';

    $chart['data'][] = array(
      'sources' => $sources_leneged,
      'visits' => (int) $value->visits,
    );

    $i++;
  }

  return theme('visualization', array('options' => $chart));
}

/**
 * Generates chart with information about page views, visitors and new visitors.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_visits_chart($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  if (isset($date_range['group'])) {
    $parameters['group'] = $date_range['group'];
  }

  $results = yandex_metrics_reports_retreive_data('/stat/traffic/summary', $parameters);
  $visits = json_decode($results->data);
  if (empty($visits->data)) {
    return t('There is no information about page views and visitors for the selected date range.');
  }

  $chart = array(
    'title' => t('Page Views, Visitors, New Visitors'),
    'type' => 'line',
    'fields' => array(
      'dates' => array(
        'label' => t('Dates'),
        'enabled' => FALSE,
      ),
      'page_views' => array(
        'label' => t('Page Views'),
        'enabled' => TRUE,
      ),
      'visitors' => array(
        'label' => t('Visitors'),
        'enabled' => TRUE,
      ),
      'new_visitors' => array(
        'label' => t('New Visitors'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'dates',
    ),
  );

  foreach ($visits->data as $value) {
    $timestamp = strtotime(check_plain($value->date));

    $chart['data'][] = array(
      'dates' => date('d.m.y', $timestamp),
      'page_views' => (int) $value->page_views,
      'visitors' => (int) $value->visitors,
      'new_visitors' => (int) $value->new_visitors,
    );
  }

  return theme('visualization', array('options' => $chart));
}

/**
 * The function generates the table of popular content.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_popular_content($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  $report_content = yandex_metrics_reports_retreive_data('/stat/content/popular', $parameters);
  $content = json_decode($report_content->data);

  if (empty($content->data)) {
    return t('There is no information about popular content for the selected date range.');
  }

  $header = array(t('URL'), t('Page Views'));

  $data = array();

  $i = 1;
  foreach ($content->data as $value) {
    if ($i > YANDEX_METRICS_REPORTS_POPULAR_CONTENT_COUNT) {
      break;
    }
    $page_views = (int) $value->page_views;
    $data[] = array(l($value->url, $value->url, array('attributes' => array('target' => '_blank'))), $page_views);
    $i++;
  }

  return theme('table', array('header' => $header, 'rows' => $data, 'caption' => t("Popular Content")));
}

/**
 * The function generates pie chart with geographical information on visitors.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_geo_chart($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  $results = yandex_metrics_reports_retreive_data('/stat/geo', $parameters);
  $geo = json_decode($results->data);
  if (empty($geo->data)) {
    return t('There is no information about geography of visits for the selected date range.');
  }

  $chart = array(
    'title' => t('Geography of Visits'),
    'type' => 'pie',
    'fields' => array(
      'country' => array(
        'label' => t('Country'),
        'enabled' => FALSE,
      ),
      'visits' => array(
        'label' => t('Visits'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'country',
    ),
  );

  $total_visits = $geo->totals->visits;

  // Exclude unknown visits.
  foreach ($geo->data as $key => $value) {
    if ($value->name == "Не определено") {
      $total_visits -= $value->visits;
      unset($geo->data[$key]);
      break;
    }
  }

  $i = 1;
  $sum_visits = 0;
  foreach ($geo->data as $value) {

    $visits = (int) $value->visits;

    if ($i > 10) {
      $others_visits = $total_visits - $sum_visits;

      $chart['data'][] = array(
        'country' => t('Others'),
        'visits' => $others_visits,
      );

      break;
    }

    $sum_visits += $visits;

    $name = check_plain($value->name);
    $chart['data'][] = array(
      'country' => $name,
      'visits' => $visits,
    );

    $i++;
  }

  return theme('visualization', array('options' => $chart));
}

/**
 * The function generates chart with information about hourly traffic.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_traffic_hourly_chart($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  if (isset($date_range['group'])) {
    $parameters['group'] = $date_range['group'];
  }

  $results = yandex_metrics_reports_retreive_data('/stat/traffic/hourly', $parameters);
  $hourly_report = json_decode($results->data);
  if (empty($hourly_report->data)) {
    return t('There is no information about hourly traffic for the selected date range.');
  }

  $chart = array(
    'title' => t('Hourly Traffic'),
    'type' => 'column',
    'fields' => array(
      'hours' => array(
        'label' => t('Hours'),
        'enabled' => FALSE,
      ),
      'avg_visits' => array(
        'label' => t('Visits per hour'),
        'enabled' => TRUE,
      ),
      'denials' => array(
        'label' => t('Denials (visits with only one page view)'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'hours',
    ),
  );

  foreach ($hourly_report->data as $hour_data) {
    list($hour,) = explode(':', $hour_data->hours);
    $chart['data'][] = array(
      'hours' => $hour,
      'avg_visits' => round($hour_data->avg_visits, 2),
      // Convert denials from percents.
      'denials' => round($hour_data->avg_visits * $hour_data->denial, 2),
    );
  }

  return theme('visualization', array('options' => $chart));
}

/**
 * The function generates pie chart with demography information.
 *
 * @param string $counter_id
 *    Counter id.
 * @param string $filter
 *    Date range filter.
 */
function yandex_metrics_reports_gender_chart($counter_id, $filter) {

  $date_range = yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date'],
  );

  $results = yandex_metrics_reports_retreive_data('/stat/demography/structure', $parameters);
  $demography = json_decode($results->data);
  if (empty($demography->data)) {
    return t('There is no demography information for the selected date range.');
  }

  $chart = array(
    'title' => t('Demography of Visits'),
    'type' => 'pie',
    'fields' => array(
      'gender' => array(
        'label' => t('Gender'),
        'enabled' => FALSE,
      ),
      'visits' => array(
        'label' => t('Visits'),
        'enabled' => TRUE,
      ),
    ),
    'xAxis' => array(
      'labelField' => 'gender',
    ),
  );

  $data = $demography->data;
  // Add key for sorting stability.
  foreach ($data as $key => $value) {
    $data[$key]->key = $key;
  }
  // Sort data by gender.
  usort($data, '_yandex_metrics_reports_gender_sort');

  $label_counter = 1;
  foreach ($data as $value) {
    if ($value->visits_percent === 0) {
      continue;
    }

    $age = check_plain($value->name);
    $name_gender = check_plain($value->name_gender);
    $gender_legend = $label_counter . '.' . $name_gender . '/' . $age . '—' . round($value->visits_percent * 100, 2) . '%';
    $chart['data'][] = array(
      'gender' => $gender_legend,
      'visits' => $value->visits,
    );

    $label_counter++;
  }

  return theme('visualization', array('options' => $chart));
}

/**
 * Sort callback to order data objects by gender DESC, then by key ASC.
 */
function _yandex_metrics_reports_gender_sort($a, $b) {
  if ($a->name_gender == $b->name_gender) {
    return ($a->key < $b->key) ? -1 : 1;
  }

  return ($a->name_gender > $b->name_gender) ? -1 : 1;
}
