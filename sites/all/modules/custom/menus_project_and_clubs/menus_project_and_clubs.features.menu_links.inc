<?php
/**
 * @file
 * menus_project_and_clubs.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_project_and_clubs_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu
  $menu_links['management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-mobile-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Mobile Menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'management_mobile-menu:admin/structure/menu/manage/menu-mobile-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: menu-mobile-menu_-:baza_vedau
  $menu_links['menu-mobile-menu_-:baza_vedau'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'baza_vedau',
    'router_path' => 'baza_vedau',
    'link_title' => 'База знаний',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_-:baza_vedau',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -30,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:afishy
  $menu_links['menu-mobile-menu_:afishy'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'afishy',
    'router_path' => 'afishy',
    'link_title' => 'Афиши',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:afishy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:cluby
  $menu_links['menu-mobile-menu_:cluby'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'cluby',
    'router_path' => 'cluby',
    'link_title' => 'Клубы',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:cluby',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:gallery
  $menu_links['menu-mobile-menu_:gallery'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'gallery',
    'router_path' => 'gallery',
    'link_title' => 'Галерея',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:gallery',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -33,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:news
  $menu_links['menu-mobile-menu_:news'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'Новости',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:news',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:node/147
  $menu_links['menu-mobile-menu_:node/147'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'node/147',
    'router_path' => 'node/%',
    'link_title' => 'Контакты',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:node/147',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_:proekty
  $menu_links['menu-mobile-menu_:proekty'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'proekty',
    'router_path' => 'proekty',
    'link_title' => 'Проекты',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'ru',
      'identifier' => 'menu-mobile-menu_:proekty',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-menu_news--announce:news_anounce
  $menu_links['menu-mobile-menu_news--announce:news_anounce'] = array(
    'menu_name' => 'menu-mobile-menu',
    'link_path' => 'news_anounce',
    'router_path' => 'news_anounce',
    'link_title' => 'News & Announce',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'langcode' => 'en',
      'identifier' => 'menu-mobile-menu_news--announce:news_anounce',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Mobile Menu');
  t('News & Announce');
  t('Афиши');
  t('База знаний');
  t('Галерея');
  t('Клубы');
  t('Контакты');
  t('Новости');
  t('Проекты');


  return $menu_links;
}
