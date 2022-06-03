#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	if (fork() == 0)
        printf("In Child process\n");
  
    else
        printf("In Parent process\n");
}