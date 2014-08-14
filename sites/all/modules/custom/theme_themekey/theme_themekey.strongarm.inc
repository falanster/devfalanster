<?php
/**
 * @file
 * theme_themekey.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function theme_themekey_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_attributes';
  $strongarm->value = array(
    'drupal:base_path' => array(
      'description' => 'Drupal: Base path - If Drupal is installed in a subdirectory, the base path will be \'/[subdirectory]/\', otherwise just \'/\'.',
      'page cache' => 1,
    ),
    'drupal:get_q' => array(
      'description' => 'Drupal: $_GET[\'q\'] - Current value of Drupal\'s query parameter "q"',
      'validator' => '',
      'page cache' => 1,
    ),
    'drupal:is_front_page' => array(
      'description' => 'Drupal: Is front page - \'true\' if current page is front page, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'drupal:path' => array(
      'description' => 'Drupal: Drupal path like "node/add/story" or path alias with support for wildcards.<br />
Query parameters are stripped off before the path gets examined. P.e. "node/add/story?destination=node" becomes "node/add/story" first. If you want to access query parameters, have a look at the <strong>system:query_param</strong> property.<br />
Wildcard characters are "#" for numeric parts and "%" for all characters. To match conditions against a certain part, use an identifier with the wildcard. For example "comment/reply/#xyz" matches all paths with "comment/reply" and a numeric third argument. You can then specify conditions for every wildcard argument using the property "drupal:path:wildcard" and the identifier you choose ("xyz" in this example).<br />
These are the possible wildcard replacements for foo/bar/42/test.html:<pre>
foo/bar/42/test.html
foo/bar/42/%
foo/bar/42
foo/bar/%/test.html
foo/bar/%/%
foo/bar/%
foo/bar/#/test.html
foo/bar/#/%
foo/bar/#
foo/bar
foo/%/42/test.html
foo/%/42/%
foo/%/42
foo/%/%/test.html
foo/%/%/%
foo/%/%
foo/%/#/test.html
foo/%/#/%
foo/%/#
foo/%
foo
%/bar/42/test.html
%/bar/42/%
%/bar/42
%/bar/%/test.html
%/bar/%/%
%/bar/%
%/bar/#/test.html
%/bar/#/%
%/bar/#
%/bar
%/%/42/test.html
%/%/42/%
%/%/42
%/%/%/test.html
%/%/%/%
%/%/%
%/%/#/test.html
%/%/#/%
%/%/#
%/%
%
</pre>',
      'validator' => 'themekey_validator_drupal_path',
      'page cache' => 1,
    ),
    'drupal:path:wildcard' => array(
      'description' => 'Wildcard of "drupal:path". See explanation of "drupal:path" for details.',
      'validator' => 'themekey_validator_wildcard',
      'page cache' => 1,
    ),
    'drupal:path_is_admin' => array(
      'description' => 'Drupal: Path is admin - \'true\' if current page\'s path belongs to the admin section, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'locale:language' => array(
      'description' => 'Locale: Language - The code of the current site language, formatted like "en" or "de" or "neutral". See <a href="/ru/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'locale:language_content' => array(
      'description' => 'Locale: Language Content - The code of the current content language, formatted like "en" or "de" or "neutral". See <a href="/ru/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'locale:language_from_browser' => array(
      'description' => 'Locale: Language From Browser - Identify best matching language from the Accept-language HTTP header we got.',
      'validator' => 'themekey_validator_language',
      'page cache' => 0,
    ),
    'node:body_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_summary' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">summary</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:changed' => array(
      'description' => 'Материал: Дата изменения - Дата, когда материал был изменен/обновлен в формате UNIX. Например, "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:changed_date' => array(
      'description' => 'Материал: Дата изменения - Дата, не включающая время, когда материал был изменен/обновлен в формате "2009-12-24".',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:changed_date_time' => array(
      'description' => 'Материал: Дата изменения - Дата, включающая время, когда материал был изменен/обновлен в формате "2009-12-24 18:13:24".',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:created' => array(
      'description' => 'Материал: Дата создания - Дата, когда материал был создан в формате UNIX. Например, "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:created_date' => array(
      'description' => 'Материал: Дата создания - Дата, не включающая время, когда материал был создан в формате "2009-12-24".',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:created_date_time' => array(
      'description' => 'Материал: Дата создания - Дата, включающая время, когда материал был создан в формате "2009-12-24 18:13:24".',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:field_audio_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_audio</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_audio_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_audio</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_audio_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_audio</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_author_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_author</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_author_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_author</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_banner_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_banner</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_banner_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_banner</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_banner_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_banner</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_banner_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_banner</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_banner_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_banner</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_event_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_event_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_f_voc_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_f_voc</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_file_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_file_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_file_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_fivestar_rating' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">rating</em> of the field <em class="placeholder">field_fivestar</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_fivestar_target' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">target</em> of the field <em class="placeholder">field_fivestar</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_gallery_nid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">nid</em> of the field <em class="placeholder">field_gallery</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_news_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_image_news</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_news_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_image_news</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_news_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_image_news</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_news_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_image_news</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_news_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_image_news</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_knowledge_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_knowledge</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_open_tag_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_open_tag</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_preview_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_preview</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_preview_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_preview</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_preview_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_preview</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_preview_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_preview</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_preview_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_preview</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_related_node_nid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">nid</em> of the field <em class="placeholder">field_related_node</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_simplenews_term_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_simplenews_term</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_target_page_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_target_page</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_target_page_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_target_page</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_taxonomy_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_taxonomy</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_url_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_url_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_video_youtube_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_video_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_video_youtube_embed_code' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">embed_code</em> of the field <em class="placeholder">field_video_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_video_youtube_thumbnail_path' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">thumbnail_path</em> of the field <em class="placeholder">field_video_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_video_youtube_video_data' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">video_data</em> of the field <em class="placeholder">field_video_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_video_youtube_video_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">video_url</em> of the field <em class="placeholder">field_video_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:language' => array(
      'description' => 'Node: Language - The code of the selected language of a node (formatted like "en" or "de") or "neutral". See <a href="/ru/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'node:nid' => array(
      'description' => 'Материал: ID - ID материала (nid); может быть обнаружен в URL материала: "node/23" или "node/23/edit" (23 = nid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:promote' => array(
      'description' => 'Материал: Помещен ли на главную - Возможны значения "0" для true и "1" для false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:sticky' => array(
      'description' => 'Материал: Прикреплен - Установлен ли флаг "Закреплять вверху списков" для материала. Возможны значения "0" для true и "1" для false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:title' => array(
      'description' => 'Материал: Заголовок - Заголовок материала.',
      'page cache' => 1,
    ),
    'node:type' => array(
      'description' => 'Node: Type - The machine-readable content type of the node. See <a href="/ru/admin/structure/types">admin/structure/types</a> for your content types (use column "Type"). Drupal default types are "page" and "story".',
      'validator' => 'themekey_validator_node_type',
      'page cache' => 1,
    ),
    'node:uid' => array(
      'description' => 'Node: User ID - The node author\'s user id (uid). The user id can be found in the URL of the user\'s profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/ru/admin/user/user/list">admin/user/user/list</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:vid' => array(
      'description' => 'Node: The version id of a node (vid), mostly for internal use within ThemeKey. In most cases it\'s better to use node:nid within your rule chains.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'path:node_alias' => array(
      'description' => 'Path: Node alias - The path alias assigned to a node.',
      'validator' => '',
      'page cache' => 1,
    ),
    'system:cookie' => array(
      'description' => 'System: Cookie - Every single cookie and its value if present will be formatted like \'COOKIE_NAME=COOKIE_VALUE\'',
      'page cache' => 0,
    ),
    'system:date' => array(
      'description' => 'System: Date - Current time formatted as Y-m-d (example: 2009-12-24)',
      'validator' => 'themekey_validator_date',
      'page cache' => 2,
    ),
    'system:date_time' => array(
      'description' => 'System: Date Time - Current time formatted as Y-m-d H:i:s (example: 2009-12-24 18:30:10)',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 2,
    ),
    'system:day_of_month' => array(
      'description' => 'Система: Число - Текущее число месяца (от 1 до 31)',
      'validator' => 'themekey_validator_day_of_month',
      'page cache' => 2,
    ),
    'system:day_of_week' => array(
      'description' => 'System: Day of Week - Current day of the week formatted as three letters \'Mon\' through \'Sun\'',
      'validator' => 'themekey_validator_day_of_week',
      'page cache' => 2,
    ),
    'system:dummy' => array(
      'description' => 'System: Dummy - Dummy property. Value is always \'dummy\'',
      'page cache' => 1,
    ),
    'system:host' => array(
      'description' => 'System: HTTP_HOST - The hostname/domain of the site without http:// or https://, like "www.drupal.org" or "www.biologis.com"',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 1,
    ),
    'system:http_header' => array(
      'description' => 'Система: HTTP-заголовок - Каждый HTTP-заголовок и его значение (если присутствует) будет отформатировано в виде \'HEADER_NAME=HEADER_VALUE\'',
      'page cache' => 0,
    ),
    'system:https' => array(
      'description' => 'System: \'HTTPS\' - Set to \'true\' value if the script was queried through the HTTPS protocol, otherwise \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'system:month' => array(
      'description' => 'Система: Месяц - Текущий месяц в формате от \'Янв\' до \'Дек\'',
      'validator' => 'themekey_validator_month',
      'page cache' => 2,
    ),
    'system:post' => array(
      'description' => 'System: POST - Every single POST value formatted like \'POST_VARIABLE_NAME=POST_VARIABLE_VALUE\'. Example: form_id=node_form. If the POST value is not a scalar but a complex type like array or object, the resulting string is formatted as \'POST_VARIABLE_NAME\' without a value.',
      'page cache' => 0,
    ),
    'system:query_param' => array(
      'description' => 'System: Query Parameter - Every single query parameter other than \'q\' and its value, if present. Note that values are url decoded. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will cause three entries \'foo=bar\', \'dummy\' and \'filter=tid:27\'. For \'q\', see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:query_string' => array(
      'description' => 'System: Query String - Complete query string except parameter \'q\'. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will result in \'foo=bar&dummy&filter=tid%3A27\'. For \'q\' see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:random' => array(
      'description' => 'System: Random - A random value that could be \'0\' or 1\'.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 0,
    ),
    'system:referer' => array(
      'description' => 'System: \'HTTP_REFERER\' - The address of the page (if any) which referred the user agent to the current page. This is set by the user agent. Not all user agents will set this, and some provide the ability to modify HTTP_REFERER as a feature. In short, it cannot really be trusted.',
      'page cache' => 0,
    ),
    'system:remote_ip' => array(
      'description' => 'System: \'REMOTE_ADDR\' - The IP address from which the user is viewing the current page.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_ip' => array(
      'description' => 'System: \'SERVER_ADDR\' - The IP address of the server under which the current script is executing.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_name' => array(
      'description' => 'System:  \'SERVER_NAME\' - The name of the server host under which the current script is executing. If the script is running on a virtual host, this will be the value defined for that virtual host.',
      'page cache' => 0,
    ),
    'system:server_port' => array(
      'description' => 'System: \'SERVER_PORT\' - The port on the server machine being used by the web server for communication. For default setups, this will be \'80\'; using SSL, for instance, will change this to whatever your defined secure HTTP port is.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'system:session' => array(
      'description' => 'System: Session - Every single session parameter and its value, if a value is present and a simple type (string, integer, boolean). Booleans are represented as integers; \'1\' as TRUE and \'0\' as FALSE.',
      'page cache' => 1,
    ),
    'system:time' => array(
      'description' => 'System: Time - Current time formatted as H:i:s (example: 18:30:10)',
      'validator' => 'themekey_validator_time',
      'page cache' => 2,
    ),
    'system:user_agent' => array(
      'description' => 'System: \'HTTP_USER_AGENT\' - Contents of the User-Agent: header from the current request, if there is one. This is a string denoting the user agent which is accessing the page. A typical example is: Mozilla/4.5 [en] (X11; U; Linux 2.2.9 i586).',
      'page cache' => 0,
    ),
    'system:user_browser' => array(
      'description' => 'Система: Браузер - Информация о браузере пользователя. Возможные значения: \'Blazer [VERSION]\', \'Internet Explorer [VERSION]\', \'Internet Explorer Mobile [VERSION]\', \'Mozilla Firefox [VERSION]\', \'Netscape [VERSION]\', \'Google Chrome [VERSION]\', \'Safari [VERSION]\', \'Galeon [VERSION]\', \'Konqueror [VERSION]\', \'Gecko based\', \'Opera [VERSION]\', \'Lynx [VERSION]\', \'Fennec [VERSION]\', \'Maemo [VERSION]\', \'неизвестно\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_browser_simplified' => array(
      'description' => 'Система: Браузер - Краткая информация о браузере пользователя. Возможные значения: \'Blazer\', \'Internet Explorer\', \'Internet Explorer Mobile\', \'Mozilla Firefox\', \'Netscape\', \'Google Chrome\', \'Safari\', \'Galeon\', \'Konqueror\', \'Gecko based\', \'Opera\', \'Lynx\', \'Fennec\', \'Maemo\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os' => array(
      'description' => 'Система: Операционная система - Информация о браузере пользователя. Возможные значения: \'Windows XP\', \'Windows Vista\', \'Windows 98\', \'Windows 2000\', \'Windows 2003 server\', \'Windows NT\',  \'Windows ME\', \'Windows CE\', \'Windows ME\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'неизвестно\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os_simplified' => array(
      'description' => 'Система: ОС - Краткая информация о браузере пользователя. Возможные значения: \'Windows\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'taxonomy:name' => array(
      'description' => 'Taxonomy: Name - The term name (name) of a taxonomy term without support for translations.',
      'validator' => '',
      'page cache' => 1,
    ),
    'taxonomy:tid' => array(
      'description' => 'Taxonomy: Term - The term id (tid) of a taxonomy term.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'taxonomy:tid_and_childs' => array(
      'description' => 'Taxonomy: Term and its childs - The term id (tid) of a taxonomy term. If set, all child terms of this term will be used too.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'taxonomy:vid' => array(
      'description' => 'Taxonomy: Vocabulary - The vocabulary id (vid) of a taxonomy vocabulary. See <a href="/ru/admin/structure/taxonomy">admin/structure/taxonomy</a> for your vocabularies.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'themekey_ui:author_triggers_theme' => array(
      'description' => 'The property, themekey_ui:author_triggers_theme, could not be selected from the property drop down. You get this static property by activating <a href="/ru/admin/config/user-interface/themekey/settings/ui">Let the user select a theme that will be used to display all content she creates.</a>. Afterwards, you can move the property to any position in the rule chain. When done, it triggers the switch to the theme the author selected in her user profile for own content, a contact form or blog pages.',
      'page cache' => 1,
      'static' => TRUE,
    ),
    'themekey_ui:node_triggers_theme' => array(
      'description' => 'The property, themekey_ui:node_triggers_theme, could not be selected from the property drop-down. You get this static property by activating <a href="/ru/admin/config/user-interface/themekey/settings/ui">Отображать опцию выбора темы оформления при создании/редактировании материала.</a>. Afterwards, you can move the property to any position in the rule chain. When done, it triggers the switch to the theme assigned to the current node using ThemeKey UI.',
      'page cache' => 1,
      'static' => TRUE,
    ),
    'user:hostname' => array(
      'description' => 'User: Hostname - The user hostname property which is the IP address of client machine, adjusted for reverse proxy. Text from Drupal bootstrap.inc:
      If Drupal is behind a reverse proxy, we use the X-Forwarded-For header instead of $_SERVER[\'REMOTE_ADDR\'], which would be the IP address of the proxy server, and not the client\'s.',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 0,
    ),
    'user:language' => array(
      'description' => 'User: Language - The language the user has set in the settings of his profile page.
      Format is the language code (for example "en" for English or "de" for German) that can be found on <a href="/ru/admin/config/regional/language/overview">admin/config/regional/language/overview</a>.',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'user:name' => array(
      'description' => 'User: Name - The username of the user. See <a href="/ru/admin/people/people">admin/people/people</a> for your users.',
      'page cache' => 1,
    ),
    'user:profile_triggers_theme' => array(
      'description' => 'Property user:profile_triggers_theme could not be selected from the property drop down. You get this static property by activating <a href="/ru/admin/config/user-interface/themekey/settings/ui">Добавить опцию темы оформления в пользовательский профиль</a>. Afterwards you can move the property to any position in the rule chain. When done it triggers the switch to the theme assigned to a user profile using ThemeKey User Profile if the current user has selected a theme in her profile.',
      'page cache' => 1,
      'static' => TRUE,
    ),
    'user:role' => array(
      'description' => 'User: Role - Defined user roles (examples: \'anonymous user\', \'authenticated user\')',
      'validator' => 'themekey_validator_role',
      'page cache' => 1,
    ),
    'user:uid' => array(
      'description' => 'User: ID - The id of the user (uid). The user id can be found in the URL of the users profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/ru/admin/people/people">admin/people/people</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'views:human_name' => array(
      'description' => 'Views: Human Name - The (human readable) name of a view',
      'page cache' => 1,
    ),
    'views:machine_name' => array(
      'description' => 'Views: Machine Name - The machine name of a view',
      'page cache' => 1,
    ),
    'views:vid' => array(
      'description' => 'Views: VID - The vid of a view (vid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
  );
  $export['themekey_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_cron_rules_processed';
  $strongarm->value = array();
  $export['themekey_cron_rules_processed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_maps';
  $strongarm->value = array(
    0 => array(
      'src' => 'profile:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_user_profile2theme',
    ),
    1 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_param',
      'callback' => 'themekey_dummy2query_param',
    ),
    2 => array(
      'src' => 'system:dummy',
      'dst' => 'system:cookie',
      'callback' => 'themekey_dummy2cookie',
    ),
    3 => array(
      'src' => 'system:dummy',
      'dst' => 'system:http_header',
      'callback' => 'themekey_dummy2http_header',
    ),
    4 => array(
      'src' => 'system:dummy',
      'dst' => 'system:post',
      'callback' => 'themekey_dummy2post',
    ),
    5 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_string',
      'callback' => 'themekey_dummy2query_string',
    ),
    6 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date_time',
      'callback' => 'themekey_dummy2date_time',
    ),
    7 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date',
      'callback' => 'themekey_dummy2date',
    ),
    8 => array(
      'src' => 'system:dummy',
      'dst' => 'system:month',
      'callback' => 'themekey_dummy2month',
    ),
    9 => array(
      'src' => 'system:dummy',
      'dst' => 'system:time',
      'callback' => 'themekey_dummy2time',
    ),
    10 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_week',
      'callback' => 'themekey_dummy2day_of_week',
    ),
    11 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_month',
      'callback' => 'themekey_dummy2day_of_month',
    ),
    12 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_browser',
      'callback' => 'themekey_dummy2user_browser',
    ),
    13 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_os',
      'callback' => 'themekey_dummy2user_os',
    ),
    14 => array(
      'src' => 'system:user_browser',
      'dst' => 'system:user_browser_simplified',
      'callback' => 'themekey_user_browser2user_browser_simplified',
    ),
    15 => array(
      'src' => 'system:user_os',
      'dst' => 'system:user_os_simplified',
      'callback' => 'themekey_user_os2user_os_simplified',
    ),
    16 => array(
      'src' => 'system:dummy',
      'dst' => 'system:session',
      'callback' => 'themekey_dummy2session',
    ),
    17 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:vid',
      'callback' => 'themekey_taxonomy_tid2vid',
    ),
    18 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:tid_and_childs',
      'callback' => 'themekey_taxonomy_tid2tid_and_parents',
    ),
    19 => array(
      'src' => 'node:nid',
      'dst' => 'taxonomy:tid',
      'callback' => 'themekey_taxonomy_nid2tid',
    ),
    20 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:name',
      'callback' => 'themekey_taxonomy_tid2name',
    ),
    21 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:vid',
      'callback' => 'themekey_views_getq2vid',
    ),
    22 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:machine_name',
      'callback' => 'themekey_views_getq2machine_name',
    ),
    23 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:human_name',
      'callback' => 'themekey_views_getq2human_name',
    ),
    24 => array(
      'src' => 'node:nid',
      'dst' => 'node:changed',
      'callback' => 'themekey_node_nid2changed',
    ),
    25 => array(
      'src' => 'node:nid',
      'dst' => 'node:created',
      'callback' => 'themekey_node_nid2created',
    ),
    26 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    27 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    28 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    29 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    30 => array(
      'src' => 'node:nid',
      'dst' => 'node:language',
      'callback' => 'themekey_node_nid2language',
    ),
    31 => array(
      'src' => 'node:nid',
      'dst' => 'node:vid',
      'callback' => 'themekey_node_nid2vid',
    ),
    32 => array(
      'src' => 'node:nid',
      'dst' => 'node:promote',
      'callback' => 'themekey_node_nid2promote',
    ),
    33 => array(
      'src' => 'node:nid',
      'dst' => 'node:sticky',
      'callback' => 'themekey_node_nid2sticky',
    ),
    34 => array(
      'src' => 'node:nid',
      'dst' => 'node:type',
      'callback' => 'themekey_node_nid2type',
    ),
    35 => array(
      'src' => 'node:nid',
      'dst' => 'node:uid',
      'callback' => 'themekey_node_nid2uid',
    ),
    36 => array(
      'src' => 'node:nid',
      'dst' => 'node:title',
      'callback' => 'themekey_node_nid2title',
    ),
    37 => array(
      'src' => 'drupal:get_q',
      'dst' => 'node:type',
      'callback' => 'themekey_node_get_q2type',
    ),
    38 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    39 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_summary',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'summary',
        'translatable' => '0',
      ),
    ),
    40 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    41 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_simplenews_term_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_simplenews_term',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '1',
      ),
    ),
    42 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_date',
        'type' => 'datetime',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    43 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_f_voc_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_f_voc',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    44 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_event_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_event_date',
        'type' => 'datetime',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    45 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_taxonomy_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_taxonomy',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    46 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_open_tag_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_open_tag',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    47 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_related_node_nid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_related_node',
        'type' => 'node_reference',
        'column' => 'nid',
        'translatable' => '0',
      ),
    ),
    48 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_gallery_nid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_gallery',
        'type' => 'node_reference',
        'column' => 'nid',
        'translatable' => '0',
      ),
    ),
    49 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_author_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_author',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    50 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_author_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_author',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    51 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_fivestar_rating',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_fivestar',
        'type' => 'fivestar',
        'column' => 'rating',
        'translatable' => '0',
      ),
    ),
    52 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_fivestar_target',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_fivestar',
        'type' => 'fivestar',
        'column' => 'target',
        'translatable' => '0',
      ),
    ),
    53 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_knowledge_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_knowledge',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    54 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    55 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    56 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    57 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    58 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    59 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_audio_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_audio',
        'type' => 'file',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    60 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_audio_display',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_audio',
        'type' => 'file',
        'column' => 'display',
        'translatable' => '0',
      ),
    ),
    61 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_audio_description',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_audio',
        'type' => 'file',
        'column' => 'description',
        'translatable' => '0',
      ),
    ),
    62 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_file_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_file',
        'type' => 'file',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    63 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_file_display',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_file',
        'type' => 'file',
        'column' => 'display',
        'translatable' => '0',
      ),
    ),
    64 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_file_description',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_file',
        'type' => 'file',
        'column' => 'description',
        'translatable' => '0',
      ),
    ),
    65 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_preview_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_preview',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    66 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_preview_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_preview',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    67 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_preview_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_preview',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    68 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_preview_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_preview',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    69 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_preview_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_preview',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    70 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_video_youtube_video_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_video_youtube',
        'type' => 'video_embed_field',
        'column' => 'video_url',
        'translatable' => '0',
      ),
    ),
    71 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_video_youtube_thumbnail_path',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_video_youtube',
        'type' => 'video_embed_field',
        'column' => 'thumbnail_path',
        'translatable' => '0',
      ),
    ),
    72 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_video_youtube_video_data',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_video_youtube',
        'type' => 'video_embed_field',
        'column' => 'video_data',
        'translatable' => '0',
      ),
    ),
    73 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_video_youtube_embed_code',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_video_youtube',
        'type' => 'video_embed_field',
        'column' => 'embed_code',
        'translatable' => '0',
      ),
    ),
    74 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_video_youtube_description',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_video_youtube',
        'type' => 'video_embed_field',
        'column' => 'description',
        'translatable' => '0',
      ),
    ),
    75 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_url_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_url',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    76 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_url_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_url',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    77 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_banner_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_banner',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    78 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_banner_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_banner',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    79 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_banner_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_banner',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    80 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_banner_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_banner',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    81 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_banner_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_banner',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    82 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_news_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_news',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    83 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_news_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_news',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    84 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_news_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_news',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    85 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_news_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_news',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    86 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_news_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_news',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    87 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_target_page_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_target_page',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    88 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_target_page_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_target_page',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    89 => array(
      'src' => 'node:nid',
      'dst' => 'path:node_alias',
      'callback' => 'themekey_path_nid2alias',
    ),
    90 => array(
      'src' => 'system:dummy',
      'dst' => 'locale:language_from_browser',
      'callback' => 'themekey_locale_dummy2language_from_browser',
    ),
    91 => array(
      'src' => 'contact:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_contact_uid2theme',
    ),
    92 => array(
      'src' => 'node:nid',
      'dst' => 'themekey_ui:node_triggers_theme',
      'callback' => 'themekey_ui_nid2theme',
    ),
    93 => array(
      'src' => 'node:nid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_ui_node_author2theme',
    ),
    94 => array(
      'src' => 'user:uid',
      'dst' => 'user:profile_triggers_theme',
      'callback' => 'themekey_user_profile_uid2profile_theme',
    ),
  );
  $export['themekey_maps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_modules';
  $strongarm->value = array(
    0 => 'user',
    1 => 'system',
    2 => 'taxonomy',
    3 => 'views',
    4 => 'node',
    5 => 'path',
    6 => 'locale',
    7 => 'contact',
    8 => 'admin_menu',
  );
  $export['themekey_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_paths';
  $strongarm->value = array(
    0 => array(
      'path' => 'node/#/revisions/#/view',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
        3 => 'node:vid',
      ),
      'weight' => 10,
      'fit' => 21,
    ),
    1 => array(
      'path' => 'taxonomy/term/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'taxonomy:tid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    2 => array(
      'path' => 'user/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    3 => array(
      'path' => 'user/#/contact',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'contact:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    4 => array(
      'path' => 'user/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
    5 => array(
      'path' => 'node/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
  );
  $export['themekey_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_properties';
  $strongarm->value = array(
    'drupal:base_path' => 'drupal:base_path',
    'drupal:get_q' => 'drupal:get_q',
    'drupal:is_front_page' => 'drupal:is_front_page',
    'drupal:path' => 'drupal:path',
    'drupal:path:wildcard' => 'drupal:path:wildcard',
    'drupal:path_is_admin' => 'drupal:path_is_admin',
    'locale:language' => 'locale:language',
    'locale:language_content' => 'locale:language_content',
    'locale:language_from_browser' => 'locale:language_from_browser',
    'node:body_format' => 'node:body_format',
    'node:body_summary' => 'node:body_summary',
    'node:body_value' => 'node:body_value',
    'node:changed' => 'node:changed',
    'node:changed_date' => 'node:changed_date',
    'node:changed_date_time' => 'node:changed_date_time',
    'node:created' => 'node:created',
    'node:created_date' => 'node:created_date',
    'node:created_date_time' => 'node:created_date_time',
    'node:field_audio_description' => 'node:field_audio_description',
    'node:field_audio_display' => 'node:field_audio_display',
    'node:field_audio_fid' => 'node:field_audio_fid',
    'node:field_author_format' => 'node:field_author_format',
    'node:field_author_value' => 'node:field_author_value',
    'node:field_banner_alt' => 'node:field_banner_alt',
    'node:field_banner_fid' => 'node:field_banner_fid',
    'node:field_banner_height' => 'node:field_banner_height',
    'node:field_banner_title' => 'node:field_banner_title',
    'node:field_banner_width' => 'node:field_banner_width',
    'node:field_date_value' => 'node:field_date_value',
    'node:field_event_date_value' => 'node:field_event_date_value',
    'node:field_f_voc_tid' => 'node:field_f_voc_tid',
    'node:field_file_description' => 'node:field_file_description',
    'node:field_file_display' => 'node:field_file_display',
    'node:field_file_fid' => 'node:field_file_fid',
    'node:field_fivestar_rating' => 'node:field_fivestar_rating',
    'node:field_fivestar_target' => 'node:field_fivestar_target',
    'node:field_gallery_nid' => 'node:field_gallery_nid',
    'node:field_image_alt' => 'node:field_image_alt',
    'node:field_image_fid' => 'node:field_image_fid',
    'node:field_image_height' => 'node:field_image_height',
    'node:field_image_news_alt' => 'node:field_image_news_alt',
    'node:field_image_news_fid' => 'node:field_image_news_fid',
    'node:field_image_news_height' => 'node:field_image_news_height',
    'node:field_image_news_title' => 'node:field_image_news_title',
    'node:field_image_news_width' => 'node:field_image_news_width',
    'node:field_image_title' => 'node:field_image_title',
    'node:field_image_width' => 'node:field_image_width',
    'node:field_knowledge_tid' => 'node:field_knowledge_tid',
    'node:field_open_tag_tid' => 'node:field_open_tag_tid',
    'node:field_preview_alt' => 'node:field_preview_alt',
    'node:field_preview_fid' => 'node:field_preview_fid',
    'node:field_preview_height' => 'node:field_preview_height',
    'node:field_preview_title' => 'node:field_preview_title',
    'node:field_preview_width' => 'node:field_preview_width',
    'node:field_related_node_nid' => 'node:field_related_node_nid',
    'node:field_simplenews_term_tid' => 'node:field_simplenews_term_tid',
    'node:field_target_page_format' => 'node:field_target_page_format',
    'node:field_target_page_value' => 'node:field_target_page_value',
    'node:field_taxonomy_tid' => 'node:field_taxonomy_tid',
    'node:field_url_format' => 'node:field_url_format',
    'node:field_url_value' => 'node:field_url_value',
    'node:field_video_youtube_description' => 'node:field_video_youtube_description',
    'node:field_video_youtube_embed_code' => 'node:field_video_youtube_embed_code',
    'node:field_video_youtube_thumbnail_path' => 'node:field_video_youtube_thumbnail_path',
    'node:field_video_youtube_video_data' => 'node:field_video_youtube_video_data',
    'node:field_video_youtube_video_url' => 'node:field_video_youtube_video_url',
    'node:language' => 'node:language',
    'node:nid' => 'node:nid',
    'node:promote' => 'node:promote',
    'node:sticky' => 'node:sticky',
    'node:title' => 'node:title',
    'node:type' => 'node:type',
    'node:uid' => 'node:uid',
    'node:vid' => 'node:vid',
    'path:node_alias' => 'path:node_alias',
    'system:cookie' => 'system:cookie',
    'system:date' => 'system:date',
    'system:date_time' => 'system:date_time',
    'system:day_of_month' => 'system:day_of_month',
    'system:day_of_week' => 'system:day_of_week',
    'system:dummy' => 'system:dummy',
    'system:host' => 'system:host',
    'system:http_header' => 'system:http_header',
    'system:https' => 'system:https',
    'system:month' => 'system:month',
    'system:post' => 'system:post',
    'system:query_param' => 'system:query_param',
    'system:query_string' => 'system:query_string',
    'system:random' => 'system:random',
    'system:referer' => 'system:referer',
    'system:remote_ip' => 'system:remote_ip',
    'system:server_ip' => 'system:server_ip',
    'system:server_name' => 'system:server_name',
    'system:server_port' => 'system:server_port',
    'system:session' => 'system:session',
    'system:time' => 'system:time',
    'system:user_agent' => 'system:user_agent',
    'system:user_browser' => 'system:user_browser',
    'system:user_browser_simplified' => 'system:user_browser_simplified',
    'system:user_os' => 'system:user_os',
    'system:user_os_simplified' => 'system:user_os_simplified',
    'taxonomy:name' => 'taxonomy:name',
    'taxonomy:tid' => 'taxonomy:tid',
    'taxonomy:tid_and_childs' => 'taxonomy:tid_and_childs',
    'taxonomy:vid' => 'taxonomy:vid',
    'user:hostname' => 'user:hostname',
    'user:language' => 'user:language',
    'user:name' => 'user:name',
    'user:role' => 'user:role',
    'user:uid' => 'user:uid',
    'views:human_name' => 'views:human_name',
    'views:machine_name' => 'views:machine_name',
    'views:vid' => 'views:vid',
  );
  $export['themekey_properties'] = $strongarm;

  return $export;
}
