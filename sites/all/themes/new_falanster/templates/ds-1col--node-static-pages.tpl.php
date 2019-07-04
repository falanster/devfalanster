<main>
    <section class="banner">
      <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_preview['und'][0]['uri']); print render($field_background)?>');">
        <div class="banner__container container-inner">
          <div class="banner__text">
            <h1 class="banner__heading"><?php print($title)?></h1>
          </div>
          <button class="banner__btn-scroll btn-scroll" type="button">Далей</button>
          <?php
            $field_print_the_results = field_get_items('node', $node, 'field_status_display');
            $display_print_the_results = $field_print_the_results[0]['value'];
            if($display_print_the_results=='Спынены'){
              echo'<p class="banner__status banner__status--process">';
              print_r($display_print_the_results);
              echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/stop.svg">
              </span></p>';
              }else if($display_print_the_results=='Скончаны'){
                echo'<p class="banner__status banner__status--process">';
                print_r($display_print_the_results);
                echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/finished.svg">
                </span></p>';
                  }else if($display_print_the_results=='Гарачы'){
                    echo'<p class="banner__status banner__status--process">';
                    print_r($display_print_the_results);
                    echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/hot_project.svg">
                    </span></p>';
                      }else if($display_print_the_results=='Бягучы'){
                        echo'<p class="banner__status banner__status--process">';
                        print_r($display_print_the_results);
                        echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/process.svg">
                        </span></p>';}?>
            </div>
        </div>
      </section>

    <section class="content negative-margin_top">
      <div class="container-inner">
        <article class="content__text">
          <?php print render($content['body']);?>
          <div id="field_video_youtube">
            <?php print render($content['field_video_youtube']);?>
          </div>
          <div id="field_audio">
            <?php print render($content['field_audio']);?>
          </div>
          <div id="field_file">
            <?php print render($content['field_file']);?>
          </div>
          <?php   $field_print_the_results = field_get_items('node', $node, 'field_print_the_results');
            $display_print_the_results = $field_print_the_results[0]['value'];
                if ($display_print_the_results == 1) {
                         echo'<footer class="content__summary"><h4>Вынiкi праекта</h4>';
                         print render($content['field_project_results']);
                         echo'</footer>';
                       }
              ?>
            <div id="field_related_node">
              <?php print render($content['field_related_node']);?>
            </div>
            <div id="field_image">
              <?php print render($content['field_image']);?>
            </div>
          </article>
      </div>
    </section>
  </main>
