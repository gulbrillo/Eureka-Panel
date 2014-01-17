/*
This module returns the HTML header
*/

int card_layout_header(void)
{

    FILE *ptr_file;
    char buf[1000];

//    printf( "HTTP/1.1 200 OK\n" );
//    printf( "Content-Type: text/html; charset=UTF-8\n\n" );

// HTML STARTS HERE (header)

printf("<!DOCTYPE html>");
printf("\n<html>");
printf("\n  <head>");
printf("\n  <meta charset=\"utf-8\">");
printf("\n  <meta name=\"viewport\" content=\"initial-scale=1.0, maximum-scale=1.0, user-scaleable=no, width=device-width\" />");
printf("\n  <title>Chromecast Configuration Panel - Eureka Rom</title>");
//printf("\n  <link href='http://fonts.googleapis.com/css?family=Roboto:300,100' rel='stylesheet' type='text/css'>");
printf("\n  <link href=\"cards.css\" media=\"screen\" rel=\"stylesheet\" type=\"text/css\">");

//printf("\n<script src=\"http://code.jquery.com/jquery-latest.js\"></script>");

printf("\n<script type='text/javascript' src='js/jquery-1.10.2.min.js'></script>");
printf("\n<script type='text/javascript' src='js/jquery.scrollTo-min.js'></script>");
printf("\n<script type='text/javascript' src='js/ajax.js'></script>");

printf("\n</head>");
printf("\n");


char currenttheme[1024];
read_config_var("Webpanel", "theme", currenttheme);


printf("\n<body class=\"%s\">", currenttheme);
printf("\n<div id=\"page\" class=\"page1\">");
printf("\n<div id=\"shade\"></div>");



printf("\n<div id=\"top\">");


printf("\n  <div id=\"eureka\">");

printf("\n  <div id=\"eurekayellow\">");
printf("<img src=\"images/yellow-01.svg\" class=\"yellow\">");
printf("\n</div>");
printf("\n  <div id=\"eurekadark\">");
printf("<img src=\"images/dark-01.svg\" class=\"dark\">");
printf("\n</div>");
printf("\n  <div id=\"eurekalight\">");
printf("<img src=\"images/light-01.svg\" class=\"light\">");
printf("\n</div>");
printf("\n  <div id=\"eurekawhite\"><div id=\"fade\">");
printf("<img src=\"images/white-01.svg\" class=\"white\">");
printf("\n</div></div>");
printf("\n  <div id=\"eurekatext\"><div id=\"overflow\">");
printf("<img src=\"images/eureka.svg\" class=\"etext\">");
printf("\n</div></div>");
printf("\n  <div id=\"chrometext\">");
printf("<img src=\"images/chrome.svg\" class=\"ctext\">");
printf("\n</div>");

printf("\n</div>");

printf("\n  <div id=\"ccname\"><div class=\"inner\">");

printf("<span class=\"castlogo\"><img src=\"images/cast.svg\" class=\"castlogo\"></span>");

// NAME OF CHROMECAST

 ptr_file=popen("cat /data/chrome/.eureka.conf | grep eureka-name | busybox awk -F \":\" '{print $2}' | busybox awk -F '\"' '{print $2}' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {

printf( "%s", buf );
}
    pclose(ptr_file);

printf("\n  </div></div>");
printf("\n</div>");
printf("\n");
printf("\n<div id=\"slides\">");

}
