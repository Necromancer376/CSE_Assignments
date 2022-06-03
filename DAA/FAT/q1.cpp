#include<iostream>

using namespace std;


int nIr1 = 0;
int nIr2 = 0;

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


int main()
{
	pair<int, int> DAC;
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

	DAC = MinMaxDaC(arr, 0, n-1);

	cout << "Using Divide and Conquer: " << endl;
	cout << "Min: " << DAC.first << "\tMax: " << DAC.second << endl;
}