<!-- Navigation-->
<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php else : ?>
    <nav id="navigation">
        <div class="wrapper clearfix">
            <a class="logo" href="<?php if(isset($base_url)) {print $base_url;}?>"><img  src="<?php print $GLOBALS['base_url'] . '/' .drupal_get_path('theme','md_boom').'/sub-logo.png'?>"/></a>
        </div>
    </nav>
<?php endif;?>
<!--end:navigation-->
<?php if ($messages): ?>
    <div id="messages">
        <?php print $messages; ?>
    </div> <!-- /#messages -->
<?php endif; ?>
<div class="container">
    <div class="row-fluid">
        <?php if($page['content']):?>
            <?php print render($page['content']);?>
        <?php endif;?>
    </div>
</div>

<?php
$twitter_acc = theme_get_setting('twitter_account');
$skype_acc = theme_get_setting('skype_account');
$facebook_acc = theme_get_setting('facebook_account');
$youtube_channel = theme_get_setting('youtube_channel');
$gplus = theme_get_setting('google+_account');
$linkedin = theme_get_setting('dribbble_account');
$pinterest = theme_get_setting('pinterest_account');
$dribbble = theme_get_setting('linkedin_account');
?>

<footer id="flx-footer">

    <div class="page-bottom">
        <div class="wrapper">

            <center>
                <?php if(theme_get_setting('enable_socials','md_boom') == '1'):?>
                    <?php if($twitter_acc != null || $skype_acc != null || $facebook_acc != null || $youtube_channel != null || $gplus != null || $linkedin != null || $pinterest != null || $dribbble != null ):?>
                        <ul class="social-links clearfix">
                            <?php if($twitter_acc != null):?><li class="flx-twitter-icon"><a href="<?php print $twitter_acc;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($facebook_acc != null):?><li class="flx-facebook-icon"><a href="<?php print $facebook_acc;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($skype_acc != null):?><li class="flx-skype-icon"><a href="<?php print $skype_acc;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($youtube_channel != null):?><li class="flx-youtube-icon"><a href="<?php print $youtube_channel;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($gplus != null):?><li class="flx-gplus-icon"><a href="<?php print $gplus;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($dribbble != null):?><li class="flx-dribbble-icon"><a href="<?php print $dribbble;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($pinterest != null):?><li class="flx-pinterest-icon"><a href="<?php print $pinterest;?>" target="_blank"></a></li><?php endif;?>
                            <?php if($linkedin != null):?><li class="flx-linkedin-icon"><a href="<?php print $linkedin;?>" target="_blank"></a></li><?php endif;?>
                        </ul>
                    <?php endif;?>
                <?php endif;?>
            </center>

        </div><!--end:wrapper-->
    </div><!--end:page-bottom-->

    <div id="footer-bottom">
        <div class="wrapper">
            <div id="footer-logo">
                <a href=""><img src="<?php if(isset($footer_logo_path)) { print $footer_logo_path;}?>" alt="" /></a>
            </div><!--end:footer-logo-->
            <center>
                <?php if(isset($footer_text)) :print t($footer_text);else : print t('<strong>Boom</strong>
                                    - Html theme © 2013 by
                                    <a href="http://megadrupal.com">MegaDrupal.com</a>
                                    </p>
                                    <p>All stock photos used on this Boom demo site are only for demo purposes and not included in the template package.</p>'); endif;?>
            </center>
        </div><!--end:wrapper-->
    </div><!--end:footer-bottom-->
</footer><!--end:flx-footer-->
