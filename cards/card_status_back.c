/*
This module presents basic network information to the user
*/


int card_status_back(void)
{
    printf("\n<div id=\"status_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<img src=\"images/x.svg\" onclick=\"document.querySelector('#status').classList.toggle('flip');\" class=\"corner\">");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Status</div>");
    printf("\n<div class=\"description\">Chromecast packs a Marvell Armada 1500-Mini SoC featuring a single ARMv7 core, 2 GB flash memory, and 512 MB of RAM (298 MB available to the system). The CPU core temperature shall not exceed 70&deg;C (158&deg;F). Linux loads are given in 1, 5, and 15 minute averages. CPU usage is averaged between updates (every 15 seconds).");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

printf("\n</div>");
}
