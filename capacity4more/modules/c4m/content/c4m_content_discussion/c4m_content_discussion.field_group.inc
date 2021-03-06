<?php
/**
 * @file
 * c4m_content_discussion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_discussion_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_details|node|discussion|full';
  $field_group->group_name = 'group_node_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '8',
    'children' => array(
      0 => 'c4m_related_topic',
      1 => 'c4m_vocab_date',
      2 => 'c4m_vocab_geo',
      3 => 'c4m_vocab_language',
      4 => 'og_vocabulary',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-details field-group-fieldset clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_node_details|node|discussion|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_meta|node|discussion|full';
  $field_group->group_name = 'group_node_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group meta',
    'weight' => '6',
    'children' => array(
      0 => 'c4m_user_picture',
      1 => 'c4m_user_first_and_last_name',
      2 => 'c4m_ds_creation_date',
      3 => 'c4m_ds_type_posted_by',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group meta',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-meta field-group clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_node_meta|node|discussion|full'] = $field_group;

  return $export;
}
