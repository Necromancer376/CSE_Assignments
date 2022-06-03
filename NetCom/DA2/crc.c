#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CRC(char *data, char* div, int dataSize, int divSize)
{
    // char *final = (char*)malloc(64*sizeof(char));
    char *temp = (char*)malloc(64*sizeof(char));
    char* key = (char*)malloc(32*sizeof(char));
    char* quot = (char*)malloc(32*sizeof(char));
    char* rem = (char*)malloc(32*sizeof(char));
    strcpy(key, div);

    for(int i=0; i<divSize; i++)
        temp[i] = data[i];

    for(int i=0; i<dataSize; i++)
    {
        quot[i] = temp[0];
        if(quot[i] == '0')
        {
            for(int j=0; j<divSize; j++)
                key[j] = '0';
        }
        else
        {
            for(int j=0; j<divSize; j++)
                key[j] = div[j];
        }
        for(int j=divSize-1; j>0; j--)
        {
            if(temp[j] == key[j])
                rem[j-1] = '0';
            else
                rem[j-1] = '1';
        }
        rem[divSize-1] = data[i+divSize];
        strcpy(temp, rem);
    }

    strcpy(rem, temp);
    printf("\nQuotient:  %s\n", quot);
    printf("Remainder:  %s\n", rem);
    printf("Final Data:  ");
    for(int i=0; i<dataSize; i++)
        printf("%c", data[i]);
    printf("%s\n", rem);
}



int main(void)
{
    char *div = (char*)malloc(32*sizeof(char));
    char *data = (char*)malloc(32*sizeof(char));
    char *final = (char*)malloc(64*sizeof(char));
    int divSize, dataSize;
    printf("Divisor size: \n");
    scanf("%d", &divSize);
    printf("Divisor: \n");
    // for(int i=0; i<divSize; i++)
    //  scanf("%c", &div[i]);
    scanf("%s", div);

    printf("Data size: \n");
    scanf("%d", &dataSize);
    printf("Data: \n");
    // for(int i=0; i<dataSize; i++)
    //  scanf("%c", &data[i]);
    scanf("%s", data);

    for(int i=0; i<divSize; i++)
        data[i+dataSize] = '0';

    CRC(data, div, dataSize, divSize);
    printf("%s\n", final);

    return 0;
}