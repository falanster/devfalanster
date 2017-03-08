<?php

/**
 * @file
 * Default theme implementation to present share button.
 */
?>
<div class="ssc-follow-box-wrapper ssc-container">
<?php if (!empty($data['profile_links']['facebook'])):?>
<a class="facebook-button" href="<?php print $data['profile_links']['facebook'];?>" target="_blank">
	<span class="fa-facebook-square"></span>
</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['twitter'])):?>
<a class="twitter-button" href="<?php print $data['profile_links']['twitter'];?>" target="_blank">
	<span class="fa-twitter"></span>
</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['google_plus'])):?>
	<a class="googleplus-button" href="<?php print $data['profile_links']['google_plus'];?>" target="_blank">
		<span class="fa-google-plus "></span>
	</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['linkedin'])):?>
	<a class="linkedin-button" href="<?php print $data['profile_links']['linkedin'];?>" target="_blank">
		<span class="fa-linkedin-square "></span>
	</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['pinterest'])):?>
	<a class="pinterest-button" href="<?php print $data['profile_links']['pinterest'];?>" target="_blank">
		<span class="fa-pinterest "></span>
	</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['stumbleupon'])):?>
		<a class="stumbleupon-button" href="<?php print $data['profile_links']['stumbleupon'];?>" target="_blank">
		<span class="fa-stumbleupon "></span>
	</a>
<?php endif;?>
<?php if (!empty($data['profile_links']['rss'])):?>
		<a class="rss-button" href="<?php print $data['profile_links']['rss'];?>" target="_blank">
		<span class="fa-rss "></span>
	</a>
<?php endif;?>
</div>