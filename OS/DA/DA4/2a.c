#include <stdio.h>
#include <stdlib.h>


void FCFS(int n, int arr[])
{
	int c = 0;
	printf("%d ", arr[n]);
	for(int i=0; i<n-1; i++)
	{
		printf("%d ", arr[i]);
		c += abs(arr[i] - arr[i+1]);
	}
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
	arr[n+1] = 199;
	arr[n+2] = 0;

	printf("\nSequence: \n");
	FCFS(n, arr);
	printf("\n");
}
