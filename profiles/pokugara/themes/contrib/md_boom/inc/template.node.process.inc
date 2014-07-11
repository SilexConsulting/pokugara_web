<?php
/**
 * Override or insert vars into the node template.
 */
function md_boom_preprocess_node(&$vars) {
    $themepath = drupal_get_path('theme', 'md_boom');
    drupal_add_js($themepath . '/js/onepage/custom-node.js');

    if (theme_get_setting('extra_article_classes')) {
        if (module_exists('translation')) {
            if ($vars['node']->language) {
                global $language;
                $vars['classes_array'][] = 'article-lang-'. $vars['node']->language;
            }
        }
    }

    $vars['classes_array'][] = $vars['zebra'];

    $vars['submitted'] = t('Published by !username on !datetime', array('!username' => $vars['name'], '!datetime' => $vars['date']));

    if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
        $vars['classes_array'][] = 'node-full';
    }

    if ($vars['view_mode'] == 'teaser') {
        $vars['classes_array'][] = "node-".$vars['node']->type."-teaser";
    }

    $vars['nodeurl'] = url("node/".$vars['node']->nid, array('absolute' => TRUE));

    $node_content_type = (theme_get_setting('node_enable') == 1) ? $vars['node']->type : 'default';

    $vars['node_share_position'] = theme_get_setting('node_share_position_'. $node_content_type);

    $vars['facebook_display'] = theme_get_setting('node_share_facebook_'. $node_content_type);
    if (theme_get_setting('node_share_facebook_'. $node_content_type)){
        $vars['facebook_layout'] = theme_get_setting('node_share_facebook_layout_'. $node_content_type);
        $vars['facebook_display_font'] = theme_get_setting('node_share_facebook_font_'. $node_content_type);
        $vars['facebook_display_color'] = theme_get_setting('node_share_facebook_color_'. $node_content_type);
    }

    $vars['twitter_display'] = theme_get_setting('node_share_twitter_'. $node_content_type);
    if (theme_get_setting('node_share_twitter_'. $node_content_type)){
        $vars['twitter_display_style'] = theme_get_setting('node_share_twitter_style_'. $node_content_type);
        $vars['twitter_display_lang'] = theme_get_setting('node_share_twitter_lang_'. $node_content_type);
    }

    $vars['gplus_display'] = theme_get_setting('node_share_gplus_'. $node_content_type);
    if (theme_get_setting('node_share_gplus_'. $node_content_type)){
        drupal_add_js('https://apis.google.com/js/plusone.js', 'external');
        $vars['gplus_display_size'] = theme_get_setting('node_share_gplus_size_'. $node_content_type);
        $vars['gplus_annotation'] = theme_get_setting('node_share_gplus_annotation_'. $node_content_type);
    }

    $vars['pinterest_display'] = theme_get_setting('node_share_pinterest_'. $node_content_type);
    if (theme_get_setting('node_share_pinterest_'. $node_content_type)){
        drupal_add_js('http://assets.pinterest.com/js/pinit.js', 'external');
        $vars['pinterest_layout'] = theme_get_setting('node_share_pinterest_layout_'. $node_content_type);
        $vars['pinterest_media'] = '';
        if (theme_get_setting('node_share_pinterest_image_'. $node_content_type)) {
            $pinterest_image_field = 'field_'.theme_get_setting('node_share_pinterest_image_'. $node_content_type);
            $pinterest_image = $vars['node']->$pinterest_image_field;
            if (isset($pinterest_image) && !empty($pinterest_image['und'][0]['filename'])) {
                $vars['pinterest_media'] = file_create_url(file_build_uri($pinterest_image['und'][0]['filename']));
            }
        }
    }

    $vars['stumble_display'] = theme_get_setting('node_share_stumble_'. $node_content_type);
    if (theme_get_setting('node_share_stumble_'. $node_content_type)){
        $vars['stumble_display_style'] = theme_get_setting('node_share_stumble_style_'. $node_content_type);
    }
        /*===================== Prepare node variable each content type =========================*/
    $node = $vars['node'];
    if($node->type == 'portfolio'){
        $node_id = $node->nid;
        $query1 = new EntityFieldQuery;
        $count_node = $query1->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'portfolio')
            ->propertyCondition('status', 1) // Getting published nodes only.
            ->count()
            ->execute();
        $query2 = new EntityFieldQuery;
        $all_nodes = $query2->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'portfolio')
            ->propertyCondition('status', 1) // Getting published nodes only.
            ->execute();

        $array_nid = array();
        foreach($all_nodes['node'] as $key =>$nid){
            $array_nid[] = $key;
        }

        $random_var = array();
        foreach($array_nid as $nid){
            $array_node_id[] = $nid;
        }
        foreach($array_node_id as $key => $value){
            if($value == $node_id){
                $current_key = $key;
                $next = $key+1;
                $previous = $key-1;
            }
        }
        if(isset($array_node_id[$previous])){
            $vars['previous'] = $array_node_id[$previous];
        }
        if(isset($array_node_id[$next])){
            $vars['next'] = $array_node_id[$next];
        }
    }
    if($node->type == 'blog'){
        $author = user_load($node->uid);
        if(isset($author->field_team_social[$node->language])) {
            $author_social_info = $author->field_team_social[$node->language];
            $author_social = array(
            );
            foreach($author_social_info as $key => $value){
                $field_collection = entity_load('field_collection_item', array($value['value']));
                $idx = $value['value'];
                $author_social_icon = $field_collection[$idx]->field_social_icon[$node->language][0]['icon'];
                $author_social_account = $field_collection[$idx]->field_social_account['und'][0]['value'];
                $author_social[] = array('social_icon' => $author_social_icon,'social_account' => $author_social_account);
            }
            $vars['author_social'] = $author_social;
            $vars['author_description'] = $author->field_user_description[$node->language][0]['safe_value'];
        }
    }
}
