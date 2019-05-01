(function ($) {

  Drupal.behaviors.agenda = {
    attach: function(context, settings) {
      $('.agenda-block .calendar_title').click(function () {
        $(this).next('ul').toggle('show');
      });
    }
  };

})(jQuery);
