#include<iostream>
#include<vector>
#define change(x) (x == 1 ? "True" : "False")

using namespace std;


bool CheckAll(int d, vector<int> arr1, vector<int> arr2)
{
	for(int i=0; i<d; i++)
	{
		for(int j=0; j<d; j++)
		{
			if(arr1[i] == arr2[j])
				return false;
		}
	}
	return true;
}


int main()
{
	int n, d;
	cout << "Number of Arrays: ";
	cin >> n;

	cout << "Size of Array: ";
	cin >> d;

	vector<vector<int>> arr(n, vector<int>(d));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<d; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "Single Array Comparison: " << endl;
	for(int i=0; i<n; i++)
	{
		bool flag = false;
		for(int j=0; j<d; j++)
		{
			for(int k=0; k<d; k++)
			{
				if(j != k && arr[i][j] == arr[i][k])
				{
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout << "Array " << i  << ": " << change(!flag) << endl;
		else
			cout << "Array " << i  << ": " << change(!flag) << endl;
	}

	cout << endl << "Multiple Array Comparison: " << endl;
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(i != j)
			{
				cout << "Array (" << i << ", " << j << "): " << change(CheckAll(d, arr[i], arr[j])) << endl;
			}
		}
	}

	return 0;
}



// bool CheckOne(int d, int x, vector<vector<int>> arr)
// {
// 	for(int i=0; i<d; i++)
// 	{
// 		for(int j=i; i<d; j++)
// 		{
// 			if(i != j)
// 			{
// 				if(arr[x][i] == arr[x][j])
// 				{
// 					return false;
// 				}
// 			}
// 		}
// 	}

// 	return true;
// }
