#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int Queue[100];
int front = -1, back = -1;


void EnqueueBack()
{
    int item;

    if(back == 100)
    {
        printf("Overflow\n");
        exit(1);
    }

    printf("Data: ");
    scanf("%d", &item);

    if(front == -1 && back == -1)
    {
        front = 0;
        back = 0;
    }
    else
        back++;

    Queue[back] = item;
}


void EnqueueFront()
{
    int item;

    if(back == 100 && front == 0)
    {
        printf("Overflow\n");
        exit(1);
    }

    printf("Data: ");
    scanf("%d", &item);

    if(front == -1 && back == -1)
    {
        front = 0;
        back = 0;
    }
    else if(front == 0)
    {
        int n = back + 1;
        while(n != front)
        {
            Queue[n] = Queue[n - 1];
            n--;
        }
        back++;
    }
    else
    {
        front--;
    }

    Queue[front] = item;
}


void DequeueFront()
{
    int item;
    if(front == -1 || front > back)
    {
        printf("Underflow\n");
        exit(1);
    }
    else
    {
        item = Queue[front];
        if(front == back)
        {
            front--;
            back--;
        }
        else
            front++;
    }
}


void DequeueBack()
{
    int item;
    if(front == -1 || front > back)
    {
        printf("Underflow\n");
        exit(1);
    }
    else
    {
        item = Queue[back];
        if(front == back)
        {
            front--;
            back--;
        }
        else
            back--;
    }
}


void Print()
{
    if(back == -1)
        printf("Empty Queue\n");

    else
    {
        printf("Queue: \n");
        for(int i = front; i <= back; i++)
            printf("%d ", Queue[i]);
    }
}


int main()
{
    int op;
    printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n0.%s\nOperation: ", "Enqueue from Back", "Enqueue from Fromt", "Dequeue from Front", "Dequeue from Back", "Print", "Exit");
    scanf("%d", &op);

    while(op != 0)
    {
        switch(op)
        {
            case 1: 
                EnqueueBack(); 
                Print();
                printf("\n");
                break;
            case 2: 
                EnqueueFront(); 
                Print();
                printf("\n");
                break;
            case 3:
                DequeueFront();
                Print();
                printf("\n");
                break;
            case 4:
                DequeueBack();
                Print();
                printf("\n");
                break;
            case 5:
                Print();
                printf("\n");
                break;
            default:
                printf("Wrong operation\n");
                break;
        }
        printf("Operation: ");
        scanf("%d", &op);
    }

    printf("\n");
}