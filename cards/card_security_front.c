/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))


int card_security_front(void)
{
    FILE *ptr_file;
    char buf[1000];
    char path[1035];
    char securewebpanel[1024];
    char securessh[1024];
    char *webpaneltick;
    char *sshtick;
    char passhash[1024];
    char *sshtickid;
    char *webpaneltickid;

    printf("\n<div class=\"cbot\">");

    printf("\n<form id=\"customPassform\">");
    printf("\n<input type=\"hidden\" name=\"action\" value=\"update\">");

    printf("\n<div class=\"changePass\" id=\"changePass\">");
    printf("\n<div><label>Change password</label></div>");
    printf("\n</div>");

// CUSTOM PASSWORD FORM
    printf("<div id=\"Passcustom\">");

    printf("\n<div class=\"table inputtable\">");

    printf("\n<div class=\"row\">");
    printf("\n<div>Password</div>");

    printf("\n<div><input value=\"\" type=\"password\" class=\"passinput\" name=\"newpass1\" id=\"pass1field\" autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>");

    printf("\n</div>");

    printf("\n<div class=\"row\">");
    printf("\n<div>Repeat</div>");
    printf("\n<div><input value=\"\" type=\"password\" class=\"passinput\" name=\"newpass2\"  id=\"pass2field\"  autocorrect=\"off\" autocomplete=\"off\" autocapitalize=\"off\" spellcheck=\"false\"/></div>");
    printf("\n</div>");

    printf("\n</div>");

	printf("\n<div class=\"buttons\">");

	printf("\n<div id=\"CANCELpass\">Cancel</div><div id=\"SENDpass\">OK</div>");

	printf("\n</div>");


    printf("\n</div>");

webpaneltick = " ";
sshtick = " ";

read_config_var("Security", "webprotected", securewebpanel);
	if (compStr(securewebpanel, "true", 1024)) {webpaneltick = "checked";} else {webpaneltick = " ";}
read_config_var("Security", "sshprotected", securessh);
	if (compStr(securessh, "true", 1024)) {sshtick = "checked";} else {sshtick = " ";}
read_config_var("Security", "pass", passhash);
	if (compStr(passhash, "undefined", 1024)) {sshtickid = "makepassfirst"; webpaneltickid = "makepassfirst";} else {sshtickid = "tickssh"; webpaneltickid = "tickwebpanel";}

printf("\n<div id=\"secureOptionsform\"><div class=\"ticks\" id=\"secureOptions\">");
    printf("\n<div><label id=\"labeltickwebpanel\" class=\"%s\"><input %s value=\"true\" type=\"checkbox\" name=\"Security/webprotected\" value=\"true\" id=\"%s\">Secure web panel</label></div>", webpaneltick, webpaneltick, webpaneltickid);

    printf("\n<div><label id=\"labeltickssh\" class=\"%s\"><input %s value=\"true\" type=\"checkbox\" name=\"Security/sshprotected\" value=\"true\" id=\"%s\">Secure SSH/Telnet</label></div>", sshtick, sshtick, sshtickid);

printf("\n</div></div>");

printf("\n</form>");

printf("\n</div>");

}
