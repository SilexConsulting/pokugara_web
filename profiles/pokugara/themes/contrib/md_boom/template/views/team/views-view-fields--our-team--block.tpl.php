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
<li style="width: 230px;">
    <article class="flx-team">
        <a class="team-avatar" href="#"><?php print $fields['field_team_avatar']->content;?></a>
        <ul class="about-social-link clearfix">
            <?php print $fields['field_team_social']->content;?>
        </ul><!--end:about-social-link-->
        <!--end:about-social-link-->
        <h5><span id="node-title"><span class="node-<?php print $view->name;?>-title"><a href="#"><?php print $fields['title']->content;?></a></span></span></h5>
        <span><?php print $fields['field_team_job']->content;?></span>
    </article><!--end:flx-team-->
</li>

