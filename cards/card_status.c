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

}
