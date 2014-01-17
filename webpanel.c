#include "stdio.h"
#include "cgic.h"
#include "stdlib.h"
#include "time.h"
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

#include "cards/card_slides.c"
#include "cards/card_layout_header.c"
#include "cards/card_layout_footer.c"
#include "cards/card_layout_settings.c"
#include "cards/card_layout_httpkill.c"
#include "cards/card_links.c"
#include "cards/card_network.c"
#include "cards/card_wifi.c"
#include "cards/card_wifi_front.c"
#include "cards/card_wifi_back.c"
#include "cards/card_twitter.c"
#include "cards/card_status.c"
#include "cards/card_status_front.c"
#include "cards/card_status_back.c"
#include "cards/card_playing.c"
#include "cards/card_playing_front.c"
#include "cards/card_playing_back.c"
#include "cards/card_dns.c"
#include "cards/card_dns_front.c"
#include "cards/card_dns_back.c"
#include "cards/card_security.c"
#include "cards/card_security_front.c"
#include "cards/card_security_back.c"
#include "cards/card_services.c"
#include "cards/card_services_front.c"
#include "cards/card_services_back.c"
#include "cards/card_team_rom.c"
#include "cards/card_team_chris.c"
#include "cards/card_team_thomas.c"
#include "cards/card_team_trevor.c"
#include "cards/card_team_simon.c"


#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
#define QS_LEN 65536
#define BLOCK_SIZE 512

//This is the main web panel application that includes all portal modules
//Please make modules where possible, and include them. Only modify this if necessary

int CookieCheck()
{
char password[1024];
char protected[1024];
char session[1024];
char cookie[1024];

read_config_var("Security", "webprotected", protected);
read_config_var("Security", "pass", password);

if (compStr(protected, "undefined", 1024) || !compStr(protected, "true", 1024) || compStr(password, "undefined", 1024)) {
	return 1;	
	} else {
		read_config_var("Security", "session", session);


		if (cgiCookieString("session", cookie, sizeof(cookie)) == cgiFormSuccess) {
		if (compStr(session, cookie, 1024) && !compStr(session, "undefined", 1024) && !compStr(session, "", 1024))
			{return 1;}
		else
			{return 0;}
		} else {
			return 0;
		}
	}

}

void CookieSet()
{
  char *cname = "session";
  char *cvalue;

  int r;

    FILE *ptr_file;
    char command[300];
    char buf[1024];

  srand ( (unsigned)time ( NULL ) );
  r = rand();


    snprintf(command, sizeof command, "echo -n '%d' | busybox sha1sum | busybox awk -F \" \" '{print $1}' | busybox tr '\n' ' ' | busybox tr -d ' '", r);

    ptr_file=popen(command,"r");
       while (fgets(buf,1000, ptr_file)!=NULL)
       {
          cvalue = buf;
       }
    pclose(ptr_file);

          write_config_var("Security", "session", buf);

if (strlen(cname) && strlen(cvalue)) {
//    cgiHeaderCookieSetString(cname, cvalue, 1200, cgiScriptName, cgiServerName);
//      cgiHeaderCookieSetString(cname, cvalue, 1200, path, cgiServerName);
      printf("Content-type: text/html\n");
      printf("Set-Cookie: %s=%s; Path=/; Domain=%s; HttpOnly\n\n", cname, cvalue, cgiServerName);	

  }
}

int processLogin()
{

    char value[80];
    FILE *ptr_file;
    char command[200];
    char buf[1024];
    char *sha1pass;

    cgiFormStringNoNewlines("action", value, 80);
    if(compStr(value, "login", sizearray(value)))
    {
    cgiFormStringNoNewlines("welcome_password", value, 80);


    snprintf(command, sizeof command, "echo -n '%s' | busybox sha1sum | busybox awk -F \" \" '{print $1}' | busybox tr '\n' ' ' | busybox tr -d ' '", value);

    ptr_file=popen(command,"r");
       while (fgets(buf,1000, ptr_file)!=NULL)
       {
	 strcpy(sha1pass, buf);
       }
    pclose(ptr_file);

	read_config_var("Security", "pass", buf);
//	printf("%s = %s?", buf, sha1pass);


//	n = write_config_var("Security", "pass", sha1pass);

	if ( compStr(sha1pass, buf, 1024) )
		return 1;
	else
		return 0;

    }

}

void writenewPass()
{

    char value[80];
    int n;
    FILE *ptr_file;
    char command[200];
    char buf[1024];
//    char *sha1pass;

    cgiFormStringNoNewlines("newpass1", value, 80);

    snprintf(command, sizeof command, "echo -n '%s' | busybox sha1sum | busybox awk -F \" \" '{print $1}' | busybox tr '\n' ' ' | busybox tr -d ' '", value);

    ptr_file=popen(command,"r");
       while (fgets(buf,1000, ptr_file)!=NULL)
       {
//	printf("sha: %s, buf: %s<p>", sha1pass, buf);
	n = write_config_var("Security", "pass", buf);
//         strcpy(sha1pass, buf);
       }
    pclose(ptr_file);

//       read_config_var("Security", "pass", buf);
//      printf("%s = %s?", buf, sha1pass);


//      n = write_config_var("Security", "pass", sha1pass);

}



