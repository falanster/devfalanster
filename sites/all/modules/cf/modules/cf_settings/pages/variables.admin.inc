<?php

/**
 * @file
 * Common Functionality - Settings - Administration Pages.
 */

/**
 * @addtogroup cf_settings
 * @{
 */

/**
 * Display the system variables registry.
 *
 * @param int $variable_type_id
 *   The numeric id of the variable type.
 *
 * @return array
 *   A themed list of registry variables.
 */
function cf_settings_administer_variables($variable_type_id = NULL) {
  global $conf;
  $output = '';

  if ($variable_type_id == NULL) {
    $variable_types = cf_settings_get_variable_types();
    $output .= theme('cf_settings_view_registry', array('variable_types' => $variable_types));
  }
  elseif (is_numeric($variable_type_id)) {
    $variable_type = cf_settings_get_variable_types($variable_type_id);

    drupal_set_title(t("%name Settings Registry", array('%name' => $variable_type->human_name)), PASS_THROUGH);

    $output .= '<div class="description">' . check_plain($variable_type->description) . '</div>';

    $variables = cf_settings_get_registered(array('variable_type' => $variable_type->id), 'id');
    $rows = array();

    foreach ($variables as $variable_id => &$variable) {
      if (isset($rows[$variable->variable_name])) {
        $rows[$variable->variable_name][1] .= ', ' . $variable->module_name;
      }
      else {
        $row = array();
        $row[0] = $variable->variable_name;
        $row[1] = $variable->module_name;

        $rows[$variable->variable_name] = $row;
      }
    }

    asort($rows);

    $header = array(t("Variable Name"), t("Module Names"));
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t("There are no variables of this type registered.")));
  }

  return array('content' => array('#markup' => $output));
}

/**
 * @} End of '@addtogroup cf_settings'.
 */
