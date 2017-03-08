<?php

/**
 * @file
 * Default theme implementation to present share button.
 */
?>
<aside class="ssc-container">
    <div class="sharebox" data-url="<?php print $data['link_url'];?>" data-text="<?php print $data['title'];?>">
      <div class="count">
        <div class="counts"><?php print $data['ssc_min_to_show'];?></div>
        <span class="sharetext"><?php print $data['count_text'];?></span>
      </div>
      <div class="share-button-wrapper">
      <a href="javascript:;" class="csbuttons" data-type="facebook" data-count="true">
        <span class="fa-facebook-square">
          <span	class="expanded-text"><?php print $data['button_text']['facebook'];?></span>
          <span	class="alt-text-facebook">Share</span>
        </span>
      </a>
      <a href="javascript:;" class="csbuttons" data-type="twitter" data-txt="<?php print $data['title'];?>" data-via="<?php print $data['via'];?>" data-count="true">
        <span class="fa-twitter">
          <span class="expanded-text-twitter"><?php print $data['button_text']['twitter'];?></span>
          <span	class="alt-text-tweet">Tweet</span>
        </span>
      </a>
      <a href="javascript:;" style="display:none;" class="csbuttons" data-type="whatsapp" data-txt="<?php print $data['title'];?>" data-via="<?php print $data['via'];?>" data-count="true">
        <span class="fa-whatsapp">
          <span class="expanded-text-whatsapp">Share</span>
          <span	class="alt-text-whatsapp">Share</span>
        </span>
      </a>
      <div class="secondary">
        <a href="javascript:;" class="csbuttons" data-type="google" data-count="true">
          <span class="fa-google-plus "></span>
        </a>
        <a href="javascript:;" class="csbuttons" data-type="linkedin" data-txt="<?php print $data['title'];?>" data-count="true">
          <span class="fa-linkedin-square "></span>
        </a>
        <a href="javascript:;" class="csbuttons" data-type="stumbleupon" data-txt="<?php print $data['title'];?>" data-count="true">
          <span class="fa-stumbleupon "></span>
        </a>
        <a href="javascript:;" class="csbuttons" data-type="pinterest" data-txt="<?php print $data['title'];?>" data-count="true">
          <span class="fa-pinterest "></span>
        </a>
        <a class="switch2" href="javascript:;"></a>
      </div>
      <a class="switch" href="javascript:;"></a>
      </div>
    </div>
</aside>