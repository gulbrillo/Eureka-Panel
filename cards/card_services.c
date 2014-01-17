/*
This module presents basic network information to the user
*/

int card_services(void)
{


printf("<div id=\"services\" class=\"flipcard\">");

// front

  printf("\n<div id=\"services_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#services').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Services</div>");
    printf("\n</div>");

printf("<div id=\"services_update\">");
 card_services_front();
printf("</div>");


 printf("</div>");
//

            card_services_back();

printf("</div>");

//printf("\n<script type='text/javascript'>(function($){$(document).ready(function(){setTimeout(function(){scrollTo(0,0);},1);});})(jQuery);</script>");


}
