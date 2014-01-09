/*
This module presents basic network information to the user
*/


int card_security_back(void)
{
    printf("\n<div id=\"security_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<img src=\"images/x.svg\" onclick=\"document.querySelector('#security').classList.toggle('flip');\" class=\"corner\">");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Security</div>");
    printf("\n<div class=\"description\">You may want to protect this web panel and the SSH/Telnet service by password. Be aware that with http and telnet passwords are transmitted as plain text. The web panel stores a random hash value as session cookie. You can only be logged in with one client at a time. Please remember to always log out on exit.</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
