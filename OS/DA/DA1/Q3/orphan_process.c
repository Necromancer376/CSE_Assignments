#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(void)
{
    int pid = fork();
  
    if (pid > 0)
        printf("In parent process\n");

    else if (pid == 0)
    {
        sleep(5);
        printf("In child process\n");
    }
  
    return 0;
}