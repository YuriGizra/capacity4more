<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render date on which user became C4M member.
 *
 * @param array $field
 *   The field information.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_member_since(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('member-since'),
    ),
    '#value'     => c4m_helper_date_time_ago($field['entity']->created,
      '<none>', 86400, '>', t('today')),
  );
  return theme_html_tag($tag);
}

/**
 * Render user activity summary.
 *
 * @param array $field
 *   Field information.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_summary(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count_posts = c4m_user_count_nodes($user->uid);

  // Count published comments of user.
  $count_comments = c4m_user_count_comments($user->uid);

  return t(
    'Posted !posts and !comments',
    array(
      '!posts' => format_plural($count_posts, '1 Item', '@count Items'),
      '!comments' => format_plural($count_comments, '1 Comment', '@count Comments'),
    )
  );
}

/**
 * Render count of posts (nodes) for the given user.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_posts(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count = c4m_user_count_nodes($user->uid);
  return format_plural($count, '1 Post', '@count Posts');
}

/**
 * Render count of comments for the given user.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_comments(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count = c4m_user_count_comments($user->uid);
  return format_plural($count, '1 Comment', '@count Comments');
}

/**
 * DS function field.
 *
 * Render ...
 *
 * @param array $field
 *   Field info.
 *
 * @return mixed
 *   Rendered data.
 */
function theme_c4m_user_picture(array $field) {
  if (empty($field['entity']->uid)) {
    return;
  }

  // Check if image needs to be linked to user profile.
  if (FALSE !== strpos($field['formatter'], 'linked_', 0)) {
    $linked = TRUE;
    $style = substr($field['formatter'], 7);
  }
  else {
    $linked = FALSE;
    $style = $field['formatter'];
  }

  // Check if this is a user or node entity.
  $user = 'user' === $field['entity_type'] ? $field['entity'] :
    user_load($field['entity']->uid);

  // Check if we have an image.
  $wrapper = entity_metadata_wrapper('user', $user);
  $file = $wrapper->c4m_media->value();

  if (empty($file)) {
    // If there is no image, we render initials.
    $output = c4m_user_initials_themed($user, $linked);
  }
  else {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path']       = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $output             = l(theme_image_style($file), 'user/' . $user->uid,
      array('html' => 'TRUE'));
  }

  return $output;
}

/**
 * DS function field.
 *
 * Render Author first and last name.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_user_first_and_last_name(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag = array();
  $entity = $field['entity'];

  if ($entity->uid != 0) {
    $user = user_load($entity->uid);
    $name = c4m_user_name($user);

    if ('linked_user' == $field['formatter']) {
      $name = l($name, 'user/' . $user->uid);
    }

    $tag['element'] = array(
      '#tag'       => 'span',
      '#attributes' => array(
        'class' => array('user-name'),
      ),
      '#value'     => $name,
    );
  }
  else {
    if (!empty($entity->name)) {
      $tag['element'] = array(
        '#tag'       => 'span',
        '#attributes' => array(
          'class' => array('user-name', 'anonymous'),
        ),
        '#value'     => $entity->name,
      );
    }
  }

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render ...
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered output.
 */
function theme_c4m_user_country(array $field) {
  if (empty($field['entity']->uid)) {
    return;
  }

  // Check if this is a user or node entity.
  $user = 'user' === $field['entity_type'] ? $field['entity'] :
    user_load($field['entity']->uid);
  $allowed_values = &drupal_static(__FUNCTION__);
  if (empty($allowed_values)) {
    $field = field_info_field('c4m_country');
    $allowed_values = list_allowed_values($field);
  }
  // Check if we have an image.
  $wrapper = entity_metadata_wrapper('user', $user);
  $country = $allowed_values[$wrapper->c4m_country->value()];

  if (empty($country)) {
    return NULL;
  }
  if ('- choose country or region -' !== drupal_strtolower($country)) {
    return NULL;
  }

  // @codingStandardsIgnoreStart
  $value = t(ucwords(drupal_strtolower($country)));
  // @codingStandardsIgnoreEnd

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('country'),
    ),
    '#value'     => $value,
  );
  return theme_html_tag($tag);
}
