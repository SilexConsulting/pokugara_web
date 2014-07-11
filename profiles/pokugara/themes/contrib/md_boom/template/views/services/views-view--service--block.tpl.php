<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>


    <div class="wrapper container clearfix">
        <section class="flx-intro-2">
            <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
            <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php if($view_description): print $view_description; endif?></span></h5>
        </section>
        <ul class="flx-services clearfix">
            <?php print $rows;?>
        </ul><!--end:flx-services-->
    </div><!--end:container-->
