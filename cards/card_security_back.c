/*
This module presents basic network information to the user
*/


int card_security_back(void)
{
    printf("\n<div id=\"security_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#security').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Security</div>");
    printf("\n<div class=\"description\">You can protect the SSH service (not Telnet) by password. There is also a password option for the web panel, but be aware that http transmitts password as plain text. The web panel stores a random hash value as session cookie. You can only be logged in with one client at a time. Please remember to log out on exit.</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
