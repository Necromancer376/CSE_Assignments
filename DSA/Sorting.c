#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


void InsertionSort(int* arr, int size)
{
    int i, j, key;

    for(i = 1; i < size; i++)
    {
        key = *(arr + i);
        j = i - 1;

        while(j >= 0 && *(arr + j)> key)
        {
            *(arr+ j+1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j+1) = key;
    }
}


void SelectionSort(int* arr, int size)
{
    int min;

    for(int i=0; i < size-1; i++)
    {
        min = i;
        for(int j = i+1; j < size; j++)
        {
            if(*(arr + j) < *(arr + min))
                min = j;
        }
        int temp = *(arr + min);
        *(arr + min) = *(arr + i);
        *(arr + i) = temp;
    }
}


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


int Divide(int* arr, int l, int h)
{
    int pivot = *(arr + h);
    int i = (l - 1);

    for(int j = l; j < h; j++)
    {
        if(*(arr + j) <= pivot)
        {
            i++;
            int temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
        }
    }
    int x = *(arr + i + 1);
    *(arr + i +1)  = *(arr + h);
    *(arr + h) = x;
    return (i + 1);
}

void QuickSort(int* arr, int l, int h)
{
    if(l < h)
    {
        int pi = Divide(arr, l, h);

        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, h);
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

    SelectionSort(arr, length);

    printf("Sorted Array: \n");
    PrintArr(arr, length);
}