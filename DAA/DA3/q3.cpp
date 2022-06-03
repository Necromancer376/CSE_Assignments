#include<iostream>

using namespace std;


int max(int x, int y)
{
	return (x > y)? x: y;
}

int Solve(string s1, string s2, int x, int y)
{
	if(x == 0 || y == 0)
		return 0;

	if(s1[x-1] == s2[y-1])
	{
		return 1 + Solve(s1, s2, x-1, y-1);
	}
	else
		return max(Solve(s1, s2, x, y-1), Solve(s1, s2, x-1, y));
}


int main()
{
    string s1, s2;
    cout << "S1: ";
    cin >> s1;
    cout << "S2: ";
    cin >> s2;

    cout << "LCS length: " << Solve(s1, s2, s1.length(), s2.length()) << endl;
}