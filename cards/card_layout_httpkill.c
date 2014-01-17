/*
This module returns the HTML header
*/

int card_httpkill(void)
{

//    printf( "HTTP/1.1 200 OK\n" );
//    printf( "Content-Type: text/html; charset=UTF-8\n\n" );

// HTML STARTS HERE (header)

printf("<!DOCTYPE html>");
printf("\n<html>");
printf("\n  <head>");
printf("\n  <meta charset=\"utf-8\">");
printf("\n  <meta name=\"viewport\" content=\"initial-scale=1.0, maximum-scale=1.0, user-scaleable=no, width=device-width\" />");
printf("\n  <title>Chromecast Configuration Panel - Eureka Rom</title>");
// printf("\n  <link href='http://fonts.googleapis.com/css?family=Roboto:300,100' rel='stylesheet' type='text/css'>");
printf("\n  <link href=\"cards.css\" media=\"screen\" rel=\"stylesheet\" type=\"text/css\">");

printf("\n<script type='text/javascript' src='js/jquery-1.10.2.min.js'></script>");

printf("\n</head>");
printf("\n");
printf("\n<body>");
printf("\n<div id=\"page\">");

printf("\n<div id=\"welcome\">");

printf("\n<div class=\"content\">");

printf("\n<div class=\"centerme\">");

printf("\n<div class=\"centerme_backtrack goodbye\">");

printf("\n<div class=\"box\">");

        printf("\n<div id=\"goodbye\">");
        printf("\n<div class=\"header\">Good bye</div>");
	printf("\n<div class=\"text\"><p>Leaving will not be entirely easy. I have genuinely enjoyed working with you. Please feel welcome to reinstate me.</p><p>Yours sincerely,<br>Chromecast Web Panel (by Team Eureka)</p></div>");
        printf("\n</div>");

printf("\n</div>");

printf("\n<div class=\"box more\">");

	printf("\n<div class=\"text\"><p>Wanna get me back?");
	printf("\nSet 'http=1' in /data/eureka/eureka.ini and reboot or flash reset image from <a href=\"http://goo.gl/XyHWX1\">goo.gl/XyHWX1</a>.</p></div>");
	printf("\n<div class=\"down\">&#xe616;</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");

printf("\n</div>");
printf("\n");

printf("\n</div>");

printf("\n</body>");
printf("\n</html>");

 printf("\n<script type=\"text/javascript\">");
 printf("\n$(function() {");

printf("\n$.ajax({type: 'POST', cache: false, async: false, url: '?page=killhttp', data: { 'action': 'killhttp' }});");

 printf("\n});");
 printf("\n</script>");


}
