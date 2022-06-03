#include<stdio.h>
#include<stdlib.h>

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

struct node* Insert(int size, int arr[size], struct node* root, int i)
{
    if (i < size)
    {
        struct node* temp = newNode(arr[i]);
        root = temp;

        root->left = Insert(size, arr, root->left, 2 * i + 1);
        root->right = Insert(size, arr, root->right, 2 * i + 2);
    }
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
    int size;
    printf("Size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Elements: \n");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);

    struct node* root = Insert(size, arr, root, 0);
    printf("\nInorder: ");
    PrintInorder(root);
    printf("\nPreorder: ");
    PrintPreorder(root);
    printf("\nPostorder: ");
    PrintPostorder(root);
    printf("\n");

    return 0;
}