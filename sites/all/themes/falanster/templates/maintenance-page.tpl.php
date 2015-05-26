<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
	<link rel="stylesheet" type="text/css" href="sites/all/themes/falanster/css/common.css">
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  
</head>
<body class="<?php print $classes; ?>">
  <div id="page">
    <div id="header">
      

        <div id="content">
          
					<img src="sites/all/themes/falanster/images/falanster_on_rest.jpg" width="1000px" >
        </div> <!-- /content -->

      
    </div> <!-- /container -->

    
  </div> <!-- /page -->

</body>
</html>
