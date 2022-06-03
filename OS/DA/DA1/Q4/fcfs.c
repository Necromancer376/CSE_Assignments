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


int main(void)
{
	int process[] = {1, 2, 3, 4, 5};
	int burst[] = {10, 7, 2, 6, 5};
	int n = sizeof(process) / sizeof(process[0]);

	AvgTime(n, process, burst);

	printf("\n");
}