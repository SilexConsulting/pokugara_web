<?php
/**
 * View preprocess
 */
function md_boom_preprocess_views_view(&$vars) {
    $views = $vars['view'];
    if($views->disabled !== true){
        if($views->name == 'overview'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];

            $view_result = (object)$view['result'];
            $vars['view_result'] = $view_result;

            $vars['overview_left'] = '';
            foreach($view_result as $key => $record_left){
                $i=0;
                $title = $record_left->node_title;
                $node_id = $record_left->nid;
                $node_object = node_load($node_id);
                $content_type_name = $node_object->type;
                $icon = $record_left->field_field_overview_icon[$i]['rendered']['#icon'];
                $vars['overview_tabs'] = $icon;
                $vars['overview_left'] .= '<li><a href="#tab-3-'.($key+2).'"><i class="'.$icon.'" title="'.$title.'"></i><span id="node-title"><span class="node-'.$content_type_name.'-title">'.$title.'</span></span></a></li>';
                $i++;
            }
            $vars['overview_right'] = '';
            foreach($view_result as $key => $record_right){
                $y=0;
                $field_overview_skills = $record_right->field_field_overview_skills;
                if($record_right->field_field_overview_body != null){
                    $body = $record_right->field_field_overview_body[0]['rendered']['#markup'];
                }

                $vars['overview_right'] .= ' <div id="tab-3-'.($key+2).'" class="tab-content-3">
                <ul id="flx-skill">';
                foreach($field_overview_skills as $key2 => $skills){
                    $field_id = $skills['raw']['value'];
                    $skill_name = $skills['rendered']['entity']['field_collection_item'][$field_id]['field_skill_name'][0]['#markup'];
                    $skill_level = $skills['rendered']['entity']['field_collection_item'][$field_id]['field_skill_level'][0]['#markup'];

                    $vars['overview_right'] .= '<li class="clearfix"><p class="flx-skill-title">'.$skill_name.'</p>
                        <div class="progress-bar blue animate"> <span class="progress-'.$skill_level.'" style="width: '.$skill_level.'%"><span></span></span></div>
                        <p class="flx-skill-number">'.$skill_level.'%</p>
                        </li>';
                }

                $vars['overview_right'] .= '</ul>';
                if(isset($body)){
                    $vars['overview_right'] .=  $body;
                }
                $vars['overview_right'] .= '</div>';
                $y++;
            }
        }
        if($views->name == 'our_team'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'service'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'portfolio'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $view_result = (object)$view['result'];
            $taxo = taxonomy_vocabulary_machine_name_load('portfolio_category');
            $terms = taxonomy_get_tree($taxo->vid);
            $vars['taxonomy_list_terms'] = $terms;
        }
        if($views->name == 'blog'){
            $view = (array)$views;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = (object)$view['result'];
        }
        if($views->name == 'contact'){
            $view = (array)$views;
            //var_dump($view);die;
            $vars['view_name'] = $view['name'];
            $vars['view_human_name'] = $view['human_name'];
            $vars['view_description'] = $view['description'];
            $result = $view['result'];

            $vars['content_type_name'] = $view['type'];
            if(isset($result[0])) {
                $nid = $result[0]->nid;
                $node_object = node_load($nid);
                $webform = $node_object->webform;
                $components = $webform['components'];
                $field_webform_body = $view['field']['webform_form_body']->last_render;
                $vars['webform_content'] = $field_webform_body;
            }

        }
    }

}
