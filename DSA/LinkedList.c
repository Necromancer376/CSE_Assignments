#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    int data;
    struct node* next;
};

struct node* head;
int len = 0;

void InsertBeg()
{
    struct node* ptr;
    int input;

    ptr = (struct node*)malloc(sizeof(struct node*));

    if(ptr == NULL)
        printf("Overlow\n");
    else
    {
        printf("Data: ");
        scanf("%d", &input);
        ptr->data = input;
        ptr->next = head;
        head = ptr;
        len++;
    }
}

void InsertEnd()
{
    struct node* ptr, *temp;
    int input;

    ptr = (struct node*)malloc(sizeof(struct node*));

    if(ptr == NULL)
        printf("Overlow\n");
    else
    {
        printf("Data: ");
        scanf("%d", &input);
        ptr->data = input;
        
        if(head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            
            temp->next = ptr;
            ptr->next = NULL;
        }
        len++;
    }
}

void InsertPos()
{
    int input, loc;
    struct node* ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node*));

    printf("Data: ");
    scanf("%d", &input);
    ptr->data = input;
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
    len++;
}

void DeleteBeg()
{
    struct node* ptr;
    if(head == NULL)
        printf("Underflow\n");
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
    len--;
}

void DeleteEnd()
{
    struct node *ptr, *temp;
    if(head == NULL)
        printf("Underflow\n");
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        len--;
    }
}

void DeletePos()
{
    struct node *ptr, *temp;
    int loc;

    printf("Index of Deletion: ");
    scanf("%d", &loc);
    ptr = head;

    for (int i = 0; i < loc; i++)
    {
        temp = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("Error\n");
            return;
        }
    }

    temp->next = ptr->next;
    free(ptr);
    len--;
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
        while(ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    printf("-------------\n");
}


void Sort()
{
    
}


int main()
{
    int operation = -1;
    while(operation != 0)
    {
        printf("1. %s\n2. %s\n3. %s\n", "Insert at Beginning", "Insert at End", "Insert at Given Index");
        printf("4. %s\n5. %s\n6. %s\n", "Delete at Beginning", "Delete at End", "Delete at Given Index");
        printf("7.%s\n0.%s\n", "Display", "Exit");
        printf("\nOperation: ");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                InsertBeg();
                break;
            case 2:
                InsertEnd();
                break;
            case 3:
                InsertPos();
                break;
            case 4:
                DeleteBeg();
                break;
            case 5:
                DeleteEnd();
                break;
            case 6:
                DeletePos();
                break;
            case 7:
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