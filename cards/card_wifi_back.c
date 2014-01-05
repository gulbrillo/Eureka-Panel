/*
This module presents basic network information to the user
*/


int card_wifi_back(void)
{
    printf("\n<div id=\"wifi_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<img src=\"images/x.svg\" onclick=\"document.querySelector('#wifi').classList.toggle('flip');\" class=\"corner\">");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">WiFi</div>");
    printf("\n<div class=\"description\">Chromecast supports 2.4 GHz 802.11 b/g/n WiFi networks. Signal and noise power are given in dBm, the signal-to-noise ratio (SNR) is the power ratio between signal and noise (given in dB). Higher numbers repesent cleaner WiFi signals. The HDMI extender may be used to improve your WiFi reception.</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
