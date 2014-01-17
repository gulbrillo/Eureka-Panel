/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))


int card_services_front(void)
{
    FILE *ptr_file;
    char buf[1000];
    char path[1035];
    char servicewebpanel[1024];
    char servicessh[1024];
    char serviceadb[1024];
    char servicetelnet[1024];
    char *webpaneltick;
    char *sshtick;
    char *telnettick;
    char *adbtick;
    char *webpaneltick2;
    char *sshtick2;
    char *telnettick2;
    char *adbtick2;

    printf("\n<div class=\"cbot\">");


webpaneltick2 = " ";
sshtick2 = " ";
telnettick2 = " ";
adbtick2 = " ";
webpaneltick = " ";
sshtick = " ";
telnettick = " ";
adbtick = " ";


//this is a logical mess, please ignore (and don't reuse this one for other cards)

read_config_var("Services", "http", servicewebpanel);
	if (!compStr(servicewebpanel, "0", 1024)) {webpaneltick = "checked"; webpaneltick2 = " ";} else {webpaneltick = " "; webpaneltick2 = "checked";}
read_config_var("Services", "ssh", servicessh);
	if (!compStr(servicessh, "0", 1024)) {sshtick = "checked"; sshtick2 = " ";} else {sshtick = " "; sshtick2 = "checked";}
read_config_var("Services", "telnet", servicetelnet);
        if (!compStr(servicetelnet, "0", 1024)) {telnettick = "checked"; telnettick2 = " ";} else {telnettick = " "; telnettick2 = "checked";}
read_config_var("Services", "adb", serviceadb);
        if (!compStr(serviceadb, "0", 1024)) {adbtick = "checked"; adbtick2 = " ";} else {adbtick = " "; adbtick2 = "checked";}


printf("\n<form id=\"servicesForm\"><div class=\"ticks\" id=\"servicesOptions\">");


// CUSTOM PASSWORD FORM
    printf("<div id=\"httpoff\">");

    printf("\n<div class=\"warning\">");

    printf("\n<div>This will kill the web panel. Are you sure?</div>");

    printf("\n</div>");

        printf("\n<div class=\"buttons\">");

        printf("\n<div id=\"CANCELhttp\">Cancel</div><div id=\"SENDhttp\">Do it</div>");

        printf("\n</div>");

    printf("\n</div>");


    printf("\n<div><label id=\"labeltickssh\" class=\"%s\"><input %s  type=\"checkbox\" name=\"Services/ssh\" value=\"disabled\" id=\"tickservicessh\">SSH</label></div>", sshtick, sshtick2);

    printf("\n<div><label id=\"labelticktelnet\" class=\"%s\"><input %s  type=\"checkbox\" name=\"Services/telnet\" value=\"disabled\" id=\"tickservicetelnet\">Telnet</label></div>", telnettick, telnettick2);

    printf("\n<div><label id=\"labeltickadb\" class=\"%s\"><input %s type=\"checkbox\" name=\"Services/adb\" value=\"disabled\" id=\"tickserviceadb\">ADB (debug)</label></div>", adbtick, adbtick2);

    printf("\n<div><label id=\"labeltickwebpanel\" class=\"%s\"><input %s  type=\"checkbox\" name=\"Services/http\" value=\"disabled\" id=\"tickservicehttp\">HTTP/HTTPS</label></div>", webpaneltick, webpaneltick2);


printf("\n</div></form>");

printf("\n</div>");

}
