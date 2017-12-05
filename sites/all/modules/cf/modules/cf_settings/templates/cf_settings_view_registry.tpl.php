<?php
/**
 * @file
 * Default theme implementation for displaying the primary view registry settings page.
 *
 * Available Variables:
 * - $variable_types: An array of variable type objects.
 */
?>
<div class="settings_registry-wrapper">
  <?php foreach ($variable_types as $id => &$variable_type) { ?>
    <h2 class="settings_registry-<?php print(check_plain($variable_type->machine_name)); ?>"><?php print(check_plain($variable_type->human_name)); ?></h2>
    <div class="description">
      <?php print(check_plain($variable_type->description)); ?>
    </div>
    <div class="link">
      <a href="settings_registry/<?php print(check_plain($variable_type->id)); ?>">View registry settings for the <?php print(check_plain($variable_type->human_name)); ?> type.</a>
    </div>
  <?php } ?>
</div>
