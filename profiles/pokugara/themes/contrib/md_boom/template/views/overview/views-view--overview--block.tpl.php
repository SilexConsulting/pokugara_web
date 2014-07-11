<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$view_content = $view->result;
?>
<div class="flx-overview-box">
    <!-- Over view -->
    <div class="container clearfix">
        <section class="flx-intro-2">
            <h2 class="view-<?php print $view_name?>-title"><?php print $view_human_name;?></h2>
            <h5 class="flx-intro-excerpt"><span class="view-<?php print $view_name;?>-description"><?php if($view_description): print $view_description; endif?></span></h5>
        </section><!--end:flx-intro-2-->
        <section class="flx-boom clearfix">
            <div class="list-container-3">
                <ul class="tabs-3 clearfix">
                    <?php foreach($view_content as $key => $tabs):$i=0;?>
                        <li><a href="#tab-3-<?php print ($key+1);?>"><i class="<?php print $tabs->field_field_overview_icon[$i]['rendered']['#icon'];?>" title="<?php print $tabs->node_title;?> "></i><span id="node-title"><span class="node-<?php print $view->name;?>-title"><?php print $tabs->node_title;?></span></span></a></li>
                        <?php $i++;endforeach;?>
                </ul><!--end:tabs-3-->
                <div class="tab-highlight"></div>
            </div><!--end:list-container-3-->
            <div class="tab-container-3">
                <div class="jp-container" id="jp-container">
                    <?php foreach($view_content as $key => $tab_content):$y=0;
                        $field_overview_skills = $tab_content->field_field_overview_skills;
                        if($tab_content->field_field_overview_body != null){
                            $body = $tab_content->field_field_overview_body[0]['rendered']['#markup'];
                        }
                        ?>
                        <div id="tab-3-<?php print ($key+1);?>" class="tab-content-3">
                            <ul id="flx-skill">
                                <?php foreach($field_overview_skills as $key2 => $skills):
                                    $field_id = $skills['raw']['value'];
                                    $skill_name = $skills['rendered']['entity']['field_collection_item'][$field_id]['field_skill_name'][0]['#markup'];
                                    $skill_level = $skills['rendered']['entity']['field_collection_item'][$field_id]['field_skill_level'][0]['#markup'];
                                    ?>
                                    <li class="clearfix"><p class="flx-skill-title"><?php print $skill_name;?></p>
                                        <div class="progress-bar blue animate"> <span class="progress-<?php print $skill_level;?>" style="width: <?php print $skill_level;?>%"><span></span></span></div>
                                        <p class="flx-skill-number"><?php print $skill_level;?>%</p>
                                    </li>
                                <?php endforeach;?>
                            </ul>
                            <?php if(isset($body)){print $body;};?>
                        </div>
                        <?php $y++;endforeach;?>
                </div><!--end:jp-container-->
            </div><!--end:tab-container-3-->
        </section><!--end:flx-boom-->
    </div><!--end:container--><!--end:Over view-->
</div><!--end:flx-overview-box-->