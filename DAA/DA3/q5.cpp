#include <bits/stdc++.h>

using namespace std;


int n;

bool isValid(vector<vector<int>> &board, int r, int c)
{
	int i, j;
	for(i=0; i<c; i++)
		if(board[r][i])
			return false;

	for(i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if(board[i][j])
			return false;

	 for (i = r,j = c; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool Solve(vector<vector<int>> &board, int c)
{
	if(c >= n)
		return true;

	for(int i=0; i<n; i++)
	{
		if(isValid(board, i, c))
		{
			board[i][c] = 1;

			if(Solve(board, c+1))
				return true;

			board[i][c] = 0;
		}
	}

	return false;
}


int main()
{
	cout << "N: ";
	cin >> n;

	vector<vector<int>> board(n, vector<int> (n));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			board[i][j] = 0;


	if(Solve(board, 0) == false)
	{
		cout << "No Solution" << endl;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	
	return 0;	
}