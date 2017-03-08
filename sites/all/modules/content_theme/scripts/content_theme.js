
(function ($) {

Drupal.behaviors.contentThemeFieldsetSummaries = {

  attach: function (context) {

    $('fieldset.content-theme-content-type-form', context).drupalSetSummary(function (context) {
      var editTheme = $('.form-item-content-theme-content-type-edit select option:selected', context).text();
      var viewTheme = $('.form-item-content-theme-content-type-view select option:selected', context).text();

      return Drupal.t('Editing: @edit; Viewing: @view', { '@edit': editTheme, '@view': viewTheme });
    });

    $('fieldset.content-theme-content-node-form', context).drupalSetSummary(function (context) {
      var editTheme = $('.form-item-content-theme-content-node-edit select option:selected', context).text();
      var viewTheme = $('.form-item-content-theme-content-node-view select option:selected', context).text();

      return Drupal.t('Editing: @edit; Viewing: @view', { '@edit': editTheme, '@view': viewTheme });
    });
  }
};

})(jQuery);
