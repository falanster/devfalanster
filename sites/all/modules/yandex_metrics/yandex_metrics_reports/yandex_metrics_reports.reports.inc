<?php
/**
 * @file
 *   Report callbacks for Yandex.Metrics Reports module.
 */

/**
 * The function generates content of search phrases table ordered by popularity.
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_search_phrases($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
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
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_sources_chart($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
  );

  $results = yandex_metrics_reports_retreive_data('/stat/sources/summary', $parameters);
  $summary = json_decode($results->data);
  if (empty($summary->data)) {
    return t('There is no information about traffic sources for the selected date range.');
  }

  $chart = array(
    '#chart_id' => 'chart_sources',
    '#title' => chart_title(t('Traffic Sources'), '000000', 15),
    '#type' => CHART_TYPE_PIE,
    '#size' => chart_size(500, 200),
    '#adjust_resolution' => TRUE,
  );

  $sum = $summary->totals->visits;

  $i = 1;
  foreach ($summary->data as $value) {
    $name = check_plain($value->name);
    $chart['#data'][] = (int) $value->visits;
    $chart['#labels'][] = $i;
    $chart['#legends'][] = $i . '. ' . $name . ' (' . round($value->visits * 100 / $sum) . '%' . ')';
    $chart['#data_colors'][] = chart_unique_color('sources_' . $i, 'yandex_metrics_reports');
    $i++;
  }

  return theme('chart', array('chart' => $chart));
}

/**
 * The function generates chart with information about page views, visitors and new visitors.
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_visits_chart($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
  );

  if (isset($date_range['group'])) {
    $parameters['group'] = $date_range['group'];
  }

  $results = yandex_metrics_reports_retreive_data('/stat/traffic/summary', $parameters);
  $visits = json_decode($results->data);
  if (empty($visits->data)) {
    return t('There is no information about page views and visitors for the selected date range.');
  }

  $dates = array();
  $page_views = array();
  $visitors = array();
  $new_visitors = array();

  // If there is only one date point, we should duplicate for
  // building horizontal line.
  if (count($visits->data) == 1) {
    $z_point = $visits->data[0];
    $page_views[] = (int) $z_point->page_views;
    $visitors[] = (int) $z_point->visitors;
    $new_visitors[] = (int) $z_point->new_visitors;
    // Set date label to the middle.
    $position = 50;
  }
  else {
    $position = NULL;
  }
  foreach ($visits->data as $value) {
    $dates[] = check_plain($value->date);
    $page_views[] = (int) $value->page_views;
    $visitors[] = (int) $value->visitors;
    $new_visitors[] = (int) $value->new_visitors;
  }

  $dates = array_reverse($dates);
  $page_views = array_reverse($page_views);
  $visitors = array_reverse($visitors);
  $new_visitors = array_reverse($new_visitors);

  $width = 500;
  $height = 250;

  $chart = array(
    '#chart_id' => 'chart_visits',
    '#title' => chart_title(t('Page Views, Visitors, New Visitors'), '000000', 15),
    '#type' => CHART_TYPE_LINE,
    '#size' => chart_size($width, $height),
    '#legend_position' => CHART_LEGEND_BOTTOM,
  );

  $chart['#data']['views'] = $page_views;
  $chart['#data']['visitors'] = $visitors;
  $chart['#data']['new_visitors'] = $new_visitors;

  $max = 0;
  foreach ($chart['#data'] as $data) {
    $max_new = max($data);
    if ($max_new > $max) {
      $max = $max_new;
    }
  }

  // Calculate max value for grid.
  $max_grid = _yandex_metrics_reports_calculate_max_grid(0, $max);
  $chart['#fluid_grid_adjust'] = array('#max' => $max_grid);

  $chart['#data_colors']['views'] = '0000FF'; // Blue.
  $chart['#data_colors']['visitors'] = '008000'; // Green.
  $chart['#data_colors']['new_visitors'] = 'FF0000'; // Red.

  $chart['#legends']['views'] = t('Page Views');
  $chart['#legends']['visitors'] = t('Visitors');
  $chart['#legends']['new_visitors'] = t('New Visitors');

  // Calculate grid step for X.
  $step_x_percent = _yandex_metrics_reports_calculate_grid_step_fixed(count($dates));
  // Calculate grid step for Y.
  list($step_y, $step_y_percent) = _yandex_metrics_reports_calculate_grid_step_fluid($max_grid, $height);

  // Count Y labels.
  $axis_y_count_labels = round($max_grid / $step_y, 0, PHP_ROUND_HALF_DOWN);

  // Draw Y labels.
  for ($i = 1; $i <= $axis_y_count_labels; $i++) {
    $chart['#mixed_axis_labels'][CHART_AXIS_Y_LEFT][0][] = chart_mixed_axis_label($i * $step_y, $i * $step_y_percent);
  }
  // Add grids to chart.
  $chart['#grid_lines'] = chart_grid_lines($step_x_percent, $step_y_percent);

  // Draw X labels.
  foreach ($dates as $date) {
    $timestamp = strtotime($date);

    $chart['#mixed_axis_labels'][CHART_AXIS_X_BOTTOM][1][] = chart_mixed_axis_label(date('d.m.y', $timestamp), $position);
  }

  return theme('chart', array('chart' => $chart));
}

/**
 * The function generates the table of popular content.
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_popular_content($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
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
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_geo_chart($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
  );

  $results = yandex_metrics_reports_retreive_data('/stat/geo', $parameters);
  $geo = json_decode($results->data);
  if (empty($geo->data)) {
    return t('There is no information about geography of visits for the selected date range.');
  }

  $chart = array(
    '#chart_id' => 'chart_geo',
    '#title' => chart_title(t('Geography of Visits'), '000000', 15),
    '#type' => CHART_TYPE_PIE,
    '#size' => chart_size(500, 230),
    '#adjust_resolution' => TRUE,
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

      $chart['#data'][] = $others_visits;
      $chart['#labels'][] = t('Others') . ' (' . round($others_visits * 100 / $total_visits, 1) . '%' . ')';

      $chart['#data_colors'][] = chart_unique_color('geo_' . $i, 'yandex_metrics_reports');

      break;
    }

    $sum_visits += $visits;

    $name = check_plain($value->name);
    $chart['#data'][] = $visits;
    $chart['#labels'][] = $name . ' (' . round($visits * 100 / $total_visits, 1) . '%' . ')';

    $chart['#data_colors'][] = chart_unique_color('geo_' . $i, 'yandex_metrics_reports');
    $i++;
  }

  return theme('chart', array('chart' => $chart));
}

/**
 * The function generates chart with information about hourly traffic.
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_traffic_hourly_chart($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

  $parameters = array(
    'id' => $counter_id,
    'date1' => $date_range['start_date'],
    'date2' => $date_range['end_date']
  );

  if (isset($date_range['group'])) {
    $parameters['group'] = $date_range['group'];
  }

  $results = yandex_metrics_reports_retreive_data('/stat/traffic/hourly', $parameters);
  $hourly_report = json_decode($results->data);
  if (empty($hourly_report->data)) {
    return t('There is no information about hourly traffic for the selected date range.');
  }

  $hours = array();
  $avg_visits = array();
  $denials = array();

  foreach ($hourly_report->data as $hour_data) {
    $hours[] = $hour_data->hours;
    $avg_visits[] = $hour_data->avg_visits;
    // Convert denials from percents.
    $denials[] = $hour_data->avg_visits * $hour_data->denial;
  }

  // Look up max value only in avg_visits because denials are always less.
  $max = max($avg_visits);
  $max_grid = _yandex_metrics_reports_calculate_max_grid(0, $max);

  $width = 500;
  $height = 350;

  $chart = array(
    '#chart_id' => 'chart_hourly',
    '#title' => chart_title(t('Hourly Traffic'), '000000', 15),
    '#type' => CHART_TYPE_BAR_V_GROUPED,
    '#size' => chart_size($width, $height),
    '#fluid_grid_adjust' => array('#max' => $max_grid),
    '#legend_position' => CHART_LEGEND_BOTTOM,
    '#bar_size' => array('#size' => 5, '#spacing' => 0),
  );

  $chart['#data']['avg_visits'] = $avg_visits;
  $chart['#data']['denials'] = $denials;

  $chart['#data_colors']['avg_visits'] = '4671D5'; // Blue.
  $chart['#data_colors']['denials'] = 'FF4E40'; // Red.

  $chart['#legends']['avg_visits'] = t('Visits per hour');
  $chart['#legends']['denials'] = t('Denials (visits with only one page view)');
  // Calculate grid step for X.
  $step_x_percent = _yandex_metrics_reports_calculate_grid_step_fixed(count($hours) + 1);
  // Calculate grid step for Y.
  list($step_y, $step_y_percent) = _yandex_metrics_reports_calculate_grid_step_fluid($max_grid, $height);
  // Count Y labels.
  $axis_y_count_labels = round($max_grid / $step_y, 0, PHP_ROUND_HALF_DOWN);

  // Draw Y labels.
  for ($i = 1; $i <= $axis_y_count_labels; $i++) {
    $chart['#mixed_axis_labels'][CHART_AXIS_Y_LEFT][0][] = chart_mixed_axis_label($i * $step_y, $i * $step_y_percent);
  }

  // Add grids to chart.
  $chart['#grid_lines'] = chart_grid_lines($step_x_percent, $step_y_percent);

  // Draw X labels.
  foreach ($hours as $hour) {
    list($label, ) = explode(':', $hour);
    $chart['#mixed_axis_labels'][CHART_AXIS_X_BOTTOM][1][] = chart_mixed_axis_label($label);
  }

  return theme('chart', array('chart' => $chart));
}

/**
 * The function generates pie chart with demography information.
 * @param string $counter_id
 * @param string $filter
 */
