/*
This module presents basic network information to the user
*/

int card_team_simon(void)
{


printf("<div id=\"team_simon\" class=\"flipcard team\">");

// front

  printf("\n<div id=\"simon_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_simon').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Simon</div><br /><div class=\"description\">gulbrillo</div>");
    printf("\n</div>");

printf("<div class=\"cbot\">");
    printf("\n<div>Graphic design</div><br /><div>Frontend development</div></div>");

 printf("</div>");
//


    printf("\n<div id=\"simon_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_simon').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");

    printf("\n<div class=\"title\">Simon</div>");
    printf("\n<div class=\"description\">Simon Barke (gulbrillo) tries to enhance the user perception with lots of eye candy and mature GUI concepts. As PhD student in physics he works on the LISA Mission, shooting lasers into space to track down black holes throughout the universe. (Germany)</div>");

    printf("\n</div>");


printf("<div class=\"cbot\">");
    printf("\n<a href=\"https://github.com/gulbrillo/\" target=\"_blank\" title=\"GitHub\"><i class=\"icon-git\"></i></a><a href=\"http://forum.xda-developers.com/member.php?u=3151419\" target=\"_blank\" title=\"XDA\"><i class=\"icon-xda\"></i></a><a href=\"https://twitter.com/simonbarke\" target=\"_blank\" title=\"Twitter\"><i class=\"icon-twitter\"></i></a><a href=\"https://google.com/+SimonBarke\" target=\"_blank\" title=\"Google+\"><i class=\"icon-google-plus\"></i></a></div>");



    printf("\n</div>");


printf("</div>");


}
