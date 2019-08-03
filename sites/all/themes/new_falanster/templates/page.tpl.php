
		<div class="header__menu container">
			<!-- Prints logo start -->
			<?php if ($logo): ?>
						<a class="header__logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
						<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
						</a>
			<?php endif; ?>
			<!-- Prints logo end -->
			<?php print render($page['header']); ?>	    <!--Top menu-->
		</div>
		<!-- Menu main start-->
		<div class="header__nav">
			<div class="header__nav-items  container">
			<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('header__nav-items','header__nav-item','links', 'inline', 'clearfix')))); ?>
			</div>
		</div>

		<?php if ($tabs && !empty($tabs['#primary'])): ?><div class="tabs-clearfix"><?php print render($tabs); ?></div><?php endif; ?>
		<!-- Menu main end -->
	

		<!-- Menu main end -->
		<?php print render($page['content']); ?> <!-- Manifesto-->
    <!-- Mobile burger -->
    <?php
      if (drupal_is_front_page()) {
          ?><h2 class="container blog__heading">Блог</h2><?php
      }
    ?>
    <div class="blog__container">
	<div class="blog-image-right"></div>
      <?php print render($page['blog_left']); ?>
      <div class="blog__right-side">
        <?php print render($page['blog_right']); ?>
        <?php
          if (drupal_is_front_page()) {
              ?><a href="#" class="blog__link">Усе падзеi</a><?php
          }
        ?>
      </div>
    </div>
    <div class="prefooter_mt">
      <?php print render($page['footer']); ?> <!-- Printing pre-footer content -->
    </div>
		<footer class="footer">
			<div class="footer__container container">
				 <?php print render($page['bottom']); ?><!-- Printing exact footer -->
			</div>
		</footer>



        <header class="header">
			<div class="header__mobile-menu mobile-menu">
				<button class="button-close" type="button">&#10006;</button>
				<div class="mobile-menu__links">
					<ul class="mobile-menu__list">
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://falanster.by/be/arganyzacyja">Фаланстэр</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://falanster.by/be/volunteers">Валанцёру</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://falanster.by/be/news">Блог</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://falanster.by/be/projects_and_clubs">Наша дзейнасць</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="#calendar">Каляндар</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://wiki.falanster.info/wiki/Профiль_Фаланстэраhttps://wiki.falanster.info/wiki/Заглавная_страница">Wiki</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="http://falanster.by/be/partners">Партнерства</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="https://falanster.by/be/kantakt">Кантакты</a>
						</li>
					</ul>

					<ul class="mobile-menu__list">
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="#">Запоўнiць анкету</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="#">Дапамагчы</a>
						</li>
						<li class="mobile-menu__item">
							<a class="mobile-menu__link" href="#">Уваход</a>
						</li>
					</ul>
				</div>

				<ul class="mobile-menu__language">
					<li class="mobile-menu__language-item">
						<a class="mobile-menu__language-link mobile-menu__language-link--active" href="#">Бел</a>
					</li>
					<li class="mobile-menu__language-item">
						<a class="mobile-menu__language-link" href="#">Рус</a>
					</li>
					<li class="mobile-menu__language-item">
						<a class="mobile-menu__language-link" href="#">Eng</a>
					</li>
				</ul>
			</div>