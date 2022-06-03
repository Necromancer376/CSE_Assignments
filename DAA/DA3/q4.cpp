#include <iostream>
#include <vector>

using namespace std;



bool Check(int n, vector<vector<bool>> graph, int* cycle, int p)
{
	if(graph[cycle[p-1]][n] == 0)
		return false;

	for(int i=0; i<p; i++)
	{
        if(cycle[i] == n)
            return false;
	}

	return true;
}


bool HamiltonianCycle(vector<vector<bool>> graph, int* cycle, int p, int n)
{
	if(p == n)
	{
		if(graph[cycle[p-1]][cycle[0]] == 1)
			return true;
		else
			return false;
	}

	for(int i=1; i<n; i++)
	{
		if(Check(i, graph, cycle, p))
		{
			cycle[p] = i;
			if(HamiltonianCycle(graph, cycle, p+1, n) == true)
				return true;

			cycle[p] = -1;
		}
	}

	return false;
}


bool Call(vector<vector<bool>> graph, int n)
{
	int * cycle = new int[n];
	for(int i=0; i<n; i++)
		cycle[i] = -1;
	cycle[0] = 0;

	if(HamiltonianCycle(graph, cycle, 1, n) == false)
	{
		cout << "No Solution" << endl;
		return false;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			cout << cycle[i] << " ";
		}
		cout << cycle[0] << endl;
	}
	return true;
}


int main()
{
	int n;
	cout << "n: ";
	cin >> n;

	vector<vector<bool>> graph(n, vector<bool> (n));

	cout << "graph: " << endl;
	for(int i=0; i<n; i++)
	{
		vector<bool> x;
		for(int j=0; j<n; j++)
		{
			bool temp;
			cin >> temp;
			x.push_back(temp);
		}
		graph.push_back(x);
		// cycle[i] = -1;
	}
	// cycle[0] = 0;

	Call(graph, n);

	// for(int i=0; i<n; i++)
	// {
	// 	cout << cycle[i] << " ";
	// }
	// cout << cycle[0] << endl;
}

