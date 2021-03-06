<?php
/**
 * Override blocks.
 *
 * @param array $data
 *   The render array.
 * @param stdClass $block
 *   The block information for who the block is being displayed.
 */
function _c4m_features_og_events_landing_block_view_alter(&$data, $block) {
  $info = array(
    'Facet API: Search service: Search Nodes : Date » End date' => 'Date ranges facet',
  );
  if (!empty($block->info) &&
      array_key_exists($block->info, $info)) {
    $block_title = '';
    switch ($info[$block->info]) {
      case 'Date ranges facet':
        // Remove block title and add link to current page.
        $block_title = '';
        // Make sure 'upcoming' comes before past.
        if (FALSE !== strpos($data['content']['c4m_datetime_end:value2']['#items'][0]['data'], 'past-events')) {
          // Move 'past' to the end of the list of items.
          $data['content']['c4m_datetime_end:value2']['#items'][] =
            array_shift($data['content']['c4m_datetime_end:value2']['#items']);
        }
        // Add link to Overview
        $item['class'] = 'leaf';
        $item['data'] = l(t('Overview'), 'calendar');
        if ($data['content']['c4m_datetime_end:value2']['#items']) {
          array_unshift($data['content']['c4m_datetime_end:value2']['#items'], $item);
        }
        break;
    }
    $data['subject'] = $block_title;
  }
}

/**
 * The links to event views.
 *
 * @return array
 */
function _c4m_features_og_events_block_event_views_links() {
  $group = c4m_og_current_group();
  if (!$group) {
    return;
  }

  // Link to the general overview page.
  $items[] = array(
    'data' => l(t('Overview'), 'calendar'),
    'class' => array('leaf'),
  );

  // Links to the upcoming and past events page.
  $pages = array(
    'upcoming' => array(
      'text' => t('Upcoming'),
      'date_range_operator' => '>=',
    ),
    'past' => array(
      'text' => t('Past'),
      'date_range_operator' => '<',
    ),
  );

  foreach ($pages as $key => $page) {
    $search_filters = array(
      '0' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'status',
          'value' => 1,
          'operator' => '=',
        ),
      ),
      '1' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'og_group_ref',
          'value' => $group->nid,
          'operator' => '=',
        ),
      ),
      '2' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'type',
          'value' => 'event',
          'operator' => '=',
        ),
      ),
      '3' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'c4m_datetime_end:value2',
          'value' => time(),
          'operator' => $page['date_range_operator'],
        ),
      ),
    );

    // Execute search to retrieve counts only, so we set number of rows we
    // to be returned to 0.
    $search_options = array(
      '0' => array(
        'name' => 'limit',
        'value' => 0,
      )
    );
    $result = c4m_search_custom_search($search_filters, $search_options);

    $link_options = array('query' => drupal_get_query_parameters());

    $count = ' (' . $result['result count'] . ')';
    $items[] = array(
      'data' => l($page['text'] . $count, 'calendar/' . $key, $link_options),
      'class' => array('leaf'),
    );
  }

  $list = theme_item_list(
    array(
    'title' => NULL,
    'type' => 'ul',
    'items' => $items,
    'attributes' => array('class' => array('event-views-links')),
    )
  );
  return array(
    'subject' => '',
    'content' => $list,
  );
}
