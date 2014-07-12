<?php
/**
 * @file
 * menus_top_bottom_second.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_top_bottom_second_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_hor-bottom-menu:admin/structure/menu/manage/menu-hor-bottom-menu
  $menu_links['management_hor-bottom-menu:admin/structure/menu/manage/menu-hor-bottom-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-hor-bottom-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Hor Bottom Menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_hor-bottom-menu:admin/structure/menu/manage/menu-hor-bottom-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: management_menu-hot-pages:admin/structure/menu/manage/menu-hot-pages
  $menu_links['management_menu-hot-pages:admin/structure/menu/manage/menu-hot-pages'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-hot-pages',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Menu hot pages',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_menu-hot-pages:admin/structure/menu/manage/menu-hot-pages',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_:admin/structure/menu',
  );
  // Exported menu link: menu-hor-bottom-menu_--:node/649
  $menu_links['menu-hor-bottom-menu_--:node/649'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/649',
    'router_path' => 'node/%',
    'link_title' => 'Звязацца з намі',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hor-bottom-menu_--:node/649',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-hor-bottom-menu_-:node/1
  $menu_links['menu-hor-bottom-menu_-:node/1'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'О нас',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hor-bottom-menu_-:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-hor-bottom-menu_-:node/143
  $menu_links['menu-hor-bottom-menu_-:node/143'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/143',
    'router_path' => 'node/%',
    'link_title' => 'Пра нас',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hor-bottom-menu_-:node/143',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-hor-bottom-menu_:node/651
  $menu_links['menu-hor-bottom-menu_:node/651'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/651',
    'router_path' => 'node/%',
    'link_title' => 'Контакты',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hor-bottom-menu_:node/651',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-hor-bottom-menu_about-us:node/142
  $menu_links['menu-hor-bottom-menu_about-us:node/142'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/142',
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hor-bottom-menu_about-us:node/142',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-hor-bottom-menu_contact-us:node/650
  $menu_links['menu-hor-bottom-menu_contact-us:node/650'] = array(
    'menu_name' => 'menu-hor-bottom-menu',
    'link_path' => 'node/650',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hor-bottom-menu_contact-us:node/650',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_--:node/649
  $menu_links['menu-hot-pages_--:node/649'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/649',
    'router_path' => 'node/%',
    'link_title' => 'Звязацца з намі',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hot-pages_--:node/649',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_-:node/1
  $menu_links['menu-hot-pages_-:node/1'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'О нас',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hot-pages_-:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_-:node/143
  $menu_links['menu-hot-pages_-:node/143'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/143',
    'router_path' => 'node/%',
    'link_title' => 'Пра нас',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hot-pages_-:node/143',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_-:node/179
  $menu_links['menu-hot-pages_-:node/179'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/179',
    'router_path' => 'node/%',
    'link_title' => 'Внести вклад',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hot-pages_-:node/179',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_-:node/181
  $menu_links['menu-hot-pages_-:node/181'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/181',
    'router_path' => 'node/%',
    'link_title' => 'Зрабі ўнёсак',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hot-pages_-:node/181',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_:node/651
  $menu_links['menu-hot-pages_:node/651'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/651',
    'router_path' => 'node/%',
    'link_title' => 'Контакты',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hot-pages_:node/651',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_about-us:node/142
  $menu_links['menu-hot-pages_about-us:node/142'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/142',
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hot-pages_about-us:node/142',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_contact-us:node/650
  $menu_links['menu-hot-pages_contact-us:node/650'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/650',
    'router_path' => 'node/%',
    'link_title' => 'Contact us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hot-pages_contact-us:node/650',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_faq:node/114
  $menu_links['menu-hot-pages_faq:node/114'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/114',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'be',
      'identifier' => 'menu-hot-pages_faq:node/114',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_faq:node/144
  $menu_links['menu-hot-pages_faq:node/144'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/144',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hot-pages_faq:node/144',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_faq:node/145
  $menu_links['menu-hot-pages_faq:node/145'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/145',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-hot-pages_faq:node/145',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-hot-pages_supported-falanster:node/180
  $menu_links['menu-hot-pages_supported-falanster:node/180'] = array(
    'menu_name' => 'menu-hot-pages',
    'link_path' => 'node/180',
    'router_path' => 'node/%',
    'link_title' => 'Supported Falanster',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-hot-pages_supported-falanster:node/180',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Contact Us');
  t('Contact us');
  t('FAQ');
  t('Hor Bottom Menu');
  t('Menu hot pages');
  t('Supported Falanster');
  t('Внести вклад');
  t('Звязацца з намі');
  t('Зрабі ўнёсак');
  t('Контакты');
  t('О нас');
  t('Пра нас');


  return $menu_links;
}
