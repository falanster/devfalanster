/****************************************
 * Floating Navigation jQuery feature
 ****************************************/
(function($) {
    if($('.ssc-container').length > 0) {

        // get initial top offset of navigation
        var floating_navigation_offset_top = $('.ssc-container').offset().top;
        var floating_navigation_offset_left = $('.ssc-container').offset().left;

        // define the floating navigation function
        var floating_navigation = function(){
                    // current vertical position from the top
            var scroll_top = $(window).scrollTop();

            // if scrolled more than the navigation, change its
                    // position to fixed to float to top, otherwise change
                    // it back to relative
            if (scroll_top > floating_navigation_offset_top) {
              $('.ssc-container').removeClass('shareme-relative');
              $('.ssc-container').addClass('shareme-fixed ssc-sticky');
            } else {
              $('.ssc-container').removeClass('shareme-fixed ssc-sticky');
              $('.ssc-container').addClass('shareme-relative');
            }
        };

        // run function on load
        floating_navigation();

        // run function every time you scroll
        $(window).scroll(function() {
             floating_navigation();
        });
    }
})(jQuery);
