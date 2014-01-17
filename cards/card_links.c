/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_links(void)
{


    printf("\n<div class=\"smallcard\"><div id=\"teameurekalink\" class=\"card\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-arrow-right4\"></i><div class=\"title\">Team Eureka</div>");
    printf("\n<div class=\"description\">About / contact</div>");
    printf("\n</div>");
    
    printf("\n</div>");


    printf("\n<div id=\"debuglink\" class=\"card\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-arrow-right4\"></i><div class=\"title\">Debug</div>");
    printf("\n<div class=\"description\">Logcat / dumpstate</div>");
    printf("\n</div>");

    printf("\n</div></div>");


}
