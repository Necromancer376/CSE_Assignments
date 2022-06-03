#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head;

void InsertPos()
{
    struct node *ptr, *temp;
    int input, loc;
    ptr = (struct node*)malloc(sizeof(struct node*));

    printf("Data: ");
    scanf("%d", &input);
    ptr->data = input;

    if(head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else
    {
        printf("Index of Insersion: ");
        scanf("%d", &loc);
        temp = head;
        for(int i=0; i < loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("Error\n");
                return;
            }
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
    }
}

void Display()
{
    struct node* ptr;
    ptr = head;

    printf("-------------\n");
    if(ptr == NULL)
        printf("Empty list\n");
    else
    {
        printf("NULL<->");
        while(ptr != NULL)
        {
            printf("%d<->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    printf("-------------\n");
}


int main(void)
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