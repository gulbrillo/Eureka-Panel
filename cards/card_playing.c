/*
This module presents basic network information to the user
*/

int card_playing(void)
{


printf("<div id=\"playing\" class=\"flipcard\">");

  printf("\n<div id=\"playing_front\" class=\"card front\">");

    printf("<div id=\"playing_update\">");
            card_playing_front();
    printf("</div>");

  printf("</div>");

            card_playing_back();

printf("</div>");

printf("\n<script>");
printf("\n(function($)");
printf("\n{");
printf("\n    $(document).ready(function()");
printf("\n    {");
printf("\n        var $container = $(\"#playing_update\");");
printf("\n        var refreshId = setInterval(function()");
printf("\n        {");
printf("\n            $container.load('?page=playing_front&footers=0&headers=0&newcache=' +Math.random());");
printf("\n        }, 5000);");
printf("\n    });");
printf("\n})(jQuery);");
printf("\n</script>");


}