function yandex_metrics_reports_gender_chart($counter_id, $filter) {

  $date_range = _yandex_metrics_reports_filter_to_date_range($filter);

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
    '#chart_id' => 'chart_gender',
    '#title' => chart_title(t('Demography of Visits'), '000000', 15),
    '#type' => CHART_TYPE_PIE,
    '#size' => chart_size(500, 200),
    '#adjust_resolution' => TRUE,
  );

  $data = $demography->data;
  // Add key for sorting stability.
  foreach ($data as $key => $value) {
    $data[$key]->key = $key;
  }
  // Sort data by gender.
  usort($data, '_yandex_metrics_reports_gender_sort');

  $colors = array(
    '6C8CD5', '4671D5', '1240AB', '2A4480', '06266F', // Male colors.
    'FB8BBA', 'EB6AA4', 'EB3B8B', 'D60062', '8B003F', // Female colors.
  );

  $label_counter = 1;
  foreach ($data as $i => $value) {
    if ($value->visits_percent === 0) {
      continue;
    }

    $age = check_plain($value->name);
    $gender = check_plain($value->name_gender);
    $chart['#data'][] = $value->visits_percent;
    $chart['#labels'][] = $label_counter;
    $chart['#legends'][] = "$label_counter . $gender / $age  — " . round($value->visits_percent * 100, 2) . '%';
    $chart['#data_colors'][] = $colors[$i];
    $label_counter++;
  }

  return theme('chart', array('chart' => $chart));
}

