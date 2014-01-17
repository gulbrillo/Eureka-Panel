/*
This module presents basic network information to the user
*/


int card_services_back(void)
{
    printf("\n<div id=\"services_back\" class=\"card back\">");

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#services').classList.toggle('flip');\" class=\"corner icon-close\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Services</div>");
    printf("\n<div class=\"description\">You can enable different services to communicate with your Chromecast. A root shell (root@");

FILE *ptr_file;
char buf[1000];

//IP ADDRESS
    ptr_file = popen("busybox ifconfig | busybox grep -e \"inet:\" -e \"addr:\" | busybox grep -v \"inet6\" | busybox grep -v \"127.0.0.1\" | busybox head -n 1 | busybox awk '{print $2}' | busybox cut -c6-","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        printf( "%s", buf );
    }
    pclose(ptr_file);

printf(") is provided by SSH (port 22) and Telnet (port 23). The Android Debug Bridge (ADB) is a command line tool that also lets you push data to the device. This webpanel runs on ports 80 (http) and 443 (https).</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");
    printf("\n</div>");


    printf("\n</div>");

}
