<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
    <div class="wrapper container">
        <section class="flx-intro-2">
            <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
            <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php if($view_description): print $view_description; endif?></span></h5>
        </section><!--end:flx-intro-2-->
    </div><!--end:wrapper-->
    <div class="pf-detail-box" id="pf-detail-box" style="display: none;">
        <div class="wrapper">
            <div class="row-fluid">
            </div><!--end:row-fluid-->
        </div><!--end:wrapper-->
    </div><!--end:pf-detail-box-->
    <div class="wrapper">
        <section id="options" class="clearfix">
            <ul id="filters" class="option-set clearfix" data-option-key="filter">
                <li><a href="#filter" data-option-value="*" class="selected">Portfolio</a></li>
                <?php foreach($taxonomy_list_terms as $term):?>
                <li><a href="#filter" data-option-value=".flx-<?php print $term->tid;?>"><?php print $term->name;?></a></li>
                <?php endforeach;?>
            </ul><!--end:filters-->

            <ul id="etc" class="clearfix">
                <li id="toggle-sizes">
                    <a class="toggle-selected" href="#toggle-sizes"><i class="icon-th-list icon-2x"></i></a>
                    <a href="#toggle-sizes" class=""><i class="icon-th icon-2x"></i></a>
                </li>
            </ul><!--end:etc-->
        </section> <!--end:options-->
        <div id="container" class="variable-sizes clickable clearfix">
            <?php print $rows;?>
        </div><!--end:container-->

    </div><!--end:wrapper-->
