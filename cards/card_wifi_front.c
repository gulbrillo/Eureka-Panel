/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_wifi_front(void)
{
    FILE *ptr_file;
    char buf[1000];
    int snr;

    const char *a[6];
    a[5] = "Excellent";
    a[4] = "Very good";
    a[3] = "Good";
    a[2] = "Low";
    a[1] = "Very low";
    a[0] = "No signal";
    
    int link = 5;

    printf("\n<div class=\"topright\">");
    printf("\n<i onclick=\"document.querySelector('#wifi').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">WiFi</div>");

//NOISE LEVEL
 ptr_file=popen("cat /data/wifi/wpa_supplicant.conf | grep ssid | busybox awk -F \"\\\"\" '{print $2}' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
    snr =  snr - (int) strtol(buf, (char **)NULL, 10);
    printf( "\n<div class=\"description\">%s</div>", buf );
    }
    pclose(ptr_file);


    printf("\n</div>");
    printf("\n<div class=\"cbot\">");

    printf("\n<div class=\"table\">");

    printf("\n<div class=\"rowsmall\">");
    printf("\n<div>Signal</div>");

//SIGNAL LEVEL

 ptr_file=popen("cat /proc/net/wireless | grep mlan0 | busybox awk -F \".\" '{print $2}' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
    snr = (int) strtol(buf, (char **)NULL, 10);
    printf( "<div>%s dBm</div>", buf );
    }

    pclose(ptr_file);

    printf("\n</div>");


    printf("\n<div class=\"rowsmall\">");
    printf("\n<div>Noise</div>");

//NOISE LEVEL
 ptr_file=popen("cat /proc/net/wireless | grep mlan0 | busybox awk -F \".\" '{print $3}' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
    snr =  snr - (int) strtol(buf, (char **)NULL, 10);
    printf( "<div>%s dBm</div>", buf );
    }
    pclose(ptr_file);

    printf("\n</div>");


    printf("\n<div class=\"rowsmall\">");
    printf("\n<div>SNR</div>");

//SNR

    printf( "<div>%d dB</div>", snr );


    printf("\n</div>");

    printf("\n</div>");

    printf("\n</div>");


    printf("\n<div class=\"botright\">");

//BARS
//NOISE LEVEL
 ptr_file=popen("cat /proc/net/wireless | grep mlan0 | busybox awk -F \"02\" '{print $2}' | busybox awk -F \".\" '{print $1}' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
    link  =  (int) strtol(buf, (char **)NULL, 10);
    }

    pclose(ptr_file);

    if(link > 5 || link < 1) {link = 0;}

printf("\n  <div class=\"wifis r5 wlight\"></div>");
printf("\n  <div class=\"wifis r%d wdark\"></div>", link);
printf("\n  <div class=\"wifir r0\"></div>");
printf("\n  <div class=\"wifir r1\"></div>");
printf("\n  <div class=\"wifir r2\"></div>");
printf("\n  <div class=\"wifir r3\"></div>");
printf("\n  <div class=\"wifir r4\"></div>");
printf("\n  <div class=\"wifir r5\"></div>");

    printf("\n<div class=\"cenlarge\">%s</div>", a[link]);
    printf("\n<div class=\"censmall\">Connectivity</div>");

    printf("\n</div>");


}
