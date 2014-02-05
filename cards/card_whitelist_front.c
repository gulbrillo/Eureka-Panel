/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int printWhitelistProviders()
{
    char whitelistDisplayName[1024];
    char selectedWhitelistProvider[1024];
    char* WhitelistProvider0selected = "";
    char* WhitelistProvider1selected = "";
    char* WhitelistProvider2selected = "";
    char* WhitelistProvider3selected = "";


    read_config_var("WhiteList", "useSelection", selectedWhitelistProvider);
    if(compStr(selectedWhitelistProvider, "0", sizearray(selectedWhitelistProvider)))
    {
        strcpy(whitelistDisplayName, "Team Eureka");
	WhitelistProvider0selected = "checked";
    }
    if(compStr(selectedWhitelistProvider, "1", sizearray(selectedWhitelistProvider)))
    {
        strcpy(whitelistDisplayName, "Google (default)");
	WhitelistProvider1selected = "checked";
    }
    if(compStr(selectedWhitelistProvider, "2", sizearray(selectedWhitelistProvider)))
    {
        strcpy(whitelistDisplayName, "Locally stored");
	WhitelistProvider2selected = "checked";
    }
    if(compStr(selectedWhitelistProvider, "3", sizearray(selectedWhitelistProvider)))
    {
        strcpy(whitelistDisplayName, "Custom server");
	WhitelistProvider3selected = "checked";
    }


    printf("<div class=\"WHITEname\" id=\"WHITEselected\">");
    printf("\n<div><label>%s</label></div>", whitelistDisplayName);
    printf("\n</div>");

    printf("<div class=\"WHITEname invisible\" id=\"WHITEselection\">");

    printf("\n<div id=\"WhitelistProvider0\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"local\" id=\"local-radio\" %s></input><label class=\"%s\" for=\"local-radio\">Team Eureka</label></div>", WhitelistProvider0selected, WhitelistProvider0selected);
    printf("\n<div id=\"WhitelistProvider1\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"local\" id=\"local-radio\" %s></input><label class=\"%s\" for=\"local-radio\">Google (default)</label></div>", WhitelistProvider1selected, WhitelistProvider1selected);
    printf("\n<div id=\"WhitelistProvider2\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"local\" id=\"local-radio\" %s></input><label class=\"%s\" for=\"local-radio\">Locally stored</label></div>", WhitelistProvider2selected, WhitelistProvider2selected);
    printf("\n<div id=\"WhitelistProvider3\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"local\" id=\"local-radio\" %s></input><label class=\"%s\" for=\"local-radio\">Custom server</label></div>", WhitelistProvider3selected, WhitelistProvider3selected);


    printf("</div>");

    //scroll to selected Whitelist
    printf("\n<script type='text/javascript'>   $('#WHITEselection').scrollTo($('#WhitelistProvider%s'));</script>\n", selectedWhitelistProvider);

return 1;
}


int card_whitelist_front(void)
{
    FILE *ptr_file;
    char buf[1000];
    char *nameservers;
    char *nameserver;
    char *dns1;
    char *dns2;

    printf("\n<div class=\"cbot\">");
       printWhitelistProviders();

// CURRENT ACTIVE WHITELIST

ptr_file = popen("cat /etc/resolv.conf | grep \"nameserver\" | busybox tr 'nameserver\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {        nameservers = buf;    }
fclose(ptr_file);

    //DNS1
        nameserver = strtok(nameservers, " ");
        dns1 = nameserver;
    //DNS2
        nameserver = strtok(NULL, " ");
        dns2 = nameserver;


// CUSTOM DNS FORM
    printf("<div id=\"WHITEcustom\">");

    printf("\n<form id=\"customWHITEform\">");
    printf("\n<input name=\"action\" type=\"hidden\" id=\"action\" value=\"update\">");
    printf("\n<input name=\"DNS/useDHCP\" type=\"hidden\" id=\"useDHCP\" value=\"0\">");
    printf("\n<input name=\"SmartDNS/selected\" type=\"hidden\" id=\"useDHCP\" value=\"other\">");

    printf("\n<div class=\"table\">");

    printf("\n<div class=\"row\">");
    printf("\n<div>Custom server</div>");
    printf("\n</div>");

    printf("\n<div class=\"row\">");
    printf("\n<div><input value=\"%s\" type=\"text\" class=\"dnsinput\" name=\"DNS/Secondary\"  id=\"dns2field\"  autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>", dns2);
    printf("\n</div>");

    printf("\n</div>");

	printf("\n<div class=\"buttons\">");

	printf("\n<div id=\"CANCELcustomWHITE\">Cancel</div><div id=\"SENDcustomWHITE\">OK</div>");

	printf("\n</div>");

    	printf("\n</form>");

    printf("\n</div>");


    printf("\n<div class=\"table\">");


    printf("\n<div class=\"row\">");
    printf("\n<div>Primary</div>");

	printf( "\n<div>%s</div>", dns1 );

    printf("\n</div>");


    printf("\n<div class=\"row\">");
    printf("\n<div>Secondary</div>");

        printf( "\n<div>%s</div>", dns2 );

    printf("\n</div>");

    printf("\n</div>");



printf("\n</div>");

return 1;
}
