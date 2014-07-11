<?php

/**
 * @file
 * Theme settings .
 */

function md_boom_theme_settings_text(&$form, &$form_state) {
	$form['md_boom_settings']['text'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -3,
		'#prefix'  				=> '<div id="md-text-typography" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-text-typography -->',
	);
	
	$form['md_boom_settings']['text']['text_htmllist'] = array(
		'#markup' 				=> '<div class="md-listleft">
				<ul>
					<li><a href="#tt-text">Text &amp; Links</a></li>
					<li><a href="#tt-typography">Typography</a></li>
				</ul>
			</div><div class="md-listcontent">',
		'#weight' 				=> -15,
	);
	
	$form['md_boom_settings']['text']['text_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);
	
	/* 1.	Text & link style
	--------------------------------------------------------------------------*/
	$form['md_boom_settings']['text']['text_normal'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -5,
		'#prefix'  				=> '<div id="tt-text" class="md-tabcontent clearfix">',
		'#suffix'        	=> '</div><!-- / #tt-text -->',
	);
		
		// Text
		$form['md_boom_settings']['text']['text_normal']['text_style'] = array(
	        '#type' 					=> 'fieldset',
			'#prefix'  				=> '<h3>'.t('Text style').'</h3>',
	    );
		
			$form['md_boom_settings']['text']['text_normal']['text_style']['text_font'] = array(
				'#type'          	=> 'hidden',
				'#default_value' 	=> theme_get_setting('text_font','md_boom'),
				'#prefix' => '<div id="text-font" class="choosefont clearfix">',
				'#suffix' => '</div>',
			);
			
			$form['md_boom_settings']['text']['text_normal']['text_style']['ts_font_color'] = array(
				'#type'          	=> 'textfield',
				'#title'         	=> t('Color'),
				'#default_value' 	=> theme_get_setting('ts_font_color','md_boom'),
				'#prefix' => '<div class="form-font-color">',
				'#suffix' => '</div>',
				'#attributes' 		=> array(
                                            'class' => array(
                                                'form-colorpicker',
                                            ),
	            ),
			);

		// Text selection
		$form['md_boom_settings']['text']['text_normal']['text_selection'] = array(
	    '#type' 					=> 'fieldset',
			'#prefix'  				=> '<h3>'.t('Text selection style').'</h3>',
	    );
			
			$form['md_boom_settings']['text']['text_normal']['text_selection']['tss_bgcolor'] = array(
				'#type'          	=> 'textfield',
				'#title'         	=> t('Background color'),
				'#default_value' 	=> theme_get_setting('tss_bgcolor','md_boom'),
				'#prefix' => '<div class="form-font-color">',
				'#suffix' => '</div>',
				'#attributes' 		=> array(
                                            'class' => array(
                                                'form-colorpicker',
                                            ),
	            ),
			);
			
			$form['md_boom_settings']['text']['text_normal']['text_selection']['tss_tcolor'] = array(
				'#type'          	=> 'textfield',
				'#title'         	=> t('Text color'),
				'#default_value' 	=> theme_get_setting('tss_tcolor','md_boom'),
				'#prefix' => '<div class="form-font-color">',
				'#suffix' => '</div>',
				'#attributes' 		=> array(
                                            'class' => array(
                                                'form-colorpicker',
                                            ),
	            ),
			);
			
		// Link
		$form['md_boom_settings']['text']['text_normal']['link_style'] = array(
	    '#type' 					=> 'fieldset',
			'#prefix'  				=> '<h3>'.t('Link style').'</h3>',
			'#description'		=> t('This change will be applied to every link in your website'),
	  );
			
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_style_htmllist'] = array(
				'#markup' 				=> '<div id="md-subtabs" class="md-subtabs">
								<div class="md-subtabs-head">
		              <ul class="clearfix">
		                <li class="subtab-item clearfix first"> <a class="subtab-link" href="#link-regular">Regular</a> </li>
		                <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-rollover">Rollover</a> </li>
		                <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-visited">Visited</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#link-on">On</a> </li>
		              </ul>
		            </div>',
				'#weight' 				=> -15,
			);
			
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_style_htmllistclose'] = array(
				'#markup' 				=> '</div><!-- /#sub-tab -->',
				'#weight' 				=> 15,
			);
			
			// Link regular
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_regular'] = array(
				'#type' 					=> 'fieldset',
				'#weight' 				=> -5,
				'#prefix'  				=> '<div id="link-regular" class="md-subtabcontent clearfix">',
				'#suffix'        => '</div><!-- / #link-regular -->',
			);
			
				md_boom_prepare_link_style($form,'regular');
			
			// Link rollover
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_rollover'] = array(
				'#type' 					=> 'fieldset',
				'#weight' 				=> -4,
				'#prefix'  				=> '<div id="link-rollover" class="md-subtabcontent clearfix">',
				'#suffix'        => '</div><!-- / #link-rollover -->',
			);
			
				md_boom_prepare_link_style($form,'rollover');
			
			// Link visited
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_visited'] = array(
				'#type' 					=> 'fieldset',
				'#weight' 				=> -3,
				'#prefix'  				=> '<div id="link-visited" class="md-subtabcontent clearfix">',
				'#suffix'        => '</div><!-- / #link-visited -->',
			);
			
				md_boom_prepare_link_style($form,'visited');
			
			// Link on
			$form['md_boom_settings']['text']['text_normal']['link_style']['link_on'] = array(
				'#type' 					=> 'fieldset',
				'#weight' 				=> -2,
				'#prefix'  				=> '<div id="link-on" class="md-subtabcontent clearfix">',
				'#suffix'        => '</div><!-- / #link-on -->',
			);
			
				md_boom_prepare_link_style($form,'on');
	
	/* 2.	Typography
	--------------------------------------------------------------------------*/
	$form['md_boom_settings']['text']['text_typography'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -5,
		'#prefix'  				=> '<div id="tt-typography" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #tt-typography -->',
	);
    /*--------------------------------- Heading Style -------------------------------------------------*/
    $form['md_boom_settings']['text']['text_typography']['typo_heading'] = array(
        '#type' 					=> 'fieldset',
        '#prefix'  				=> '<h3>'.t('Heading').'</h3>',
    );

    $form['md_boom_settings']['text']['text_typography']['typo_heading']['typo_heading_style_enable'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Use custom settings for each Heading instead of the default above'),
        '#default_value' => theme_get_setting('typo_heading_style_enable','md_boom') ? theme_get_setting('typo_heading_style_enable','md_boom') : 0,
        '#suffix'				=> '<div id="typo-heading-style-custom-typo">',
    );

    for($i=1;$i<=6;$i++){
        $form['md_boom_settings']['text']['text_typography']['typo_heading']['typo_heading_h'.$i.''] = array(
            '#type' 					=> 'fieldset',
            '#prefix'  				=> '<h3>'.t('Heading !name', array('!name' => t($i))).'</h3>',
            '#description'		=> t('Change the Heading h'.$i.' font.'),
        );
        $form['md_boom_settings']['text']['text_typography']['typo_heading']['typo_heading_h'.$i.'']['typo_heading_h'.$i.'_style'] = array(
            '#type'          	=> 'hidden',
            '#default_value' 	=> theme_get_setting('typo_heading_h'.$i.'_style','md_boom'),
            '#prefix' => '<div id="typo_heading_h'.$i.'_style" class="choosefont clearfix">',
            '#suffix' => '</div>',
        );

        $form['md_boom_settings']['text']['text_typography']['typo_heading']['typo_heading_h'.$i.'']['typo_heading_h'.$i.'_color'] = array(
            '#type'          	=> 'textfield',
            '#title'         	=> t('Color'),
            '#default_value' 	=> theme_get_setting('typo_heading_h'.$i.'_color'),
            '#prefix' => '<div class="form-font-color">',
            '#suffix' => '</div>',
            '#attributes' 		=> array(
                'class' => array(
                    'form-colorpicker',
                ),
            ),
        );
    }


    $form['md_boom_settings']['text']['text_typography']['typo_heading']['typo_heading_style_enable_close'] = array(
        '#markup' 				=> '</div>'
    );
		// Node title
		$form['md_boom_settings']['text']['text_typography']['typo_nodetitle'] = array(
	    '#type' 					=> 'fieldset',
			'#prefix'  				=> '<h3>'.t('Node title').'</h3>',
			'#description'		=> t('Change the Node title font.'),
	  );
		
	  	$form['md_boom_settings']['text']['text_typography']['typo_nodetitle']['typo_nodetitle_style'] = array(
				'#type'          	=> 'hidden',
				'#default_value' 	=> theme_get_setting('typo_nodetitle_style','md_boom'),
				'#prefix' => '<div id="typo-nodetitle-style" class="choosefont clearfix">',
				'#suffix' => '</div>',
			);
			
			$form['md_boom_settings']['text']['text_typography']['typo_nodetitle']['nodetitle_color'] = array(
				'#type'          	=> 'textfield',
				'#title'         	=> t('Color'),
				'#default_value' 	=> theme_get_setting('nodetitle_color','md_boom'),
				'#prefix' => '<div class="form-font-color">',
				'#suffix' => '</div>',
				'#attributes' 		=> array(
														'class' => array(
															'form-colorpicker',
														),
	      ),
			);
			
			$form['md_boom_settings']['text']['text_typography']['typo_nodetitle']['nodetitle_hover_color'] = array(
				'#type'          	=> 'textfield',
				'#title'         	=> t('Hover color'),
				'#default_value' 	=> theme_get_setting('nodetitle_hover_color','md_boom'),
				'#prefix' => '<div class="form-font-color">',
				'#suffix' => '</div>',
				'#attributes' 		=> array(
														'class' => array(
															'form-colorpicker',
														),
	      ),
			);
			
		$form['md_boom_settings']['text']['text_typography']['nodetitle_enable'] = array(
	    '#type'          => 'checkbox',
	    '#title'         => t('Use custom settings for each content type instead of the default above'),
	    '#default_value' => theme_get_setting('nodetitle_enable','md_boom'),
			'#suffix'				=> '<div id="node-custom-typo">',
	  );
		
		foreach (node_type_get_types() as $type => $name) {
			$form['md_boom_settings']['text']['text_typography']['typo_n'.$type.'title'] = array(
		    '#type' 					=> 'fieldset',
				'#prefix'  				=> '<h3>'.t('!name title', array('!name' => t($type))).'</h3>',
				'#description'		=> t('Change the '.$type.' title font.'),
		  );
				$form['md_boom_settings']['text']['text_typography']['typo_n'.$type.'title']['typo_n'.$type.'title_style'] = array(
					'#type'          	=> 'hidden',
					'#default_value' 	=> theme_get_setting('typo_n'.$type.'title_style','md_boom'),
					'#prefix' => '<div id="typo-n'.$type.'title-style" class="choosefont clearfix">',
					'#suffix' => '</div>',
				);
				
				$form['md_boom_settings']['text']['text_typography']['typo_n'.$type.'title']['n'.$type.'title_color'] = array(
					'#type'          	=> 'textfield',
					'#title'         	=> t('Color'),
					'#default_value' 	=> theme_get_setting('n'.$type.'title_color','md_boom'),
					'#prefix' => '<div class="form-font-color">',
					'#suffix' => '</div>',
					'#attributes' 		=> array(
															'class' => array(
																'form-colorpicker',
															),
		      ),
				);
				
				$form['md_boom_settings']['text']['text_typography']['typo_n'.$type.'title']['n'.$type.'title_hover_color'] = array(
					'#type'          	=> 'textfield',
					'#title'         	=> t('Hover color'),
					'#default_value' 	=> theme_get_setting('n'.$type.'title_hover_color','md_boom'),
					'#prefix' => '<div class="form-font-color">',
					'#suffix' => '</div>',
					'#attributes' 		=> array(
															'class' => array(
																'form-colorpicker',
															),
		      ),
				);
	  }
		
		$form['md_boom_settings']['text']['text_typography']['nodetitle_enable_close'] = array(
	    '#markup' 				=> '</div>'
	  );

    if(module_exists('views') == TRUE) {
    // View block title
    $form['md_boom_settings']['text']['text_typography']['typo_view_title'] = array(
        '#type' 					=> 'fieldset',
        '#prefix'  				=> '<h3>'.t('View title').'</h3>',
        '#description'		=> t('Change the View title font.'),
    );

    $form['md_boom_settings']['text']['text_typography']['typo_view_title']['typo_view_title_style'] = array(
        '#type'          	=> 'hidden',
        '#default_value' 	=> theme_get_setting('typo_view_title_style','md_boom'),
        '#prefix' => '<div id="typo-view-title-style" class="choosefont clearfix">',
        '#suffix' => '</div>',
    );

    $form['md_boom_settings']['text']['text_typography']['typo_view_title']['typo_view_title_color'] = array(
        '#type'          	=> 'textfield',
        '#title'         	=> t('Color'),
        '#default_value' 	=> theme_get_setting('typo_view_title_color','md_boom'),
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>',
        '#attributes' 		=> array(
            'class' => array(
                'form-colorpicker',
            ),
        ),
    );

    $form['md_boom_settings']['text']['text_typography']['typo_view_title_enable'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Use custom settings for each content type instead of the default above'),
        '#default_value' => theme_get_setting('typo_view_title_enable','md_boom'),
        '#suffix'				=> '<div id="typo-view-title-custom-typo">',
    );

        $views = views_get_all_views($reset =  FALSE);
        foreach($views as $view_name => $view){
            if(($view->disabled) !== true ){
                $view_title = $view->name;
                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_title'] = array(
                    '#type' 					=> 'fieldset',
                    '#prefix'  				=> '<h3>'.t('!name title', array('!name' => t($view_title))).'</h3>',
                    '#description'		=> t('Change the '.$view_title.' title font.'),
                );
                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_title']['typo_view_'.$view_title.'_title_style'] = array(
                    '#type'          	=> 'hidden',
                    '#default_value' 	=> theme_get_setting('typo_view_'.$view_title.'_title_style','md_boom'),
                    '#prefix' => '<div id="typo_view_'.$view_title.'_title_style" class="choosefont clearfix">',
                    '#suffix' => '</div>',
                );

                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_title']['typo_view_'.$view_title.'_title_color'] = array(
                    '#type'          	=> 'textfield',
                    '#title'         	=> t('Color'),
                    '#default_value' 	=> theme_get_setting('typo_view_'.$view_title.'_title_color','md_boom'),
                    '#prefix' => '<div class="form-font-color">',
                    '#suffix' => '</div>',
                    '#attributes' 		=> array(
                        'class' => array(
                            'form-colorpicker',
                        ),
                    ),
                );
            }
        }

        $form['md_boom_settings']['text']['text_typography']['typo_view_title_enable_close'] = array(
            '#markup' 				=> '</div>'
        );

        //View block description

        $form['md_boom_settings']['text']['text_typography']['typo_view_description'] = array(
            '#type' 					=> 'fieldset',
            '#prefix'  				=> '<h3>'.t('View description').'</h3>',
            '#description'		=> t('Change the View description font.'),
        );

        $form['md_boom_settings']['text']['text_typography']['typo_view_description']['typo_view_description_style'] = array(
            '#type'          	=> 'hidden',
            '#default_value' 	=> theme_get_setting('typo_view_description_style','md_boom'),
            '#prefix' => '<div id="typo-view-description-style" class="choosefont clearfix">',
            '#suffix' => '</div>',
        );

        $form['md_boom_settings']['text']['text_typography']['typo_view_description']['typo_view_description_color'] = array(
            '#type'          	=> 'textfield',
            '#description'         	=> t('Color'),
            '#default_value' 	=> theme_get_setting('typo_view_description_color','md_boom'),
            '#prefix' => '<div class="form-font-color">',
            '#suffix' => '</div>',
            '#attributes' 		=> array(
                'class' => array(
                    'form-colorpicker',
                ),
            ),
        );


        $form['md_boom_settings']['text']['text_typography']['typo_view_description_enable'] = array(
            '#type'          => 'checkbox',
            '#description'         => t('Use custom settings for each content type instead of the default above'),
            '#default_value' => theme_get_setting('typo_view_description_enable','md_boom'),
            '#suffix'				=> '<div id="typo-view-description-custom-typo">',
        );
        foreach($views as $view_name => $view){
            if(($view->disabled) !== true ){
                $view_title = $view->name;
                $view_description = $view->description;
                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_description'] = array(
                    '#type' 					=> 'fieldset',
                    '#prefix'  				=> '<h3>'.t('!name description', array('!name' => t($view_title))).'</h3>',
                    '#description'		=> t('Change the '.$view_title.' description font.'),
                );
                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_description']['typo_view_'.$view_title.'_description_style'] = array(
                    '#type'          	=> 'hidden',
                    '#default_value' 	=> theme_get_setting('typo_view_'.$view_title.'_description_style','md_boom'),
                    '#prefix' => '<div id="typo_view_'.$view_title.'_description_style" class="choosefont clearfix">',
                    '#suffix'   => '</div>',
                );

                $form['md_boom_settings']['text']['text_typography']['typo_view_'.$view_title.'_description']['typo_view_'.$view_title.'_description_color'] = array(
                    '#type'          	=> 'textfield',
                    '#description'         	=> t('Color'),
                    '#default_value' 	=> theme_get_setting('typo_view_'.$view_title.'_description_color','md_boom'),
                    '#prefix' => '<div class="form-font-color">',
                    '#suffix' => '</div>',
                    '#attributes' 		=> array(
                        'class' => array(
                            'form-colorpicker',
                        ),
                    ),
                );

            }
        }
        $form['md_boom_settings']['text']['text_typography']['typo_view_description_enable_close'] = array(
            '#markup' 				=> '</div>'
        );
    }
    $form['md_boom_settings']['text']['text_typography']['typo_webform'] = array(
        '#type' 					=> 'fieldset',
        '#prefix'  				=> '<h3>'.t('Webform title').'</h3>',
        '#description'		=> t('Change the Webform title font.'),
    );
        $form['md_boom_settings']['text']['text_typography']['typo_webform']['typo_webformtitle_style'] = array(
            '#type'          	=> 'hidden',
            '#default_value' 	=> theme_get_setting('typo_webformtitle_style','md_boom'),
            '#prefix' => '<div id="typo-webformtitle-style" class="choosefont clearfix">',
            '#suffix' => '</div>',
        );

        $form['md_boom_settings']['text']['text_typography']['typo_webform']['typo_webformtitle_color'] = array(
            '#type'          	=> 'textfield',
            '#title'         	=> t('Color'),
            '#default_value' 	=> theme_get_setting('typo_webformtitle_color','md_boom'),
            '#prefix' => '<div class="form-font-color">',
            '#suffix' => '</div>',
            '#attributes' 		=> array(
                'class' => array(
                    'form-colorpicker',
                ),
            ),
        );
    $form['md_boom_settings']['text']['text_typography']['typo_webform_des'] = array(
        '#type' 					=> 'fieldset',
        '#prefix'  				=> '<h3>'.t('Webform description').'</h3>',
        '#description'		=> t('Change the Webform title & description font.'),
    );
        $form['md_boom_settings']['text']['text_typography']['typo_webform_des']['typo_webformdescription_style'] = array(
            '#type'          	=> 'hidden',
            '#default_value' 	=> theme_get_setting('typo_webformdescription_style','md_boom'),
            '#prefix' => '<div id="typo-webformdescription-style" class="choosefont clearfix">',
            '#suffix' => '</div>',
        );

        $form['md_boom_settings']['text']['text_typography']['typo_webform_des']['typo_webformdescription_color'] = array(
            '#type'          	=> 'textfield',
            '#title'         	=> t('Color'),
            '#default_value' 	=> theme_get_setting('typo_webformdescription_color','md_boom'),
            '#prefix' => '<div class="form-font-color">',
            '#suffix' => '</div>',
            '#attributes' 		=> array(
                'class' => array(
                    'form-colorpicker',
                ),
            ),
        );

}		
	

