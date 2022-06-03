#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int Dif(int n, int arr[], int start, int diff[][2])
{
	for(int i=0; i<n; i++)
		diff[i][0] = abs(start - arr[i]);
}


int Close(int diff[][2], int n)
{
	int indx = -1;
    int min = INT_MAX;
   
    for(int i=0; i<n; i++)
    {
        if (!diff[i][1] && min > diff[i][0])
        {
            min = diff[i][0];
            indx = i;
        }
    }
    return indx;
}


void SSTF(int n, int arr[], int start)
{
	if(n == 0)
		return;

	int diff[n][2];
	int c = 0;
	int seq[n+1];

	for(int i=0; i<n; i++)
	{
		diff[i][0] = 0;
		diff[i][1] = 0;
		seq[i] = 0;
	}
	seq[n] = 0;

	for(int i=0; i<n; i++)
	{
		seq[i] = start;
		Dif(n, arr, start, diff);
		int indx = Close(diff, n);
		diff[indx][1] = 1;

		c += diff[indx][0];
		start = arr[indx];
	}
	seq[n] = start;

	for(int i=0; i<=n; i++)
	{
		printf("%d ", seq[i]);
	}
	printf("\ncount: %d\n", c);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int start;
	printf("start: ");
	scanf("%d", &start);

	printf("\nSequence: \n");
	SSTF(n, arr, start);
	printf("\n");
}
