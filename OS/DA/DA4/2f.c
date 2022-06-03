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

void CLOOK(int n, int arr[], int start)
{
	int c = 0;
	BubbleSort(arr, n+1);
	int temp = 0;
	for(int i=0; i<=n; i++)
	{
		if(arr[i] == start)
		{
			temp = i;
			break;
		}
	}

	for(int i=temp; i<n; i++)
	{
		printf("%d ", arr[i]);
		c += abs(arr[i] - arr[i+1]);
	}
	printf("%d ", arr[n]);

	for(int i=temp-1; i<=0; i--)
	{
		printf("%d ", arr[i]);
		c += abs(arr[i] - arr[i+1]);
	}
	printf("%d \n", arr[0]);

	printf("count: %d\n", c);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int arr[n+1];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("start: ");
	scanf("%d", &arr[n]);

	printf("\nSequence: \n");
	CLOOK(n, arr, arr[n]);
	printf("\n");
}