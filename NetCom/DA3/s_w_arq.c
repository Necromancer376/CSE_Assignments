#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int time = 0;

int Reciever(int frame, int t)
{
    if(frame)
    {
        time++;
        return 0;
    }
    else
    {
        time++;
        return 1;
    }
}


void Sender(int n)
{
    int fno = 0;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        if(i % 2 == 0)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    while(fno < n)
    {
        int ack = Reciever(arr[fno], time);
        time++;

        if(ack == 0)
        {
            printf("id_%d success\n", fno);
        }
        else if(ack == 1)
        {
            printf("id_%d lost\n", fno);
            arr[fno] = 1;
            fno--;
        }
        else
        {
            printf("id_%d timed out\n", fno);
            fno--;
        }
        fno++;
    }
}


int main(void)
{
    int n;
    printf("number of frames: ");
    scanf("%d", &n);
    printf("\n");

    Sender(n);

    printf("\n");
}
