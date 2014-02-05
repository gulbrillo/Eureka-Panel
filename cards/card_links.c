/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_links(void)
{

    printf("\n<div class=\"twoorless\">");
    printf("\n<div class=\"smallcard\"><div id=\"statuslink\" class=\"card linkcard\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-meter2 thumb\"></i><div class=\"title\">Status</div>");
    printf("\n<div class=\"description\">Control / system / connectivity</div>");
    printf("\n</div>");

    printf("\n</div>");


    printf("\n<div id=\"settingslink\" class=\"card linkcard\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-equalizer2 thumb\"></i><div class=\"title\">Settings</div>");
    printf("\n<div class=\"description\">Features / services / updates</div>");
    printf("\n</div>");

    printf("\n</div></div>");


    printf("\n<div class=\"smallcard\"><div id=\"teameurekalink\" class=\"card linkcard\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-users thumb\"></i><div class=\"title\">Team Eureka</div>");
    printf("\n<div class=\"description\">About / contact</div>");
    printf("\n</div>");
    
    printf("\n</div>");


    printf("\n<div id=\"debuglink\" class=\"card linkcard\">");

    printf("\n<div class=\"ctop\">");
    printf("\n<i class=\"icon-bug2 thumb\"></i><div class=\"title\">Debug</div>");
    printf("\n<div class=\"description\">Logcat / dumpstate</div>");
    printf("\n</div>");

    printf("\n</div></div>");
    printf("\n</div>");

return 1;
}
