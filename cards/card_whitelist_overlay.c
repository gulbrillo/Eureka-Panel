/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_whitelist_overlay(void)
{

    char buf[20000];
    char enabledappids[20000];
    char configuration[20000];
    FILE *ptr_file;


        printf("\n<div class=\"editbox\"><form id=\"editWHITEform\"><input name=\"action\" type=\"hidden\" id=\"action\" value=\"update\">");

                printf("\n\"applications\":[");
                printf("\n<br><textarea name=\"applications\">");

//    cat /data/eureka/apps.conf |  busybox tr '\n' 'X' | busybox sed s/^\)\\]}\'X{\"applications\":\\[//g | busybox sed s/\\],\"enabled_app_ids.*//g | busybox sed s/},{/},\\n{/g 
    ptr_file=popen("cat /data/eureka/apps.conf |  busybox tr '\n' 'X' | busybox sed s/^\\)\\\\]}\\'X{\\\"applications\\\":\\\\[//g | busybox sed s/\\\\],\\\"enabled_app_ids.*//g | busybox sed s/},{/},\\\\n{/g","r");    
    while (fgets(buf,20000, ptr_file)!=NULL)
    {printf("%s",buf);}
    pclose(ptr_file);

    ptr_file=popen("cat /data/eureka/apps.conf |  busybox tr '\n' 'X' | busybox sed s/.*\\\"enabled_app_ids\\\":\\\\[//g | busybox sed s/\\\\],\\\"configuration.*//g","r");
    while (fgets(buf,20000, ptr_file)!=NULL)
    {strcpy(enabledappids,buf);}
    pclose(ptr_file);

    ptr_file=popen("cat /data/eureka/apps.conf |  busybox tr '\n' 'X' | busybox sed s/.*\\\"configuration\\\":{//g | busybox sed s/}}$//g","r");
    while (fgets(buf,20000, ptr_file)!=NULL)
    {strcpy(configuration,buf);}
    pclose(ptr_file);


		printf("\n</textarea><br>");
		printf("\n],<br>\"enabled_app_ids\":[ <br><input type=\"text\" name=\"enabled_app_ids\" value='%s'><br> ],",enabledappids);
		printf("\n<br>\"configuration\":{ <br><input type=\"text\" name=\"configuration\" value='%s'><br> }<br>&nbsp;",configuration);

         printf("\n<div class=\"buttons\">");
	 printf("\n<div id=\"cancelWHITE\">Cancel</div><div id=\"saveWHITE\">Save</div>");
	 printf("\n</div>");

	printf("\n</form></div>");	

return 1;
}
