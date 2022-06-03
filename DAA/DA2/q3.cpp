#include <bits/stdc++.h>

using namespace std;


int cost = 0;

int Least(int n, vector<vector<int>> mat, vector<int>cmp, int loc)
{
	int nh = INT_MAX, min = INT_MAX, temp;

	for(int i=0; i<n; i++)
	{
		if((mat[loc][i] != 0) && (cmp[i] == 0))
		{
			if(mat[loc][i] + mat[i][loc] < min)
			{
				min = mat[i][0] + mat[loc][i];
				temp = mat[loc][i];
				nh = i;
			}
		}
	}

	if(min != INT_MAX)
	{
		cost += temp;
	}

	return nh;
}


void TSP(int n, vector<vector<int>> mat, vector<int> cmp, int loc)
{
	int nh;
	cmp[loc] = 1;
	cout << loc << "-";
	nh = Least(n, mat, cmp, loc);
	
	if(nh == INT_MAX)
	{
		nh = 0;
		cout << nh;
		cost += mat[loc][nh];
		return;
	}

	TSP(n, mat, cmp, nh);
}


int main()
{
	int n;
	cout << "nodes: ";
	cin >> n;
	vector<vector<int>> mat;
	vector<int> cmp;

	for(int i=0; i<n; i++)
	{
		vector<int> x;
		for(int j=0; j<n; j++)
		{
			int temp;
			cin >> temp;
			x.push_back(temp);
			cmp.push_back(0);
		}
		mat.push_back(x);
	}

	cout << endl << "Path: ";
    TSP(n, mat, cmp, 0);
    cout << endl << "Cost: " << cost << endl;

}

// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0