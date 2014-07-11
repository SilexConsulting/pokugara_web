<?php

/**
 * @file
 * Theme settings .
 */

function md_boom_theme_settings_display(&$form, &$form_state) {
    $form['md_boom_settings']['display'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -1,
        '#prefix'  				=> '<div id="md-display" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #md-display -->',
    );

    $form['md_boom_settings']['display']['display_htmllist'] = array(
        '#markup' 				=> '<div class="md-listleft">
				<ul>
					<li><a href="#s-contact">Contact</a></li>
					<li><a href="#s-footer">Footer</a></li>
					<li><a href="#s-map">Map</a></li>
				</ul>
			</div><div class="md-listcontent">',
        '#weight' 				=> -15,
    );

    $form['md_boom_settings']['display']['display_htmllistclose'] = array(
        '#markup' 				=> '</div><!-- /.md-listleft -->',
        '#weight' 				=> 15,
    );

    /*---------------- Contact Detail ----------------------*/

    $email = theme_get_setting('sites_email','md_boom');
    $address = theme_get_setting('address','md_boom');
    $phone = theme_get_setting('phone','md_boom');
    $fax = theme_get_setting('fax','md_boom');
    $description = theme_get_setting('sites_description','md_boom');
    $form['md_boom_settings']['display']['contact']['detail'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="s-contact" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #contact -->',
    );
    $form['md_boom_settings']['display']['contact']['detail']['webform_title'] = array(
        '#type' => 'textfield',
        '#title'    => 'Webform Title',
        '#default_value'    => theme_get_setting('webform_title','md_boom')
    );
    $form['md_boom_settings']['display']['contact']['detail']['webform_des'] = array(
        '#type' => 'textfield',
        '#title'    => 'Webform Description',
        '#default_value'    => theme_get_setting('webform_des','md_boom')
    );
    $form['md_boom_settings']['display']['contact']['detail']['sites_email'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Sites Email'),
        '#default_value' 	=>      $email ? $email : t('contact@megadrupal.com'),
        '#prefix'					=> '<h3>' . t('Contact Detail') . '</h3>',
    );
    $form['md_boom_settings']['display']['contact']['detail']['address'] = array(
        '#type' 					=> 'textarea',
        '#resizable'    => false,
        '#title'					=> t('Address'),
        '#default_value' 	=>  $address ? $address : t('Ha Noi, Viet Nam'),

    );
    $form['md_boom_settings']['display']['contact']['detail']['phone'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Phone'),
        '#default_value' 	=>  $phone ? $phone : t('+84 123 456 789'),

    );
    $form['md_boom_settings']['display']['contact']['detail']['fax'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Fax'),
        '#default_value' 	=>  $fax ? $fax : t('+84 012 345 6789'),

    );
    $form['md_boom_settings']['display']['contact']['detail']['sites_description'] = array(
        '#type' 					=> 'textarea',
        '#resizable'    => false,
        '#title'					=> t('Sites Description'),
        '#default_value' 	=>  $description ? $description : t('<h5>Say Hello !</h5>
<p>To find out more about what we can do for you, request some more examples of our work, or arrange a meeting, please dont hesitate to get in touch.</p>'),

    );

    $form['md_boom_settings']['display']['footer'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -7,
        '#prefix'  				=> '<div id="s-footer" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #footer -->',
    );
    $form['md_boom_settings']['display']['footer']['footer_text'] = array(
        '#type' 					=> 'textarea',
        '#resizable'    => false,
        '#title'					=> t('Footer Text'),
        '#default_value' 	        =>  theme_get_setting('footer_text','md_boom') ? theme_get_setting('footer_text','md_boom') : '<p id="copyright">
                                        <strong>MD Boom - Designed by Felixplus</strong>
                                        - Drupal theme by
                                        <a href="http://megadrupal.com">MegaDrupal</a>
                                        </p>
                                        <p>All stock photos used on this Boom demo site are only for demo purposes and not included in the template package.</p>',
        '#prefix'					=> '<h3>' . t('Footer Detail') . '</h3>',
    );
    $form['md_boom_settings']['display']['map'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -8,
        '#prefix'  				=> '<div id="s-map" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #footer -->',
    );
    $form['md_boom_settings']['display']['map']['map_latlng'] = array(
        '#type' 					=> 'textfield',
        '#title'					=> t('Google Map location'),
        '#default_value' 	        =>  theme_get_setting('map_latlng','md_boom') ? theme_get_setting('map_latlng','md_boom') : t('40.748395,-73.985542'),
        '#description'              =>  t('Find your map point by reading our documentation'),
    );
    $form['md_boom_settings']['display']['map']['map_types']   = array(
        '#type'         => 'select',
        '#title'        => t('Map types'),
        '#options'      => array(
            'ROADMAP'  => t('Road Map'),
            'SATELINE' => t('Sate Line'),
            'HYBRID'    => t('Hybrid'),
            'TERRAIN'   => t('Terrain'),
        ),
        '#default_value'    => theme_get_setting('map_types','md_boom') ? theme_get_setting('map_types','md_boom') : t('ROADMAP'),
    );
    $form['md_boom_settings']['display']['map']['map_zoom_level'] = array(
        '#type'         => 'textfield',
        '#title'        => t(' Map Zoom Level'),
        '#default_value'    => theme_get_setting('map_zoom_level','md_boom') ? theme_get_setting('map_zoom_level','md_boom') : 16,
    );
}