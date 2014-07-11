
<?php if($page['header']):?>
    <!-- Home Page-->
    <div id="index">
        <?php print render($page['header']);?>
    </div>
<?php endif;?>

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
<?php if($page['content_1']):?>
    <!-- About Us-->
    <div id="content1">
        <?php print render($page['content_1']);?>
    </div><!--end:About Us-->
<?php endif;?>

<?php if($page['content_2']):?>
    <!-- Overview -->
    <div id="content2">
        <?php print render($page['content_2']);?>
    </div><!--end:Overview-->
<?php endif;?>

<!-- Separator1-->
<?php if(theme_get_setting('parallax_1_enabled') != null && theme_get_setting('parallax_1_enabled') == TRUE):?>
<div id="section1">
    <div class="section1-bg"></div>
   <?php if($page['parallax_1']):?>
    <?php print render($page['parallax_1']);?>
    <?php endif;?>
</div><!--end:Separator1-->
<?php endif;?>

<?php if($page['content_3']):?>
    <!-- Our Services-->
    <div id="content3">
         <?php print render($page['content_3']);?>
    </div>
    <!--end:Our Services-->
<?php endif ;?>

<!-- Separator2-->
<?php if(theme_get_setting('parallax_2_enabled') != null && theme_get_setting('parallax_2_enabled') == TRUE):?>
<div id="section2">
    <div class="section2-bg"></div>
      <?php if($page['parallax_2']):?>
    <?php print render($page['parallax_2'])?>
    <?php endif;?>
</div><!--end:Separator2-->
<?php endif;?>

<?php if($page['content_4']):?>
    <!-- Portfolio-->
    <div id="content4">
        <?php print render($page['content_4']);?>
    </div>
    <!--end:Portfolio-->
<?php endif;?>

  <!-- Separator3-->
<?php if(theme_get_setting('parallax_3_enabled') != null && theme_get_setting('parallax_3_enabled') == TRUE):?>
<div id="section3">
    <div class="pattern"></div>
    <div class="section3-bg"></div>
    <?php if($page['parallax_3']):?>
        <?php print render($page['parallax_3']);?>
    <?php endif;?>
</div><!--end:Separator3-->
<?php endif;?>

<?php if($page['content_5'] != null):?>
<!-- Our Blog-->
<div id="content5">
   <?php print render($page['content_5']);?>
</div>
<!--end:News-->
<?php endif;?>

  <!--/Separator4-->
<?php if(theme_get_setting('parallax_4_enabled') != null && theme_get_setting('parallax_4_enabled') == TRUE):?>
<div id="section4">
    <div class="section4-bg"></div>
    <?php if($page['parallax_4']):?>
        <?php print render($page['parallax_4']);?>
    <?php endif;?>
</div><!--end:Separator4-->
<?php endif;?>


<?php if($page['content_6']):?>
    <!-- Contact-->
    <div id="content6">
        <?php print render($page['content_6']);?>
    </div>
        <!--end:Contact-->
<?php endif;?>

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
