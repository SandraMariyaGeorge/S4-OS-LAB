#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int a,b;
	a=fork();
	if(a==0)
	{	
		b=getppid();
		printf("parent process id is %d\n",b);
		b=getpid();
		printf("child process id is %d\n",b);
		
	}
	else if(a>0)
	{
		b=getpid();
		printf("parent process id is %d\n",b);
	}
	else
	{
		printf("Error");
	}
}
