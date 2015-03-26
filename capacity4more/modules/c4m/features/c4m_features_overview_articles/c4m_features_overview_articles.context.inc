<?php
/**
 * @file
 * c4m_features_overview_articles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_articles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_articles';
  $context->description = 'Overview page of all Voices & Views';
  $context->tag = 'cap4more - Voices & Views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_articles' => 'c4m_overview_articles',
        'c4m_overview_og_members:page' => 'c4m_overview_og_members:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_search_filter-search_filter_interests' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter_interests',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_articles-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_articles-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Voices & Views');
  t('cap4more - Voices & Views');
  $export['c4m_overview_articles'] = $context;

  return $export;
}