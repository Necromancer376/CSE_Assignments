#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int n;

char DtoH(int n)
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

    return ans[strlen(ans)-1];
}

int CtoD(char x)
{
    int ans = 0, c=1;
    if(x >= '0' && x <= '9')
    {
        ans += (x - 48) * c;
        c *= 16;
    }
    else if(x >= 'A' && x <= 'F')
    {
        ans += (x - 55) * c;
        c *= 16;
    }

    return ans;
}

char Complement(char c)
{
    int num = CtoD(c);
    num = 15 - num;

    if(num > 9)
        return (num + 55);
    return (num + 48);
}


char Add(char x, char y)
{
    int ret = CtoD(x) + CtoD(y);

    return ret;
}


char* Checksum(char *data, char *checksum)
{
    char carry;
    
    for(int i=0; i<n; i+=4)
    {   
        for(int j=0; j<4; j++)
        {
            int temp = Add(*(checksum + j), *(data + i + j));
            if(temp > 15)
                carry = DtoH(temp);
            else if(temp > 9)
                *(checksum + j) = temp + 55;
            else
                *(checksum + j) = temp + 48;

            temp = Add(*(checksum + j), carry);
            if(temp > 15)
                carry = DtoH(temp);
            else
                carry = '0';
        }
    }

    for(int i=0; i<4; i++)
        *(checksum + i) = Complement(*(checksum + i));

    return checksum;
}


int main(void)
{
    printf("Length of data: ");
    scanf("%d", &n);
    char *data = (char*)malloc(n * sizeof(char));
    char *sender = (char*)malloc(4 * sizeof(char));
    char *reciever = (char*)malloc(4 * sizeof(char));
    char *checksum = (char*)malloc(4*sizeof(char));
    printf("Data: ");
    for(int i=0; i<4; i++)
        *(checksum + i) = '0';
    
    for(int i=0; i<n; i++)
        scanf("%c", (data + i));

    sender = Checksum(data, checksum);
    printf("\nChecksum on sender side = %s\n", sender);

    reciever = Checksum(data, sender);
    printf("Checksum on reciever side = %s\n", reciever);

    if(strcmp(reciever, "0000"))
        printf("Error\n");
    else
        printf("No error\n");
}