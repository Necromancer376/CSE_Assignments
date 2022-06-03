#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define nf 5
#define maxf 10

int sw, rw;

void Sender(int, int*, int, int*, int*, char*);

void Reciever(int frame, int arr[], int sendTo, int resvArr[], int sendArr[], char acks[])
{
    int i, j, k;
    time_t t;
    int f, f1, a1;
    char ch;

    srand((unsigned) time(&t));

    for(i=0; i<sendTo; i++)
    {
        if(acks[i] == 'n')
        {
            f = rand() % 10;

            if(f != 5)
            {
                for(j=0; i<sendTo; j++)
                {
                    if(resvArr[j] == sendArr[i])
                    {
                        printf("Reciever: recieved %d\n", resvArr[j]);
                        resvArr[j] = arr[rw];
                        rw = (rw + 1) % frame;
                        break;
                    }
                    if(j == sendTo)
                        printf("Reciever: duplicate %d\n", sendArr[i]);

                    a1 = rand() % 5;

                    if(a1 == 3)
                    {
                        printf("Acknowledgement %d lost\n", sendArr[i]);
                        printf("Sender timeout\n");
                        acks[i] = 'n';
                    }
                    else
                    {
                        printf("Acknowledgement %d recieved\n", sendArr[i]);
                        acks[i] = 'p';
                        break;
                    }
                }
            }
            else
            {
                int ld = rand() % 2;
                if(ld == 0)
                {
                    printf("Reciever: frame %d corrupted\n", sendArr[i]);
                }
                else
                {
                    printf("Reciever: frame %d lost\n", sendArr[i]);
                    printf("Sender timeout\n");
                }
                acks[i] = 'n';
            }
        }
    }

    for(j=0; i<sendTo; j++)
    {
        if(acks[j] == 'n')
            break;
    }

    i = 0;

    for(k=j; k < sendTo; k++)
    {
        sendArr[i] = sendArr[k];
        if(acks[k] == 'n')
            acks[i] = 'n';
        else
            acks[i] = 'p';
        i++;
    }

    if(i != sendTo)
    {
        for(k=i; k< sendTo; k++)
        {
            sendArr[k] = arr[sw];
            sw = (sw + 1) % frame;
            acks[k] = 'n';
        }
    }
}


void Sender(int frame, int arr[], int sendTo, int resvArr[], int sendArr[], char acks[])
{
    for(int i=0; i < sendTo; i++)
    {
        if(acks[i] == 'n')
            printf("Sender: sent %d\n", sendArr[i]);
    }
    Reciever(frame, arr, sendTo, resvArr, sendArr, acks);
}


int main(void)
{
    int m, n, sendTo;
    int t=0;
    int sendArr[nf];
    int arr[maxf];
    int resvArr[nf];
    char acks[nf];

    printf("No. Bits: ");
    scanf("%d", &n);

    m = pow(2, n);
    sendTo = (m / 2);

    for(int i=0; i < maxf; i++)
    {
        arr[i] = t;
        t = (t + 1) % m;
    }
    for(int i=0; i < maxf; i++)
    {
        sendArr[i] = arr[i];
        resvArr[i] = arr[i];
        acks[i] = 'n';
    }
    rw = sw = sendTo;

    Sender(m, arr, sendTo, resvArr, sendArr, acks);
}