
<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<!-- Container-->
<div class="container-blog">
    <div class="wrapper">
        <section class="flx-intro-2">
            <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
            <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php print $view_description;?></span></h5>
        </section><!--end:flx-intro-2-->

        <!-- content5 Navigation-->
        <div id="blog-navigation">
            <a id="prev2" class="prev" href="#"></a>
            <a id="next2" class="next" href="#"></a>
        </div><!--end:content5 Navigation-->
    </div><!--end:wrapper-->

    <!-- content5 Carousel-->
    <div class="list_carousel">
        <!-- content5 List-->
        <ul id="blog-carousel">
            <?php print $rows;?>
        </ul><!--end:content5 List-->
    </div><!--end:content5 Carousel-->
</div><!--end:Container-->
