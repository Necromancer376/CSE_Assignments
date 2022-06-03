#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char *data = (char*)malloc(20*sizeof(char));
    printf("data: ");
    scanf("%s", data);
    int parity;

    int c = 0;
    for(int i=0; i<strlen(data); i++)
    {
        if(*(data + i) == '1')
            c++;
    }

    if(c % 2 == 0)
        parity = 0;
    else
        parity = 1;

    printf("\ndata: %d%s\n", parity, data);
    printf("parity bit: %d\n", parity);
}