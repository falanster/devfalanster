(function ($) {
    Drupal.behaviors.initColorboxDefaultStyle = {
        attach: function (context, settings) {
            $(document).bind('cbox_complete', function () {
                // Enables MediaElement player inside Colorbox popup.
                // Required because video element is added dynamically and original MediaElement JS only scans the page during page load.
                $('video,audio', context).once('mediaelement', function() {
                    var player_container = $(this);
                    player_container.mediaelementplayer();
                    // fix for IE so whole video screen shows up even if video fails to load
                    $.colorbox.resize({
                        innerWidth: player_container.attr('width'),
                        innerHeight: player_container.attr('height')
                    });
                });
            });
        }
    };
})(jQuery);

//