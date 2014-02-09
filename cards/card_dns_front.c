/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int printDNSProviders()
{
    long n;
    char str[1024];
    char buf[1024];
    char *token;
    char providerDisplayName[1024];
    char selectedProvider[1024];
    char *selectedProviderText;
    char *selectedProviderID;
    char *providerPrimaryIP;
    char *providerSecondaryIP;

    read_config_var("SmartDNS", "selected", selectedProvider);

	if (compStr(selectedProvider, "local", sizearray(selectedProvider))) {
	strcpy(providerDisplayName, "Local servers (DHCP)");
        } else if (compStr(selectedProvider, "other", sizearray(selectedProvider))) { 
        strcpy(providerDisplayName, "Custom servers");
        } else {
	strcpy(buf, "SmartDns-");
	strcat(buf, selectedProvider);
	read_config_var(buf, "displayName", providerDisplayName);
	}

    printf("<div class=\"DNSname\" id=\"DNSselected\">");
    printf("\n<div><label>%s</label></div>", providerDisplayName);
    printf("\n</div>");

    printf("<div class=\"DNSname invisible\" id=\"DNSselection\">");

    //check if local is selectedProvider
    if(compStr(selectedProvider, "local", sizearray(selectedProvider)))
    {
        selectedProviderText = "checked";
        selectedProviderID = "local";
    }
    else
    {
        selectedProviderText = "";
    }

    printf("\n<div id=\"local\"><input type=\"radio\" name=\"SmartDNS/selected\" value=\"local\" id=\"local-radio\" %s></input><label class=\"%s\" for=\"local-radio\">Local servers (DHCP)</label></div>", selectedProviderText, selectedProviderText);
    read_config_var("SmartDNS", "Providers", str);


    //check if other is selectedProvider
    if(compStr(selectedProvider, "other", sizearray(selectedProvider)))
    {
        selectedProviderText = "checked";
        selectedProviderID = "other";
    }
    else
    {
        selectedProviderText = "";
	selectedProviderID = "local";
    }
    printf("\n<div id=\"other\"><input type=\"radio\" name=\"SmartDNS/selected\" value=\"other\" id=\"other-radio\" %s></input><label class=\"%s\" for=\"other-radio\">Custom servers</label></div>", selectedProviderText, selectedProviderText);


    token = strtok (str,",");
    while (token != NULL)
    {
        if(compStr(selectedProvider, token, sizearray(selectedProvider)))
        {
            selectedProviderText = "checked";
            selectedProviderID = token;
        }
        else
        {
            selectedProviderText = "";
        }
        //buf = "";
        strcpy(buf, "SmartDns-");
        strcat(buf, token);
        //get DisplayName from config
        read_config_var(buf, "displayName", providerDisplayName);
        printf("\n<div id=\"%s\"><input type=\"radio\" name=\"SmartDNS/selected\" value=\"%s\" %s id=\"%s-radio\"></input><label class=\"%s\" for=\"%s-radio\">%s</label></div>", token, token, selectedProviderText, token, selectedProviderText, token, providerDisplayName);
        token = strtok (NULL, ",");
    }

printf("</div>");

    //scroll to selected DNS
    printf("\n<script type='text/javascript'>   $('#DNSselection').scrollTo($('#%s'));</script>\n", selectedProviderID);
//    printf("\n<script type='text/javascript'>   $(document).ready(function(){$(\".dnsinput}\").inputmask(\"ip\",{ \"placeholder\": \" \", showMaskOnFocus: false, showMaskOnHover: false });});</script>\n");


}


int card_dns_front(void)
{
    FILE *ptr_file;
    char buf[1000];
    char path[1035];
    char *nameservers;
    char *nameserver;
    char *dns1;
    char *dns2;

    printf("\n<div class=\"cbot\">");
       printDNSProviders();

// CURRENT ACTIVE DNS SERVERS

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
    printf("<div id=\"DNScustom\">");

    printf("\n<form id=\"customDNSform\">");
    printf("\n<input name=\"action\" type=\"hidden\" id=\"action\" value=\"update\">");
    printf("\n<input name=\"DNS/useDHCP\" type=\"hidden\" id=\"useDHCP\" value=\"0\">");
    printf("\n<input name=\"SmartDNS/selected\" type=\"hidden\" id=\"useDHCP\" value=\"other\">");

    printf("\n<div class=\"table\">");

    printf("\n<div class=\"row\">");
    printf("\n<div>Primary</div>");
    printf("\n<div><input value=\"%s\" type=\"text\" class=\"dnsinput\" name=\"DNS/Primary\" id=\"dns1field\" autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>", dns1);
    printf("\n</div>");

    printf("\n<div class=\"row\">");
    printf("\n<div>Secondary</div>");
    printf("\n<div><input value=\"%s\" type=\"text\" class=\"dnsinput\" name=\"DNS/Secondary\"  id=\"dns2field\"  autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>", dns2);
    printf("\n</div>");

    printf("\n</div>");

	printf("\n<div class=\"buttons\">");

	printf("\n<div id=\"CANCELcustomDNS\">Cancel</div><div id=\"SENDcustomDNS\">OK</div>");

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

}
