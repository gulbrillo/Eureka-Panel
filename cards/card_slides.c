/*
This module returns the Slides
*/

void card_slides()
{

// HTML STARTS HERE (footer)

printf("\n<div id=\"page1\"><div class=\"anchor\"><div class=\"cards\">");

               card_twitter();
	       card_playing();
               card_wifi();
               card_status();
	       card_links();
               card_network();
               card_dns();
               card_security();
               card_services();

printf("\n<div class=\"clearspace\"></div>");

printf("\n</div></div></div>");

printf("\n<div id=\"page2\"><div class=\"anchor\"><div class=\"cards\">");

card_team_rom();
card_team_chris();
card_team_thomas();
card_team_trevor();
card_team_simon();

printf("\n<div class=\"clearspace\"></div>");

printf("\n</div></div></div>");



}
