#include<iostream>

using namespace std;

int nIr1 = 0;
int nIr2 = 0;

pair<int, int> MinMaxIterative(int arr[], int n)
{
	pair<int, int> MinMax;
	MinMax.first = arr[0];
	MinMax.second = arr[0];

	if(n == 1)
		return MinMax;

	for(int i=0; i<n; i++)
	{
		if(arr[i] < MinMax.first && nIr1++)
			MinMax.first = arr[i];

		else if(arr[i] > MinMax.second && nIr1++)
			MinMax.second = arr[i];

	}

	return MinMax;
}


pair<int, int> MinMaxDaC(int arr[], int low, int high)
{
	pair<int, int> MinMax, mmLeft, mmRight;

	if(high == low)
	{
		MinMax.first = arr[low];
		MinMax.second = arr[high];
		return MinMax;
	}

	if(high == low + 1)
	{
		if(arr[low] > arr[high] && nIr2++)
		{
			MinMax.first = arr[high];
			MinMax.second = arr[low];
		}
		else
		{
			MinMax.first = arr[low];
			MinMax.second = arr[high];
		}
		
		return MinMax;
	}

	int mid = (low + high) / 2;
	mmLeft = MinMaxDaC(arr, low, mid);
	mmRight = MinMaxDaC(arr, mid+1, high);

	if(mmLeft.first < mmRight.first && nIr2++)
		MinMax.first = mmLeft.first;
	else
		MinMax.first = mmRight.first;

	if(mmLeft.second > mmRight.second && nIr2++)
		MinMax.second = mmLeft.second;
	else
		MinMax.second = mmRight.second;

	return MinMax;
}


void NumComparisons(int n)
{
	int n1 = 0, n2 = 0;

	n2 += 3*n/2 - 2;

	n1 += 2 * n;

	cout << endl << "Worst Case No. Of Comparisons: " << endl;
	cout << "Iterative: " << n1 << endl;
	cout << "Divide and Conquer: " << n2 << endl;
	cout << endl << "Current Case No. Of Comparisons: " << endl;
	cout << "Iterative: " << nIr1 << endl;
	cout << "Divide and Conquer: " << nIr2 << endl;
}


int main()
{
	pair<int, int> Iterative, DAC;
	int n;
	cout << "size: ";
	cin >> n;
	int arr[n];

	cout << "Elements: ";
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	cout << endl;

	Iterative = MinMaxIterative(arr, n);

	DAC = MinMaxDaC(arr, 0, n-1);

	cout << "Using Iterative: " << endl;
	cout << "Min: " << Iterative.first << "\tMax: " << Iterative.second << endl << endl;

	cout << "Using Divide and Conquer: " << endl;
	cout << "Min: " << DAC.first << "\tMax: " << DAC.second << endl;

	NumComparisons(n);
}