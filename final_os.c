#include<stdio.h>
#include<stdlib.h>
int main()// main start

{

int counting,n,a,timing,remain,flagvalue=0,time_quantume;// variable define

int wait_timing=0,turnaround_timing=0,array1[10],array2[10],array3[10];
printf("\n   = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");
printf("\n \n\n  \t\t\t Enter number of total Process:\t ");
scanf("%d",&a);
if(a==0){/////                             wrong enrty
printf("\n   sorry  !!!!   wrong entry");
   exit(1);
}
printf("\n \n  = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");



remain=a;

for(counting=0;counting<a;counting++)   // inputs from user

{

printf("\n\n \t\t\tEnter arrival time for process , Process Number %d :",counting+1);
scanf("%d",&array1[counting]);
if(array1[counting]==0){
printf("\n   sorry  !!!!   wrong entry");
   exit(1);
}
printf("\n \t\t\tEnter  Burst Time for Process , Process Number %d :",counting+1);
scanf("%d",&array2[counting]);
if(array2[counting]==0){
printf("\n   sorry  !!!!   wrong entry");
   exit(1);
}
array3[counting]=array2[counting];

}

printf("	\n\t\t\t enter time quantum:\t");

scanf("%d",&time_quantume);

printf("\n\t\t\t process\t|turnaround time|waiting time\n\n");

for(timing=0,counting=0;remain!=0;)

{

if(array3[counting]<=time_quantume&& array3[counting]>0)

{

timing+=array3[counting];

array3[counting]=0;

flagvalue=1;

}

else if(array3[counting]>0)

{

array3[counting]-=time_quantume;

timing+=time_quantume;

}

if(array3[counting]==0 && flagvalue==1)

{

remain--;

printf("\t\t\t\tP[%d]\t|\t%d\t|\t%d\n",counting+1,timing-array1[counting],timing-array1[counting]-array2[counting]);

wait_timing+=timing-array1[counting]-array2[counting];

turnaround_timing+=timing-array1[counting];

flagvalue=0;

}

if(counting==a-1)

counting=0;

else if(array1[counting+1]<=timing)

counting++;

else

counting=0;

}
printf(" \n\n \t\t= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");

printf("\n\n \t\t\t average waitting timee= %f\n",wait_timing*1.0/a);
printf("\t\t\t avarage turnarrounde timee = %f",turnaround_timing*1.0/a);

printf(" \n \t\t= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");

printf("\n \n = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");
printf(" \n = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  ");

return 0;

}
