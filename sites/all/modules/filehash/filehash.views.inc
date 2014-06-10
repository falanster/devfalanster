<?php
/**
 * @file
 *
 * Provide views data and handlers for filehash table.
 */

/**
 * Implements hook_views_data()
 */
function filehash_views_data() {
  $data['filehash']['table']['group']  = t('File');
  $data['filehash']['table']['join'] = array(
    'file_managed' => array(
      'left_field' => 'fid',
      'field' => 'fid',
     ),
  );
  // Use a nice human-readable name for each hash algorithm.
  $algos = array('md5' => 'MD5', 'sha1' => 'SHA-1', 'sha256' => 'SHA-256');
  foreach (filehash_algos() as $algo) {
    $data['filehash'][$algo] = array(
      'title' => t('@algo hash', array('@algo' => $algos[$algo])),
      'help' => t('The @algo hash of the file.', array('@algo' => $algos[$algo])),
      'field' => array(
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }
  return $data;
}
