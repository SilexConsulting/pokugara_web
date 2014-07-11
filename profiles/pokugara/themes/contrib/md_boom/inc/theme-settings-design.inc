<?php

/**
 * @file
 * Theme settings .
 */

function md_boom_theme_settings_design(&$form, &$form_state) {
	$form['md_boom_settings']['design'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -4,
		'#prefix'  				=> '<div id="md-design" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-design -->',
	);
	
	$form['md_boom_settings']['design']['design_htmllist'] = array(
		'#markup' 				=> '<div class="md-listleft">
				<ul>
				    <li><a href="#ds-general">Skins</a></li>
					<li><a href="#ds-parallax">Parallax</a></li>
				</ul>
			</div><div class="md-listcontent">',
		'#weight' 				=> -15,
	);
	$form['md_boom_settings']['design']['design_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);
    $form['md_boom_settings']['design']['design_general'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-general" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    // Site skins
    $form['md_boom_settings']['design']['design_general']['skins'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose skin'),
        '#default_value' => theme_get_setting('skins'),
        '#options'       => array(
            'default'   => t('Default (Orange)'),
            'blue' 	    => t('Blue'),
            'brown' 	=> t('Brown'),
            'gray' 	    => t('Gray'),
            'green' 	=> t('Green'),
            'pink' 	    => t('Pink'),
            'red' 	    => t('Red'),
            'violet'    => t('Violet')
        ),
        '#prefix' => '<div id="design-skins" class="clearfix">',
        '#suffix' => '</div>',
    );

    /* 6.	Parallax
    --------------------------------------------------------------------------*/


    $form['md_boom_settings']['design']['design_parallax'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="ds-parallax" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    for($i=1;$i<=5;$i++) {
        $parallax_enabled = theme_get_setting('parallax_'.$i.'_enabled','md_boom');
        $form['md_boom_settings']['design']['design_parallax']['parallax_'.$i] = array(
            '#type'             => 'fieldset',
            '#title'            => t('<h1>Parallax 1</h1>'),
            '#description'      => t(''),
        );
        $form['md_boom_settings']['design']['design_parallax']['parallax_'.$i]['parallax_'.$i.'_enabled'] = array(
            '#type'             => 'checkbox',
            '#title'            => t('Enable Parallax 1'),
            '#default_value'    => $parallax_enabled,
            '#suffix'           => '<div id="parallax-1-custom">',

        );
        $parallax_path = theme_get_setting('parallax_'.$i.'_path','md_boom');
        $form['md_boom_settings']['design']['design_parallax']['parallax_'.$i]['parallax_'.$i.'_path'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background'),
            '#default_value' =>  $parallax_path,
            '#prefix' => '<div id="design-parallax-'.$i.'-custom" class="clearfix">',
        );

        $form['md_boom_settings']['design']['design_parallax']['parallax_'.$i]['parallax_'.$i.'_upload'] = array(
            '#type' => 'file',
            '#suffix'   => 'Your background image should be 1600x1000 or higher</div>',
        );
        $form['md_boom_settings']['design']['design_parallax']['parallax_'.$i]['parallax_'.$i.'_enable_close'] = array(
            '#markup' 				=> '</div>'
        );
    }
}
