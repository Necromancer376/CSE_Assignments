// Number Conversion
// Name: Malhar Dharmadhikari
// Regno: 20BCE2110

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}


int DtoB(int n)
{
    int ans = 0;

    for(int i=0; n > 0; i++)
    {
        ans = (ans * 10) + n%2;
        n = n/2;
    }

    return ans;
}


int BtoD(int n)
{
    int ans = 0;

    int c = 0;

    while(n > 0)
    {
        ans +=  (n%10) * pow(2, c);
        n = n/10;
        c++;
    }

    return ans;
}


char* DtoH(int n)
{
    char *ans = malloc(20);
    int i=0;

    while(n != 0)
    {
        int temp = n % 16;
        if(temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

        *(ans + i) = temp;
        i++;
        n = n / 16;
    }

    return strrev(ans);
}


int HtoD(char *n)
{
    int ans = 0, c = 1;
    int l = strlen(n);

    for(int i = l-1; i >= 0; i--)
    {
        if(*(n+i) >= '0' && *(n+i) <= '9')
        {
            ans += (*(n+i) - 48) * c;
            c *= 16;
        }

        else if(*(n+i) >= 'A' && *(n+i) <= 'F')
        {
            ans += (*(n+i) - 55) * c;
            c *= 16;
        }

        else if(*(n+i) >= 'a' && *(n+i) <= 'f')
        {
            ans += (*(n+i) - 87) * c;
            c *= 16;
        }
    }

    return ans;
}


int main(void)
{
    int option, c=0;
    int n;
    char* hex;
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("0. Exit\n");

    while(c != 1)
    {
        printf("\nOption: ");
        scanf("%d", &option);
        printf("\n");

        switch(option)
        {
            case 0:
                c =1;
                break;
            case 1:
                printf("Decimal: ");
                scanf("%d", &n);
                printf("Binary: %d\n", DtoB(n));
                break;

            case 2:
                printf("Binary: ");
                scanf("%d", &n);
                printf("Decimal: %d\n", BtoD(n));
                break;

            case 3:
                printf("Decimal: ");
                scanf("%d", &n);
                printf("Hexadecimal: %s\n", DtoH(n));
                break;

            case 4:
                printf("Hexadecimal: ");
                scanf("%s", hex);
                printf("Decimal: %d\n", HtoD(hex));
                break;
        }
    }
}