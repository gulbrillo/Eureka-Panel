#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "assert.h"
#include "string.h"
#include "minIni.h"
#include "malloc.h"
#include "modules/common_func.c"
#include "modules/web_module_home.c"
#include "modules/web_module_logcat.c"
// #include "modules/web_module_settings.c"
#include "modules/web_module_headers.c"
#include "modules/web_module_footer.c"
#include "modules/web_module_status.c"
#include "modules/web_module_debug.c"
#include "modules/web_module_aboutus.c"
#include "modules/web_module_companion.c"
#include "modules/web_module_popup_headers.c"

#include "cards/card_layout_header.c"
#include "cards/card_layout_footer.c"
#include "cards/card_network.c"
#include "cards/card_wifi.c"
#include "cards/card_wifi_front.c"
#include "cards/card_wifi_back.c"
#include "cards/card_twitter.c"
#include "cards/card_status.c"
#include "cards/card_status_front.c"
#include "cards/card_status_back.c"
#include "cards/card_dns.c"
#include "cards/card_dns_front.c"
#include "cards/card_dns_back.c"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
#define QS_LEN 65536
#define BLOCK_SIZE 512

//This is the main web panel application that includes all portal modules
//Please make modules where possible, and include them. Only modify this if necessary

int processPostData(char *postData)
{

    char *token;
    char buf[1024];
    char decodedToken[100];
    char action[80];
    char section[80];
    char field[80];
    char value[80];
    int smartDnsUpdatePerformed;
    char smartDnsProviderPrimary[1024];
    char smartDnsProviderSecondary[1024];
    int n;

    sscanf(postData, "action=%[0-9a-zA-Z]", &action);
    if(compStr(action, "update", sizearray(action)))
    {
        token = strtok (postData,"&");
        while (token != NULL)
        {
            //check if contains "/" so we know it's a var to update
            urldecode2(decodedToken, token);
            if(strstr(decodedToken, "/") != NULL)
            {
                sscanf(decodedToken, "%[0-9a-zA-Z]/%[0-9a-zA-Z]=%[0-9a-zA-Z.:/_%-]", section, field, value);
                //check if DNS update and allowed to perform
                if(compStr(section, "DNS", sizearray(section)) && !compStr(field, "useDHCP", sizearray(field)) && (smartDnsUpdatePerformed == 1))
                {
                    //do nothing
                }
                else
                {
                    n = write_config_var(section, field, value);
                }
                //Check if an update for smartDNS selected which is not set to other
                if(compStr(section, "SmartDNS", sizearray(section)) && compStr(field, "selected", sizearray(section)) && !compStr(value, "other", sizearray(section)))
                {
                    strcpy(buf, "SmartDNS-");
                    strcat(buf, value);
                    //get DNS details for SmartDNS provider
                    read_config_var(buf, "primary", smartDnsProviderPrimary);
                    read_config_var(buf, "secondary", smartDnsProviderSecondary);
                    //set DNS details to selected SmartDNS Provider
                    n = write_config_var("DNS", "primary", smartDnsProviderPrimary);
                    n = write_config_var("DNS", "secondary", smartDnsProviderSecondary);
                    //set that DNS update has been performed so any unwanted commits don't occur after
                    smartDnsUpdatePerformed=1;
                }
            }
            token = strtok (NULL, "&");
        }

    }
}

