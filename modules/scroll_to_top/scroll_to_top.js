/**
 * Scroll to top behavior
 */
Drupal.behaviors.scroll_to_top = function (context) {
		// append  back to top link top body
		var exist= $('#back-top').length; // exist = 0 if element doesn't exist
		if(exist == 0){ // this test is for fixing the ajax bug 
			$("body").append("<div id='back-top'><a href='#top'><span class='icon'></span><span id='link'>"+Drupal.t("Back to Top")+"</div></a></span>");
		}
		// hide #back-top first
		$("#back-top").hide();
		$(window).scroll(function () {
			if ($(this).scrollTop() > 100) {
				$('#back-top').fadeIn();
			} else {
				$('#back-top').fadeOut();
			}
		});

		// scroll body to 0px on click
		$('#back-top a').click(function () {
			$('body,html').animate({
				scrollTop: 0
			}, 800);
			return false;
		}); 
};

