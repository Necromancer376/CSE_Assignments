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
	nh = Least(n, mat, cmp, loc);
	
	if(nh == INT_MAX)
	{
		nh = 0;
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
	vector<vector<int>> sym_mat;
	vector<int> sym_cmp;
	vector<vector<int>> asym_mat;
	vector<int> asym_cmp;

	for(int i=0; i<n; i++)
	{
		vector<int> x;
		for(int j=0; j<n; j++)
		{
			int temp;
			cin >> temp;
			x.push_back(temp);
			sym_cmp.push_back(0);
			asym_cmp.push_back(0);
		}
		sym_mat.push_back(x);
		asym_mat.push_back(x);
	}

	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			sym_mat[j][i] = sym_mat[i][j];
		}
	}

	cout << endl << "Symetric: " << endl;
    TSP(n, sym_mat, sym_cmp, 0);
    cout << "Cost: " << cost << endl;

    cost = 0;
    cout << endl << "Asymetric: " << endl;
    TSP(n, asym_mat, asym_cmp, 0);
    cout << "Cost: " << cost << endl;

}

// 0 10 15 20
// 5 0 10 15
// 10 20 0 15
// 5 10 15 0


// #include <bits/stdc++.h>

// using namespace std;


// int TSP(vector<vector<pair<int, int>>> mat, int s)
// {
// 	vector<int> node;
// 	int n = mat[0].size();

// 	for(int i=0; i<n; i++)
// 		if(i != s)
// 			node.push_back(i);

// 	int minP = INT_MAX;

// 	do 
// 	{
// 		int pw = 0;
// 		int temp = s;
// 		for(int i=0; i<node.size(); i++)
// 		{
// 			if(temp < node[i])
// 				pw += mat[temp][node[i]].first;
// 			else
// 				pw += mat[temp][node[i]].second;
// 			temp = node[i];
// 		}

// 		pw += mat[temp][s].first;

// 		minP = min(minP, pw);

// 	}while(next_permutation(node.begin(), node.end()));

// 	return minP;
// }


// int main()
// {
// 	int n;
// 	cout << "nodes: ";
// 	cin >> n;
// 	vector<vector<pair<int, int>>> mat;

// 	for(int i=0; i<n; i++)
// 		for(int j=0; j<n; j++)
// 			cin >> mat[i][j].first >> mat[i][j].second;

//     cout << TSP(mat, 0) << endl;

// }