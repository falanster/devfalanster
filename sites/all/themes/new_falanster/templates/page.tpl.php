		<!-- Mobile burger -->
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
			<!-- Mobile Burger ends -->
			
			<div class="header__menu container">
				<!-- Static header__logo -->
				<!-- <a class="header__logo" href="./index.html">
					<img 
						srcset="sites/all/themes/new_falanster/images-source/header-logo.png 185w,
										sites/all/themes/new_falanster/images-source/header-logo-mobile.png 500w"
						sizes="(max-width: 1079px) 500px,
										185px"
						src="sites/all/themes/new_falanster/images-source/header-logo.png"
						alt="Фаланстэр">
				</a> -->
				<!-- Prints logo start -->
				<?php if ($logo): ?>
					<a class="header__logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
					<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
					</a>
				<?php endif; ?>
				<!-- Prints logo end -->
				<!-- Top menu starts -->
				<div class="header__top-menu">
					<ul class="header__controls">
						<li class="header__controls-item">
							<a class="header__controls-link header__controls-link--form" href="https://docs.google.com/forms/d/e/1FAIpQLSf78xrCLn3zsUaXmQGNrA58puu1Mk7AK4gIFyAwVXpNU1TyAw/viewform">Запоўнiць анкету</a>
						</li>
						<li class="header__controls-item">
							<a class="header__controls-link header__controls-link--help" href="https://falanster.by/be/help">Дапамагчы</a>
						</li>
						<li class="header__controls-item header__controls-item--login">
							<a class="header__controls-link header__controls-link--login" href="#">Уваход</a>
						</li>
					</ul>
								
					<ul class="header__language">
						<li class="header__language-item header__language-item--active">
							<a class="header__language-link" href="#">Бел</a>
						</li>
						<li class="header__language-item">
							<a class="header__language-link" href="#">Рус</a>
						</li>
						<li class="header__language-item">
							<a class="header__language-link" href="#">Eng</a>
						</li>
					</ul>
					<button class="button-hamburger"><img src="sites/all/themes/new_falanster/images-source/hamburger.jpg" alt="Меню" height="80" width="100"></button>
				</div>
			</div>
			<!-- Top menu ends -->
			<!-- Nav menu starts -->
			<nav class="header__nav">
				<ul class="header__nav-items container">
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/arganyzacyja">Фаланстэр</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/volunteers">Валанцеру</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/news">Блог</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/projects_and_clubs">Наша дзейнасць</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="#calendar">Каляндар</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://wiki.falanster.info/wiki/%D0%9F%D1%80%D0%BE%D1%84i%D0%BB%D1%8C_%D0%A4%D0%B0%D0%BB%D0%B0%D0%BD%D1%81%D1%82%D1%8D%D1%80%D0%B0">Wiki</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/ulaziny">Партнерства</a>
					</li>
					<li class="header__nav-item">
						<a class="header__nav-link" href="https://falanster.by/be/kantakt">Кантакты</a>
					</li>
				</ul>
			</nav>
		</header>
			<!-- Nav menu ends -->
		<main>
			<section class="manifest">
				<h1 class="visually-hidden">Фаланстэр</h1>
				<div class="manifest__container">
					<div class="manifest__left">
						<div class="manifest__content">
							<p class="manifest__text">Мы - каманда сацыяльных
							наватараў, якая з дапамогай
							адкрытых i свабодных лiчбавых
							i гуманiтарных тэхналогiй стварае
							больш аўтаномнае i дынамiчнае
							беларускае грамадства</p>
							<a class="manifest__button" href="https://falanster.by/be/pra_nas">Чытаць пра нас</a>
						</div>
					</div>
					
					<div class="manifest__right">
						<div class="manifest__content">
							<p class="manifest__text">Мы - каманда сацыяльных<br>
							наватараў, якая з дапамогай<br>
							адкрытых i свабодных лiчбавых<br>
							i гуманiтарных тэхналогiй стварае<br>
							больш аўтаномнае i дынамiчнае<br>
							беларускае грамадства</p>
							<a class="manifest__button" href="https://falanster.by/be/pra_nas">Чытаць пра нас</a>
						</div>
					</div>
				</div>

			</section>
			<!-- ossset testings -->
			<?php print render($page['content']); ?>
			<?php print ($content) ?>
			<!-- ends ossset testings -->
			<section class="projects">
				<div class="projects-image-left"></div>
				
				<div class="projects__container">
					<h2 class="projects__heading">Гарачыя праекты</h2>
					
					<div class="projects__items">
						<div class="projects__items-row">
					
							<div class="projects__item" id="project1">
								<div class="projects__overlay">

									<a href="https://falanster.by/be/wikification">
										<img class="projects__image" alt="Вiкiфiкацыя" src="sites/all/themes/new_falanster/images-source/x1.jpg" height="398" width="456">
									</a>
								
									<div class="projects__overlay-text">
										<h2 class="projects__overlay-title">Вiкiфiкацыя</h2>
										<a class="projects__button-link" href="https://falanster.by/be/wikification">Даведацца больш</a>
									</div>
								
									<div class="projects__text">
										<h2 class="projects__title">
											<a class="projects__title-link" href="https://falanster.by/be/wikification">Вiкiфiкацыя</a>
										</h2>
										<p class="projects__description">Узмацняем беларускую вікіпедыйную супольнасць, 
										робім майстар-класы і іншыя мерапрыемствы, перадаем веды. </p>
										<a class="projects__link" href="https://falanster.by/be/wikification">Падрабязнее</a>
									</div>
								
								</div>
							</div>
						
							<div class="projects__item" id="project2">
								<div class="projects__overlay">
									<a href="https://it.falanster.by/">
										<img class="projects__image" alt="Лiчбавая майстэрня" src="sites/all/themes/new_falanster/images-source/x2.jpg" height="398" width="456">
									</a>
								
									<div class="projects__overlay-text">
										<h2 class="projects__overlay-title">Лiчбавая майстэрня</h2>
										<a class="projects__button-link" href="https://it.falanster.by/">Даведацца больш</a>
									</div>
								
									<div class="projects__text">
										<h2 class="projects__title">
											<a class="projects__title-link" href="https://it.falanster.by/">Лiчбавая майстэрня</a>
										</h2>
										<p class="projects__description">Развіваем айціваланцёрства у Беларусі для дапамогі 
										грамадскім арганізацыям паляпшыць сваю лічбавую інфрастуруктуру.</p>
										<a class="projects__link" href="https://it.falanster.by/">Падрабязнее</a>
									</div>
								</div>

							</div>
						
						</div>
					
						<div class="projects__items-row">
						
							<div class="projects__item" id="project3">
								<div class="projects__overlay">
								
									<a href="https://falanster.by/be/creativecommons">
										<img class="projects__image" alt="Градка" src="sites/all/themes/new_falanster/images-source/x3.jpg" height="398" width="456">
									</a>
								
									<div class="projects__overlay-text">
										<h2 class="projects__overlay-title">Градка</h2>
										<a class="projects__button-link" href="https://falanster.by/be/creativecommons">Даведацца больш</a>
									</div>
								
									<div class="projects__text">
										<h2 class="projects__title">
											<a class="projects__title-link" href="https://falanster.by/be/creativecommons">Градка</a>
										</h2>
										<p class="projects__description">Распаўсюджваем веды пра адкрыты і свабодны код 
										і кантэнт у грамадскіх арганiзацыях, заканадаўстве 
										і сярод грамадзянскай супольнасці. 
										Садзейнічаем рэформе аўтарскага права ў Беларусі.</p>
										<a class="projects__link" href="https://falanster.by/be/creativecommons">Падрабязнее</a>
									</div>
								</div>
							</div>
						
							<div class="projects__item" id="project4">
								<div class="projects__overlay">
								
									<a href="https://falanster.by/be/ulaziny">
										<img class="projects__image" alt="Улазiны" src="sites/all/themes/new_falanster/images-source/x4.jpg" height="398" width="456">
									</a>
								
									<div class="projects__overlay-text">
										<h2 class="projects__overlay-title">Улазiны</h2>
										<a class="projects__button-link" href="https://falanster.by/be/ulaziny">Даведацца больш</a>
									</div>
								
									<div class="projects__text">
										<h2 class="projects__title">
											<a class="projects__title-link" href="https://falanster.by/be/ulaziny">Улазiны</a>
										</h2>
										<p class="projects__description">Дзелімся сваімі рэсурсамі і прасторай з 
										адзінадумцамі і пачынаючымі ініцыятывамі.</p>
										<a class="projects__link" href="https://falanster.by/be/ulaziny">Падрабязнее</a>
									</div>
								</div>
							</div>
						
						</div>
					</div>
					
					<div class="projects__mobile-buttons">
						<button onclick="button_click();" class="projects__button projects__button--basic" id="btn1"></button>
						<button class="projects__button projects__button--basic" id="btn2"></button>
						<button class="projects__button projects__button--basic" id="btn3"></button>
						<button class="projects__button projects__button--basic" id="btn4"></button>
					</div>
				</div>
		
				<div class="projects-image-right"></div>
			</section>
			
			<section class="calendar" id="calendar">
				<h2 class="visually-hidden">Каляндар</h2>
			</section>
			
			<section class="blog" id="blog">
				<div class="container">
					<h2 class="blog__heading">Блог</h2>
					
					<div class="blog__articles">
						<article class="blog__article--main">
							<h3 class="blog__article-title--main">
								<a class="blog__article-link--main" href="https://falanster.by/be/news" id="recent_article1">Хто на майстра Йоду правы мае? Сустрэча з польскiм фiлiялам Creative Commons Частка 1</a>
							</h3>
							<div class="blog__article-info">
								<p class="blog__date">
									серада, 23.11.2018
								</p>
								<p class="blog__author">
									Той, хто напiсаў
								</p>
							</div>
							<img class="blog__article-image" src="sites/all/themes/new_falanster/images-source/blogphoto.jpg" alt="" height="295" width="485">
						</article>
					
						<div class="blog__aside">
							<article class="blog__article--aside">
								<h3 class="blog__article-title">
									<a class="blog__article-link" href="https://falanster.by/be/news" id="recent_article2">Хто на майстра Йоду правы мае? Сустрэча з польскiм фiлiялам Creative Commons Частка 1</a>
								</h3>
								<div class="blog__article-info">
									<p class="blog__date">
										серада, 23.11.2018
									</p>
									<p class="blog__author">
										Той, хто напiсаў
									</p>
								</div>
							</article>
							
							<article class="blog__article--aside">
								<h3 class="blog__article-title">
									<a class="blog__article-link" href="https://falanster.by/be/news" id="recent_article3">Хто на майстра Йоду правы мае? Сустрэча з польскiм фiлiялам Creative Commons Частка 1</a>
								</h3>
								<div class="blog__article-info">
									<p class="blog__date">
										серада, 23.11.2018
									</p>
									<p class="blog__author">
										Той, хто напiсаў
									</p>
								</div>
							</article>
							
							<article class="blog__article--aside">
								<h3 class="blog__article-title">
									<a class="blog__article-link" href="https://falanster.by/be/news" id="recent_article4">Хто на майстра Йоду правы мае? Сустрэча з польскiм фiлiялам Creative Commons Частка 1</a>
								</h3>
								<div class="blog__article-info">
									<p class="blog__date">
										серада, 23.11.2018
									</p>
									<p class="blog__author">
										Той, хто напiсаў
									</p>
								</div>
							</article>
							
							<p class="blog__more">
								<a class="blog__more-link" href="#">Усе падзеi</a>
							</p>
						</div>
					</div>
					
				</div>
				<div class="blog-image-right"></div>
			</section>
			
			<section class="prefooter" id="prefooter">
				<div class="prefooter__left">
					<h3 class="prefooter__heading">Стань<br>валанцёрам!</h3>
					<p class="prefooter__text--left">Нашы падыходы базуюцца на асветнiцкай,
						арганiзацыйнай i iнфраструктурнай актыўнасцi
						дзесяткаў валанцёраў, ахвяроўваннях грамадзян,
						а таксама супрацы з iншымi iнiцыятывамi.</p>
				</div>
				
				<div class="prefooter__right">
					<p class="prefooter__text--right">Нашы падыходы базуюцца на асветнiцкай,<br>
						арганiзацыйнай i iнфраструктурнай актыўнасцi<br>
						дзесяткаў валанцёраў, ахвяроўваннях грамадзян,<br>
						а таксама супрацы з iншымi iнiцыятывамi.</p>
				</div>
			</section>
		</main>

		<footer class="footer">	
			<div class="footer__container container">
				<ul class="footer__menu">
					<li class="footer__menu-item">
						<a class="footer__menu-link" href="URL">Правiлы сайта</a>
					</li>
					<li class="footer__menu-item">
						<a class="footer__menu-link" href="https://falanster.by/be/pytanni">FAQ</a>
					</li>
					<li class="footer__menu-item">
						<a class="footer__menu-link" href="https://falanster.by/be/help">Зрабi ўнесак</a>
					</li>
					<li class="footer__menu-item">
						<a class="footer__menu-link" href="https://falanster.by/be/kantakt">Кантакты</a>
					</li>
				</ul>
			
				<div class="footer__social">
					<p class="footer__social-title">Мы у сац. сетках</p>
					<ul class="footer__social-links">
						<li>
							<a class="footer__social-link footer__social-link--vk" href="https://vk.com/falanster_by">
								<img class="vk-icon" alt="УКантакце" src="sites/all/themes/new_falanster/images-source/vk.png" height="60" width="60">
							</a>
						</li>
						<li>
							<a class="footer__social-link" href="https://t.me/falansterby">
								<img class="telegram-icon" alt="Telegram" src="sites/all/themes/new_falanster/images-source/telegram.png" height="30" width="30">
							</a>
						</li>
						<li>
							<a class="footer__social-link" href="https://www.facebook.com/falanster.by/">
								<img class="fb-icon" alt="Facebook" src="sites/all/themes/new_falanster/images-source/face.png" height="45" width="45">
							</a>
						</li>
						<li>
							<a class="footer__social-link" href="https://www.youtube.com/channel/UCAmTfxxasQwNaKkljnmvc5A">
								<img class="youtube-icon" alt="Youtube" src="sites/all/themes/new_falanster/images-source/yo.png" height="45" width="45">
							</a>
						</li>
					</ul>
				
					<img class="footer__license" alt="Creative Commons Attribution-ShareAlike" src="sites/all/themes/new_falanster/images-source/footerlogo2.jpg" height="34" width="95">
				</div>
			
				<div class="footer__subscribe">
					<label class="footer__subscribe-title" for="subscribe-email">Падпiсацца на нас</label>
					<input class="footer__email-input" id="subscribe-email" type="email" placeholder="Ваш e-mail">
					<a class="footer__subscribe-button" href="#modal">OK</a>
					<img class="footer__license--big" alt="Creative Commons Attribution-ShareAlike" src="sites/all/themes/new_falanster/images-source/by-sa.png">
				</div>
				
				<div class="modal" id="modal">
					<div class="modal__popup">
						<img class="popup-bg-topleft" src="sites/all/themes/new_falanster/images-source/topleft.jpg" alt="" height="54" width="80">
						<img class="popup-bg-topright" src="sites/all/themes/new_falanster/images-source/topright.jpg" alt="" height="54" width="80">
						<h2 class="modal__popup-heading">Дзякуй!</h2>
						<img class="face-icon" src="sites/all/themes/new_falanster/images-source/modal.svg" alt="">
						<p class="modal__popup-text">Амаль гатова!<br>Толькi што вам на email быу адпраулены лiст. 
						<br>Клiкнiце па спасылке унутры, каб пацвердзiць падпiску</p>
						<a class="modal__close-button" href="#vk">Добра!</a>
						<img class="popup-bg-bottomleft" src="sites/all/themes/new_falanster/images-source/bottom.jpg" alt="" height="40" width="80">
						<img class="popup-bg-bottomright" src="sites/all/themes/new_falanster/images-source/bottom.jpg" alt="" height="40" width="80">
					</div>
				</div>
			</div>
		</footer>
		
		<script src="script.js"></script>

