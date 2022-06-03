#include<stdio.h>
#include<stdlib.h>


void Merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i=0; i < n1; i++)
        L[i] = *(arr + l + i);
    for(j=0; j < n2; j++)
        R[j] = *(arr + m + 1 +j);

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            *(arr+ k) = L[i];
            i++;
        }
        else
        {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }


    while(i < n1)
    {
        *(arr + k) = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        *(arr + k) = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* arr, int l, int r)
{
    if(l < r)
    {
        int m = (l + r - 1) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
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
    int* arr;
    int length;
    printf("Length: ");
    scanf("%d", &length);

    printf("Array: \n");
    for (int i = 0; i < length; i++)
    {
        int x;
        scanf("%d", &x);
        *(arr + i) = x;
    }

    MergeSort(arr, 0, length-1);

    printf("Sorted Array: \n");
    PrintArr(arr, length);

    int search, index;
    printf("search item: ");
    scanf("%d", &search);

    index = BinarySearch(arr, length, search);

    printf("Element is at index: %d\n\n", index);
}