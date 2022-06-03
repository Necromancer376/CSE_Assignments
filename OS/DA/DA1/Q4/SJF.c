#include<stdio.h>


void Waiting(int n, int proc[], int bt[], int wt[])
{
	wt[0] = 0;
	for(int i=1; i<n; i++)
	{
		wt[i] = bt[i-1]+wt[i-1]; 
	}
}

void TAT(int n, int proc[], int bt[], int wt[], int tat[])
{
	for(int i=0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];
	}
}

void AvgTime(int n, int proc[], int bt[])
{
	int wt[n], tat[n];
	int total_wt = 0, total_tat = 0;

	Waiting(n, proc, bt, wt);
	TAT(n, proc, bt, wt, tat);

	printf("Process\tBurstTime\tWaitingTime\tTAT\n");

	for(int i=0; i<n; i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];

		printf("%d\t%d\t\t%d\t\t%d\n", proc[i], bt[i], wt[i], tat[i]);
	}

	float avg_wt = (float)total_wt / (float)n;
	float avg_tat = (float)total_tat / (float)n;

	printf("Avg WT: %f\n", avg_wt);
	printf("Avg TAT: %f\n", avg_tat);
}

void BubbleSort(int* arr, int* proc, int size)
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

                int temp1 = *(proc + j);
                *(proc + j) = *(proc + j+1);
                *(proc + j+1) = temp1;
            }
        }
    }
}


int main(void)
{
	int process[] = {1, 2, 3, 4, 5};
	int burst[] = {10, 7, 2, 6, 5};
	int n = sizeof(process) / sizeof(process[0]);

	BubbleSort(burst, process, n);
	AvgTime(n, process, burst);

	printf("\n");
}