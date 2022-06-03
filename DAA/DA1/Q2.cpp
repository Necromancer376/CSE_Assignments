#include<iostream>

using namespace std;


int main()
{
	int n;
	cout << "n: ";
	cin >> n;
	int inv = 0;

	int arr[n];
	cout << "elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	for(int i=0; i<n-1; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(arr[i] > arr[j])
			{
				cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
				inv++;
			}
		}
	}
	cout << "Number of inversions: " << inv << endl;
}