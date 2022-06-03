#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* next;
};

struct node* head;


void Push()
{
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL)
    {  
        printf("Overflow");
    }  
    else   
    {  
        printf("Data: ");
        scanf("%d",&data);

        if(head == NULL)
        {         
            temp -> data = data;
            temp -> next = NULL;
            head = temp;
        }
        else
        {
            temp -> data = data;
            temp -> next = head;
            head = temp;
        }
    }
}

void Pop()
{
    int item;

    struct node* temp;

    if(head == NULL)
        printf("Underflow\n");
    else
    {
        item = head->data;
        temp = head;
        head = head->next;
        free(temp);
    }
}

void Print()
{
    struct node* temp;
    temp = head;

    if(temp == NULL)
        printf("Empty Stack\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
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