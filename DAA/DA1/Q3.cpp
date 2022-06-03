#include<iostream>

using namespace std;


int main()
{
	int n;
	cout << "n: ";
	cin >> n;
	int k = 0;
	int flag = false;

	int arr[n];
	cout << "elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	for(int i=0; i<n; i++)
	{
		int inc = 0;
		int dec = 0;
		for(int j=0; j<i; j++)
		{
			if(arr[j] < arr[j+1])
			{
				inc++;
			}
		}
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] < arr[j-1])
			{
				dec++;
			}
		}
		if(inc == i && dec == n-i-1)
			cout << "k = " << i << endl;
	}
}