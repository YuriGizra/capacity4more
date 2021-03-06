<?php
/**
 * @file
 * c4m_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'c4m_user_teaser_list' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_user_teaser_table' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_picture' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_list_global' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_user_teaser_table_global' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'summary' => array(
          'default' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'c4m_user_picture' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
        ),
        'mimemail' => array(
          'c4m_user_teaser_table' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_list' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'c4m_user_teaser_list_global' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'c4m_user_teaser_table_global' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  return $export;
}
