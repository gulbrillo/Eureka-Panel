/*
This module presents basic network information to the user
*/

int card_security(void)
{


printf("<div id=\"security\" class=\"flipcard\">");

// front

  printf("\n<div id=\"dns_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<img src=\"images/i.svg\" onclick=\"document.querySelector('#security').classList.toggle('flip');\" class=\"corner\"></img>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Security</div>");
    printf("\n</div>");

printf("<div id=\"security_update\">");
 card_security_front();
printf("</div>");


 printf("</div>");
//

            card_security_back();

printf("</div>");

//printf("\n<script type='text/javascript'>(function($){$(document).ready(function(){setTimeout(function(){scrollTo(0,0);},1);});})(jQuery);</script>");


}
