<?php
/**
 * $node: Node element.
 * $content : Node content.
 * $content['field_name'] : Node field element.
 * Some variables was defined in function md_boom_preprocess_node from inc/template.node.process.inc file
 */
?>
<?php
$taxonomy = $node->field_blog_tag[$node->language];
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
        $taxonomy_output .= '<a href="'.url('taxonomy/term/'.$current[$last_key]['tid'].'').'">'.$current[$last_key]['taxonomy_term']->name.'</a>';
    } else {
        $taxonomy_output .= '<a href="'.url('taxonomy/term/'.$taxonomy[0]['tid'].'').'">'.$taxonomy[0]['taxonomy_term']->name.'</a>';
    }

}
?>
<!--Blog Page-->
<div class="blog_page popup-all clearfix">
    <!--Flex Slider-->
    <div class="wrapper">
        <div class="row-fluid">
            <section class="flx-entry-box">
                <div class="flx-entry-thumb">
                    <?php print render($content['field_blog_image']);?>
                </div><!--end:flx-entry-thumb-->
                <div class="flx-entry-content">
                    <header> <!-- Fixes some node information in header -->
                        <h2 class="entry-title"><span id="node-title"><span class="node-<?php print $node->type;?>-title"><?php print $node->title;?></span></span></h2>
                        <span class="flx-entry-date"><?php print t('Created in '); ?></span><?php print date('m/d/Y',$node->created);?>
                        <span class="flx-entry-meta"><?php print t('Posted by '); ?> </span><a class="flx-entry-author" href="#"><?php print $node->name;?></a>
                        <span class="flx-entry-meta"><?php print t('In '); ?></span><?php if(isset($taxonomy_output)):print $taxonomy_output;endif;?>
                        <span class="flx-entry-meta">|&nbsp;</span><a class="flx-entry-comment" href="#">Comments <?php print $node->comment_count;?></a>
                    </header>
                    <?php
                    hide($content['field_blog_image']);
                    hide($content['field_blog_thumbnail']);
                    hide($content['field_blog_tag']);
                    hide($content['links']);
                    hide($content['comments']);
                    ?>
                    <p><?php print render($content);?></p>
                </div><!--end:flx-entry-content-->
            </section><!--end:flx-entry-box-->

            <div id="comments-box">
                <h3><?php print $node->comment_count;?> comments</h3>
                <?php print render($content['comments']); ?>
            </div><!--end:comments-->
        </div>
    </div>
</div>
<!--Blog page-->