<?php
/*
 * 
 * @file 
 * 
 * Allows to execute the updatescript processing via drush.
 * 
 */


/*
 * Shows drush commands to drush.
 * @return array	An array which contains informations about the drush command items.
 * Implememts hook_drush_command
 */
function ftools_drush_command() {
  $items = array();

  $items['ftools-exec-unlink'] = array(
    'description' => "Execute a unlink file.",
    'arguments' => array(
      'feature' => 'A space delimited list of unlink file to execute',
    ),
    'drupal dependencies' => array('ftools'),
    'aliases' => array('feu'),
  );
  $items['ftools-exec-unlink-all'] = array(
    'description' => "Execute all available unlink files.",
    'arguments' => array(
      'feature_exclude' => 'A space-delimited list of unlink files to exclude from being executed.',
    ),
    'drupal dependencies' => array('ftools'),
    'aliases' => array('feua', 'feu-all'),
  );

  return $items;
}

/*
 * Help Information for drush commands
 * @param string $section 	Specifies the help document section.
 */
function ftools_drush_help($section) {
  
  switch ($section) {
    case 'drush:ftools-exec-unlink':
      return "Execute the ftools unlink files given as argument white space separated";
      break;
    case 'drush:ftools-exec-unlink-all':
      return "Execute all ftools unlink files except the files given as argument separated by spaces";
      break;
  }
  
  return;
}

/**
 * Execute a unlink file
 * Optionally accept a list of unlink files to execute, separated by whitespaces.
 */
function drush_ftools_exec_unlink() {
  if ($args = func_get_args()) {
    _ftools_drush_exec_unlink_file($args);
  } else {
    _ftools_drush_unlink_files();  //list files
  }
    
}

/**
 * Execute all unlink files add so revert the file to their definitions in code.
 *
 * @param ...
 *   (Optional) A list of unlink files to exclude from being executed.
 */
function drush_ftools_exec_unlink_all() {
  
  module_load_include('inc', 'features', 'features.export');
  $files_to_exclude = func_get_args();

  //prepare arguments with respect to excluded unlink files
  $available_files = _ftools_get_unlink_files();
  $args = array();
  //does this file exist?
  $basename = false;
  foreach ($available_files as $available_file) {
    $exclude = false;
    foreach ($files_to_exclude as $exclude_file) {
      if ($available_file->filename == $exclude_file || $available_file->name == $exclude_file) {
        $exclude = true;
      }
    }
    
    if (!$exclude) {
      $args[] = $available_file->filename;
    }
  }

  drush_invoke('ftools-exec-unlink', $args);
}

/**
* Executes a given unlink file
*/
function _ftools_drush_exec_unlink_file($args) {
  module_load_include('module', 'ftools', 'ftools');

  // Determine if -y was supplied. If so, we can filter out needless output
  // from this command.
  $skip_confirmation = drush_get_context('DRUSH_AFFIRMATIVE');

  // Parse list of arguments.
  $files = array();
  foreach ($args as $arg) {
    $files[] = $arg;
  }

  // Process files.
  $available_files = _ftools_get_unlink_files();
  foreach ($files as $delta => $file) {
    
    //does this file exist?
    $basename = false;
    foreach ($available_files as $available_file) {
      if ($available_file->filename == $file || $available_file->name == $file) {
        $file_url = $available_file->uri;
        $basename = basename($file_url, '.inc');
        break;
      }
    }

    $dt_args['@file'] = $file;
    if (!$basename) {
      drush_log(dt('File @file does not exists. Skipped execution.', $dt_args), 'error');
      continue;
    }
    
    $confirmation_message = 'Do you really want to execute the unlink file for @file?';
    if ($skip_confirmation || drush_confirm(dt($confirmation_message, $dt_args))) {
      //if the file ends with .inc we remove this
      $base_name = basename($file, '.inc');
      //Execute the unlink
      _ftools_exec_unlink($base_name);
      drush_log(dt('Executed unlink file for @file.', $dt_args), 'ok');
    }
    else {
      drush_log(dt('Skipping @file.', $dt_args), 'ok');
    }
    
  }
}

/**
* List all available unlink files
*/
function _ftools_drush_unlink_files() {
  $rows = array(array(dt('Name')));
  
  $files = _ftools_get_unlink_files();

  foreach ($files as $file) {
    $rows[] = array(
      $file->name,
    );
  }
  drush_print_table($rows, TRUE);
}