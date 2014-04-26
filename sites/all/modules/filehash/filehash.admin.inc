<?php

/**
 * @file
 * File hash configuration.
 */

/**
 * Builds the file hash settings form.
 */
function filehash_settings() {
  $form['filehash_algos'] = array(
    '#default_value' => variable_get('filehash_algos', array()),
    '#description' => t('The checked hash algorithm(s) will be calculated when a file is saved. For optimum performance, only enable the hash algorithm(s) you need.'),
    '#options' => array('md5' => t('MD5'), 'sha1' => t('SHA-1'), 'sha256' => t('SHA-256')),
    '#title' => t('Enabled hash algorithms'),
    '#type' => 'checkboxes',
  );
  return system_settings_form($form);
}
