#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a = fork();

	if(a == 0)
	{
		printf("in child procces id = %d\n", getpid());
		printf("parent id = %d\n", getppid());
	}
	else
	{
		sleep(5);
		printf("in parent process id = %d\n", getpid());
	}

	return 0;
}
