#include<stdio.h>
#include<string.h>
#define MAX 10
struct process
{
	int at,bt,ct,no,tt,wt,pr;
    char prname[10];
}p[MAX],temp,gant[MAX],idle,min;
void main()
{
	int loc,time,i,n,j,g;
	float tat=0,twt=0;
	printf("Enter the number of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Process name Arrival time, Burst Time and Priority of process %d : \n",i+1);
		scanf("%s%d%d%d",p[i].prname,&p[i].at,&p[i].bt,&p[i].pr);
		p[i].no=i+1;
	}
	
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

	idle.bt=0;
	for(i=0,g=0,time=0;i<n;i++)
	{
		if(time<p[i].at)
		{
			gant[g]=idle;
    		gant[g++].ct=time=p[i--].at;
		}
		else
		{	
			loc=i;
    		for(j=i,min.pr=p[j].pr;j<n&&p[j].at<=time;j++)
    		{
    			if(p[j].pr<min.pr)
    			{
    				min=p[j];
    				loc=j;
    			}
    		}
    		if(i!=loc)
    		{
    			p[loc]=p[i];
    			p[i]=min;
    		}
    		time+=p[i].bt;
    		p[i].ct=time;
	    	gant[g++]=p[i];
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		twt=twt+p[i].wt;
		tat=tat+p[i].tt;
	}
	printf("Gantt chart:\n");
	for(i=0;i<g;i++)
	{
		if(gant[i].bt==0)
			printf("| Idle   ");
		else
			printf("| %s   ",gant[i].prname);
	}
	printf("|\n");
	printf("0\t");  
	for(i=0;i<g;i++)
		printf("%2d\t",gant[i].ct);
	printf("\nTable :\n");
	printf(" _____________________________________\n");
	printf("|Process| AT | BT | P  | CT | TT | WT |\n");
	printf("|-------------------------------------|\n");
	for(i=0;i<n;i++)
	{
		printf("|p%d \t| %2d | %2d | %2d | %2d | %2d | %2d |\n",p[i].no,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tt,p[i].wt);
	}
	printf(" _____________________________________\n");
	twt=twt/n;
	tat=tat/n;
	printf("\nAverage WT:%f\n",twt);	
	printf("Average TT:%f\n",tat);		
}