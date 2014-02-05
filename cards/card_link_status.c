/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_status_team(void)
{


    printf("\n<div id=\"statuslink\" class=\"flipcard\"><div class=\"card linkcard\">");

    printf("\n<div class=\"ctop\"><i class=\"icon-meter2 thumb\"></i>");
    
    printf("\n<div class=\"title\">Status</div>");
    printf("\n<div class=\"description\">Control, system load, connectivity</div>");


    printf("\n<div class=\"cbot\">");

    printf("\n<div>Internet status: dunno</div>");
    printf("\n<div>WiFi connectivity: Foo bar</div>");
    printf("\n<div>CPU: 1%, Temperature: 10°C</div>");
    printf("\n<div>Casting: idle</div>");

    printf("\n</div>");


    printf("\n</div>");
    printf("\n</div></div>");

}
