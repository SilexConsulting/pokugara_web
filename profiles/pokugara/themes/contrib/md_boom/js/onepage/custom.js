/*===========================================================
 ************* Ajax Load Portfolio Detail*******************
 ===========================================================*/
function boom_portfolio_detail_click(obj, nid, effect){
    var current_path = window.location.href;
    current_path = current_path.substring(0, Math.max(current_path.lastIndexOf("/"), current_path.lastIndexOf("\\\\")));
    jQuery.ajax({
        type:'POST',
        url: current_path + '/?q=ajax_node',
        async:false,
        data: {nodeid:nid},
        beforeSend:function(XMLHttpRequest, settings){
            obj.addClass('inprocess');
            jQuery('.pf-detail-box .row-fluid').html('<center>Loading...</center>');
            if(false == effect)
                jQuery('.pf-detail-box').fadeTo("slow", 0.5);
        },
        complete:function(XMLHttpRequest, textStatus){},
        success : function(data){

            /* var body = jQuery("body, html");
             var top = body.scrollTop();
             if(jQuery("#pf-detail-box").size() > 0){
             var boxOffset = jQuery("#pf-detail-box").offset().top;
             var navHeight = jQuery("#navigation").height();
             var toolbarHeight = jQuery("#toolbar").height();
             var scrollBody = boxOffset-navHeight-toolbarHeight-60;
             if((top!=0) && (top != null)){
             body.animate({scrollTop:boxOffset},'slow');
             };
             };*/

            jQuery('body','html').animate({scrollTop:jQuery("#pf-detail-box").offset().top - 70},'slow');
            if(true == effect)
                jQuery('.pf-detail-box').slideDown(500);
            else
                jQuery('.pf-detail-box').fadeTo("slow", 1);

            jQuery('.pf-detail-box .row-fluid').html(data);
            obj.removeClass('inprocess');
        },
        error : function(XMLHttpRequest, textStatus, errorThrown) {}
    });
    return true;
}
function boom_portfolio_hide_click(obj){
    obj.remove();
    jQuery('.pf-detail-box').slideUp(500);
    return true;
}
jQuery(function($){

    jQuery(document).ready(function($){
        $('.clickable').bind('click',function(event){
            event.preventDefault();
            var current_path = window.location.href;
            current_path = current_path.substring(0, Math.max(current_path.lastIndexOf("/"), current_path.lastIndexOf("\\\\")));
            var nid = $(this).attr("data-nid");
            jQuery.ajax({
                type:'POST',
                url: current_path + '/?q=ajax_node',
                async:false,
                data: {nodeid:nid},
                beforeSend:function(XMLHttpRequest, settings){
                    $(this).addClass('inprocess');
                    $('.pf-detail-box .row-fluid').html('<center>Loading...</center>');
                },
                complete:function(XMLHttpRequest, textStatus){

                },
                success : function(data){

                    /*var body = jQuery("body, html");
                    var top = body.scrollTop();
                    if(jQuery("#pf-detail-box").size() > 0){
                        var boxOffset = jQuery("#pf-detail-box").offset().top;
                        var navHeight = jQuery("#navigation").height();
                        var toolbarHeight = jQuery("#toolbar").height();
                        var scrollBody = boxOffset-navHeight-toolbarHeight;
                        if((top!=0) && (top != null)){
                            body.animate({scrollTop: boxOffset}, 'slow',function(){});
                        };
                    };*/
                    jQuery('body','html').animate({scrollTop:jQuery("#pf-detail-box").offset().top -70},'slow');
                    $('.pf-detail-box').fadeTo("slow", 1);

                    $('.pf-detail-box .row-fluid').html(data);
                    $(this).removeClass('inprocess');
                },
                error : function(XMLHttpRequest, textStatus, errorThrown) {}
            });
            return false;
        });
/*=====================================================================
 *****************************Blog Magnific Popup*********************
 ====================================================================*/
        //  Magnific Popup for images
        if ($('.popup-image').length > 0) {
            $('.popup-image').magnificPopup({
                type: 'image'
            });
        }

        // Magnific Popup for gallery project
        if ($('.popup-gallery').length > 0) {
            $('.popup-gallery').magnificPopup({
                type: 'inline',
                callbacks: {
                    open: function() {
                        // console.log('popup open');
                        $(".img-slideshow").owlCarousel({
                            autoPlay: 6000,
                            slideSpeed : 500,
                            navigation: false,
                            pagination: true,
                            singleItem:true

                        });
                        // Will fire when this exact popup is opened
                        // this - is Magnific Popup object
                    },
                    close: function() {
                        // Will fire when popup is closed
                    },
                    imageLoadComplete: function() {
                        // fires when image in current popup finished loading
                        // avaiable since v0.9.0
                    }
                    // e.t.c.
                }
            });
        }

        // Magnific Popup for soundcloud
        if ($('.popup-soundcloud').length > 0) {
            $('.popup-soundcloud').magnificPopup({
                type: 'iframe',
                mainClass: 'soundcloud-popup'
            });
        }

        // Magnific Popup for videos and google maps
        if ($('.popup-youtube, .popup-vimeo, .popup-gmaps').length > 0) {
            $('.popup-youtube, .popup-vimeo, .popup-gmaps').magnificPopup({
                disableOn: 700,
                type: 'iframe',
                fixedContentPos: false,
                fixedBgPos: false,
                mainClass: 'mfp-fade',
                removalDelay: 160,
                preloader: false
            });
        }
        $.magnificPopup.defaults.callbacks = {
            open: function() {
                $('html').addClass('modal');
            },
            close: function() {
                // Wait until overflow:hidden has been removed from the html tag
                setTimeout(function() {
                    $('html').removeClass('modal');
                }, 100)
            }
        };
        if ($('.popup-ajax').size() > 0) {
            $('.popup-ajax').magnificPopup({
                type: 'ajax',
                fixedBgPos:true,
                fixedContentPos:true,
                midClick:true,
                closeOnBgClick:false,
                callbacks: {
                    parseAjax: function(mfpResponse) {
                        // mfpResponse.data is a "data" object from ajax "success" callback
                        // for simple HTML file, it will be just String
                        // You may modify it to change contents of the popup
                        // For example, to show just #some-element:
                        // mfpResponse.data = $(mfpResponse.data).find('#some-element');
                        // mfpResponse.data must be a String or a DOM (jQuery) element
                    },
                    ajaxContentAdded: function() {
                        // Ajax content is loaded and appended to DOM
                        $('.filter-guidelines').once('filter-guidelines')
                            .find(':header').hide()
                            .closest('.filter-wrapper').find('select.filter-list')
                            .bind('change', function () {
                                $(this).closest('.filter-wrapper')
                                    .find('.filter-guidelines-item').hide()
                                    .siblings('.filter-guidelines-' + this.value).show();
                            })
                            .change();


                        if(jQuery('#flx-slides-3 li').length > 3){
                            jQuery('#flx-slides-3').carouFredSel({
                                responsive: true,
                                prev: '#prev-4',
                                next: '#next-4',
                                width: '100%',
                                scroll: 1,
                                auto: false,
                                items: {
                                    width: 220,
                                    height: 'auto',
                                    visible: {
                                        min: 1,
                                        max: 4
                                    }
                                }
                            })
                        }

                    }
                }
            });
        }
        $("#flx-team-slides").owlCarousel({
            navigation:true,
            slideSpeed : 500,
            pagination : true,
            items : 4,
            navigationText: ["<i class='icon-angle-left icon-2x'></i>","<i class='icon-angle-right icon-2x'></i>"],
            responsive:true,
            autoPlay: true,
            itemsDesktop : [1000,4], //5 items between 1000px and 901px
            itemsDesktopSmall : [900,3], // betweem 900px and 601px
            itemsTablet: [600,2], //2 items between 600 and 0
            itemsMobile : [479,1] // itemsMobile disabled - inherit from itemsTablet option
        });
        /*===========================================================
         ******************Carousel for content5**************************
         ===========================================================*/
        var blog = jQuery('#blog-carousel');
        if(blog.size() > 0){
            //	Scrolled by user interaction
            blog.owlCarousel({
                navigation:false,
                slideSpeed : 500,
                pagination : false,
                items : 3,
                responsive: true,
                autoPlay: false,
                itemsDesktop : [1000,3], //5 items between 1000px and 901px
                itemsDesktopSmall : [900,2], // betweem 900px and 601px
                itemsTablet: [600,1], //2 items between 600 and 0
                itemsMobile : [479,1] // itemsMobile disabled - inherit from itemsTablet option
            });
            //get carousel instance data and store it in variable owl
            var owlBlog = $("#blog-carousel").data('owlCarousel');
            $("#blog-navigation .prev").click(function() {
                owlBlog.prev();
                return false;
            });
            $("#blog-navigation .next").click(function() {
                owlBlog.next();
                return false;
            })

        }
        $(".jp-container").niceScroll({
            cursorborder:"",
            cursorcolor:"#000",
            cursoropacitymax: 0.6,
            cursorwidth: 8,
            boxzoom:true
        });

    })
});

