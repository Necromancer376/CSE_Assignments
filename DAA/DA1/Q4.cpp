#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


vector<int> l[100];
int c = 0;

void Subsets(int *arr, int n)
{    
    int num = 0;
    while(num<pow(2,n))
    {
        for(int i=0;i<n;++i)
        {
            if((num&(1<<i))!=0)
            {
                l[c].push_back(arr[i]);
            }
        }
        ++num;
        c++;
    }
}


int main()
{
	int n, w, max = 0, ans;
	cout << "Max Weight: ";
	cin >> w;
	cout << "Size: ";
	cin >> n;

	int arr[n];
	cout << "Items: " << endl;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	Subsets(arr, n);

	for(int i=0; i<c; i++)
	{
		int sum = 0;
		for(int j=0; j<l[i].size(); j++)
		{
			sum += l[i][j];
		}
		if(sum > max && sum <= w)
		{
			max = sum;
			ans = i;
		}
	}

	cout << "Items to keep: ";
	for(int i=0; i<l[ans].size(); i++)
		cout << l[ans][i] << " ";
	cout << endl;
}

