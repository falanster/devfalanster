(function ($) {

  Drupal.behaviors.agenda = {
    attach: function(context, settings) {

      $('.agenda-block .calendar_title').click(function (event) {
          $(this).next('ul').toggle("slow", function() {


          if ($(this).css("display") == 'none'){
              $(this).prev("span").css('color', 'black');
              $(this).prev("span").css('background', '#fafafa');
              $(this).prev("span").css('box-shadow', "none");
              $(this).prev("span").css('font-weight', 'normal');

              }
              else{
                  $(this).prev("span").css('color', '#ff6600');
                  $(this).prev("span").css('background', '#ececec');
                  $(this).prev("span").css('box-shadow', '0 0 10px rgba(0,0,0,0.5)');
                  $(this).prev("span").css('z-index', "1");
                  $(this).prev("span").css('font-weight', 'bold');
                  $(this).prev("span").css('min-height', '48px');
                  $(this).next('p').css('height', '50px');
                  $(this).next('p').css('display', 'block');

                  }

  } );


      });
    }
  };

})(jQuery);