jQuery(function($){
    $("#toolbar a").not($("#toolbar a.toggle")).click(function() {
        $("#navigation").css("z-index",499);
    });
    navSticky();
    $(window).load(function(){
        'use strict';
        if($("#toolbar").size() > 0) {
            $("#toolbar a.toggle").click(function () {
                if($("body").hasClass("toolbar")) {
                    if($("body").hasClass("toolbar-drawer")) {
                        $("#navigation").sticky({topSpacing:65});
                    } else {
                        $("#navigation").sticky({topSpacing:30});
                    }
                } else {
                    $("#navigation").sticky({topSpacing:0});
                }
            })
        }
    })


    /* ======================================= Sticky Menu ======================================*/
    function navSticky() {
        if($("body").hasClass("toolbar")) {
            if($("body").hasClass("toolbar-drawer")) {
                $("#navigation").sticky({topSpacing:65});
            } else {
                $("#navigation").sticky({topSpacing:30});
            }
        } else {
            $("#navigation").sticky({topSpacing:0});
        }
    }


    /* ======================================= Parallax =========================================*/
//.parallax(xPosition, speedFactor, outerHeight) options:
//xPosition - Horizontal position of the element
//inertia - speed to move relative to vertical scroll. Example: 0.1 is one tenth the speed of scrolling, 2 is twice the speed of scrolling
//outerHeight (true/false) - Whether or not jQuery should use it's outerHeight option to determine when a section is in the viewport
    $('.section1-bg').parallax("50%", 0);
    $('.section2-bg').parallax("50%", 0);
    $('.section3-bg').parallax("50%", 0);
    $('.section4-bg').parallax("50%", 0);

    /*----------------Resposive Menu----------------*/

    $(function() {
        if($('#navigation').size() > 0){
            var eTop = $('#navigation').offset().top;
            if ( ( eTop - $(window).scrollTop()) == eTop ) {
                jQuery('#navigation .wrapper-dropdown-3 .dropdown').css({ "top": '-660%' });
                jQuery('#navigation .wrapper-dropdown-3').addClass('dropdown-arrow');
            }
            $(window).scroll(function() {
                if ( ( eTop - $(window).scrollTop()) == eTop ) {
                    jQuery('#navigation .wrapper-dropdown-3 .dropdown').css({ "top": '-660%' });
                    jQuery('#navigation .wrapper-dropdown-3').addClass('dropdown-arrow');
                }
                else {
                    jQuery('#navigation .wrapper-dropdown-3 .dropdown').css({ "top": '140%' });
                    jQuery('#navigation .wrapper-dropdown-3').removeClass('dropdown-arrow');
                }
            });
        }

    });


});

