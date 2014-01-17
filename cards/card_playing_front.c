/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_playing_front(void)
{

    char buf[1000];
    char servicename[1000];
    char titlename[1000];
    char imagename[1000];
    FILE *ptr_file;

    printf("\n<div class=\"topright\">");
    printf("\n<i  onclick=\"document.querySelector('#playing').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    

// SERVICE NAME

    ptr_file=popen("curl -L -H 'Content-Type: application/json' http://localhost:8008/apps/ -X GET -s | grep 'name' | busybox sed s/\\<name\\>//g | busybox sed s/\\<\\\\/name\\>//g | busybox tr '\r\n' ' ' | busybox sed s/^\\\\s\\\\\\{0,\\\\\\}//g | busybox sed s/\\\\s\\\\\\{0,\\\\\\}$//g","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {strcpy(servicename ,buf);}
    pclose(ptr_file); 

if (compStr(servicename, "00000000-0000-0000-0000-000000000000", 1000))
{
printf("\n<div class=\"title\">Cast</div>");
printf("\n<div class=\"description\">Display website or run video</div>");
} else 
{

    printf("\n<div class=\"title\">Now casting</div>");

    ptr_file=popen("curl -L -H 'Content-Type: application/json' http://localhost:8008/apps/ -X GET -s | grep 'description' | busybox sed s/\\<description\\>//g | busybox sed s/\\<\\\\/description\\>//g | busybox tr '\r\n' ' ' | busybox sed s/^\\\\s\\\\\\{0,\\\\\\}//g | busybox sed s/\\\\s\\\\\\{0,\\\\\\}$//g","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {strcpy(titlename,buf);}
    pclose(ptr_file);

    ptr_file=popen("curl -L -H 'Content-Type: application/json' http://localhost:8008/apps/ -X GET -s | grep 'image' | busybox tr '\r\n' ' ' | busybox sed s/^\\\\s\\\\\\{0,\\\\\\}//g | busybox sed s/\\\\s\\\\\\{0,\\\\\\}$//g","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {strcpy(imagename,buf);}
    pclose(ptr_file);


printf("\n<div class=\"description\"><div class=\"icon\">%s</div><div class=\"name\">%s</div></div>", imagename, titlename);

}

printf("\n</div>");

printf("\n<div class=\"cbot\">I could make the service stop (kill it and go back to idle screen). Also the user should be able to fling any website to the CC from here. What about videos? Is it possible to play videos without this ramp stuff?</div>");

 
}
