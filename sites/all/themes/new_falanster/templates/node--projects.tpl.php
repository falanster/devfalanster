<main>
    <section class="banner">
      <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_background_projects['und'][0]['uri']); print render($field_background)?>');">
        <div class="banner__container container-inner">
          <div class="banner__text">
            <h1 class="banner__heading"><?php print($title)?></h1>
          </div>
          <button class="banner__btn-scroll btn-scroll" type="button">Далей</button>
          <p class="banner__status banner__status--process">
            <?php
                $my_field_items = field_get_items('node', $node, 'field_current_project');
                $display_the_field = $my_field_items[0]['value'];
                  if ($display_the_field == 1) {
                    print_r('Бягучы');
                    echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/process.svg">
                    </span>';
                  }
                $field_hot_project = field_get_items('node', $node, 'field_hot_project');
                $display_hot_project = $field_hot_project[0]['value'];
                  if ($display_hot_project == 1) {
                    print_r('Гарачы');
                    echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/hot_project.svg">
                    </span>';
                  }
                $field_completed_projects = field_get_items('node', $node, 'field_completed_projects');
                $display_completed_projects = $field_completed_projects[0]['value'];
                  if ($display_completed_projects == 1) {
                    print_r('Скончаны');
                    echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/finished.svg">
                    </span>';
                }
                $field_stopped_projects = field_get_items('node', $node, 'field_stopped_projects');
                $display_stopped_projects = $field_stopped_projects[0]['value'];
                  if ($display_stopped_projects == 1) {
                    print_r('Спынены');
                    echo '<span class="banner__status-icon" style="content: url(/devfalanster/sites/all/themes/new_falanster/stop.svg">
                    </span>';
                  }
            ?>
          </p>
        </div>
      </div>
    </section>

    <section class="content negative-margin_top">
      <div class="container-inner">
        <article class="content__text">
          <?php
              print render($content['body']);
              $field_print_the_results = field_get_items('node', $node, 'field_print_the_results');
              $display_print_the_results = $field_print_the_results[0]['value'];
                if ($display_print_the_results == 1) {
                         echo'<footer class="content__summary"><h4>Вынiкi праекта</h4>';
                         print render($content['field_project_results']);
                         echo'</footer>';
                       }
          ?>
        </article>
      </div>
    </section>
  </main>