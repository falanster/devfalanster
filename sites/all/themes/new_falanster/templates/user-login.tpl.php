<main>
    <section>
      <div class="banner_login_admin_panel">
        <div class="banner__text">
            <p><?php print render($intro_text);?></p>
            <div class="login_admin_panel">
              <?php print drupal_render_children($form)?>
            </div>
          </div>
      </div>
    </section>
</main>
