<?php
/**
 * Add body classes if certain regions have content.
 */
function md_boom_preprocess_html(&$vars) {
    global $base_url;
    $css = "";
    $themepath = drupal_get_path('theme', 'md_boom');

    drupal_add_css($themepath . '/css/additional.css');
    drupal_add_css($themepath . '/css/style.css');
    drupal_add_css($themepath . '/css/isotope.css');
    drupal_add_css($themepath . '/css/onepage.css');
    drupal_add_css($themepath . '/css/jquery.jscrollpane.codrops.css');
    drupal_add_css($themepath . '/css/flexslider.css');
    drupal_add_css($themepath . '/css/prettyPhoto.css');
    drupal_add_css($themepath . '/css/colorbox.css');
    drupal_add_css($themepath . '/css/magnific-popup.css');
    drupal_add_css($themepath . '/css/owl.carousel.css');
    drupal_add_css($themepath . '/css/bx-slider.css');
    drupal_add_css($themepath . '/css/drop-down.css');
    drupal_add_css($themepath . '/css/responsive.css');

    drupal_add_css($themepath . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 9', '!IE' => FALSE), 'preprocess' => FALSE));

    drupal_add_js($themepath . '/js/onepage/jquery.carouFredSel-6.1.0-packed.js');
    drupal_add_js($themepath . '/js/onepage/jquery.touchSwipe.min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.sticky.js');
    drupal_add_js($themepath . '/js/onepage/jquery.parallax-1.1.3.js');
    drupal_add_js($themepath . '/js/onepage/jquery.localscroll-1.2.7-min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.scrollTo-1.4.2-min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.colorbox.js');
    drupal_add_js($themepath . '/js/onepage/owl.carousel.min.js');
    drupal_add_js('http://maps.google.com/maps/api/js?sensor=false', 'external');
    drupal_add_js($themepath . '/js/onepage/jquery.flexslider-min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.easing.1.3.js');
    drupal_add_js($themepath . '/js/onepage/jquery.nicescroll.min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.magnific-popup.min.js');
    drupal_add_js($themepath . '/js/onepage/jquery.isotope.min.js');
    //drupal_add_js($themepath . '/js/onepage/modernizr.custom.js');
    drupal_add_js($themepath . '/js/onepage/StackBlur.js');
    drupal_add_js($themepath . '/js/onepage/jquery.cycle2.js');
    drupal_add_js($themepath . '/js/onepage/custom.js');
    drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:400,300,300italic,400italic,600,600italic,700,700italic,800italic,800', 'external');
    drupal_add_css('http://fonts.googleapis.com/css?family=Source+Sans+Pro:400,200,300,300italic,200italic,400italic,600italic,600,700,700italic,900,900italic', 'external');
    drupal_add_css('http://fonts.googleapis.com/css?family=Pacifico', 'external');
    $html5shiv = array(
        '#tag' => 'script',
        '#attributes' => array( // Set up an array of attributes inside the tag
            'src' => $base_url . '/' . $themepath . '/js/onepage/html5.js',
        ),
        '#prefix' => '<!--[if lte IE 9]>',
        '#suffix' => '</script><!'.'[endif]-->',
    );
    $css3_queries = array(
        '#tag' => 'script',
        '#attributes' => array( // Set up an array of attributes inside the tag
            'src' => $base_url . '/' . $themepath . '/js/onepage/css3.mediaqueries.js',
        ),
        '#prefix' => '<!--[if lte IE 9]>',
        '#suffix' => '</script><!'.'[endif]-->',
    );
    drupal_add_html_head($html5shiv, 'html5shiv');
    drupal_add_html_head($css3_queries, 'css3_queries');


    /* ------------------------- Site Logo ------------------------*/
    if(theme_get_setting('logo_normal_path','md_boom')){
        $logo_normal_path = theme_get_setting('logo_normal_path','md_boom');
        $logo_normal_scheme = file_uri_scheme($logo_normal_path);
        if ($logo_normal_scheme == 'public') {
            $css .= '#logo { background: url('.file_create_url($logo_normal_path).') no-repeat scroll left top transparent;}';
            $css .= "\n";
        } else {
            $css .= '#logo { background: url('.file_create_url(file_build_uri($logo_normal_path)).') no-repeat scroll left top transparent;}';
            $css .= "\n";
        }
    }
    if(theme_get_setting('logo_retina_path','md_boom')){
        $logo_retina_path = theme_get_setting('logo_retina_path','md_boom');
        $logo_retina_scheme = file_uri_scheme($logo_retina_path);
        if ($logo_retina_scheme == 'public') {
            $css .= '';
        } else {
            $css .= '#logo { background: url('.file_create_url(file_build_uri($logo_retina_path)).') no-repeat scroll left top transparent;}';
            $css .= "\n";
        }

    }

    //Skin
    if (theme_get_setting('skins') != '0') {
        drupal_add_css($themepath . '/css/colors/'.theme_get_setting('skins').'.css', array('group' => CSS_THEME));
    }
    // Custom Parallax
                    /* --------------- Parallax ------------------*/
    for($i=1;$i<=5;$i++) {
        if(theme_get_setting('parallax_'.$i.'_path','md_boom')){
            $parallax_path = md_boom_theme_setting_check_path(theme_get_setting('parallax_'.$i.'_path','md_boom'));
            $css .= '.section'.$i.'-bg {
                            background: url('.$parallax_path.') repeat fixed 0 top / cover transparent;
                            height: 100%;
                            position: absolute;
                            width: 100%;
                            z-index: -1;
                          }';
        }
    }
    $vars['theme_setting_css'] = $css;
	// Custom Web clip
	$webclip_path = theme_get_setting('webclip_path','md_boom');
	if ($webclip_path) {
    $wc_href = "";
		if (file_uri_scheme($webclip_path) == 'public') {
			$wc_href = file_create_url($webclip_path);
		} else {
			$wc_href = file_create_url(file_build_uri($webclip_path));
		}
		
		$wc_rel = "apple-touch-icon";
	  if (theme_get_setting('webclip_precomp','md_boom')) { // no output if $url_precomp = ''
	    $wc_rel = "apple-touch-icon-precomposed";
	  }
		$wc = array(
			'#tag' => 'link',
			'#attributes' => array(
				'href' => $wc_href,
				'rel' => $wc_rel,
				'type' => file_get_mimetype($wc_href),
			),
		);
		drupal_add_html_head($wc, 'webclip');
	}
	
	// Enable Responsive
	if (theme_get_setting('responsive','md_boom')) {
		$menuid = 'main-menu';
		if (!empty($vars['page']['superfish'])) {
			$tmp_array_keys = array_keys($vars['page']['superfish']);
			$menuid = str_replace("_","-",$tmp_array_keys[0]);
		}
		$selecnav = '(function ($) {
			$(function(){
				selectnav(\''.$menuid.'\', {
					label: \''.t('--- Table of content ---').'\',//first select field
					nested: true,
					indent: \'-\'
			 });		
		});
		})(jQuery);';
		drupal_add_js($selecnav, 'inline');
		$vp = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' =>  'viewport',
            'content' =>  'width=100%, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no'
          )
        );
        drupal_add_html_head($vp, 'viewport');
	}

    $vars['theme_setting_css'] = $css;
    //Google Fonts
    if(theme_get_setting('googlewebfonts','md_boom')) {
        drupal_add_css(theme_get_setting('googlewebfonts'),'external');
    }
	// Typekit
	if (theme_get_setting('typekit_id','md_boom')) {
		drupal_add_js('http://use.typekit.net/'.theme_get_setting('typekit_id','md_boom').'.js', 'external');
		drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
	}

	/* Text/typography
	---------------------------------------------------------------------------------------- */
	$typography = '';
	// common text
	if (theme_get_setting('text_font','md_boom') || theme_get_setting('ts_font_color','md_boom')) {
    $typography = "body {";
    $typography .= md_boom_font_to_css(theme_get_setting('text_font','md_boom'));
		if (theme_get_setting('ts_font_color','md_boom')) {
      $typography .= 'color: #' . theme_get_setting('ts_font_color') . ';';
		}
    $typography   .= "}\n";
	}
    /////
  $text_font_arr = explode("|", theme_get_setting('text_font','md_boom'));
  if (count($text_font_arr) == 5 && $text_font_arr[0] != '0') {
    $typography   .= '#forum, ul.quicktabs-tabs, #nav ul.sf-menu li li,.ui-widget {font-family: '.$text_font_arr[4].';}';
  }
    /////
	// Text selection
	if (theme_get_setting('tss_bgcolor','md_boom') || theme_get_setting('tss_tcolor','md_boom')) {
    $tss_bgcolor = '';
    $tss_tcolor = '';
		if (theme_get_setting('tss_bgcolor','md_boom')) {
		  $tss_bgcolor   = 'background: #'.theme_get_setting('tss_bgcolor','md_boom').';';
		}
		if (theme_get_setting('tss_tcolor','md_boom')) {
		  $tss_tcolor   = 'color: #'.theme_get_setting('tss_tcolor','md_boom').';';
		}
    $typography   .= "::-moz-selection {". $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
    $typography   .= "::selection {" . $tss_bgcolor . $tss_tcolor. "text-shadow: none;}\n";
	}
	// link regular
	if (theme_get_setting('l_regular_color','md_boom') || theme_get_setting('l_regular_st','md_boom') || theme_get_setting('l_regular__hl','md_boom') || theme_get_setting('l_regular_ts','md_boom')) {
    $typography   .= "a:link, #node-title a {";
		if (theme_get_setting('l_regular_color','md_boom')) {
      $typography   .= 'color: #'.theme_get_setting('l_regular_color','md_boom').';';
		}
		if (theme_get_setting('l_regular__hl','md_boom')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_regular__hlc','md_boom').';';
		}
        if(theme_get_setting('l_regular_st','md_boom') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_regular_ts','md_boom');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// link rollover
	if (theme_get_setting('l_rollover_color','md_boom') || theme_get_setting('l_rollover_st','md_boom') || theme_get_setting('l_rollover__hl','md_boom') || theme_get_setting('l_rollover_ts','md_boom')) {
		$typography   .= "a:hover, #node-title a:hover {";
		if (theme_get_setting('l_rollover_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_rollover_color','md_boom').';';
		}
		if (theme_get_setting('l_rollover__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_rollover__hlc','md_boom').';';
		}
        if(theme_get_setting('l_rollover_st','md_boom') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_rollover_ts','md_boom');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	
	// link visited
	if (theme_get_setting('l_visited_color','md_boom') || theme_get_setting('l_visited_st','md_boom') || theme_get_setting('l_visited__hl','md_boom') || theme_get_setting('l_visited_ts','md_boom')) {
		$typography   .= "a:visited, #node-title a:visited {";
		if (theme_get_setting('l_visited_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_visited_color','md_boom').';';
		}
		if (theme_get_setting('l_visited__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_visited__hlc','md_boom').';';
		}
        if(theme_get_setting('l_visited_st','md_boom') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_visited_ts','md_boom');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	
	// link on
	if (theme_get_setting('l_on_color','md_boom') || theme_get_setting('l_on_st','md_boom') || theme_get_setting('l_on_hl','md_boom') || theme_get_setting('l_on_ts','md_boom')) {
		$typography   .= "a:focus, a:active, #node-title a:focus, #node-title a:active {";
		if (theme_get_setting('l_on_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_on_color','md_boom').';';
		}
		if (theme_get_setting('l_on_hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_on_hlc','md_boom').';';
		}
        if(theme_get_setting('l_on_st','md_boom') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_on_ts','md_boom');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// Main menu
	if (theme_get_setting('typo_menu_style','md_boom') || theme_get_setting('typo_menu_color','md_boom')) {
		$typography   .= "#menu li{";
		if (theme_get_setting('text_font','md_boom')) {
		  $typography   .= md_boom_font_to_css(theme_get_setting('typo_menu_style','md_boom'));
		}
		
		if (theme_get_setting('typo_menu_color','md_boom')) {
		  $typography   .= 'color: #'.theme_get_setting('typo_menu_color','md_boom').';';
		}
		$typography   .= "}\n";
		
		if (theme_get_setting('typo_menu_color','md_boom')) {
		  $typography   .= '#menu li a, #nav ul.sf-menu li a {color: #'.theme_get_setting('typo_menu_color','md_boom').';}';
		}
		if (theme_get_setting('typo_menu_hover_color','md_boom')) {
		  $typography   .= '#menu li > a:hover,#menu li.sfHover > a, #main li:hover a {color: #'.theme_get_setting('typo_menu_hover_color','md_boom').';}'."\n";
		}
		if (theme_get_setting('typo_menu_active_color','md_boom')) {
		  $typography   .= '#menu li > a:hover, #menu li.sfHover > a, #menu li a.active, #menu li.active a {color: #'.theme_get_setting('typo_menu_active_color','md_boom').';}'."\n";
		}
	}
    /*-------------------------------------- Heading --------------------------------*/
    if(theme_get_setting('typo_heading_style_enable','md_boom') == 1){
        for($i=1;$i<=6;$i++){
            $typography .= 'h'.$i.' {';
            if(theme_get_setting('typo_heading_h'.$i.'_style') || theme_get_setting('typo_heading_h'.$i.'_color','md_boom')){
                if(theme_get_setting('typo_heading_h'.$i.'_style')){
                    $typography .= md_boom_font_to_css(theme_get_setting('typo_heading_h'.$i.'_style'));
                }
                if(theme_get_setting('typo_heading_h'.$i.'_color','md_boom')){
                    $typography .= ' color: #'.theme_get_setting('typo_heading_h'.$i.'_color').';';
                }
            }
            $typography .= "}\n";
        }
    }
	/*------------------------------------ Node title ---------------------------------*/
	if (theme_get_setting('typo_nodetitle_style','md_boom') || theme_get_setting('nodetitle_color','md_boom')) {
		$typography   .= "#node-title {";
		if (theme_get_setting('typo_nodetitle_style')) {
		  $typography   .= md_boom_font_to_css(theme_get_setting('typo_nodetitle_style'));
		}
		
		if (theme_get_setting('nodetitle_color','md_boom')) {
		  $typography   .= 'color: #'.theme_get_setting('nodetitle_color','md_boom').';';
		}
		$typography   .= "}\n";

		if (theme_get_setting('nodetitle_color')) {
		  $typography   .= '#node-title a {color: #'.theme_get_setting('nodetitle_color','md_boom').';}'."\n";
		}

		if (theme_get_setting('nodetitle_hover_color')) {
		  $typography   .= '#node-title a:hover {color: #'.theme_get_setting('nodetitle_hover_color','md_boom').';}'."\n";
		}
	}
	
	if (theme_get_setting('nodetitle_enable','md_boom') == 1) {
		foreach (node_type_get_types() as $type => $name) {
			if (theme_get_setting('typo_n'.$type.'title_style') || theme_get_setting('n'.$type.'title_color','md_boom')) {
				$typography   .= "#node-title span.node-$type-title {";
				if (theme_get_setting('typo_n'.$type.'title_style')) {
				  $typography   .= md_boom_font_to_css(theme_get_setting('typo_n'.$type.'title_style','md_boom'));
				}
				
				if (theme_get_setting('n'.$type.'title_color','md_boom')) {
				  $typography   .= 'color: #'.theme_get_setting('n'.$type.'title_color','md_boom').';';
				}
				$typography   .= "}\n";

				if (theme_get_setting('n'.$type.'title_color','md_boom')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a {color: #'.theme_get_setting('n'.$type.'title_color','md_boom').';}'."\n";
				}
				
				if (theme_get_setting('n'.$type.'title_hover_color','md_boom')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a:hover {color: #'.theme_get_setting('n'.$type.'title_hover_color','md_boom').';}'."\n";
				}
			}
		}
	}

    // View block title
    if (theme_get_setting('typo_view_title_style','md_boom') || theme_get_setting('typo_view_title_color','md_boom')) {
        $typography   .= ".flx-intro-2 h2 {";
        if (theme_get_setting('typo_view_title_style','md_boom')) {
            $typography   .= md_boom_font_to_css(theme_get_setting('typo_view_title_style','md_boom'));
        }

        if (theme_get_setting('typo_view_title_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_title_color','md_boom').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_title_enable','md_boom') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_title_style') || theme_get_setting('typo_view_'.$view_title.'_title_color','md_boom')) {
                    $typography   .= ".flx-intro-2 h2.view-".$view_title."-title {";
                    if (theme_get_setting('typo_view_'.$view_title.'_title_style')) {
                        $typography   .= md_boom_font_to_css(theme_get_setting('typo_view_'.$view_title.'_title_style','md_boom'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_title_color','md_boom')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_title_color','md_boom').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    //View block description
    if (theme_get_setting('typo_view_description_style','md_boom') || theme_get_setting('typo_view_description_color','md_boom')) {
        $typography   .= ".flx-intro-2 h5.flx-intro-excerpt {";
        if (theme_get_setting('typo_view_description_style','md_boom')) {
            $typography   .= md_boom_font_to_css(theme_get_setting('typo_view_description_style','md_boom'));
        }

        if (theme_get_setting('typo_view_description_color','md_boom')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_description_color','md_boom').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_description_enable','md_boom') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_boom') || theme_get_setting('typo_view_'.$view_title.'_description_color','md_boom')) {
                    $typography   .= ".flx-intro-2 span.view-".$view_title."-description {";
                    if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_boom')) {
                        $typography   .= md_boom_font_to_css(theme_get_setting('typo_view_'.$view_title.'_description_style','md_boom'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_description_color','md_boom')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_description_color','md_boom').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    if (theme_get_setting('typo_webformtitle_style','md_boom') || theme_get_setting('typo_webformtitle_color','md_boom')) {
        $typography   .= ".flx-map-form span.webform-title{";
        if (theme_get_setting('typo_webformtitle_style','md_boom')) {
            $typography   .= md_boom_font_to_css(theme_get_setting('typo_webformtitle_style','md_boom'));
        }

        if (theme_get_setting('typo_webformtitle_color','md_boom')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformtitle_color','md_boom').' !important;';
        }
        $typography   .= "}\n";

    }
    if (theme_get_setting('typo_webformdescription_style','md_boom') || theme_get_setting('typo_webformdescription_color','md_boom')) {
        $typography   .= ".flx-map-form span.webform-description{";
        if (theme_get_setting('typo_webformdescription_style','md_boom')) {
            $typography   .= md_boom_font_to_css(theme_get_setting('typo_webformdescription_style','md_boom'));
        }

        if (theme_get_setting('typo_webformdescription_color','md_boom')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformdescription_color','md_boom').' !important;';
        }
        $typography   .= "}\n";
    }

	$vars['typography'] = $typography;
    /*--------------------------------- Map -----------------------------------------------*/
    if($vars['is_front'] == true){
        if(theme_get_setting('map_latlng','md_boom')){
            $map_latlng = theme_get_setting('map_latlng','md_boom');
            $map_types = theme_get_setting('map_types','md_boom');
            $map_zoom_level = theme_get_setting('map_zoom_level','md_boom');
            $map_js = ' var $map_canvas = jQuery("#map_canvas");
                            if($map_canvas.size()>0){
                                function initialize() {
                                    var map_center = Drupal.settings.map_latlng;
                                    var latlng = new google.maps.LatLng('.$map_latlng.');
                                    var settings = {
                                        zoom: '.$map_zoom_level.',
                                        center: latlng,
                                        scrollwheel: false,
                                        navigationControl: false,
                                        scaleControl: false,
                                        streetViewControl: false,
                                        draggable: true,
                                        mapTypeControl: true,
                                        mapTypeControlOptions: {style: google.maps.MapTypeControlStyle.DROPDOWN_MENU},
                                        navigationControl: true,
                                        navigationControlOptions: {style: google.maps.NavigationControlStyle.SMALL},
                                        mapTypeId: google.maps.MapTypeId.'.$map_types.'
                                    };
                                    var map = new google.maps.Map(document.getElementById("map_canvas"), settings);
                                }
                                window.onload = initialize();
                            }';
            drupal_add_js($map_js,array('type' => 'inline','scope' => 'footer'));
        }
    }
	/* Get theme settings
	---------------------------------------------------------------------------------------- */
	$vars['footer_text']   = theme_get_setting('footer_text','md_boom');
	$vars['header_code']   = theme_get_setting('header_code','md_boom');
	$vars['footer_code']   = theme_get_setting('footer_code','md_boom');
	if (theme_get_setting('custom_css','md_boom')) {
		$vars['custom_css']  = theme_get_setting('custom_css','md_boom');
	}
	drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

function md_boom_font_to_css($font) {
    $font_arr = explode("|", $font);
    $css = "";
    if(count($font_arr) == 6) {
        if ($font_arr[0] != '0') {
            $css = ''.$font_arr[5].';';
        }
    }
    return $css;
}

function md_boom_expand_font_weight($fw) {
				switch($fw) {
					case 'n1':
						$fontExpand = "font-style: normal; font-weight: 100;";
				  	break;
					case 'i1':
						$fontExpand = "font-style: italic; font-weight: 100;";
						break;
					case 'n2':
						$fontExpand = "font-style: normal; font-weight: 200;";
				  	break;
					case 'i2':
						$fontExpand = "font-style: italic; font-weight: 200;";
						break;
					case 'n3':
						$fontExpand = "font-style: normal; font-weight: 300;";
				  	break;
					case 'i3':
						$fontExpand = "font-style: italic; font-weight: 300;";
						break;
					case 'n4':
						$fontExpand = "font-style: normal; font-weight: normal;";
				  	break;
					case 'i4':
						$fontExpand = "font-style: italic; font-weight: normal";
						break;
					case 'n5':
						$fontExpand = "font-style: normal; font-weight: 500;";
				  	break;
					case 'i5':
						$fontExpand = "font-style: italic; font-weight: 500;";
						break;
					case 'n6':
						$fontExpand = "font-style: normal; font-weight: 600;";
				  	break;
					case 'i6':
						$fontExpand = "font-style: italic; font-weight: 600;";
						break;
					case 'n7':
						$fontExpand = "font-style: normal; font-weight: bold;";
				  	break;
					case 'i7':
						$fontExpand = "font-style: italic; font-weight: bold;";
						break;
					case 'n8':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i8':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					case 'n9':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i9':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					default:
						$fontExpand = "";
				}
				
				return $fontExpand;
			}

/**
 * Override or insert vars into the page template for HTML output.
 */
function md_boom_process_html(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
	
	$classes = explode(' ', $vars['classes']);
  if ($node = menu_get_object()) {
    $node_type_class = drupal_html_class('node-type-' . $node->type);
    if (in_array($node_type_class, $classes)) {
      theme_get_setting('extra_page_classes','md_boom') == 0 ? '' : $classes = str_replace($node_type_class, '', $classes);
      $classes = str_replace('node-type-', 'page-type-', $classes);
    }
  }
  $vars['classes'] = trim(implode(' ', $classes));
}



/**
 * Override or insert vars into the page template.
 */
function md_boom_process_page(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
	
	$status = drupal_get_http_header("status");  
  if($status == "404 Not Found") {      
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

	$vars['social_links'] = 0;
	
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $vars['hide_site_name']   = theme_get_setting('toggle_name','md_boom') ? FALSE : TRUE;
  $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan','md_boom') ? FALSE : TRUE;
  if ($vars['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($vars['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($vars['title_suffix']['add_or_remove_shortcut']) && $vars['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $vars['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $vars['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $vars['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

}

/**
 * Implements hook_preprocess_page().
 */
function md_boom_preprocess_page(&$vars, $hook) {
    if(theme_get_setting('footer_logo_path','md_boom')){
        $footer_logo_path = md_boom_theme_setting_check_path(theme_get_setting('footer_logo_path','md_boom'));
        $vars['footer_logo_path'] = $footer_logo_path;
    }
    if(theme_get_setting('footer_text','md_boom')){
        $vars['footer_text'] = theme_get_setting('footer_text','md_boom');
    }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function md_boom_preprocess_maintenance_page(&$vars) {
  if (!$vars['db_is_active']) {
    unset($vars['site_name']);
  }
  drupal_add_css(drupal_get_path('theme', 'md_boom') . '/css/maintenance-page.css');
}

/**
 * Override or insert vars into the maintenance page template.
 */
function md_boom_process_maintenance_page(&$vars) {
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $vars['hide_site_name']   = theme_get_setting('toggle_name','md_boom') ? FALSE : TRUE;
  $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan','md_boom') ? FALSE : TRUE;
  if ($vars['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($vars['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}

function md_boom_check_und($param) {
	if (isset($param['und'])) {
		return $param['und'][0];
	} else {
		return $param[0];
	}
}

