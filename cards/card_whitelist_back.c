/*
This module presents basic network information to the user
*/


int card_whitelist_back(void)
{
    printf("\n<div id=\"whitelist_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#whitelist').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Whitelist</div>");
    printf("\n<div class=\"description\">Chromecast was designed to use Google's own DNS servers. In order to remove geographical restrictions you can choose alternative servers. This will place your device in a different country and unlock more services. However, some of these DNS servers are not free of charge and require an associated user account.</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
