/*
This module presents basic network information to the user
*/

int card_whitelist(void)
{


printf("<div id=\"whitelist\" class=\"flipcard\">");

// front

  printf("\n<div id=\"dns_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#whitelist').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Whitelist</div>");
    printf("\n</div>");

printf("<div id=\"whitelist_update\">");
 card_whitelist_front();
printf("</div>");


 printf("</div>");
//

            card_whitelist_back();

printf("</div>");

}
