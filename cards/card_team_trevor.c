/*
This module presents basic network information to the user
*/

int card_team_trevor(void)
{


printf("<div id=\"team_trevor\" class=\"flipcard team\">");

// front

  printf("\n<div id=\"trevor_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_trevor').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Trevor</div><br><div class=\"description\">kyonz</div>");
    printf("\n</div>");

printf("<div class=\"cbot\">");
    printf("\n<div>Code review</div><br /><div>Backend development</div></div>");

 printf("</div>");
//


    printf("\n<div id=\"trevor_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_trevor').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");

    printf("\n<div class=\"title\">Trevor</div>");
    printf("\n<div class=\"description\">Trevor Preston (kyronz) has a found keenness in physical and logical automation. He provides all CGI backend applications for whitelisting, webpanel, and settings. When not spending time fighting Sauron, he works as a Solution Architect. (New Zealand)</div>");

    printf("\n</div>");

printf("<div class=\"cbot\">");
    printf("\n<a href=\"https://github.com/kyonz/\" target=\"_blank\" title=\"GitHub\"><i class=\"icon-git\"></i></a><a href=\"http://forum.xda-developers.com/member.php?u=2634811\" target=\"_blank\" title=\"XDA\"><i class=\"icon-xda\"></i></a><a href=\"https://twitter.com/kyonz\" target=\"_blank\" title=\"Twitter\"><i class=\"icon-twitter\"></i></a><a href=\"http://www.linkedin.com/in/trevorpreston\" target=\"_blank\" title=\"LinkedIn\"><i class=\"icon-linkedin\"></i></a><a href=\"https://plus.google.com/109181921514421986332\" target=\"_blank\" title=\"Google+\"><i class=\"icon-google-plus\"></i></a></div>");

    printf("\n</div>");


printf("</div>");


}
