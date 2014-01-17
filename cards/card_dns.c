/*
This module presents basic network information to the user
*/

int card_dns(void)
{


printf("<div id=\"dns\" class=\"flipcard\">");

// front

  printf("\n<div id=\"dns_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#dns').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">DNS</div>");
    printf("\n</div>");

printf("<div id=\"dns_update\">");
 card_dns_front();
printf("</div>");


 printf("</div>");
//

            card_dns_back();

printf("</div>");

}