int processPostData()
{

    char buf[1024];
    char section[80];
    char field[80];
    char value[80];
    int smartDnsUpdatePerformed;
    char smartDnsProviderPrimary[1024];
    char smartDnsProviderSecondary[1024];
    int n;

    char **array, **arrayStep;

    cgiFormStringNoNewlines("action", value, 80);

//  sscanf(postData, "action=%[0-9a-zA-Z]", &action);
    if(compStr(value, "update", sizearray(value)))
    {
//        token = strtok (postData,"&");
//        while (token != NULL) {

//GO THROUGH ALL FORM KEY/VALUES
          if (cgiFormEntries(&array) == cgiFormSuccess) {

	  arrayStep = array;

	while (*arrayStep) {

            //check if contains "/" so we know it's a var to update
//            urldecode2(decodedToken, token);


	    if(strchr(*arrayStep, '/'))
            {

		cgiFormStringNoNewlines(*arrayStep, value, 80);
		sscanf(*arrayStep, "%[0-9a-zA-Z]/%[0-9a-zA-Z]", section, field);

//                sscanf(decodedToken, "%[0-9a-zA-Z]/%[0-9a-zA-Z]=%[0-9a-zA-Z.:/_%-]", section, field, value);
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
//            token = strtok (NULL, "&");
		arrayStep++;
        }

	cgiStringArrayFree(array);	

	}
    }
}


//main function for web services
int cgiMain()
{

    char strPage[1023];
    char strFooters[1023];
    char strHeaders[1023];
    char strPopup[1023];
    char command[1024] = "echo Welcome to EurekaRom";
    char decodedCommand[1024];
    char *data;
    char *token;
    const char *key, *value;

    data = malloc(QS_LEN);
    token = malloc(QS_LEN);
    key = malloc(QS_LEN);
    value = malloc(QS_LEN);

    FILE *ptr_file;


    //Operations if POST detected
    if(compStr(cgiRequestMethod, "POST", sizearray(cgiRequestMethod)))
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
        if (compStr(strPage, "debug", sizearray(strPage) ))
        {
		cgiHeaderContentType("text/html");
	if( CookieCheck() ) {
//            sscanf(postData, "page=debug&command=%[^,]", command);
//            urldecode2(decodedCommand, command);
	    card_layout_header();
            web_module_debug(decodedCommand);
	    card_layout_footer();
	}
        }
        else if ( compStr(strPage, "dns", sizearray(strPage)) )
        {
		cgiHeaderContentType("text/html");
	if( CookieCheck() ) {
		processPostData();
		//reload dhcp for DNS change to take effect
			ptr_file=popen("dhcpcd  -n mlan0","r");
			sleep(1);
			pclose(ptr_file);
		card_dns_front();
	}
        }
	else if ( compStr(strPage, "theme", sizearray(strPage)) )
        {
                cgiHeaderContentType("text/html");
        if( CookieCheck() ) {
                processPostData();
                settings_theme();
        }
        }
        else if ( compStr(strPage, "services", sizearray(strPage)) )
        {

	cgiHeaderContentType("text/html");

        if( CookieCheck() ) {
//                processPostData(); TOO DANGEROUS (you may switch everything off by accident)
//				     let's do it one by one and activate the service if there is no value given
//                                   also removed the action update input field

	char httpvalue[20];
	char sshvalue[20];
	char adbvalue[20];
	char telnetvalue[20];

        cgiFormStringNoNewlines("Services/telnet", telnetvalue, 20);
        if(compStr(telnetvalue, "disabled", 20)) {
                write_config_var("Services", "telnet", "0");
        } else {write_config_var("Services", "telnet", "1");}

        cgiFormStringNoNewlines("Services/adb", adbvalue, 20);
        if(compStr(adbvalue, "disabled", 20)) {
                write_config_var("Services", "adb", "0");
        } else {write_config_var("Services", "adb", "1");}

        cgiFormStringNoNewlines("Services/ssh", sshvalue, 20);
        if(compStr(sshvalue, "disabled", 20)) {
                write_config_var("Services", "ssh", "0");
        } else {write_config_var("Services", "ssh", "1");}


        cgiFormStringNoNewlines("Services/http", httpvalue, 20);
        if(compStr(httpvalue, "disabled", 20)) {
                write_config_var("Services", "http", "0");


		printf("ikilledhttp");
		exit(0);

        } else {write_config_var("Services", "http", "1");}

                card_services_front();

	}
        
        }
        else if ( compStr(strPage, "newpass", sizearray(strPage)) )
        {
        if( CookieCheck() ) {

    char newpass1[80];
    char newpass2[80];

    cgiFormStringNoNewlines("newpass1", newpass1, 80);
    cgiFormStringNoNewlines("newpass2", newpass2, 80);
	    if(compStr(newpass1, newpass2, 80) && newpass1[0] != '\0')
		{

	char protected[80];
	cgiFormStringNoNewlines("Security/webprotected", protected, 80);


	        if (compStr(protected, "true", 80)) 
		{
			CookieSet();

printf("\n<script>");
printf("\n(function($)");
printf("\n{");
printf("\n    $(document).ready(function()");
printf("\n    {");
printf("\n        $('#logout').removeClass(\"invisible\");$('#settings').addClass(\"logout\");");
printf("\n    });");
printf("\n})(jQuery);");
printf("\n</script>");

}

			printf("<div class=\"actiontaken\">Password updated</div>");
			
			writenewPass();

	                processPostData();
	//Todo: RELOAD SSH Server and maybe kill session?
	                card_security_front();
		} else {
			cgiHeaderContentType("text/html");
			printf("<div class=\"actiontaken\">No match, try again</div>");
			card_security_front();
		}
        }
        }
	else if ( compStr(strPage, "security", sizearray(strPage)) )
        {
		cgiHeaderContentType("text/html");
        if( CookieCheck() ) {
		processPostData();
		card_security_front();
	}
	}
        else if (compStr(strPage, "login", sizearray(strPage) ))
        {
		if( processLogin() ) {
			CookieSet();
//			cgiHeaderContentType("text/html");
			printf("Correct");
		} else {
			cgiHeaderContentType("text/html");
			printf("Wrong");
		}
	        	
        }
	else if (compStr(strPage, "killhttp", sizearray(strPage) ))
	{
    char value[80];

    if( CookieCheck() ) {
    cgiFormStringNoNewlines("action", value, 80);
    if(compStr(value, "killhttp", sizearray(value)))
    {
	cgiHeaderContentType("text/html");
	printf("I got killed");
	
                // restart with: lighttpd -f /system/etc/httpd.conf -m /system/usr/lib/
                FILE *ptr_file;
                ptr_file=popen("busybox killall lighttpd","r");
                pclose(ptr_file);


	exit(0);
    }
    }

	}
	else
	{
		cgiHeaderContentType("text/html");
		card_layout_header();
		printf("You should not be here. Like never. Do you have JavaScript and Cookies enabled?");
		card_layout_footer();
	}

    }
    else
    {

        if (!getenv("QUERY_STRING"))
        {
            //no query string
	    card_layout_header();
            card_layout_footer();
        }
        if (getenv("QUERY_STRING"))
        {

//LOGOUT and redirect back to start
	if ( compStr(getenv("QUERY_STRING"), "logout", 1024 ))
            {

		  char *cname = "session";
		  char *cvalue = "";


		//only log out (kill session) if you own the session
                if( CookieCheck() ){write_config_var("Security", "session", "undefined");}

//		cgiHeaderCookieSetString(cname, cvalue, 0, path, cgiServerName);

//      printf("Content-type: text/html\n");

	printf("Set-Cookie: %s=%s; Path=/; Domain=%s; HttpOnly\n", cname, cvalue, cgiServerName);
	printf("Location: /test/\n\n");


//		cgiHeaderLocation(location);
		exit(0);
            }

	else if ( compStr(getenv("QUERY_STRING"), "ikilledhttp", 1024 ))
            {
		if( CookieCheck() ){

		cgiHeaderContentType("text/html");
		card_httpkill();

//		need to do that with a java redirect, else it's killed before shoing the confirmation
//                ptr_file=popen("busybox killall lighttpd","r");
//                pclose(ptr_file);

		exit(0);
		}
	    }


//WITHOUT POST THERE IS NO LOGIN, SO PRINT HEADERS. But: this, if possible, should be all done with ajax and POST.
    cgiHeaderContentType("text/html");


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


        if ( compStr(strPage, "verify", sizearray(strPage) ))
        {
                if( CookieCheck() ) {
                        printf("Correct");
                        exit(0);
                } else {
                        printf("Wrong");
                        exit(0);
                }

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
	       card_layout_header();

            }
            if ( compStr(strPopup, "1", sizearray(strHeaders) ))
            {
                web_module_popup_headers(strPage);
            }



// for auto update (ajax)
if( CookieCheck() ) {
            if ( compStr(strPage, "wifi_front", sizearray(strPage) ))
            {
                card_wifi_front();
            }
            else if ( compStr(strPage, "status_front", sizearray(strPage) ))
            {
                card_status_front();
            }
            else if ( compStr(strPage, "playing_front", sizearray(strPage) ))
            {
                card_playing_front();
            }
            else if ( compStr(strPage, "cards", sizearray(strPage) ))
            {
	       card_slides();
            }
} else {

 printf("\n<script type=\"text/javascript\">");
 printf("\n$(function() {");
 printf("\nwindow.location.replace(\"/test/\");");
 printf("\n});");
 printf("\n</script>");

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
		card_layout_footer();
            }

        }
    }
return 0;
}
