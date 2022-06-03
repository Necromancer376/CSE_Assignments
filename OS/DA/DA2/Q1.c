#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	int m, n;
	printf("Dim: \n");
	scanf("%d%d", &n, &m);

	int allocated[n][m];
	int max[n][m];
	int available[m];

	int f[n], ans[n], required[n][m];
	int index = 0;

	for(int k=0; k<2; k++)
	{
		if(k == 0)
			printf("allocated:\n");
		else
			printf("max:\n");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(k == 0)
					scanf("%d", &allocated[i][j]);
				else
					scanf("%d", &max[i][j]);
			}
		}
	}

	printf("available:\n");
	for(int i=0; i<m; i++)
	{
		scanf("%d", &available[i]);
	}

	for(int i=0; i<n; i++)
	{
		f[i] = 0;
		ans[i] = 0;
	}


	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			required[i][j] = max[i][j] - allocated[i][j];


	for(int c=0; c<n; c++)
	{
		for (int i=0; i<n; i++)
		{
			if(f[i] == 0)
			{
				int flag = 0;
				for(int j=0; j<m; j++)
				{
					if(required[i][j] > available[j])
					{
						flag = 1;
						break;
					}
				}

				if(flag == 0)
				{
					ans[index] = i;
					for(int j=0; j<m; j++)
					{
						available[j] += allocated[i][j];
					}
					f[i] = 1;
					index++;
				}
			}
		}
	}

	printf("\n");
	if(index == n)
	{
		printf("Sequence: ");
	    for (int i=0; i<n; i++)
	        printf("%d, ", ans[i]);
	}
	else
		printf("No Safe Sequence(Deadlock)");
	printf("\n");
	return 0;
}
