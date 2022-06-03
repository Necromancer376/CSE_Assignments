// chain matrix

#include <bits/stdc++.h>

using namespace std;


int MulMatrix(int dim[], int i, int j)
{
	if(i == j)
		return 0;

	int k, c;
	int min = INT_MAX;

	for(int k=i; k < j; k++)
	{
		c = MulMatrix(dim, i, k) + MulMatrix(dim, k+1, j) + dim[i-1]*dim[k]*dim[j];

		if(min > c)
			min = c;
	}

	return min;
}


int main()
{
	int dim[] = {3, 4, 3, 5, 6, 8};
	int n = sizeof(dim) / sizeof(dim[0]);

	cout << "Dimentions: ";
	for(int i=0; i<n; i++)
		cout << dim[i] << ", ";
	cout << endl;
	cout << "Min multiplications = " << MulMatrix(dim, 1, n-1) << endl;
}