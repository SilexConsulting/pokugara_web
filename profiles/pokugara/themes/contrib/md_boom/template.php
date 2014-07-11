<?php

include_once './' . drupal_get_path('theme', 'md_boom') . '/inc/template.process.inc';
include_once './' . drupal_get_path('theme', 'md_boom') . '/inc/template.view.process.inc';
include_once './' . drupal_get_path('theme', 'md_boom') . '/inc/template.node.process.inc';
/**
 * Implements theme_menu_tree().
 */
function md_boom_menu_tree($variables) {
    return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function md_boom_field__taxonomy_term_reference($variables) {
    $output = '';

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
        $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
    }

    // Render the items.
    $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
    foreach ($variables['items'] as $delta => $item) {
        $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    $output .= '</ul>';

    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '">' . $output . '</div>';

    return $output;
}

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */
function md_boom_textarea($variables) {
    $element = $variables['element'];
    $element['#attributes']['name'] = $element['#name'];
    $element['#attributes']['id'] = $element['#id'];
    $element['#attributes']['cols'] = $element['#cols'];
    $element['#attributes']['rows'] = $element['#rows'];
    _form_set_class($element, array('form-textarea'));

    $wrapper_attributes = array(
        'class' => array('form-textarea-wrapper'),
    );

    // Add resizable behavior.
    if (!empty($element['#resizable'])) {
        $wrapper_attributes['class'][] = 'resizable';
    }

    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
}

/**
 * @param $variables
 * @return Main menu
 */
function md_boom_links__system_main_menu($variables) {
    $html = "<div>\n";
    $html .= "  <ul>\n";
    foreach ($variables['links'] as $link) {
        $html .= "<li>".l($link['title'], $link['path'].$link['menu_scrollto_path'], $link)."</li>";
    }
    $html .= "  </ul>\n";
    $html .= "</div>\n";

    return $html;
}

function phptemplate_preprocess_page(&$vars){
    if ( isset($_GET['ajax']) && $_GET['ajax'] == 1 ) {
        $vars['template_file'] = 'page-ajax';
    }
}
/**
 * Check file path upload in theme setting
 */
function md_boom_theme_setting_check_path($path) {
    $path_scheme = file_uri_scheme($path);
    if ($path_scheme == 'public') {
        $return_path = file_create_url($path);
    } else if (($path_scheme == 'http') || ($path_scheme == 'https')) {
        $return_path = $path;
    } else {
        $return_path = file_create_url(file_build_uri($path));
    }
    return $return_path;
}

/**
 * @param $path
 * @param $upload
 * @param $form_state_value
 * @return mixed
 */
function saveImage($path, $upload, $form_state_value) {
    if ($image_file = file_save_upload($upload)) {
        $parts = pathinfo($image_file->filename);
        $destination = 'public://' . $parts['basename'];
        $image_file->status = FILE_STATUS_PERMANENT;
        if (file_copy($image_file, $destination, FILE_EXISTS_REPLACE)) {
            $_POST[$path] = $form_state_value[$path] = $parts['basename'];
        }
    }
    if ($file_path = $form_state_value[$path]) {
        $file_scheme = file_uri_scheme($path);
        if($file_scheme == 'http' || $file_scheme == 'https'){
            $newimagename = basename(rawurldecode($file_path));
            $external_file = file_get_contents(rawurldecode($file_path));
            file_save_data($external_file, 'public://'.$newimagename.'',$replace = FILE_EXISTS_REPLACE);
            $form_state_value[$path] = $newimagename;
        }
    }
    return $form_state_value;
}
/**
 * @param $haystack
 * @param $needle
 * @param int $offset
 * @return bool
 * Check string in string
 */
function strposa($haystack, $needle, $offset=0) {
    if(!is_array($needle)) $needle = array($needle);
    foreach($needle as $query) {
        if(strpos($haystack, $query, $offset) !== false) return true; // stop on first true result
    }
    return false;
}