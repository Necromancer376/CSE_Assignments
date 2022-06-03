#include <bits/stdc++.h>

using namespace std;


int cost = 0;
int filled = 0;
int max_size = 100;
int visited = 1;

int Least(int n, vector<vector<pair<int, int>>> mat, vector<int>cmp, int loc)
{
	int nh = INT_MAX, min = INT_MAX, temp;

	for(int i=0; i<n; i++)
	{
		if((mat[loc][i].first != 0) && (cmp[i] == 0))
		{
			if(mat[loc][i].first + mat[i][loc].first < min)
			{
				min = mat[i][0].first + mat[loc][i].first;
				temp = mat[loc][i].first;
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


void TSP(int n, vector<vector<pair<int, int>>> mat, vector<int> cmp, int loc, int dump)
{
	int nh;
	cmp[loc] = 1;
	nh = Least(n, mat, cmp, loc);
	
	if(nh == INT_MAX)
	{
		nh = 0;
		cost += mat[loc][nh].first;
		return;
	}

	if(filled + mat[loc][nh].second <= max_size)
	{
		filled + mat[loc][nh].second;
	}
	else
	{
		filled = 0;
		nh = dump;
		cmp[dump] = 0;
	}
	visited++;
	if(visited == n)
	{
		cost += mat[nh][dump].first;
		cost += mat[dump][0].first;
	}
	TSP(n, mat, cmp, nh, dump);
}


int main()
{

	int n, dump;
	cout << "no. nodes: ";
	cin >> n;
	vector<vector<pair<int, int>>> mat;
	vector<int> cmp;

	cout << "nodes[cost, size]: " << endl;
	for(int i=0; i<n; i++)
	{
		vector<pair<int, int>> x;
		for(int j=0; j<n; j++)
		{
			pair<int, int> t;
			cin >> t.first;
			cin >> t.second;
			x.push_back(t);
			cmp.push_back(0);
		}
		mat.push_back(x);
	}
	cout << "Dump: ";
	cin >> dump;

    TSP(n, mat, cmp, 0, dump);
    cout << endl << "Cost: " << cost << endl;
}

// 0 0 20 60 25 50 50 30 50 0
// 20 0 0 0 5 50 30 40 10 0
// 25 0 5 60 0 0 15 40 20 0
// 50 0 30 60 15 50 0 0 25 0
// 50 0 10 60 20 50 25 40 0 0