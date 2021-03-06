<?php
/**
 * @file
 * c4m_content_region.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_region_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_region_node_info() {
  $items = array(
    'region' => array(
      'name' => t('Region'),
      'base' => 'node_content',
      'description' => t('A region provides a page where content related to the Region can be grouped.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function c4m_content_region_weight_features_default_settings() {
  $settings = array();

  $settings['region'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
