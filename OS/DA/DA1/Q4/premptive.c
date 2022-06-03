#include<stdio.h>

int main()
{
	int p[] = {1, 2, 3, 4, 5};
	int bt[] = {5, 2, 7, 10, 13};
	int pr[] = {4, 1, 3, 0, 2};
	int n = 5;
	int wt[n], tat[n];
	int total=0;
	

	for(int i=0; i<n; i++)
	{
		int pos=i;
		for(int j=i+1; j<n; j++)
		{
			if(pr[j] < pr[pos])
			pos = j;
		}

		int temp = pr[i];
		pr[i] = pr[pos];
		pr[pos] = temp;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}

	wt[0]=0;

	for(int i=1; i<n; i++)
	{
		wt[i] = 0;
		for(int j=0; j<i; j++)
		wt[i] += bt[j];

		total += wt[i];
	}

	float avg_wt = (float)total / (float)n;
	total = 0;

	printf("\nProcess\tBT\tWT\tTAT\n");
	for(int i=0; i<n; i++)
	{
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
	}

	float avg_tat = (float)total / (float)n;
	printf("\nAvg WT = %f\n", avg_wt);
	printf("Avg TAT = %f\n", avg_tat);

	printf("\n");
	return 0;
}