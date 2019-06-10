
<?php
// hide($content['field_blog_post_author']);
// hide($content['links']);
//выводим содержимое страницы
// print render($content); выведет весь контент кроме того что в hide
// dpm($content);  должен выводить на страницу все переменные но не работает почемуто.
print render($content['field_preview']);
print render($content['field_blog_post_image'])
?>
<div class="red-test">
<?php
print render($content['field_blog_post_author'])
?>
</div>