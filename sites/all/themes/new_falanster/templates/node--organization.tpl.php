
<main>
    <section class="banner">

      <div class="banner__photo" style="background-image: url('<?php $field_background = file_create_url($node->field_background_picture ['und'][0]['uri']); print render($field_background)?>');">

        <div class="banner__text">
          <h1 class="banner__heading"><?php print($title)?></h1>
        </div>

        <button class="banner__btn-scroll btn-scroll" type="button">Далей</button>
      </div>
    </section>

    <section class="content negative-margin_top">
      <div class="container-inner">
        <article class="content__text">
  <?php print render($content['body'])?>
        </article>
      </div>
    </section>
  </main>
