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

    printf("\n<div id=\"WhitelistProvider0\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"0\" id=\"wleureka-radio\" %s></input><label class=\"%s\" for=\"wleureka-radio\">Team Eureka</label></div>", WhitelistProvider0selected, WhitelistProvider0selected);
    printf("\n<div id=\"WhitelistProvider1\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"1\" id=\"wlgoogle-radio\" %s></input><label class=\"%s\" for=\"wlgoogle-radio\">Google (default)</label></div>", WhitelistProvider1selected, WhitelistProvider1selected);
    printf("\n<div id=\"WhitelistProvider2\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"2\" id=\"wllocal-radio\" %s></input><label class=\"%s\" for=\"wllocal-radio\">Locally stored</label></div>", WhitelistProvider2selected, WhitelistProvider2selected);
    printf("\n<div id=\"WhitelistProvider3\"><input type=\"radio\" name=\"WhiteList/useSelection\" value=\"3\" id=\"wlcustom-radio\" %s></input><label class=\"%s\" for=\"wlcustom-radio\">Custom server</label></div>", WhitelistProvider3selected, WhitelistProvider3selected);


    printf("</div>");

    //scroll to selected Whitelist
    printf("\n<script type='text/javascript'>   $('#WHITEselection').scrollTo($('#WhitelistProvider%s'));</script>\n", selectedWhitelistProvider);

return 1;
}


int card_whitelist_front(void)
{

    char selectedWhitelistProvider[1024];
    char customwhiteserver[1024];
    read_config_var("WhiteList", "customURL", customwhiteserver);


    printf("\n<div class=\"cbot\">");
       printWhitelistProviders();



// CUSTOM DNS FORM
    printf("<div id=\"WHITEcustom\">");

    printf("\n<form id=\"customWHITEform\">");
    printf("\n<input name=\"action\" type=\"hidden\" id=\"action\" value=\"update\">");
    printf("\n<input name=\"WhiteList/useSelection\" type=\"hidden\" id=\"useCustomWhite\" value=\"3\">");

    printf("\n<div class=\"table\">");

    printf("\n<div class=\"row\">");
    printf("\n<div>Custom server</div>");
    printf("\n</div>");

    printf("\n<div class=\"row\">");
    printf("\n<div><input value=\"%s\" type=\"text\" class=\"whiteinput\" name=\"WhiteList/customURL\"  id=\"whitefield\"  autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>", customwhiteserver);
    printf("\n</div>");

    printf("\n</div>");

	printf("\n<div class=\"buttons\">");

	printf("\n<div id=\"CANCELcustomWHITE\">Cancel</div><div id=\"SENDcustomWHITE\">OK</div>");

	printf("\n</div>");

    	printf("\n</form>");

    printf("\n</div>");


    read_config_var("WhiteList", "useSelection", selectedWhitelistProvider);
    if(compStr(selectedWhitelistProvider, "0", sizearray(selectedWhitelistProvider)))
    {
        printf("\nWhitelist updated regularly from Team Eureka servers. If you want to edit the whitelist manually, select 'Locally stored' from the menu.");
    }
    else if(compStr(selectedWhitelistProvider, "1", sizearray(selectedWhitelistProvider)))
    {
	printf("\nWhitelist updated regularly from Google servers. If you want to edit the whitelist manually, select 'Locally stored' from the menu.");
    }
    else if(compStr(selectedWhitelistProvider, "2", sizearray(selectedWhitelistProvider)))
    {
        printf("\n<div style=\"margin-bottom:41px;\">Whitelist stored locally on Chromecast in file /data/eureka/apps.conf.</div><div class=\"buttons\"><div id=\"editWHITE\">Edit whitelist</div></div>");
    }
    else if(compStr(selectedWhitelistProvider, "3", sizearray(selectedWhitelistProvider)))
    {
	printf("\nWhitelist updated regularly from server <div style=\"overflow:hidden;white-space:nowrap;width:306px;\">%s.</div> If you want to edit the whitelist manually, select 'Locally stored' from the menu.",customwhiteserver);
    }
    else
    {
	printf("\nIf you would like to edit the whitelist manually, please select 'Locally stored' from the menu.");
    }



printf("\n</div>");

return 1;
}
