/*
This module presents basic network information to the user
*/

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

int card_status_front(void)
{

    char buf[1000];
    char command[200];    
    FILE *ptr_file;
    FILE *oldcpu;

    int i = 2;

    int cputemp = 0;
    int cputemp2 = 0;
    int memory = 0;
    char * load;
    int memory2 = 0;
    char * cpus;
    char * oldcpus;
    char * cput;
    char * oldcput;
    long cpu = 0;
    long cpuidle = 0;
    long cpuusage = 0;
    int cpuusage2 = 0;

    printf("\n<div class=\"topright\">");
    printf("\n<i  onclick=\"document.querySelector('#status').classList.toggle('flip');\" class=\"corner icon-info\"></i>");
    printf("\n</div>");

    printf("\n<div class=\"ctop\">");
    
    printf("\n<div class=\"title\">Status</div>");


//CPU
//total


//  while (i < 11)
//    snprintf(command, sizeof command, "cat /proc/stat | grep 'cpu ' | busybox tr '\n' ' '", i);

    ptr_file=popen("cat /proc/stat | grep 'cpu ' | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {cpus = buf;}
    pclose(ptr_file); 

  cput = strtok (cpus," ");

  while (cput != NULL)
  {
    cpu =  cpu + (long) strtol(cput, (char **)NULL, 10);
    cput = strtok (NULL, " ");
  }


//idle (percentage used)


    ptr_file=popen("cat /proc/stat | grep 'cpu ' | busybox awk -F \" \" '{print $5}' | busybox tr '\n' ' '","r");

    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        cpuidle  =  cpuidle + (long) strtol(buf, (char **)NULL, 10);
    }
    pclose(ptr_file);

//get old reference value
oldcpu = popen("cat /tmp/cpu.stat | busybox tr '\n' ' '","r");
    while (fgets(buf,1000, oldcpu)!=NULL)
    {        oldcpus = buf;    }
fclose(oldcpu); 

//write stats for old reference value
oldcpu = fopen("/tmp/cpu.stat", "w");
fprintf(oldcpu, "%d %d\n", cpu, cpuidle);
fclose(oldcpu);

//calcualte differential times for CPU usage calculation

	oldcput = strtok(oldcpus, " ");
if (oldcput != NULL) {
	cpu =  cpu - (long) strtol(oldcput, (char **)NULL, 10);}
	oldcput = strtok(NULL, " ");
if (oldcput != NULL) {
	cpuidle  =  cpuidle - (long) strtol(oldcput, (char **)NULL, 10);}

//cpu usage
    cpuusage  =  (1000*(cpu - cpuidle)/cpu + 5)/10;



//MEMORY

//total
    ptr_file=popen("busybox free | grep Mem | busybox awk -F \" \" '{print $2}' | busybox tr '\n' ' '","r");

    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        memory  =  (int) strtol(buf, (char **)NULL, 10);
    }
    pclose(ptr_file);


//used
    ptr_file=popen("busybox free | grep Mem | busybox awk -F \" \" '{print $3}' | busybox tr '\n' ' '","r");

    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        memory  =  (int) strtol(buf, (char **)NULL, 10)*100/memory;
    }
    pclose(ptr_file);


//LOAD
    ptr_file=popen("cat /proc/loadavg | busybox awk -F \" \" '{print $1\" \"$2\" \"$3}' | busybox tr '\n' ' '","r");

    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        load  =  buf;
    }
    pclose(ptr_file);


    printf("\n<div class=\"description\">Load: %s (%d\% RAM used)</div>", load, memory);

    printf("\n</div>");

    printf("\n<div class=\"botleft\">");


        cpuusage2 = (int) cpuusage;
        if (cpuusage < 1) {cpuusage2 = 0;}
        if (cpuusage > 99) {cpuusage2 = 100;}
        //make sure it's a multiple of 2
        cpuusage2 = cpuusage2/2*2;

    printf("\n<div class=\"progress-radial progress-%d\"><div class=\"overlay\">%d\%</div></div>", cpuusage2, cpuusage);

    printf("\n<div class=\"censmall\">CPU</div>");

    printf("\n</div>");



    printf("\n<div class=\"botright\">");

//TEMPERATURE

    ptr_file=popen("cat /sys/devices/platform/mv88de3100-hwmon.0/hwmon/hwmon0/tsen_temp","r");
    while (fgets(buf,1000, ptr_file)!=NULL)
    {
        cputemp  =  (int) strtol(buf, (char **)NULL, 10);
    }
    pclose(ptr_file);

	cputemp2 = cputemp;
	if (cputemp2 < 5) {cputemp2 = 5;}
	if (cputemp2 > 85) {cputemp2 = 85;}
	//scale it to a range of 80 (5-85) and make sure it's a multiple of 2
	cputemp2 = (cputemp2 - 5)/8*10;

    printf("\n<div class=\"progress-radial progress-%d\"><div class=\"overlay\">%d&deg;C</div></div>", cputemp2, cputemp);

     printf("\n<div class=\"censmall\">Temperature</div>");
 
    printf("\n</div>");



}
