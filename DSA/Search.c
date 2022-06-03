#include<stdio.h>
#include<stdlib.h>


int LeniarSearch(int* array, int size, int item)
{
    int pos;

    for (int i = 0; i < size; i++)
    {
        if(*(array + i) == item)
        {
            return i;
        }
    }
    return -1;
}


int BinarySearch(int* arr, int size, int item)
{
    int low = 0, upper = size, mid;
    int temp = (low + upper)/2;

    while(low <= upper)
    {
        mid = (low + upper)/2;
 
        if(*(arr + mid-1) == item)
        {
            return mid;
        }

        else if(item > *(arr + mid-1))
        {
            low = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }

    return -1;
}


void BubbleSort(int* arr, int size)
{
    for(int i=0; i < size-1 ; i++)
    {
        for(int j=0; j < size - i - 1; j++)
        {
            if(*(arr + j) > *(arr + j+1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j+1);
                *(arr + j+1) = temp;
            }
        }
    }
}


void PrintArr(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}



int main()
{
    int *arr;
    int size, item;
    
    printf("Size: ");
    scanf("%d", &size);

    printf("Array:\n");
    for(int i=0; i<size; i++)
    {
        int x;
        scanf("%d", &x);
        *(arr+i) = x;
    }

    printf("Item: ");
    scanf("%d", &item);

    BubbleSort(arr, size);
    printf("\nSorted Array: \n");
    PrintArr(arr, size);

    int pos = BinarySearch(arr, size, item);

    if(pos == -1)
    {
        printf("Item not found\n");
    }
    else
    {
        printf("Item found at position %d\n", pos-1);
    }
}