//main function for web services
int main(void)
{

    long n;
    char strPage[1023];
    char strFooters[1023];
    char strHeaders[1023];
    char strPopup[1023];
    char str[1024];
    char command[1024] = "echo Welcome to EurekaRom";
    char decodedCommand[1024];
    char *data;
    char *token;
    char *headers;
    char *page = NULL;
    const char *key, *value;
    char *postBuffer = NULL;
    int postRead;
    unsigned int postLen;
    char postData[4096];
    char * queryString;
    char query_action[1024];
    char query_section[1024];
    char query_field[1024];
    char query_value[1024];

    data = malloc(QS_LEN);
    token = malloc(QS_LEN);
    key = malloc(QS_LEN);
    value = malloc(QS_LEN);

    FILE *ptr_file;

    //Operations if POST detected
    if(compStr(getenv("REQUEST_METHOD"), "POST", sizearray(getenv("REQUEST_METHOD"))))
    {
        if (getenv("QUERY_STRING"))
        {
            token = strtok (getenv("QUERY_STRING"),"&");
            while (token != NULL)
            {
                sscanf(token, "%[^=]=%65536s", key, value);
                if ( compStr(key, "page", sizearray(key) ))
                {
                    strcpy(strPage, value);
                }
                token = strtok (NULL, "&");
            }
        }
        postRead = getline(&postBuffer, &postLen, stdin);
        if (-1 != postRead)
        {
            strcpy(postData, postBuffer);
        }
        if (compStr(strPage, "debug", sizearray(strPage) ))
        {
            sscanf(postData, "page=debug&command=%[^,]", command);
            urldecode2(decodedCommand, command);
//            web_module_headers(strPage);
	    card_layout_header();
            web_module_debug(decodedCommand);
//            web_module_footer();
	    card_layout_footer();
        }
        if (compStr(strPage, "dns", sizearray(strPage) ))
        {
		processPostData(postData);
		//reload dhcp for DNS change to take effect
			ptr_file=popen("dhcpcd  -n mlan0","r");
			sleep(1);
			pclose(ptr_file);
		card_dns_front();
        }
        free(postBuffer);
    }
    else
    {
        if (!getenv("QUERY_STRING"))
        {
            //no query string
	    card_layout_header();
	    card_twitter();
	    card_network();
	    card_status();
	    card_dns();
	    card_wifi();
            card_layout_footer();
        }
        if (getenv("QUERY_STRING"))
        {
            //parse Query_STRING for page
            //query string present
            token = strtok (getenv("QUERY_STRING"),"&");
            while (token != NULL)
            {
                sscanf(token, "%[^=]=%65536s", key, value);
                if ( compStr(key, "page", sizearray(key) ))
                {
                    strcpy(strPage, value);
                }
                if ( compStr(key, "headers", sizearray(key) ))
                {
                    strcpy(strHeaders, value);
                }
                if ( compStr(key, "footers", sizearray(key) ))
                {
                    strcpy(strFooters, value);
                }
                if ( compStr(key, "popup", sizearray(key) ))
                {
                    strcpy(strPopup, value);
                }
                token = strtok (NULL, "&");
            }
            // Call this before headers
            if ( compStr(strPage, "dumpstate", sizearray(strPage) ))
            {
                dumpstate();
                exit(0);
            }
            //check for which page to load
            if ( compStr(strHeaders, "0", sizearray(strHeaders) ))
            {
            }
            else
            {
//                web_module_headers(strPage);
	       card_layout_header();

            }
            if ( compStr(strPopup, "1", sizearray(strHeaders) ))
            {
                web_module_popup_headers(strPage);
            }


// for auto update
            if ( compStr(strPage, "wifi_front", sizearray(strPage) ))
            {
                card_wifi_front();
            }
            if ( compStr(strPage, "status_front", sizearray(strPage) ))
            {
                card_status_front();
            }
	    if ( compStr(strPage, "dns_front", sizearray(strPage) ))
            {
                card_dns_front();
            }



            if ( compStr(strPage, "welcome", sizearray(strPage) ))
            {
            card_twitter();
            card_status();
            card_wifi();
            }
            if ( compStr(strPage, "logcat", sizearray(strPage) ))
            {
                web_module_logcat();
            }
            if ( compStr(strPage, "forceupdatecheck", sizearray(strPage) ))
            {
                forceupdatecheck();
            }
            if ( compStr(strPage, "debug", sizearray(strPage) ))
            {
                web_module_debug(command);
            }
            if ( compStr(strPage, "settings", sizearray(strPage) ))
            {
//                web_module_settings();
            }
            if ( compStr(strPage, "status", sizearray(strPage) ))
            {
                web_module_status();
            }
            if ( compStr(strPage, "companion", sizearray(strPage) ))
            {
                web_module_companion();
            }
            if ( compStr(strPage, "aboutus", sizearray(strPage) ))
            {
                web_module_aboutus();
            }
            if ( compStr(strPage, "Reboot", sizearray(strPage) ))
            {
                reboot();
            }
            if ( compStr(strPage, "factorydatareset", sizearray(strPage) ))
            {
                factorydatareset();
            }
            if ( compStr(strFooters, "0", sizearray(strFooters) ))
            {
            }
            else
            {
//                web_module_footer();
		card_layout_footer();
            }
        }
    }
}
