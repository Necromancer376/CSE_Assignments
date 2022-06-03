#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char str1[20], str2[20];

    printf("str1: ");
    scanf("%s", str1);
    printf("str2: ");
    scanf("%s", str2);

    int check = strcmp(str1, str2), count=0, l;
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    if(l1 > l2)
        l = l1;
    else
        l = l2;
    int pos[l];


    if(check != 0)
    {
        for (int i=0; i < l; ++i)
        {
            if(str1[i] != str2[i])
            {
                pos[count] = i;
                count++;
            }
        }
    }

    printf("Characters are different at positions: ");
    for(int i=0; i<count; i++)
        printf("%d ", pos[i]);
    printf("\n");

    if(str1[l1-1] == ' ' || str2[0] == ' ')
        printf("%s\n", strcat(str1, str2));
    else if(str1[l1-1] == ' ' && str2[0] == ' ')
    {
        char temp[l1-1];
        for(int i=0; i < l1; i++)
        {
            temp[i] = str1[i];
        }
        printf("%s\n", strcat(temp, str2));
    }
    else
        printf("%s\n", strcat(strcat(str1, " "), str2));

    printf("\n");
}