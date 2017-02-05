#include<stdio.h>
#include<stdlib.h>
int main()
{
int number=0,j=0,n=0,temp=0,tim[100],priority[100],abovetime=0,quantumtim,i,rotations=0,total_bursttime=0,priority_ratio[100],burst_ratio[100],priorityfactor[100];
printf("enter the number of junctions and traffic density\n");
scanf("%d \n",&number);
printf("\n Density \n");
for(i=0;i<number;i++)
{
	printf("enter the density of %d junction\n",i);
	scanf("%d",&priority[i]);
}
printf("FLOW TIME\n");
for(i=0;i<number;i++)
{
	printf("enter the flow time of %d process\n",i);
	scanf("%d",&tim[i]);
	printf("\njunction[%d] has a flow time of %d\n",i,tim[i]);
	total_bursttime=total_bursttime+tim[i];
}
printf("\n total flow time is %d \n",total_bursttime);
for(i=0;i<number;i++)
{
	priority_ratio[i]=priority[i]/number;
	burst_ratio[i]=tim[i]/total_bursttime;
	priorityfactor[i]=(priority[i]*priority_ratio[i])+(tim[i]*burst_ratio[i]);
}
for(i=0;i<number;i++)
{
	printf("priority factor of %d is %d \n",i,priorityfactor[i]);
}
for(i=0;i<number;i++)
{
	for(j=i+1;j<number;j++)
	{
		if(priorityfactor[i]>priorityfactor[j])
		{
			temp=tim[i];
			tim[i]=tim[j];
			tim[j]=temp;
		}
	}
}
for(i=0;i<number;i++)
{
	printf("\n %d ",tim[i]);
}
n=number;
do
{
quantumtim=total_bursttime/n;
n=number;
printf("signal time is  %d \n",quantumtim);
abovetime=0;
rotations++;
printf("\nrotation %d \n",rotations);
for(i=0;i<number;i++)
{
	tim[i]=tim[i]-quantumtim;
	if(tim[i]<=0)
	{
		tim[i]=0;
		n--;
	
	}
	printf("\n junction %d remaining flow time %d",i,tim[i]);
}
total_bursttime=0;
for(i=0;i<number;i++)
{
	total_bursttime=total_bursttime+tim[i];
	if(tim[i]>0)
		abovetime++;
}
printf("total flow time is %d",total_bursttime);
}while(abovetime!=0);
}
