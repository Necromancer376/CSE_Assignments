#include<stdio.h>
#include<stdbool.h>


void BubbleSort(int size, int* arr, int* proc, int* bt, int* wt)
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

                temp = *(proc + j);
                *(proc + j) = *(proc + j+1);
                *(proc + j+1) = temp;

                temp = *(bt + j);
                *(bt + j) = *(bt + j+1);
                *(bt + j+1) = temp;

                temp = *(wt + j);
                *(wt + j) = *(wt + j+1);
                *(wt + j+1) = temp;
            }
        }
    }
}

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
		BubbleSort(n, bt_left, proc, bt, wt);
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