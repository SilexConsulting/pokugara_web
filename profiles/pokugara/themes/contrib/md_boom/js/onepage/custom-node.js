jQuery(document).ready(function($) {
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
    });
    jQuery('#pf-list-flex').flexslider({
        animation: "slide",
        slideshow: true,
        start: function(slider){
            jQuery('body').removeClass('loading');
        }
    });
})

