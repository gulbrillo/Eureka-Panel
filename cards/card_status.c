/*
This module presents basic network information to the user
*/

int card_status(void)
{


printf("<div id=\"status\" class=\"flipcard\">");

  printf("\n<div id=\"status_front\" class=\"card front\">");

    printf("<div id=\"status_update\">");
            card_status_front();
    printf("</div>");

  printf("</div>");

            card_status_back();

printf("</div>");

printf("\n<script>");
printf("\n(function($)");
printf("\n{");
printf("\n    $(document).ready(function()");
printf("\n    {");
printf("\n        var $container = $(\"#status_update\");");
printf("\n        var refreshId = setInterval(function()");
printf("\n        {");
printf("\n            $container.load('?page=status_front&footers=0&headers=0&newcache=' +Math.random());");
printf("\n        }, 15000);");
printf("\n    });");
printf("\n})(jQuery);");
printf("\n</script>");


}
