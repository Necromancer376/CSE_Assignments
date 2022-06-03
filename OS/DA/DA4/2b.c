#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int arr[], int size)
{
    for(int i=0; i < size-1 ; i++)
    {
        for(int j=0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SCAN(int n, int arr[], int start)
{
	int c = 0;
	arr[n+1] = 0;
	arr[n+2] = 199;
	BubbleSort(arr, n+3);
	int temp = 0;
	for(int i=0; i<=n+3; i++)
	{
		if(arr[i] == start)
		{
			temp = i;
			break;
		}
	}

	for(int i=temp; i>0; i--)
	{
		printf("%d ", arr[i]);
		c += abs(arr[i] - arr[i-1]);
	}
	printf("%d ", arr[0]);

	for(int i=temp+1; i<n+2; i++)
	{
		printf("%d ", arr[i]);
		c += abs(arr[i] - arr[i-1]);
	}
	printf("%d\n", arr[n+2]);
	printf("\ncount: %d", c);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int arr[n+3];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("start: ");
	scanf("%d", &arr[n]);

	printf("\nSequence: \n");
	SCAN(n, arr, arr[n]);
	printf("\n");
}