/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_network(void)
{


    FILE *ptr_file;
    char buf[1000];
    char path[1035];

    printf("\n<div class=\"card\">");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Network</div>");
    printf("\n<div class=\"description\">Internet status: ");


//INTERNET STATUS
    ptr_file = popen("busybox ping -c 1 -w 2 google.com > /dev/null ; echo $?", "r");
    while (fgets(path, sizeof(path)-1, ptr_file) != NULL)
    {
        if (compStr(path, "0\n", sizearray(path) ))
        {
            printf("<span class=\"ok\">connected</span>");
        }
        else
        {
            printf("<span class=\"warning\">disconnected</span>");
        }
    }
    pclose(ptr_file);

    printf("</div>");

    printf("\n</div>");
    printf("\n<div class=\"cbot\">");

    printf("\n<div class=\"table\">");

    printf("\n<div class=\"row\">");
    printf("\n<div>IP</div>");

//IP ADDRESS
    ptr_file = popen("busybox ifconfig | busybox grep -e \"inet:\" -e \"addr:\" | busybox grep -v \"inet6\" | busybox grep -v \"127.0.0.1\" | busybox head -n 1 | busybox awk '{print $2}' | busybox cut -c6-","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        printf( "\n<div>%s</div>", buf );
    }
    pclose(ptr_file);
    printf("\n</div>");


    printf("\n<div class=\"row\">");
    printf("\n<div>Mask</div>");

//SUBNET
    ptr_file=popen("busybox ifconfig | busybox grep -e \"inet:\" -e \"addr:\" | busybox grep -v \"inet6\" | busybox grep -v \"127.0.0.1\" | busybox head -n 1 | busybox awk '{print $4}' | busybox cut -c6-","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        printf( "\n<div>%s</div>", buf );
    }
    pclose(ptr_file);
    printf("\n</div>");


    printf("\n<div class=\"row\">");
    printf("\n<div>Gateway</div>");

//GATEWAY
    ptr_file=popen("busybox route -n | busybox grep -e \"UG\" | busybox awk '{print $2}' ","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        printf( "\n<div>%s</div>", buf );    
    }
    pclose(ptr_file);
    printf("\n</div>");

    printf("\n</div>");

    printf("\n</div>");

    printf("\n</div>");

}