/**
 * Helper function to calculate params for grids with fixed number of grid lines.
 *
 * @param int $data_count
 *  Count of data values.
 */
function _yandex_metrics_reports_calculate_grid_step_fixed($data_count) {
  $grid_count = $data_count > 1 ? $data_count - 1 : $data_count;
  $step_percent = 100 / $grid_count;

  return $step_percent;
}

/**
 * Helper function to calculate dynamic integer grids.
 *
 * @param int $max_grid Max grid value.
 * @param int $axis_size Size of axis in px.
 * @param int $min_step_px Min space between two grid lines in px.
 *
 * @return array
 *   array(0 => $step, 1 => $step_percent)
 */
function _yandex_metrics_reports_calculate_grid_step_fluid($max_grid, $axis_size, $min_step_px = 25) {
  /**
   * Calculate smart grid steps for numeric values.
   *
   * We use manual method to synchronize labels and grid.
   * First, define min step as $min_step_px so grids are not too close to each other.
   * Calculate min step and round it to nice value as $step. 2 becomes 2,
   * 34 becomes 50, 148 becomes 150, 0.07 becomes 0.05.
   */
  $min_step_percent = 100 * $min_step_px / $axis_size;
  $min_step = $max_grid * $min_step_percent / 100;
  $k = log10($min_step);
  if ($min_step < 1) {
    $k_improved = round(abs($k)) + 1;
  }
  else {
    $k_improved = -round(abs($k)) + 1;
  }
  $level = pow(10, $k_improved);
  // Convert 0.07 to 7, 12 to 10, 148 to 14.8, etc. for smart rounding.
  $min_step = $min_step * $level;

  // Round min step.
  $step = round($min_step / 5) * 5;
  $step = !$step ? round($min_step) : $step;
  // Convert back to input range.
  $step = $step / $level;
  // Manually fix for 3 and 4.
  if ($step >= 3 && $step <= 4) {
    $step = 5;
  }

  // Convert min step back to percents.
  $step_percent = $step * 100 / $max_grid;

  return array($step, $step_percent);
}

/**
 * Helper function to calculate rounded max grid value.
 *
 * @param int $min Min data value.
 * @param int $max Max data value.
 *
 * @return number
 */
function _yandex_metrics_reports_calculate_max_grid($min, $max) {
  $k = log10($max - $min);
  // Scale max value for smart rounding.
  $level = pow(10, floor($k));
  $max_grid = ceil(($max - $min)/ $level) * $level;
  if ($max_grid == $max) {
    $max_grid += $max_grid * 0.05; // Add a margin.
  }

  return $max_grid;
}

/**
 * Replace for _chart_adjust_resolution().
 * Use '#fluid_grid_adjust' => array('#max' => $max_grid)
 * inslead of #adjust => TRUE for custom grids.
 */
function _yandex_metrics_chart_adjust_resolution(&$data, $max_grid) {
  if (count($data)) {
    // Encoding resolution
    $resoluton = 100;

    $divider = $max_grid / $resoluton;

    foreach ($data as $k => $v) {
      if (is_array($v)) {
        _yandex_metrics_chart_adjust_resolution($data[$k], $max_grid);
      }
      else {
        if (is_numeric($v)) {
          // Multiply or divide data values to adjust them to the resolution
          $data[$k] = floor($v / $divider);
        }
      }
    }
  }
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
