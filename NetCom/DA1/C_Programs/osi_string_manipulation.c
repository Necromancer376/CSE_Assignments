// OSI model using string manipulation
// Name: Malhar Dharmadhikari
// Regno: 20BCE2110

#include<stdio.h>
#include <stdlib.h>
#include<string.h>


char* strrmv(char* data, char* layer)
{
    char *p, *q, *r;

    if(*layer && (q = r = strstr(data, layer)) != NULL)
    {
        size_t l = strlen(layer);
        while((r = strstr(p = r+l, layer)) != NULL)
        {
            while(p < r)
                *q++ = *p++;
        }
        while((*q++ = *p++) != '\0')
            continue;
    }

    return data;
}

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
    char* data = (char*)malloc(50*sizeof(char));
    char* ah = "AH_";
    char* ph = "PH_";
    char* sh = "SH_";
    char* th = "TH_";
    char* nh = "NH_";
    char* dh = "DH_";
    char* dt = "_CRC";

    printf("Data: ");
    scanf("%s", data);
    char* bin = StoB(data);
    char *temp = strdup(data);

    printf("Sender Side: \n\n");
    strcpy(data, ah);
    strcat(data, temp);
    printf("%s\n", data);
    sleep(1);
    temp = strdup(data);
    strcpy(data, ph);
    strcat(data, temp);
    printf("%s\n", data);
    sleep(1);
    temp = strdup(data);
    strcpy(data, sh);
    strcat(data, temp);
    printf("%s\n", data);
    sleep(1);
    temp = strdup(data);
    strcpy(data, th);
    strcat(data, temp);
    printf("%s\n", data);
    sleep(1);
    temp = strdup(data);
    strcpy(data, nh);
    strcat(data, temp);
    printf("%s\n", data);
    sleep(1);
    temp = strdup(data);
    strcpy(data, dh);
    strcat(data, temp);
    strcat(data, dt);
    printf("%s\n", data);
    sleep(1);

    printf("Physical Layer: %s\n\n", bin);
    sleep(1);


    printf("Reciever Side: \n\n");
    printf("Physical Layer: %s\n", bin);
    sleep(1);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, dt);
    strrmv(data, dh);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, nh);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, th);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, sh);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, ph);
    printf("%s\n", data);
    sleep(1);
    strrmv(data, ah);
    printf("%s\n", data);
    sleep(1);


    free(data);
    free(temp);

    return 0;
}