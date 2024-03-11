#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	int a;
	a=fork();
	if (a<0)
	{
		printf("Error\n");
	}
	else if(a==0)
	{
		printf("a child process\n");
	}
	else
	{
		printf("a parent process\n");
	}
}
