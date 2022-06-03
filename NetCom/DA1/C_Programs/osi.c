// Simple OSI model
// Name: Malhar Dharmadhikari
// Regno: 20BCE2110

#include<stdio.h>
#include <stdlib.h>
#include<string.h>


// string to binary
char* StoB(char* data) {
    if(data == NULL)
        return 0;
    size_t l = strlen(data);
    char *bi = malloc(l * 8 + 1);
    bi[0] = '\0';

    for(size_t i = 0; i<l; ++i)
    {
        char c = data[i];
        for(int j = 7; j >= 0; --j)
        {
            if(c & (1 << j))
                strcat(bi, "1");
            else
                strcat(bi, "0");
        }
    }
    return bi;
}


//
int main(void)
{
    char* data = (char*)malloc(20*sizeof(char));
    printf("Data: ");
    scanf("%s", data);


    printf("Sender Side: \n\n");
    printf("AH!!%s\n", data);
    sleep(1);
    printf("PHAH!!%s\n", data);
    sleep(1);
    printf("SHPHAH!!%s\n", data);
    sleep(1);
    printf("THSHPHAH!!%s\n", data);
    sleep(1);
    printf("NHTHSHPHAH!!%s\n", data);
    sleep(1);
    printf("DHTHSHPHAH!!%sCRC\n", data);
    sleep(1);
    printf("Physical Layer: %s\n\n", StoB(data));
    sleep(1);


    printf("Reciever Side: \n\n");
    printf("Physical Layer: %s\n", StoB(data));
    sleep(1);
    printf("DHTHSHPHAH!!%sCRC\n", data);
    sleep(1);
    printf("NHTHSHPHAH!!%s\n", data);
    sleep(1);
    printf("THSHPHAH!!%s\n", data);
    sleep(1);
    printf("SHPHAH!!%s\n", data);
    sleep(1);
    printf("PHAH!!%s\n", data);
    sleep(1);
    printf("AH!!%s\n", data);
    sleep(1);

    return 0;
}
