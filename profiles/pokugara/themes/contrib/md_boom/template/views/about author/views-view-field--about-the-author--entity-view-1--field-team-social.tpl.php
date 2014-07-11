<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$output = '';
foreach($row->field_field_team_social as $social){
    $raw_value = $social['raw']['value'];
    $social_icon = $social['rendered']['entity']['field_collection_item'][$raw_value]['field_social_icon'][0]['#icon'];
    $social_account = $social['rendered']['entity']['field_collection_item'][$raw_value]['field_social_account'][0]['#markup'];

    $output .= '<a href="'.$social_account.'"><i class="'.$social_icon.'"></i></a>';
}
print $output;
?>