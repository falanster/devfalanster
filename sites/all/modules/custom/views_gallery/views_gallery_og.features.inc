<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function views_gallery_og_ctools_plugin_api() {
  module_load_include('inc', 'views_gallery_og', 'views_gallery_og.defaults');
  $args = func_get_args();
  return call_user_func_array('_views_gallery_og_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function views_gallery_og_strongarm() {
  module_load_include('inc', 'views_gallery_og', 'views_gallery_og.defaults');
  $args = func_get_args();
  return call_user_func_array('_views_gallery_og_strongarm', $args);
}
