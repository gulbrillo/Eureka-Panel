/*
This module returns the HTML footer
*/

FILE *ptr_file;
char buf[1000];

int card_layout_footer()
{

// HTML STARTS HERE (footer)


printf("\n");

printf("\n</div>");

printf("\n<div id=\"welcome\">");

printf("\n<div class=\"content\">");

printf("\n<div class=\"centerme\">");

printf("\n<div class=\"centerme_backtrack\">");

printf("\n<div class=\"box\">");

	printf("\n<div id=\"welcome_logo\">");
	printf("\n</div>");

	printf("\n<form id=\"PanelLogin\" method=\"post\"><input name=\"action\" type=\"hidden\" value=\"login\"/>");
        printf("\n<div id=\"welcome_login\">");
	printf("\n<div id=\"welcome_pass\"><input id=\"welcome_password\" name=\"welcome_password\" type=\"password\" /></div>");
	printf("\n<div id=\"welcome_send\" class=\"clickable\">Log in</div>");
	printf("\n</form>");
        printf("\n</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");
printf("\n");


printf("\n<div id=\"bottom\">");

char protected[1024];
read_config_var("Security", "webprotected", protected);

if (compStr(protected, "true", 1024)) {
        printf("\n  <div id=\"logout\" class=\"hidden\"><a href=\"?logout\">Log out</a></div>");
	printf("<div id=\"settings\" class=\"logout hidden\"><div id=\"cog\"><i class=\"icon-cog\"></i><div class=\"menu\">");
        } else {
        printf("\n  <div id=\"logout\" class=\"hidden invisible\"><a href=\"?page=logout\">Log out</a></div>");
	printf("<div id=\"settings\" class=\"hidden\"><div id=\"cog\"><i class=\"icon-cog\"></i><div class=\"menu\">");
        }


printf("<ul><li id=\"settings_theme\">");

settings_theme();

printf("</li><li><ul><form id=\"elements\">");
printf("<li><label class=\"checked\">Network</label></li><li><label class=\"checked\">Status</label></li><li><label class=\"checked\">DNS</label></li><li><label class=\"checked\">WiFi</label></li><li><label class=\"checked\">Security</label></li><li><label class=\"checked\">Services</label></li><li><label class=\"checked\">News</label></li></form></ul>Elements</li></ul>");

printf("</div></div></div>");

printf("\n<div id=\"credit\"><div class=\"ccserial\">");

// PRINT SERIAL NO
    ptr_file=popen("cat /factory/serial.txt | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        printf( "Serial #: %s", buf );
    }
    pclose(ptr_file);

printf("\n  </div>");

printf("\n  <div class=\"version\">");
printf("Powered by Team-Eureka Panel v2.0");
printf("\n  </div>");


printf("\n</div></div>");
printf("\n");


printf("\n</div>");
printf("\n");

//printf("\n<script type='text/javascript' src='js/jquery.inputmask.bundle.js'></script>");
printf("\n</body>");
printf("\n</html>");

}
