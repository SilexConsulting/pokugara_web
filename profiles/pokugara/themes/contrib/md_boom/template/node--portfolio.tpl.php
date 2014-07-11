<?php
/**
* $node: Node element.
* $content : Node content.
* $content['field_name'] : Node field element.
* Some variables was defined in function md_boom_preprocess_node from inc/template.node.process.inc file
*/
?>
<?php

$current_path = current_path();
$multimedia = $content['field_portfolio_multimedia']['#items'];
$count = count($multimedia);
$media_content = '';
foreach($multimedia as $key => $value){
    $file_type = $value['file']->type;
    $image = file_create_url($value['file']->uri);
    $image_uri = $value['file']->uri;
    if($file_type != 'image') {
        $media_content .= '<li>'.render($content['field_portfolio_multimedia'][$key]).'</li>';
    } else {
        $media_content .= '<li><img src="'.image_style_url('portfolio_preview',$image_uri).'"/></li>';
    }
}
$taxonomy = $node->field_portfolio_taxonomy[$node->language];
if($taxonomy != null) {
    $taxonomy_output = '';
    if(count($taxonomy) > 1) {
        $current = $taxonomy;
        end($taxonomy);
        $last_key = key($taxonomy);
        unset($taxonomy[$last_key]);
        foreach ($taxonomy as $key => $value){
            $taxonomy_output .= '<a href="'.url('taxonomy/term/'.$value['tid'].'').'">'.$value['taxonomy_term']->name.'</a>, ';
        }
        $taxonomy_output .= '<a href="'.url('taxonomy/term/'.$value['tid'].'').'">'.$current[$last_key]['taxonomy_term']->name.'</a>';
    } else {
        $taxonomy_output .= '<a href="'.url('taxonomy/term/'.$taxonomy[0]['tid'].'').'">'.$taxonomy[0]['taxonomy_term']->name.'</a>';
    }
}
$skill = $node->field_portfolio_skills[$node->language];
//kpr($skill);die;
if($skill != null) {
    $skill_output = '';
    if(count($skill) > 1) {
        $current = $skill;
        end($skill);
        $last_key = key($skill);
        unset($skill[$last_key]);
        foreach ($skill as $key => $value){
            $skill_output .= str_replace(' ','',$value['value']).', ';
        }
        $skill_output .= str_replace(' ','',$current[$last_key]['value']);
    } else {
        $skill_output .= str_replace(' ','',$skill[0]['value']);
    }
}
?>
<article class="pf-detail-item span12 clearfix">
    <?php
    hide($content['field_portfolio_taxonomy']);
    hide($content['field_portfolio_location']);
    hide($content['field_portfolio_skills']);
    hide($content['links']);
    hide($content['comments']);
    hide($content['field_portfolio_thumbnail']);
    hide($content['field_portfolio_layout_mode']);
    hide($content['field_portfolio_description']);

    ?>
    <?php if(isset($media_content)){?>
        <div class="pf-slider-wrapper">
            <div class="flexslider" id="pf-list-flex">
                <ul class="slides">
                    <?php print $media_content;?>
                </ul>
            </div>
        </div><!--bp-flex-->
    <?php } else { ?>
    <div class="pf-slider-wrapper">
        <?php print render($content['field_portfolio_thumbnail']);?>
    </div>
    <?php } ?>
    <div class="pf-content">
        <h3><span id="node-title"><span class="node-title"><?php print $node->title;?></span></span></h3>
        <p><?php print render($content['field_portfolio_description']);?></p>
        <div class="pf-detail-meta">
            <div><span class="pf-meta-label"><?php print t('Category');?></span><span class="pf-meta-info"><?php if(isset($taxonomy_output)) : print $taxonomy_output;endif;?></span></div>
            <p><span class="pf-meta-label"><?php print t('Location');?></span><span class="pf-meta-info"><?php print render($content['field_portfolio_location']);?></span></p>
            <p><span class="pf-meta-label"><?php print t('Skills');?></span><span class="pf-meta-info skill-output"><?php if(isset($skill_output)) : print $skill_output;endif;?></span></p>
            <p><span class="pf-meta-label"><?php print t('Date');?></span><span class="pf-meta-info"><?php print date('d,M Y',$node->created);?></span></p>
        </div><!--end:pf-detail-meta-->
<?php if(strpos('ajax_node',current_path()) !== false):?>
    <?php if(isset($previous)):?>
        <a class="pf-detail-prev" href="#pf-detail-box" onclick="return boom_portfolio_detail_click(jQuery(this),<?php print $previous; ?>,false);"></a>
    <?php endif;?>
        <a class="pf-detail-hide" href="#pf-detail-box" onclick="return boom_portfolio_hide_click(jQuery(this));"></a>
    <?php if(isset($next)):?>
        <a class="pf-detail-next" href="#pf-detail-box" onclick="return boom_portfolio_detail_click(jQuery(this),<?php print $next; ?>,false);"></a>
    <?php endif;?>
<?php endif;?>
    </div><!--end:pf-content-->
</article><!--end:pf-detail-item-->
<script type="text/javascript">
    /***Portfolio Flex slider***/
    jQuery(document).ready(function($){
        jQuery('.flexslider').flexslider({
            animation: "slide",
            slideshow: true,
            start: function(slider){
                jQuery('body').removeClass('loading');
            }
        });
    });

</script>