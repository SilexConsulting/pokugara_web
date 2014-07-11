<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php
$style_w3_h2 = 'portfolio_thumbnail_584x250';
$style_w1_h1 = 'portfolio_thumbnail_188x120';
$style_w2_h2 = 'portfolio_thumbnail_385x250';
$style_w1_h2 = 'portfolio_thumbnail_188x250';
if($fields['field_portfolio_layout_mode']->content){
    $portfolio_layout_mode = $fields['field_portfolio_layout_mode']->content;
    if($portfolio_layout_mode == '7'){
        $style_name = $style_w2_h2;
    }
    if($portfolio_layout_mode == '2'){
        $style_name = $style_w1_h1;
    }
    if($portfolio_layout_mode == '3'){
        $style_name = $style_w3_h2;
    }
    if($portfolio_layout_mode == '6'){
        $style_name = $style_w1_h2;
    }
}
if($fields['field_portfolio_thumbnail']->content){
    $portfolio_image = $row->field_field_portfolio_thumbnail[0]['raw']['uri'];
    if(isset($style_name)){
        $image_style_url = theme('image_style', array('style_name' => $style_name,'path' => $portfolio_image));
    }
}
?>

<div class="element
<?php if(isset($row->field_field_portfolio_taxonomy)) {
    foreach ($row->field_field_portfolio_taxonomy as $key => $value) {
        print ' flx-'.$value['raw']['tid'].' ';
    }
} ?>
">
    <p class="number"><?php print $fields['field_portfolio_layout_mode']->content;?></p>
    <div class="mask clickable" data-nid="<?php print $row->nid;?>">
        <a class="flx-pf-gallery" href="<?php print file_create_url($portfolio_image);?>" rel="prettyPhoto[flx-gallery-<?php if(isset($row->field_field_portfolio_taxonomy[0])) {print $row->field_field_portfolio_taxonomy[0]['raw']['tid'];}?>]"></a>
        <h4><a class="flx-pf-detail clickable" href="#pf-detail-box" data-nid="<?php print $row->nid;?>"><?php print t($row->node_title);?></a></h4>
    </div>
    <?php if(isset($image_style_url)):?>
    <?php print $image_style_url;?>
    <?php else:?>
    <?php print $fields['field_portfolio_thumbnail']->content;?>
    <?php endif;?>
</div>

