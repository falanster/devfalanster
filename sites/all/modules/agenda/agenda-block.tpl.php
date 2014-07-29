<?php

/**
 * @file
 * Template for displaying the agenda in a block
 */

// Build some neat dates.
$dates[date('Y-m-d', mktime(0, 0, 0, date("m"), date("d") - 1))] = t('Yesterday');
$dates[date('Y-m-d', mktime(0, 0, 0))] = t('Today');
$dates[date('Y-m-d', mktime(0, 0, 0, date("m"), date("d") + 1))] = t('Tomorrow');

// List of keys to display.
$keys    = array_map('trim', explode(',', $block->display_keys));
$nolabel = array_map('trim', explode(',', $block->hide_labels));
?>
<div class="agenda-block">
  <?php foreach ($events as $day): ?>
  <?php
  $date = $day[0]['start date'];

$timestamp_date = strtotime($date);
$true_date = format_date($timestamp_date, $type = 'medium', $format = $block->dateformat);

  // Substitute today/yesterday/tomorrow.
  if (isset($dates[$day[0]['when']])) {
//    $date = $dates[$day[0]['when']];
    $true_date = $dates[$day[0]['when']];
  }
  ?>
<?php //echo $date; ?>
<p><?php echo $true_date;  ?></p>
  <ol>
  <?php foreach ($day as $event): ?>
    <li class="cal_<?php echo $event['index']; ?>">
      <span class="calendar_title"><?php echo $event['title']; ?></span>
      <ul class="moreinfo">

        <?php foreach ($keys as $key): ?>
          <?php if (!empty($event[$key])): ?>
            <li>
            <?php if (!in_array($key, $nolabel)): ?>
              <em><?php echo _agenda_translate($key); ?></em>:
            <?php endif; ?>
            <?php echo $event[$key]; ?>
            </li>
          <?php endif; ?>
        <?php endforeach; ?>

      </ul>
    </li>
  <?php endforeach; ?>
  </ol>
<?php endforeach; ?>
</div>
