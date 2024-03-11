#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int i,a;
	a=fork();
	if(a<0)
	{
		printf("error");
	}
	else if(a==0)
	{
		printf("\nchild process\n");
		for(i=1;i<=10;i+=2)
		{
			printf("%d ",i);
		}
	}
	else//parent process
	{
		wait(NULL);
		printf("\nparent process\n");
		for(i=2;i<=10;i+=2)
		{
			printf("%d ",i);
		}
		
	}
	
	
}