/*===========================================================
 *********Automatically Highlights Navigation Item************
 ===========================================================*/
jQuery(function($){
    if($('body #navigation #menu').size() > 0) {
        function calculateScroll() {
            var topRange = 400;
            var contentTop		=	[];
            var contentBottom	=	[];
            var winTop		=	$(window).scrollTop();
            //rangeTop is used for changing the class a little sooner that reaching the top of the page
            //rangeBottom is similar but used for when scrolling bottom to top
            var rangeTop	=	200;
            var rangeBottom	=	500;
            $('#navigation #menu').find('a').each(function(){
                if($($(this).attr('hr-ef')).size() > 0){
                    contentTop.push( $( $(this).attr('hr-ef') ).offset().top );
                    contentBottom.push( $( $(this).attr('hr-ef') ).offset().top + $( $(this).attr('hr-ef') ).height() );
                }
            })
/*            contentTop.push($("#navigation .logo").attr('hr-ef') .offset().top);
            contentBottom.push( $("#navigation .logo").attr('hr-ef') .offset().top + $("#navigation .logo").attr('hr-ef').height() );*/
            $.each( contentTop, function(i){
                if ( winTop > contentTop[i] - rangeTop && winTop < contentBottom[i] - rangeBottom ){
                    $('#navigation #menu li')
                        .removeClass('current')
                        .eq(i).addClass('current');
                }
            })
        }
        $(document).ready(function() {
            calculateScroll()
            $(window).scroll(function(event) {
                calculateScroll();
            });
        });
    }
})
jQuery(document).ready(function($){

    /* =========================================================
     **************************Fix CSS***************************
     ============================================================ */
    jQuery(".list-container-3 ul li:first-child").css({
        "border-top-width": "1px",
        "border-top-style":"solid",
        "border-top-color":"#d9d9d9"
    });
    jQuery(".list-container-3 ul li:last-child").css({
        "border-bottom-width": "1px",
        "border-bottom-style":"solid",
        "border-bottom-color":"#d9d9d9"
    });
    jQuery(".flx-boom .list-container-3 ul li:last-child").css({
        "border-bottom":"none"
    });
    jQuery(".flx-boom .list-container-3 ul li:first-child").css({
        "border-top":"none"
    });
    jQuery("#right-sidebar .widget .flx-categories li:first-child").css({
        "border-top-width": "1px",
        "border-top-style":"solid",
        "border-top-color":"#d9d9d9"
    });
    jQuery("#left-sidebar .widget .flx-categories li:first-child").css({
        "border-top-width": "1px",
        "border-top-style":"solid",
        "border-top-color":"#d9d9d9"
    });
    jQuery(".footer-menu li:last-child").css({
        "margin-right":0
    });
    /* =========================================================
     ****************************Tabs****************************
     ============================================================ */

    if( jQuery(".tab-content-3").size() > 0){
        //Default Action Product Tab
        jQuery(".tab-content-3").hide(); //Hide all content
        jQuery("ul.tabs-3 li:first").addClass("active").show(); //Activate first tab
        jQuery(".tab-content-3:first").show(); //Show first tab content
        //On Click Event Product Tab
        jQuery("ul.tabs-3 li").click(function() {
            var CurrentPosition = jQuery(this).position();
            var NewTop = CurrentPosition.top;
            jQuery(".tab-highlight").animate({
                "top":NewTop
            },"normal");
            jQuery("ul.tabs-3 li").removeClass("active"); //Remove any "active" class
            jQuery(this).addClass("active"); //Add "active" class to selected tab
            jQuery(".tab-content-3").hide(); //Hide all tab content
            var activeTab = jQuery(this).find("a").attr("href"); //Find the rel attribute value to identify the active tab + content
            jQuery(activeTab).fadeIn(); //Fade in the active content
            return false;
        });
    }
    /* =========================================================
     ******************Clients Logo Slider***********************
     ============================================================ */
    jQuery(window).load(function() {
        if( jQuery("#flx-slides li").length > 1){
            jQuery('#flx-slides').carouFredSel({
                responsive: true,
                prev: '#prev-1',
                next: '#next-1',
                width: '100%',
                scroll: 1,
                auto: false,
                items: {
                    width: 160,
                    height: 'auto',
                    visible: {
                        min: 1,
                        max: 5
                    }
                }
            });
        }

        if( jQuery("#flx-slides-2 li").length > 1){
            jQuery('#flx-slides-2').carouFredSel({
                responsive: true,
                prev: '#prev-3',
                next: '#next-3',
                width: '100%',
                scroll: 1,
                auto: false,
                items: {
                    width: 160,
                    height: 'auto',
                    visible: {
                        min: 1,
                        max: 4
                    }
                }
            });
        }


        if( jQuery("#flx-pf-slides li").length > 1){
            jQuery('#flx-pf-slides').carouFredSel({
                responsive: true,
                prev: '#prev-5',
                next: '#next-5',
                width: '100%',
                scroll: 1,
                auto: false,
                items: {
                    width: 185,
                    height: 'auto',
                    visible: {
                        min: 1,
                        max: 5
                    }
                }
            });
        }
    });
});


