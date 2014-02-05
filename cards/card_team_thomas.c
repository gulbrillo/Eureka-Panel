/*
This module presents basic network information to the user
*/

int card_team_thomas(void)
{


printf("<div id=\"team_thomas\" class=\"flipcard team\">");

// front

  printf("\n<div id=\"thomas_front\" class=\"card front\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_thomas').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
       printf("\n<div class=\"title\">Thomas</div><br><div class=\"description\">tchebb</div>");
    printf("\n</div>");

printf("<div class=\"cbot\">");
    printf("\n<div>Make file maker</div><br /><div>FlashCast development</div></div>");

 printf("</div>");
//


    printf("\n<div id=\"thomas_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#team_thomas').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");

    printf("\n<div class=\"title\">Thomas</div>");
    printf("\n<div class=\"description\">Thomas Hebb (tchebb) is a picky perfectionist, the last barrier to low-quality code. His early insight and development formed the basis for the rooted Chromecast.  Thomas is currently in hight school studying computer science. (Massachusetts, USA)</div>");

    printf("\n</div>");

printf("<div class=\"cbot\">");
    printf("\n<a href=\"https://github.com/tchebb/\" target=\"_blank\" title=\"GitHub\"><i class=\"icon-git\"></i></a><a href=\"http://forum.xda-developers.com/member.php?u=2789381\" target=\"_blank\" title=\"XDA\"><i class=\"icon-xda\"></i></a><a href=\"https://google.com/+ThomasHebb\" target=\"_blank\" title=\"Google+\"><i class=\"icon-google-plus\"></i></a></div>");

    printf("\n</div>");


printf("</div>");

return 1;

}
