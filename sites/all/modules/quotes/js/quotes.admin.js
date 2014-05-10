/**
* @file
* Quotes admin javascript files.
*
* Javascript for vertical tabs display in quotes configuration settings form.
*/

// The following line will prevent a JavaScript error if this file is included and vertical tabs are disabled.
Drupal.verticalTabs = Drupal.verticalTabs || {};

// Note the name here matches the name of the fieldset ID.
Drupal.verticalTabs.display = function() {
  var vals = [];
  vals.push('Quotes per page: ' + $('#edit-quotes-per-page').val());
  vals.push('Leader: ' + $('#edit-quotes-leader').val());
  vals.push('Author link: ' + $('#author-link input:checked').parent().text());
  vals.push('Author bio: ' + $('#author-bio input:checked').parent().text());
  vals.push('Format: ' + $('#quotes-format input:checked').parent().text());
  vals.push('Edit link: ' + $('#quotes-edit-link input:checked').parent().text());
  vals.push('Quick nav: ' + $('#quotes-quick-nav input:checked').parent().text());
  return vals.join(', ');
}

Drupal.verticalTabs.myquotes = function() {
  var vals = [];
  vals.push('User link: ' + $('#quotes-user-link input:checked').parent().text());
  vals.push('My quotes: ' + $('#quotes-myquotes input:checked').parent().text());
  return vals.join(', ');
}

Drupal.verticalTabs.user = function() {
  var vals = [];
  vals.push('"My Account" tab: ' + $('#myquotes-tab input:checked').parent().text());
  return vals.join('<br />');
}
