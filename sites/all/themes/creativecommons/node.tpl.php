<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
 
<?php echo "123"; //print $user_picture; ?>
 
   <?php print render($title_prefix); ?>
   <?php if (!$page): ?>
     <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
   <?php endif; ?>
   <?php print render($title_suffix); ?>
 
   <?php if ($display_submitted): ?>
     <div class="submitted">
       <?php print $submitted; ?>
     </div>
   <?php endif; ?>
 
   <div class="content"<?php print $content_attributes; ?>>
    <?php
       // We hide the comments and links now so that we can render them later.
       hide($content['comments']);
       hide($content['taxonomy']);
       hide($content['field_tags']);       
       hide($content['field_f_voc']);
       hide($content['field_open_tag']);
       hide($content['field_related_node']);
       print render($content);
     ?>
   </div>
 
   <?php //print render($content['links']); ?>
 
   <?php echo "456"; //print render($content['comments']); ?>
 
</div>

