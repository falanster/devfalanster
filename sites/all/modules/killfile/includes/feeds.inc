<?php

/**
 * Outputs an RSS 1.0-compatible RDF feed containing one RSS item for each killfiled node on the site.
 * Each RSS item contains additional killfile metadata using the 'killfile:' namespace.
 *
 * @fixme: the rdf+rss is generated manually due my time constraints.
 *         I have not been able to determine how to properly use existing drupal functions to do exactly this.
 *         Any assistance is welcome on rdf+rss feeds.
 *         Also take note of the functions from killfile.module: killfile_rdf_namespaces() and killfile_rdf_mapping().
 */
function killfile_feed_page() {
  global $base_url, $language;

  $channel_title = t("Killfile for @site", array('@site' => variable_get('site_name', 'Drupal')));
  $channel_link = $base_url . '/';
  $channel_description = t("This feed contains an index of recently killfiled content at this site.");
  $channel_items = array();

  $killfile_namespaces = killfile_rdf_namespaces();
  $rss_url = url(KILLFILE_FEED_PATH, array('absolute' => TRUE));

  $nodes = killfile_get_killfiled_nodes();
  $index = array();
  $items = array();

  if (is_array($nodes)){
    foreach ($nodes as $key => $item){
      $url  = url('node/'. $item->nid, array('absolute' => TRUE, 'alias' => TRUE));
      $link = url('node/'. $item->nid, array('absolute' => TRUE));

      $index[] = $url;

      $user = user_load($item->uid);
      $user_link = url('user/' . $user->name, array('absolute' => TRUE));
      $formatted_date = format_date($item->timestamp, 'custom', 'c');

      $items[$url] = array(
        'rdf:type' => 'rss:item',
        'rss:title' => $item->title,
        'rss:link' => $link,
        'killfile:user' => $user_link,
        'killfile:date' => $formatted_date,
        'killfile:log' => empty($item->log) ? '' : $item->log,
      );
    }
  }

  $output  = '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
  $output .= '<rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns:rss="http://purl.org/rss/1.0/" xmlns:killfile="' . KILLFILE_NAMESPACE . '">' . "\n";
  $output .= '  <rss:channel rdf:about="' . $rss_url . '">' . "\n";
  $output .= '    <rss:title xml:lang="' . $language->language . '">' . $channel_title . '</rss:title>' . "\n";
  $output .= '    <rss:link>' . $channel_link . '</rss:link>' . "\n";
  $output .= '    <rss:description xml:lang="' . $language->language . '">' . $channel_description . '</rss:description>' . "\n";
  $output .= '    <rss:items rdf:nodeID="b1"/>' . "\n";
  $output .= '  </rss:channel>' . "\n";
  $output .= '  <rdf:Seq rdf:nodeID="b1">' . "\n";

  foreach ($index as $link){
    $output .= '    <rdf:li>' . $link . '</rdf:li>' . "\n";
  }

  $output .= '  </rdf:Seq>' . "\n";

  foreach ($items as $url => $item){
    $output .= '  <rss:item rdf:about="' . $url. '">' . "\n";

    foreach ($item as $key => $value){
      switch($key){
        case 'rdf:type':
          break;
        case 'killfile:date':
          $output .= '    <' . $key . ' rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">' . $value . '</' . $key . '>' . "\n";
          break;
        default:
          $output .= '    <' . $key . '>' . $value . '</' . $key . '>' . "\n";
          break;
      }
    }
    $output .= '  </rss:item>' . "\n";
  }

  $output .= '</rdf:RDF>' . "\n";

  drupal_add_http_header('Content-Type', 'application/rdf+xml; charset=utf-8');
  drupal_add_http_header('Content-Length', strlen($output));

  print($output);
}
