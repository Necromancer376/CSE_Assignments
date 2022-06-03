#include <bits/stdc++.h>

using namespace std;


bool isSafe(int n, vector<vector<bool>> graph, int node, vector<int> path, int pos)
{
    if(graph[path[pos-1]][node] == 0)
        return false;

    for(int i=0; i<pos; i++)
        if(path[i] == node)
            return false;

    return true;
}


bool Utility(int n, vector<vector<bool>> graph, vector<int> &path, int pos)
{
    if(pos == n)
    {
        if(graph[path[pos-1]][path[0]] == 1)
            return true;

        return false;
    }

    for(int i=1; i<n; i++)
    {
        if(isSafe(n, graph, i, path, pos))
        {
            path[pos] = i;

            if(Utility(n, graph, path, pos+1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}


void Solve(int n, vector<vector<bool>> graph)
{
    vector<int> path;

    for(int i=0; i<n; i++)
        path.push_back(0);
    path[0] = 0;

    if(Utility(n, graph, path, 1) == false)
    {
        cout << "No Solution" << endl;
        return;
    }

    cout << "Solution: " << endl;
    for(int i=0; i<n; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}


int main()
{
    int n;
    vector<vector<bool>> graph;

    cout << "n: ";
    cin >> n;
    cout << "Graph:" << endl;
    for(int i=0; i<n; i++)
    {
        vector<bool> temp;
        for(int j=0; j<n; j++)
        {
            bool x;
            cin >> x; 
            temp.push_back(x);
        }
        graph.push_back(temp);
    }

    Solve(n, graph);
}

// 0 1 0 1 0 0 0
// 1 0 1 1 1 1 0
// 0 1 0 0 1 0 0
// 1 1 0 0 1 0 1
// 0 1 1 1 0 0 1
// 0 1 0 0 0 0 0
// 0 0 0 1 1 0 1


// 0 1 0 1 0
// 1 0 1 1 1
// 0 1 0 0 1
// 1 1 0 0 1
// 0 1 1 1 0
