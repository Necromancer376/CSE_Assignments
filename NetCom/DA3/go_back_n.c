#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int size, ack;
    int sent=0;

    printf("window size: ");
    scanf("%d", &size);

    while(1)
    {
        for(int i = 0; i < size; i++)
        {
            printf("Transmitted frame %d\n",sent);
            sent++;
            if(sent == size)
                break;
        }
        printf("\nLast acknowledgement received: ");
        scanf("%d",&ack);

        if(ack == size)
            break;
        else
            sent = ack;
    }

    return 0;
}