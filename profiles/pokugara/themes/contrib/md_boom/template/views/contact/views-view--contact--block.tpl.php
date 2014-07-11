<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<!-- Contact-->

<div class="wrapper container">
    <section class="flx-intro-2">
        <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
        <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php print $view_description;?></span></h5>
    </section>
</div><!--end:wrapper-->


<div class="flx-gooogle-map">
    <div class="contact-info">
        <i class="icon-mail"></i>
        <h3><a href="#"><?php if(theme_get_setting('sites_email')): print theme_get_setting('sites_email'); endif;?></a></h3>
        <?php if(theme_get_setting('sites_description')): print theme_get_setting('sites_description'); endif;?>
        <h5><?php print t('Address');?></h5>
        <?php if(theme_get_setting('address')):?><p> <i class="icon-location"></i><?php print theme_get_setting('address'); ?></p> <?php endif;?>
        <?php if(theme_get_setting('phone')):?><p> <i class="icon-mobile"></i><?php print theme_get_setting('phone'); ?></p> <?php endif;?>
        <?php if(theme_get_setting('fax')):?><p> <i class="icon-stethoscope"></i><?php  print theme_get_setting('fax'); ?></p><?php endif;?>
    </div><!--end:contact-info-->
    <div id="map_canvas"></div>
</div><!--end:flx-gooogle-map-->


<div class="wrapper">
    <div class="flx-map-form">
        <h3><span class="webform-title"><?php print theme_get_setting('webform_title','md_boom');?></span></h3>
        <p><span class="webform-description"><?php print theme_get_setting('webform_des','md_boom');?></span></p>
        <?php print $rows;?>
        <div id="response"></div>
    </div><!--end:flx-map-form-->
</div>





