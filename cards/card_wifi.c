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


}
