
<main>
   <section class="banner">

     <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_background_picture_event['und'][0]['uri']); print render($field_background)?>');">


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

         <?php

        $my_field_items = field_get_items('node', $node, 'field_display_the_field');
        $display_the_field = $my_field_items[0]['value'];

        if ($display_the_field == 1) {
            echo '<p class="banner__date-block">';
            $field_field_date = field_get_items('node', $node, 'field_field_date');
            $fied_data_event_rest = $field_field_date[0]['value'];
            $time = mb_substr($fied_data_event_rest, 11, 5);
            $year = substr($fied_data_event_rest, 0, 4);
            $month = substr($fied_data_event_rest, 5, 2);
            $day = substr($fied_data_event_rest, 8, 2);
            print_r($day .".".$month .".". $year. ", " . $time);
          
            echo '</p>';

        }

      ?>
</div>
     </div>
   </section>

   <section class="content negative-margin_top">
     <div class="container-inner">
       <article class="content__text">
           <?php print render($content['body'])?>
         <img src="<?php $field_background = file_create_url($node->field_picture_epilog ['und'][0]['uri']); print render($field_background)?>" alt="" width="778" height="438">
       </article>
       <a class="content__btn" href="https://falanster.by/be/volunteers">Стань валанцёрам!</a>
     </div>
   </section>
 </main>
