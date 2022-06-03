#include <iostream>
#include <vector>

using namespace std;


bool isSafe(int n, vector<vector<int>> maze, int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y] == 1)
        return true;

    return false;
}


bool Utility(int n, vector<vector<int>> maze, int x, int y, vector<vector<int>> &soln)
{
    if(x == n-1 && y == n-1 && maze[x][y] == 1)
    {
        soln[x][y] = 1;
        return true;
    }

    if(isSafe(n, maze, x, y) == true)
    {
        if(soln[x][y] == 1)
            return false;

        soln[x][y] = 1;
        if(Utility(n, maze, x+1, y, soln) == true)
            return true;

        if(Utility(n, maze, x, y+1, soln) == true)
            return true;

        soln[x][y] = 0;
        
        return false;
    }

    return false;
}

void Solve(int n, vector<vector<int>> maze)
{
    vector<vector<int>> soln;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            temp.push_back(0);
        }
        soln.push_back(temp);
    }

    if(Utility(n, maze, 0, 0, soln) == false)
    {
        cout << "No Solution" << endl;
        return;
    }

    cout << "Solution: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    vector<vector<int>> maze;

    cout << "n: ";
    cin >> n;
    cout << "Maze:" << endl;

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            int x;
            cin >> x; 
            temp.push_back(x);
        }
        maze.push_back(temp);
    }

    Solve(n, maze);
}

// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1

// 1 0 0 0 0 0 0 0
// 1 0 0 1 1 1 0 1
// 1 1 0 1 0 1 1 0
// 0 1 1 1 0 1 0 1
// 0 1 0 0 1 1 0 0
// 1 0 1 0 1 0 0 1
// 1 1 0 0 1 1 1 0
// 1 0 0 1 0 0 1 1

// 1 0 0 0 0 0 0 0
// 1 0 0 1 1 1 0 1
// 1 1 0 0 0 1 1 0
// 0 1 1 1 0 1 0 1
// 0 0 0 1 1 0 0 0
// 1 0 1 0 1 0 0 1
// 1 1 0 0 1 1 1 0
// 1 0 0 1 0 0 1 1