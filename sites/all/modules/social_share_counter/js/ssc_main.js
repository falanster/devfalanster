var $ = jQuery.noConflict();
$(function ($) {
    $(".sharebox").on('click', '.switch', function () {
        $(this).hide();
        $(this).siblings('.secondary').css('display', 'inline-block');
        $(this).siblings('.secondary').children('.switch2').show();
    });
    $(".sharebox").on('click', '.switch2', function () {
        $(this).parent('.secondary').siblings('.switch').show();
        $(this).parent('.secondary').hide();
    });
});
var isMobile = {
    Android: function() {
        return navigator.userAgent.match(/Android/i);
    },
    BlackBerry: function() {
        return navigator.userAgent.match(/BlackBerry/i);
    },
    iOS: function() {
        return navigator.userAgent.match(/iPhone|iPad|iPod/i);
    },
    Opera: function() {
        return navigator.userAgent.match(/Opera Mini/i);
    },
    Windows: function() {
        return navigator.userAgent.match(/IEMobile/i);
    },
    any: function() {
        return (isMobile.Android() || isMobile.BlackBerry() || isMobile.iOS() || isMobile.Opera() || isMobile.Windows());
    }
};
if( isMobile.any() ) {
    $('a[data-type=whatsapp]').show();
}

(function ($) {
    $.fn.cSButtons = function (options) {
        // Default params
        var defaults =
                {
                    "url": null,
                    "type": 'facebook',
                    "txt": null,
                    "via": null,
                    "count": false,
                    "count_position": 'right',
                    "apikey": null,
                    "media": null,
                    "lang": 'en-US',
                    "total": null,
                }
        var abbrevs = {12 : "T", 9 : "B", 6 : "M", 3 : "K", 0 : ""};
        var parametres = $.extend(defaults, options);
        var totalShare = 0;
        var nbButtons = this.length;
        var i = 0;
        var jg = 0;

        if (Drupal.settings.SSC.isClean) {
            Drupal.settings.SSC.share = Drupal.settings.SSC.share + '?';
        } else {
            Drupal.settings.SSC.share = Drupal.settings.SSC.share + '&';
        }
        function shorterTotal(num) {
            if (num >= 1e9) {
                num = (num / 1e9).toFixed(0) + "B"
            } else if (num >= 1e6) {
                num = (num / 1e6).toFixed(0) + "M"
            } else if (num >= 1e3) {
                num = (num / 1e3).toFixed(0) + "k"
            }
            return num;
        }
        return this.each(function () {
            i++;
            // If option on the link attributs
            var url = ($(this).attr('data-url') != undefined && $(this).attr('data-url') != '') ? $(this).attr('data-url') : parametres.url;
            var type = ($(this).attr('data-type') != undefined && $(this).attr('data-type') != '') ? $(this).attr('data-type') : parametres.type;
            var txt = ($(this).attr('data-txt') != undefined && $(this).attr('data-txt') != '') ? $(this).attr('data-txt') : parametres.txt;
            var via = ($(this).attr('data-via') != undefined && $(this).attr('data-via') != '') ? $(this).attr('data-via') : parametres.via;
            var count = ($(this).attr('data-count') != undefined && $(this).attr('data-count') != '') ? $(this).attr('data-count') : parametres.count;
            var media = ($(this).attr('data-media') != undefined && $(this).attr('data-media') != '') ? $(this).attr('data-media') : parametres.media;
            var lang = ($(this).attr('data-lang') != undefined && $(this).attr('data-lang') != '') ? $(this).attr('data-lang') : parametres.lang;
            var popupWidth = 0;
            var popupHeight = 0;
            var shareUrl = '';

            // Url use to share
            url = (url != null) ? url : document.URL;
            $URL = url;

            switch (type) {
                case 'twitter': // Twitter share
                    var twitter = $(this);
                    popupWidth = 550;
                    popupHeight = 420;
                    shareUrl = (txt != null) ? 'https://twitter.com/intent/tweet?original_referer=' + encodeURIComponent(document.URL) + '&text=' + encodeURIComponent(txt) + '&url=' + encodeURIComponent(url) : 'https://twitter.com/intent/tweet?original_referer=' + encodeURIComponent(document.URL) + '&url=' + encodeURIComponent(url);
                    shareUrl = (via != null) ? shareUrl + '&via=' + via : shareUrl;

                    if (count) {
                        $.getJSON(Drupal.settings.SSC.share + 'url=' + $URL + '&service=twitter', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }
                    break;
                case 'google': // Google + share
                    var google = $(this);
                    jg++;

                    popupWidth = 600;
                    popupHeight = 600;
                    shareUrl = 'https://plus.google.com/share?url=' + url;
                    shareUrl = (lang != null) ? shareUrl + '&hl=' + lang : shareUrl;

                    if (count) {
                        $.getJSON(Drupal.settings.SSC.share + 'url=' + $URL + '&service=googleplus', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }
                    break;
                case 'linkedin' : // Linkedin share
                    var linkedin = $(this);
                    popupWidth = 600;
                    popupHeight = 213;
                    shareUrl = 'https://www.linkedin.com/cws/share?url=' + url;

                    if (count) {
                        $.getJSON(Drupal.settings.SSC.share + 'url=' + $URL + '&service=linkedin', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }
                    break;
                case 'stumbleupon': // StumbleUpon share
                    var stumbleupon = $(this);
                    popupWidth = 1000;
                    popupHeight = 617;
                    shareUrl = 'http://www.stumbleupon.com/submiturl=' + url;
                    shareUrl = (txt != null) ? shareUrl + '&title=' + txt : shareUrl;

                    if (count) {
                        $.get(Drupal.settings.SSC.share + 'url=' + $URL + '&service=stumbleupon', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }

                    break;
                case 'pinterest': // Pinterest share
                    var pinterest = $(this);
                    popupWidth = 1000;
                    popupHeight = 617;
                    shareUrl = 'http://www.pinterest.com/pin/create/button/?url=' + url;
                    shareUrl = (media != null) ? shareUrl + '&media=' + media : shareUrl;
                    shareUrl = (txt != null) ? shareUrl + '&description=' + txt : shareUrl;

                    if (count) {
                        $.getJSON(Drupal.settings.SSC.share + 'url=' + $URL + '&service=pinterest', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }
                    break;
                case 'whatsapp': //WhatsApp Share
                    if( isMobile.any() ) {
                      var message = encodeURIComponent(txt) + " - " + encodeURIComponent(url);
                      shareUrl = "whatsapp://send?text=" + message;
                    }
                    break;
                default: // Default Facebook share
                    var facebook = $(this);
                    popupWidth = 670;
                    popupHeight = 340;
                    shareUrl = 'https://www.facebook.com/sharer/sharer.php?u=' + url;

                    if (count) {
                        $.getJSON(Drupal.settings.SSC.share + 'url=' + $URL + '&service=facebook', function (resultdata) {
                            totalShare += (isNaN(parseInt(resultdata.count))) ? 0 : parseInt(resultdata.count);
                            if (parametres.total != null && i == nbButtons && totalShare != 0)
                                $(parametres.total).text(shorterTotal(totalShare));
                        });
                    }
                    break;
            }

            // Click to Action Open Popup Share 
            $(this).on('click tap', function () {
                // Center popup to the screen
                var left = (screen.width / 2) - (popupWidth / 2);
                var top = (screen.height / 2) - (popupHeight / 2);

                popupWindow = window.open(shareUrl, 'popUpWindow', 'height=' + popupHeight + ',width=' + popupWidth + ',left=' + left + ',top=' + top + ',resizable=yes,scrollbars=yes,toolbar=no,menubar=no,location=no,directories=no,status=yes');
            });
        });
    };
})(jQuery);

jQuery(".csbuttons").cSButtons({total: ".counts", url: Drupal.settings.SSC.page});  