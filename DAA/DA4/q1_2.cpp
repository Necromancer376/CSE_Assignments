#include <bits/stdc++.h>

using namespace std;


bool BFS(int n, vector<vector<int>> graph, int start, int t, int par[])
{
	bool visited[n];
	memset(visited, 0, sizeof(visited));

	queue<int> que;
	que.push(start);
	visited[start] = true;
	par[start] = -1;

	while(!que.empty())
	{
		int x = que.front();
		que.pop();

		for(int i=0; i<n; i++)
		{
			if(visited[i] == false && graph[x][i] > 0)
			{
				if(i == t)
				{
					par[i] = x;
					return true;
				}
				que.push(i);
				par[i] = x;
				visited[i] = true;
			}
		}
	}

	return false;
}


int FordFulkerson(int n, vector<vector<int>> graph, int start, int t)
{
	vector<vector<int>> resGrph;
	for(int i=0; i<n; i++)
	{
		vector<int> temp_vect;
		for(int j=0; j<n; j++)
		{
			temp_vect.push_back(graph[i][j]);
		}
		resGrph.push_back(temp_vect);
	}

	int par[n];
	int ans = 0;

	while(BFS(n, resGrph, start, t, par))
	{
		int path = INT_MAX;

		for(int i=t; i != start; i = par[i])
		{
			int temp = par[i];
			path = min(path, resGrph[temp][i]);
		}

		for(int i=t; i != start; i = par[i])
		{
			int temp = par[i];
			resGrph[temp][i] -= path;
			resGrph[i][temp] += path;
		}

		ans += path;
	}

	return ans;
}


int main()
{
	int n, start, end;
	vector<vector<int>> graph;

	cout << "n: ";
	cin >> n;
	cout << "Graph:" << endl;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for(int j=0; j<n; j++)
		{
			int x;
			cin >> x; 
			temp.push_back(x);
		}
		graph.push_back(temp);
	}

	cout << "Start: ";
	cin >> start;
	cout << "End: ";
	cin >> end;

	cout << "Max: " << FordFulkerson(n, graph, start, end) << endl;
}


// 0 13 10 10 0 0 0 0
// 0 0 0 0 24 0 0 0 
// 0 5 0 15 0 0 7 0
// 0 0 0 0 0 0 15 0 
// 0 0 0 0 0 1 0 9
// 0 0 0 0 0 0 6 13
// 0 0 0 0 0 0 0 16
// 0 0 0 0 0 0 0 0