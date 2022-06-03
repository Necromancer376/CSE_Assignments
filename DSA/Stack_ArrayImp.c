#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[100];
int top = -1, n = 100;
char popped;


void Push()
{
    int val;
    if (top ==  100)
        printf("\nOverflow");

    else
    {
        printf("Data:");
        scanf("%d", &val);

        top++;

        stack[top] = val;
    }   
}


void Pop()
{
    if(top == -1)
        printf("Underflow\n");
    
    else
    {
        popped = stack[top];
        top--;
    }
}


void Print()
{
    for(int i = top; i >=0; i--)
    {
        printf("%d\n", stack[i]);
    }

    if(top == -1)
    {
        printf("Empty Stack\n");
    }
}


int main()
{
    int op;
    printf("1.%s\n2.%s\n3.%s\n0.%s\nOperation: ", "Push", "Pop", "Print", "Exit");
    scanf("%d", &op);

    while(op != 0)
    {
        switch(op)
        {
            case 1: 
                Push(); 
                Print();
                printf("\n");
                break;
            case 2:
                Pop();
                Print();
                printf("\n");
                break;
            case 3:
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