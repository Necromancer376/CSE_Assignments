#include<bits/stdc++.h>
#include<stdio.h>
#include<stdbool.h>

using namespace std;

struct Process
{
	int id;
	int priority;
	int bt;
};


bool compair(struct Process a, struct Process b)
{
	return (a.priority > b.priority);
}

void Waiting(int n, struct Process proc[], int wt[])
{
	wt[0] = 0;

    for (int i=1; i<n; i++)
        wt[i] = proc[i-1].bt + wt[i-1];
}

void TAT(int n, struct Process proc[], int wt[], int tat[])
{
	for(int i=0; i<n; i++)
	{
		tat[i] = proc[i].bt + wt[i];
	}
}

void AvgTime(int n, struct Process proc[])
{
	int wt[n], tat[n];
	int total_wt = 0, total_tat = 0;

	Waiting(n, proc, wt);
	TAT(n, proc, wt, tat);

	printf("Process\tBurstTime\tWaitingTime\tTAT\n");

	for(int i=0; i<n; i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];

		printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", proc[i].id, proc[i].bt, wt[i], tat[i]);
	}

	float avg_wt = (float)total_wt / (float)n;
	float avg_tat = (float)total_tat / (float)n;

	printf("Avg WT: %f\n", avg_wt);
	printf("Avg TAT: %f\n", avg_tat);
}

void Schedule(int n, struct Process proc[])
{
	sort(proc, proc + n, compair);
    AvgTime(n, proc);
}

int main(void)
{
	struct Process proc[] = {{1, 2, 5}, {2, 5, 10}, {3, 0, 7}, {4, 1, 3}, {5, 3, 12}};
	int n = sizeof proc / sizeof proc[0];

	Schedule(n, proc);

    printf("\n");
}