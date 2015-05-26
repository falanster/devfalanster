<?php
/**
 * @file
 * content_type_static_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_static_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-static_pages-body'
  $field_instances['node-static_pages-body'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_audio'
  $field_instances['node-static_pages-field_audio'] = array(
    'bundle' => 'static_pages',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'mediaelement',
        'settings' => array(
          'controls' => 1,
          'download_link' => 0,
          'download_text' => 'Download',
          'height' => 30,
          'width' => 300,
        ),
        'type' => 'mediaelement_audio',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'mediaelement',
        'settings' => array(
          'controls' => 1,
          'download_link' => 0,
          'download_text' => 'Download',
          'height' => 30,
          'width' => 300,
        ),
        'type' => 'mediaelement_audio',
        'weight' => 2,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'mediaelement',
        'settings' => array(
          'controls' => 1,
          'download_link' => 0,
          'download_text' => 'Download',
          'height' => 30,
          'width' => 300,
        ),
        'type' => 'mediaelement_audio',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_audio',
    'label' => 'Audio',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'audio',
      'file_extensions' => 'mp3',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'imce' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'copy',
            'path' => 'file_attach',
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__news_afisha_thumb' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__test' => 0,
          'colorbox__thumbnail' => 0,
          'image' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_news_afisha_thumb' => 0,
          'image_square_thumbnail' => 0,
          'image_test' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_f_voc'
  $field_instances['node-static_pages-field_f_voc'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 8,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_f_voc',
    'label' => 'Falanster_Vocabulary',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_file'
  $field_instances['node-static_pages-field_file'] = array(
    'bundle' => 'static_pages',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file',
    'label' => 'File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'store',
      'file_extensions' => 'txt doc docx pdf ppt pptx xsl zip gz rar png jpg jpeg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'imce' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'copy',
            'path' => '',
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => 'link',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__afishi' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__news_afisha_size' => 0,
          'colorbox__news_afisha_thumb' => 0,
          'colorbox__news_square' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__video_podcast_preview' => 0,
          'colorbox__video_preview_eng' => 0,
          'image' => 0,
          'image_afishi' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_news_afisha_size' => 0,
          'image_news_afisha_thumb' => 0,
          'image_news_square' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_video_podcast_preview' => 0,
          'image_video_preview_eng' => 0,
          'link' => 'link',
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_gallery'
  $field_instances['node-static_pages-field_gallery'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gallery',
    'label' => 'Gallery',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_image'
  $field_instances['node-static_pages-field_image'] = array(
    'bundle' => 'static_pages',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_node_style' => '',
        ),
        'type' => 'colorbox',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Малюнак',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 1290,
      'file_directory' => 'page/[current-date:for_news_afisha]',
      'file_extensions' => 'png gif jpg jpeg',
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'copy',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__afishi' => 0,
          'colorbox__internal_view_square' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__news_afisha_size' => 0,
          'colorbox__news_afisha_thumb' => 0,
          'colorbox__news_square' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__video_podcast_preview' => 0,
          'colorbox__video_preview_eng' => 0,
          'colorbox__watermark' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_afishi' => 0,
          'image_internal_view_square' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_news_afisha_size' => 0,
          'image_news_afisha_thumb' => 0,
          'image_news_square' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_video_podcast_preview' => 0,
          'image_video_preview_eng' => 0,
          'image_watermark' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_open_tag'
  $field_instances['node-static_pages-field_open_tag'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'in_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_open_tag',
    'label' => 'Open tag',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_preview'
  $field_instances['node-static_pages-field_preview'] = array(
    'bundle' => 'static_pages',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_node_style' => '',
        ),
        'type' => 'colorbox',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_preview',
    'label' => 'Preview',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'page/preview',
      'file_extensions' => 'png gif jpg jpeg',
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'imce' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'copy',
            'path' => 'file_attach',
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__afishi' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__news_afisha_thumb' => 0,
          'colorbox__news_square' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__video_podcast_preview' => 0,
          'colorbox__video_preview_eng' => 0,
          'image' => 0,
          'image_afishi' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_news_afisha_thumb' => 0,
          'image_news_square' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_video_podcast_preview' => 0,
          'image_video_preview_eng' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_related_node'
  $field_instances['node-static_pages-field_related_node'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 5,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related_node',
    'label' => 'Important Info',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_target_page'
  $field_instances['node-static_pages-field_target_page'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'in_page' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_target_page',
    'label' => 'Мэтавая старонка',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-static_pages-field_video_youtube'
  $field_instances['node-static_pages-field_video_youtube'] = array(
    'bundle' => 'static_pages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'contact_us' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 3,
      ),
      'in_page' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'image_style' => 'none',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field_thumbnail_colorbox',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video_youtube',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'description_length' => 128,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audio');
  t('Body');
  t('Falanster_Vocabulary');
  t('File');
  t('Gallery');
  t('Important Info');
  t('Open tag');
  t('Preview');
  t('Video');
  t('Малюнак');
  t('Мэтавая старонка');

  return $field_instances;
}
