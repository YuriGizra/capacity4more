<?php
/**
 * @file
 * c4m_features_og_manage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_og_manage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
