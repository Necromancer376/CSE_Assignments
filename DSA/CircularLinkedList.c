#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    int data;
    struct node* next;
};

struct node* head;

void InsertPos()
{
    int input, loc;
    struct node* ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node*));

    printf("Data: ");
    scanf("%d", &input);
    ptr->data = input;

    if(head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        printf("Index of Insersion: ");
        scanf("%d", &loc);
        temp = head;
        for(int i = 0; i < loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("Error\n");
                return;
            }
        }
    
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void Display()
{
    struct node* ptr;
    printf("\n");
    if(head == NULL)
        printf("Empty list\n");
    else
    {
        ptr = head;
        printf("-------------\n");
        while(ptr->next != head)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("%d->head\n", ptr->data);
        printf("-------------\n");
    }
    printf("\n");
}


int main()
{
    int operation = -1;
    while(operation != 0)
    {
        printf("1. %s\n2. %s\n0. %s\n", "Insert at Given Index", "Display", "Exit");
        printf("\nOperation: ");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                InsertPos();
                break;
            case 2:
                Display();
                break;
            case 0:
                operation = 0;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }
}