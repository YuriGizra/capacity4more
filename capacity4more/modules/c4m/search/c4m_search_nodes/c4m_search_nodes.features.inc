<?php
/**
 * @file
 * c4m_search_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_search_nodes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_search_nodes_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
