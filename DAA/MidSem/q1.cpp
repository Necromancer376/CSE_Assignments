#include <bits/stdc++.h>

using namespace std;


int Solve(int n, vector<int> price)
{
	int ans = -1;

	if(n == 0)
		return 0;

	for(int i=1; i<n+1; i++)
	{
		int temp = price[i-1] + Solve(n-i, price);
		if(temp > ans)
			ans = temp;
	}

	return ans;
}


int main()
{
	int n;
	cout << "n: ";
	cin >> n;
	vector<int> price(n);

	cout << "Price: " << endl;
	for(int i=0;i <n; i++)
	{
		cin >> price[i];
	}
	cout << "Max: " << Solve(n, price) << endl;

	return 0;
}