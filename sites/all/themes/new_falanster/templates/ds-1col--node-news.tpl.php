<main>
   <section class="banner">
     <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_image_news['und'][0]['uri']); print render($field_background)?>');">
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
          </div>
       </div>
     </div>
   </section>
<section class="content negative-margin_top">
  <div class="container-inner">
    <article class="content__text">
      <?php print render($content['body'])?>
        <div id="field-video-youtube"><?php print render($content['field_video_youtube']);?></div>
        <div id="field-audio"><?php print render($content['field_audio']);?></div>
        <div id="field-related-node"><?php print render($content['field_related_node']);?></div>
    </article>
  </div>
</section>
</main>
