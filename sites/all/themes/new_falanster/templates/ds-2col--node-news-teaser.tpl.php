<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">

  <section class="banner">
    <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_preview['und'][0]['uri']); print render($field_background)?>');">
      <div class="banner__container container-inner">
        <div class="banner__text">
          <h1 class="banner__heading"><a href="<?php $castom_url = drupal_get_path_alias($node->disqus['url']); print render($castom_url);?>"><?php print($title)?></a></h1>
          <p class="banner__info">
            <span class="banner__date">
              <?php print($date)?>
            </span>
            <span class="banner__author">
              <?php print($name)?>
            </span>
          </p>
           <p>
             <?php print render($content['field_open_tag']);?>
           </p>
         </div>
      </div>
    </div>
  </section>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </<?php print $right_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
