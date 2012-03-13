<?php
/**
 * @file
 * datapublic_documents.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function datapublic_documents_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:node/19
  $menu_links['main-menu:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/document_page',
    'router_path' => 'node/%',
    'link_title' => 'Documents',
    'options' => array(
      'attributes' => array(
        'title' => 'Documents',
      ),
      'langcode' => 'en',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node-name/resources_page',
  );
  // Exported menu link: menu-main-menu-mobile-:node/19
  $menu_links['menu-main-menu-mobile-:node/19'] = array(
    'menu_name' => 'menu-main-menu-mobile-',
    'link_path' => 'node-name/document_page',
    'router_path' => 'node/%',
    'link_title' => 'Documents',
    'options' => array(
      'attributes' => array(
        'title' => 'Documents',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node-name/resources_page',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');


  return $menu_links;
}
