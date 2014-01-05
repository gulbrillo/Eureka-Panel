/*
This module returns the HTML footer
*/

FILE *ptr_file;
char buf[1000];

int card_layout_footer()
{

// HTML STARTS HERE (footer)

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