function md_boom_prepare_link_style(&$form, $state) {
	$form['md_boom_settings']['text']['text_normal']['link_style']['link_'.$state]['l_'.$state.'_color'] = array(
		'#type'          	=> 'textfield',
		'#title'         	=> t('Text color'),
		'#default_value' 	=> theme_get_setting('l_'.$state.'_color','md_boom'),
		'#prefix' => '<div class="form-font-color">',
		'#suffix' => '</div>',
		'#attributes' 		=> array(
												'class' => array(
													'form-colorpicker',
												),
		),
	);
	
	$form['md_boom_settings']['text']['text_normal']['link_style']['link_'.$state]['l_'.$state.'_st'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Strikethrough'),
		'#default_value' => theme_get_setting('l_'.$state.'_st','md_boom'),
		'#prefix' => '<div class="form-text-effect form-item clearfix"><label class="labelleft">'.t('Text Effect').'</label><div class="form-strikethrough">', // Open div
		'#suffix' => '</div>',
	);
	
	$form['md_boom_settings']['text']['text_normal']['link_style']['link_'.$state]['l_'.$state.'_hl'] = array(
		'#type' => 'checkbox',
		'#title' =>  t('Highlight'),
		'#default_value' => theme_get_setting('l_'.$state.'_hl','md_boom'),
		'#prefix' => '<div class="form-highlight">',
		'#suffix' => '</div>',
	);
	
	$form['md_boom_settings']['text']['text_normal']['link_style']['link_'.$state]['l_'.$state.'_hlc'] = array(
		'#type'          	=> 'textfield',
		'#default_value' 	=> theme_get_setting('l_'.$state.'_hlc','md_boom'),
		'#prefix' => '<div class="form-font-color form-link-color">',
		'#suffix' => '</div></div><!-- /.form-text-effect.form-item -->',	// Close div
		'#attributes' 		=> array(
												'class' => array(
													'form-colorpicker',
												),
		),
	);

	$form['md_boom_settings']['text']['text_normal']['link_style']['link_'.$state]['l_'.$state.'_ts'] = array(
		'#type' => 'checkboxes',
		'#title' =>  t('Text Style'),
		'#default_value' => is_array(theme_get_setting('l_'.$state.'_ts','md_boom')) ? theme_get_setting('l_'.$state.'_ts','md_boom') : array(),
		'#options' => drupal_map_assoc(array(t('bold'), t('italic'), t('underline'))),
		'#prefix' => '<div class="form-text-style clearfix">',
		'#suffix' => '</div>',
	);
}