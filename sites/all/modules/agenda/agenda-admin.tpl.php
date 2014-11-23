<?php

/**
 * @file
 * Template file for administrative page
 */
?>
<?php if ($table): ?>
  <?php echo $table; ?>
<?php else: ?>
  <p>You have not created any blocks yet.</p>
<?php endif; ?>
<p>&raquo; <?php echo l('Create a new block', 'admin/config/services/agenda/0/configure'); ?>.</p>
