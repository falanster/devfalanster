<?php
/**
 * @file
 * Contains the chart display plugin.
 *
 * @author Jimmy Berry ("boombatower", http://drupal.org/user/214218)
 */

/**
 * The plugin that handles the chart style.
 *
 * @ingroup views_style_plugins
 */
class chart_views_plugin_style_chart extends views_plugin_style {
  function option_definition () {
    $options = parent::option_definition();

    $options['type'] = array('default' => 'bhs');
    $options['width'] = array('default' => 600);
    $options['height'] = array('default' => 400);
    $options['color_scheme'] = array('default' => 'default');
    $options['label_append_value'] = array('default' => FALSE);
    $options['data_markers'] = array('default' => FALSE);
    $options['data_markers_number_type'] = array('default' => 'f');
    $options['data_markers_decimal_places'] = array('default' => '2');
    $options['data_markers_placement'] = array('default' => 'lb');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['type'] = array(
      '#type' => 'radios',
      '#title' => t('Type'),
      '#description' => t('Chart type, see <a href="http://code.google.com/apis/chart/">Google Chart API documentation</a>.'),
      '#options' => chart_types(),
      '#required' => TRUE,
      '#default_value' => $this->options['type'],
    );
    $form['width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#description' => t('Chart width in pixels'),
      '#size' => 8,
      '#required' => TRUE,
      '#default_value' => $this->options['width'],
    );
    $form['height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#description' => t('Chart height in pixels'),
      '#size' => 8,
      '#required' => TRUE,
      '#default_value' => $this->options['height'],
    );
    $form['color_scheme'] = array(
      '#type' => 'select',
      '#title' => t('Color scheme'),
      '#description' => t('Color scheme, as defined by hook_chart_color_schemes().'),
      '#options' => drupal_map_assoc(array_keys(chart_color_schemes())),
      '#required' => TRUE,
      '#default_value' => $this->options['color_scheme'],
    );
    $form['label_append_value'] = array(
      '#type' => 'checkbox',
      '#title' => t('Append value to label'),
      '#description' => t('If checked, calculated values will be appended in the chart legend.'),
      '#default_value' => $this->options['label_append_value'],
    );
    $form['data_markers'] = array(
      '#type' => 'checkbox',
      '#title' => t('Append Data Value Markers to the Chart'),
      '#description' => t('If checked, calculated data value markers will be appended to specific points on the chart[Bar, Line, Radar, Scatter]'),
      '#default_value' => $this->options['data_markers'],
      '#id' => 'edit-data-value-markers',
    );
    $form['data_markers_number_type'] = array(
      '#type' => 'select',
      '#dependency' => array(
        'edit-data-value-markers' => array(1),
      ),
      '#title' => t('Select type of Data Marker'),
      '#default_value' => $this->options['data_markers_number_type'],
      '#options' => array(
        'f' => t('Floating point format'),
        'p' => t('Percentage format'),
	      'e' => t('Scientific notation format'),
      ),
      '#description' => t('The number format, for numeric values.'),
    );
    $form['data_markers_decimal_places'] = array(
      '#type' => 'select',
      '#dependency' => array(
        'edit-data-value-markers' => array(1),
      ),
      '#title' => t('Select number of decimal places'),
      '#default_value' => $this->options['data_markers_decimal_places'],
      '#options' => array(
        '0' => t('0'),
        '1' => t('1'),
        '2' => t('2'),
      ),
      '#description' => t('An integer specifying how many decimal places to show'),
    );
    $form['data_markers_placement'] = array(
      '#type' => 'select',
      '#dependency' => array(
        'edit-data-value-markers' => array(1),
      ),
      '#title' => t('Select where the data markers should be placed'),
      '#default_value' => $this->options['data_markers_placement'],
      '#options' => array(
        'lb' => t('Left-Bottom'),
        'lv' => t('Left-Middle'),
        'lt' => t('Left-Top'),
        'hb' => t('Center-Bottom'),
        'hv' => t('Center-Middle'),
        'ht' => t('Center-Top'),
        'rb' => t('Right-Bottom'),
        'rv' => t('Right-Middle'),
        'rt' => t('Right-Top'),
        's' => t('Bar-Relative-Base'),
        'c' => t('Bar-Relative-Center'),
        'e' => t('Bar-Relative-Top'),
      ),
      '#description' => t('Additional placement details describing where to put this marker, in relation to the data point. Bar-Relative markers are applicable only for Bar charts'),
    );
  }

  function render() {
    $charts = array();
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);
    $one = count($sets) == 1;
    $set = 0;
    foreach ($sets as $title => $records) {
      $chart = array(
        '#theme' => 'chart',
        '#chart_id' => drupal_clean_css_identifier($this->view->name . '-' . $this->display->id . '-' . $set++),
        '#type' => $this->options['type'],
        // If only one set then use the view title, otherwise if the set has a
        // title then set it as the chart title.
        '#title' => $one ? $this->view->human_name : $title,
        '#size' => array(
          '#width' => $this->options['width'],
          '#height' => $this->options['height'],
        ),
        '#adjust_resolution' => TRUE,
        '#data' => array(),
        '#labels' => array(),
        '#data_colors' => array(),
        '#shape_markers' => array(),
      );

      foreach ($records as $row_index => $row) {
        foreach ($this->view->field as $key => $field) {
          if (!$field->options['exclude']) {
            $field_value = $field->get_value($row);
            $field_value = isset($field_value[0]['value']) ? $field_value[0]['value'] : 0 ;  // this would be nicer in 1 line.

            $chart['#data'][] = $field_value ;
            $chart['#labels'][] = $field->options['label'] . ($this->options['label_append_value'] ? ': ' . $field_value : ''); // @TODO Provide a way to change format.
            $chart['#data_colors'][] = chart_unique_color($key, $this->options['color_scheme']);
          }
        }
      }

      $series = 0;
      foreach ($this->view->field as $key => $field) {
        if (!$field->options['exclude']) {
          if ($this->options['data_markers']) {
            $chart['#shape_markers'][] = array(
              '#marker_type' => 'N*'.$this->options['data_markers_number_type'].$this->options['data_markers_decimal_places'].'*',
              '#color' => '000000',
              '#series_index' => $series,
              '#opt_which_points' => -1,
              '#size' => 11,
              '#opt_z_order' => '',
              '#opt_placement' => $this->options['data_markers_placement'],
            );
            $series++;
          }
        }
      }

      // Allow modules to alter the chart based on views context.
      drupal_alter('chart_views', $chart, $this->view->name, $this->display->id);

      // Since view expects string output we can't save render array for later.
      $charts[$chart['#chart_id']] = drupal_render($chart);
    }

    return implode($charts);
  }
}
