/*
This module presents basic network information to the user
*/


int card_dns_back(void)
{
    printf("\n<div id=\"dns_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#dns').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">DNS</div>");
    printf("\n<div class=\"description\">Chromecast was designed to use Google's own DNS servers. In order to remove geographical restrictions you can choose alternative servers. This will place your device in a different country and unlock more services. However, some of these DNS servers are not free of charge and require an associated user account.</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
