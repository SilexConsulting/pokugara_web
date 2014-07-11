<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
    <!-- Meet our team-->
    <div class="container clearfix">

        <section class="flx-intro-2">
            <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
            <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php if($view_description): print $view_description; endif?></span></h5>

        </section><!--end:flx-intro-2-->

        <section class="flx-meet-team">
            <div class="list-carousel responsive" >
                <ul id="flx-team-slides">
                    <?php print $rows;?>
                </ul><!--end:flx-team-slides-->
                <div class="clearfix"></div>

            </div><!--end:list-carousel-->
        </section><!--end:flx-meet-team-->

    </div><!--end:Meet our team-->
