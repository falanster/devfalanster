
<main>
   <section class="banner">
     <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_preview['und'][0]['uri']); print render($field_background)?>');">
       <div class="banner__container container-inner">
         <div class="banner__text">
           <h1 class="banner__heading"><?php print($title)?></h1>
           <p class="banner__info">
             <span class="banner__date">
               <?php print($date)?>
             </span>
             <span class="banner__author">
               <?php print($name)?>
             </span>
           </p>
            <p><?php print render($content['field_open_tag']);?>
           </p>
         </div>
       </div>
     </div>
   </section>

<section class="content negative-margin_top">
  <div class="container-inner">
    <article class="content__text">
      <?php print render($content['body'])?>
      <div>
        <?php
        print render($content['field_image_news']);
        print render($content['field_video_youtube']);
        print render($content['field_gallery']);
        print render($content['field_related_node']);
        print render($content['field_audio']);
        ?>
      </div>
    </article>
  </div>
</section>
</main>
