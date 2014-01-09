/*
This module returns the HTML footer
*/

FILE *ptr_file;
char buf[1000];

int card_layout_footer()
{

// HTML STARTS HERE (footer)

printf("\n</div>");

printf("\n<div class=\"clearspace\"></div>");

printf("\n");



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

printf("\n  <div class=\"ccserial\">");

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

printf("\n</div>");
printf("\n");


printf("\n</div>");
printf("\n");

//printf("\n<script type='text/javascript' src='js/jquery.inputmask.bundle.js'></script>");
printf("\n</body>");
printf("\n</html>");

}
