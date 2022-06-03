#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


struct node* Insert(struct node* root, int item)
{
    if(root == NULL)
        return newNode(item);

    if(root->data > item)
        root->left = Insert(root->left, item);
    else
        root->right = Insert(root->right, item);

    return root;
}


void PrintInorder(struct node* root)
{
    if(root != NULL)
    {
        PrintInorder(root->left);
        printf("%d, ", root->data);
        PrintInorder(root->right);
    }
}

void PrintPostorder(struct node* root)
{
    if(root != NULL)
    {
        PrintPostorder(root->left);
        PrintPostorder(root->right);
        printf("%d, ", root->data);
    }
}

void PrintPreorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d, ", root->data);
        PrintPreorder(root->left);
        PrintPreorder(root->right);
    }
}


int main()
{
    struct node* root = NULL;

    int size;
    printf("Size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Elements: \n");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);

    root = Insert(root, arr[0]);
    for(int i = 1; i<size; i++)
    {
        Insert(root, arr[i]);
    }
    printf("\nInorder: ");
    PrintInorder(root);
    printf("\nPreorder: ");
    PrintPreorder(root);
    printf("\nPostorder: ");
    PrintPostorder(root);
    printf("\n");
}