/* =========================================================
 **************Switch portfolio view when responsive*********
 ==========================================================*/
function flx_portfolio_view(){
    var view_port_width = jQuery(window).width();
    if (view_port_width <= 980) {
        jQuery('#toggle-sizes').find('a').click();
    }
}

jQuery(document).ready(function(){
    flx_portfolio_view();
});
jQuery(window).resize(function() {
    flx_portfolio_view();
});


jQuery(document).ready(function($){

    /*===========================================================
     ***************************Isotope**************************
     ===========================================================*/
    if($("#container.clickable").size()>0){
        $.Isotope.prototype._getCenteredMasonryColumns = function() {
            this.width = this.element.width();

            var parentWidth = this.element.parent().width();

            // i.e. options.masonry && options.masonry.columnWidth

            var colW = this.options.masonry && this.options.masonry.columnWidth ||
                // or use the size of the first item
                this.$filteredAtoms.outerWidth(true) ||
                // if there's no items, use size of container
                parentWidth;

            var cols = Math.floor( parentWidth / colW );
            cols = Math.max( cols, 1 );

            // i.e. this.masonry.cols = ....
            this.masonry.cols = cols;
            // i.e. this.masonry.columnWidth = ...
            this.masonry.columnWidth = colW;
        };

        $.Isotope.prototype._masonryReset = function() {
            // layout-specific props
            this.masonry = {};
            // FIXME shouldn't have to call this again
            this._getCenteredMasonryColumns();
            var i = this.masonry.cols;
            this.masonry.colYs = [];
            while (i--) {
                this.masonry.colYs.push( 0 );
            }
        };

        $.Isotope.prototype._masonryResizeChanged = function() {
            var prevColCount = this.masonry.cols;
            // get updated colCount
            this._getCenteredMasonryColumns();
            return ( this.masonry.cols !== prevColCount );
        };

        $.Isotope.prototype._masonryGetContainerSize = function() {
            var unusedCols = 0,
                i = this.masonry.cols;
            // count unused columns
            while ( --i ) {
                if ( this.masonry.colYs[i] !== 0 ) {
                    break;
                }
                unusedCols++;
            }

            return {
                height : Math.max.apply( Math, this.masonry.colYs ),
                // fit container to columns that have been used;
                width : (this.masonry.cols - unusedCols) * this.masonry.columnWidth
            };
        };

        jQuery(function(){

            var $container = jQuery('#container');
            var $containerSmall = jQuery('#content-small');
            if($container.size()>0){
                // add randomish size classes
                $container.find('.element').each(function(){
                    var $this = jQuery(this),
                        number = parseInt( $this.find('.number').text(), 10 );
                    if ( number % 7 % 2 === 1 ) {
                        $this.addClass('width2');
                    }
                    if ( number % 3 === 0 ) {
                        $this.addClass('height2');
                    }
                    if ( number % 7 === 0 ) { //Rare because it picks random number from 1 to 11 and only 7 matches criteria
                        $this.addClass('width3');
                        $this.addClass('height2');
                    }
                });

                // center images inside elements
                function centerIsotypeImages(){
                    jQuery('.element').each(function(){
                        var $this = jQuery(this);
                        if($this.find('img').get(0) === undefined){ return; }
                        var cont_ratio = $this.width() / $this.height();
                        var img_ratio = $this.find('img').get(0).width / $this.find('img').get(0).height;

                        if(cont_ratio <= img_ratio){
                            $this.find('img').css({ 'width' : 'auto', 'height' : '100%', 'top' : 0 }).css({ 'left' : ~(($this.find('img').width()-$this.width())/2)+1 });
                            $this.find('img').stop(true, true).fadeIn(200);
                            $this.find('img').addClass('pf-img-visible');
                        }else{
                            $this.find('img').css({ 'width' : '100%', 'height' : 'auto', 'left' : 0 }).css({ 'top' : ~(($this.find('img').height()-$this.height())/2)+1 });
                            $this.find('img').stop(true, true).fadeIn(200);
                            $this.find('img').addClass('pf-img-visible');
                        }
                    });
                }

                jQuery(".pf-img").one("load",function(){
                    var $this = jQuery(this);
                    var cont_ratio = $this.parent().width() / $this.parent().height();
                    var img_ratio = $this.get(0).width / $this.get(0).height;
                    if(cont_ratio <= img_ratio){
                        $this.css({ 'width' : 'auto', 'height' : '100%', 'top' : 0 }).css({ 'left' : ~(($this.width()-$this.parent().width())/2)+1 });
                        $this.addClass('pf-img-visible');
                    }else{
                        $this.css({ 'width' : '100%', 'height' : 'auto', 'left' : 0 }).css({ 'top' : ~(($this.height()-$this.parent().height())/2)+1 });
                        $this.addClass('pf-img-visible');
                    }
                });

                $container.isotope({
                    itemSelector : '.element',
                    masonry : {
                        //columnWidth : 120
                        columnWidth : 5,
                        gutterWidth: 5
                    },
                    masonryHorizontal : {
                        rowHeight: 120
                    },
                    cellsByRow : {
                        columnWidth : 240,
                        rowHeight : 240
                    },
                    cellsByColumn : {
                        columnWidth : 240,
                        rowHeight : 240
                    },
                    getSortData : {
                        symbol : function( $elem ) {
                            return $elem.attr('data-symbol');
                        },
                        category : function( $elem ) {
                            return $elem.attr('data-category');
                        },
                        number : function( $elem ) {
                            return parseInt( $elem.find('.number').text(), 10 );
                        },
                        weight : function( $elem ) {
                            return parseFloat( $elem.find('.weight').text().replace( /[\(\)]/g, '') );
                        },
                        name : function ( $elem ) {
                            return $elem.find('.name').text();
                        }
                    }
                });

            }


            var $optionSets = jQuery('#options .option-set'),
                $optionLinks = $optionSets.find('a');
            if($optionSets.size()>0){
                $optionLinks.click(function(){
                    var $this = jQuery(this);
                    // don't proceed if already selected
                    if ( $this.hasClass('selected') ) {
                        return false;
                    }
                    var $optionSet = $this.parents('.option-set');
                    $optionSet.find('.selected').removeClass('selected');
                    $this.addClass('selected');

                    // make option object dynamically, i.e. { filter: '.my-filter-class' }
                    var options = {},
                        key = $optionSet.attr('data-option-key'),
                        value = $this.attr('data-option-value');
                    // parse 'false' as false boolean
                    value = value === 'false' ? false : value;
                    options[ key ] = value;
                    if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
                        // changes in layout modes need extra logic
                        changeLayoutMode( $this, options )
                    } else {
                        // otherwise, apply new options
                        $container.isotope( options );
                    }

                    return false;
                });
            }

            // change layout
            var isHorizontal = false;
            function changeLayoutMode( $link, options ) {
                var wasHorizontal = isHorizontal;
                isHorizontal = $link.hasClass('horizontal');

                if ( wasHorizontal !== isHorizontal ) {
                    // orientation change
                    // need to do some clean up for transitions and sizes
                    var style = isHorizontal ?
                    { height: '80%', width: $container.width() } :
                    { width: 'auto' };
                    // stop any animation on container height / width
                    $container.filter(':animated').stop();
                    // disable transition, apply revised style
                    $container.addClass('no-transition').css( style );
                    setTimeout(function(){
                        $container.removeClass('no-transition').isotope( options );
                    }, 100 )
                } else {
                    $container.isotope( options );
                }
            }


            // toggle variable sizes of all elements
            jQuery('#toggle-sizes').find('a').click(function(){
                if(jQuery(this).hasClass('toggle-selected')){ return false; }
                jQuery('#toggle-sizes').find('a').removeClass('toggle-selected');
                jQuery(this).addClass('toggle-selected');
                if(!jQuery('#toggle-sizes a:first-child').hasClass('toggle-selected')){ $container.find('.element').addClass('element-small'); }else{ $container.find('.element').removeClass('element-small'); }
                $container.find('img').fadeOut(0);
                $container
                    .toggleClass('variable-sizes')
                    .isotope('reLayout');
                centerIsotypeImages();
                return false;
            });


            jQuery('#insert a').click(function(){
                var $newEls = jQuery( fakeElement.getGroup() );
                $container.isotope( 'insert', $newEls );

                return false;
            });

            jQuery('#append a').click(function(){
                var $newEls = jQuery( fakeElement.getGroup() );
                $container.append( $newEls ).isotope( 'appended', $newEls );

                return false;
            });


            var $sortBy = jQuery('#sort-by');
            jQuery('#shuffle a').click(function(){
                $container.isotope('shuffle');
                $sortBy.find('.selected').removeClass('selected');
                $sortBy.find('[data-option-value="random"]').addClass('selected');
                return false;
            });

        });
    }

    /* =========================================================
     **************************prettyPhoto***********************
     ============================================================ */
    /*jQuery("a[rel^='prettyPhoto']").prettyPhoto({
        overlay_gallery: true,
        "theme": 'light_rounded',
        keyboard_shortcuts: true,
        social_tools: false
    });*/



    /* =========================================================
     ***********************Background animate ******************
     ==========================================================*/
   /* var scrollSpeed = 50;
// set the default position
    var current = 1;
// set the direction, direction can be either "v", "h" (vertical or horizontal)
    var direction = 'h';
    var scrollBg = function(){
        // 1 pixel row at a time, change to -1 for other direction
        current -= 1;
        // set div
        jQuery('#content5').css("backgroundPosition", (direction == 'h') ? current+"px 0" : "0 " + current+"px");
    }
    setInterval(scrollBg, scrollSpeed);*/


    /* =========================================================
     *********************** Dropdown List **********************
     ==========================================================*/
    function DropDown_3(el_3) {
        this.dd_3 = el_3;
        this.placeholder = this.dd_3.children('span');
        this.opts = this.dd_3.find('ul.dropdown > li');
        this.val = '';
        this.index = -1;
        this.initEvents();
    }
    DropDown_3.prototype = {
        initEvents : function() {
            var obj_3 = this;

            obj_3.dd_3.on('click', function(event){
                jQuery(this).toggleClass('active');
                return false;
            });

            obj_3.opts.on('click',function(){
                var opt = jQuery(this);
                obj_3.val = opt.text();
                obj_3.index = opt.index();
                obj_3.placeholder.text(obj_3.val);
            });
        },
        getValue : function() {
            return this.val;
        },
        getIndex : function() {
            return this.index;
        }
    }

    jQuery(function() {
        var dd_3 = new DropDown_3( jQuery('#dd-3') );
        jQuery(document).click(function() {
            // all dropdowns
            jQuery('.wrapper-dropdown-3').removeClass('active');
        });
    });
});

/* ================= Fix Footer No Content =====================*/
jQuery(document).ready(function($) {
    $('#navigation').localScroll(1000);
});
