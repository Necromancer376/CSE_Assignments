#include<stdio.h>
#include<stdbool.h>


void Waiting(int n, int proc[], int bt[], int wt[], int q)
{
	int bt_left[n];
	for(int i=0; i<n; i++)
		bt_left[i] = bt[i];
	
	int t = 0;

	while(1)
	{
		bool over = true;

		for(int i=0; i<n; i++)
		{
			if(bt_left[i] > 0)
			{
				over = false;

				if(bt_left[i] > q)
				{
					t += q;
					bt_left[i] -= q;
				}
				else
				{
					t += bt_left[i];
					wt[i] = t - bt[i];
					bt_left[i] = 0;
				}
			}
		}

		if(over == true)
			break;
	}
}

void TAT(int n, int proc[], int bt[], int wt[], int tat[])
{
	for(int i=0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];
	}
}

void AvgTime(int n, int proc[], int bt[], int q)
{
	int wt[n], tat[n];
	int total_wt = 0, total_tat = 0;

	Waiting(n, proc, bt, wt, q);
	TAT(n, proc, bt, wt, tat);

	printf("Process\tBurstTime\tWaitingTime\tTAT\n");

	for(int i=0; i<n; i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];

		printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", proc[i], bt[i], wt[i], tat[i]);
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
	int quantum = 4;

	AvgTime(n, process, burst, quantum);

	printf("\n");
}