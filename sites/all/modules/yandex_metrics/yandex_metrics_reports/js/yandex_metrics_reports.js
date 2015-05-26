/**
 * @file
 * Scripts for reports page.
 */
(function ($) {
  $(document).ready(function() {
    var counter_id = $('#yandex_metrics_reports_counter_id').val();
    var filter = $('#yandex_metrics_reports_filter').val();

    var report_list = Drupal.settings.yandex_metrics_reports.reportList;

    // Load all available reports.
    $.each(report_list, function(index, value) {
      yandex_metrics_reports_load_data(counter_id, filter, value);
    });
  });

  /**
   * Performs request to Ajax callback url and loads data into report placeholder.
   * @param counter_id
   * @param filter
   * @param type
  */
  function yandex_metrics_reports_load_data(counter_id, filter, type) {
    if($('#yandex_metrics_reports_' + type).length == 0) {
      return;
    }
    var basePath = Drupal.settings.basePath;
    // Add ?q= to the url if clean urls are turned off.
    var queryParam = (parseInt(Drupal.settings.yandex_metrics_reports.cleanUrls, 10) == 0) ? "?q=" : "";
    var ajaxCallbackPath = basePath + queryParam + Drupal.settings.pathPrefix + "admin/yandex_metrics_ajax/" + counter_id + "/" + filter + "/" + type;
    var indicatorPath = basePath + Drupal.settings.yandex_metrics_reports.modulePath + "/images/progress-indicator.gif";
    $.ajax({
      url: ajaxCallbackPath,
      beforeSend: function(xhr) {
        $('#yandex_metrics_reports_' + type).html('<img src="' + indicatorPath + '" width="31" height="31" />');
      },
      success: function(data) {
        $('#yandex_metrics_reports_' + type).html(data);
      }
    });
  }
}(jQuery));
