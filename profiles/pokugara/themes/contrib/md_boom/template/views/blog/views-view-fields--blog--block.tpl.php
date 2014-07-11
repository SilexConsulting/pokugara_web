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
<li>
    <article class="flx-entry-item">

        <div class="flx-entry-thumb">
            <a class="popup-ajax"  href="?q=ajax_node&nid=<?php print $row->nid;?>">
                <p class="mask"></p>
                <?php print $fields['field_blog_thumbnail']->content;?>
            </a>
        </div><!--end:flx-entry-thumb-->

        <div class="flx-entry-content">
            <div class="flx-entry-detail">
                <h3 class="flx-entry-title"><span id="node-title"><span class="node-<?php print $view->name;?>-title"><a class="popup-ajax" href="?q=ajax_node&nid=<?php print $row->nid;?>"><?php print $fields['title']->content;?></a></span></span></h3>
                <div class="flx-entry-meta clearfix">
                    <span class="flx-entry-author"><i class="icon-user"></i><a href="#"><?php print $fields['name']->content;?></a></span>
                    <span class="flx-entry-date"><i class="icon-calendar"></i><?php print $fields['created']->content;?></span>
                    <span class="flx-entry-categories"><i class="icon-menu"></i><?php print $fields['term_node_tid']->content;?></span>
                </div><!--end:flx-entry-meta-->
                <p><?php print $fields['field_blog_body']->content;?><a class="popup-ajax" href="?q=ajax_node&nid=<?php print $row->nid;?>">[...]</a></p>
            </div><!--end:flx-entry-detail-->
            <div class="clear"></div>
        </div><!--end:flx-entry-content-->
    </article>
</li>