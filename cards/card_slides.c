/*
This module returns the Slides
*/

void card_slides()
{

// HTML STARTS HERE (footer)

printf("\n<div id=\"page1\"><div class=\"anchor\"><div class=\"cards\">");

               card_links();
	       card_twitter();
	       card_links_big();

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


printf("\n<div id=\"page3\"><div class=\"anchor\"><div class=\"cards\">");

card_playing();
card_wifi();
card_status();
card_network();

printf("\n<div class=\"clearspace\"></div>");

printf("\n</div></div></div>");


printf("\n<div id=\"page4\"><div class=\"anchor\"><div class=\"cards\">");

card_dns();
card_security();
card_services();
card_whitelist();
card_updates();

printf("\n<div class=\"clearspace\"></div>");

printf("\n</div></div></div>");



}
