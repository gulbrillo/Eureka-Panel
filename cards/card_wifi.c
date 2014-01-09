/*
This module presents basic network information to the user
*/

int card_wifi(void)
{


printf("<div id=\"wifi\" class=\"flipcard\">");

  printf("\n<div id=\"wifi_front\" class=\"card front\">");

    printf("<div id=\"wifi_update\">");
            card_wifi_front();
    printf("</div>");

  printf("</div>");

            card_wifi_back();

printf("</div>");

printf("\n<script>");
printf("\n(function($)");
printf("\n{");
printf("\n    $(document).ready(function()");
printf("\n    {");
printf("\n        var $container = $(\"#wifi_update\");");
printf("\n        var refreshId = setInterval(function()");
printf("\n        {");
printf("\n            $container.load('?page=wifi_front&footers=0&headers=0&newcache=' +Math.random());");
printf("\n        }, 2500);");
printf("\n    });");
printf("\n})(jQuery);");
printf("\n</script>");



}
