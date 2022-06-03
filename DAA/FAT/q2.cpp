#include <iostream>
#include <limits>
#include <cfloat>

using namespace std;


class point
{
public:
	double x, y;
};

class line
{
public:
	double a, b, c;
};

point getPoint(line l1, line l2)
{
	point inter;

	double x1 = (l1.b * l2.c - l2.b * l1.c);
	double x2 = (l1.a * l2.b - l2.a * l1.b);
	double y1 = (l1.c * l2.a - l2.c * l1.a);
	double y2 = (l1.a * l2.b - l2.a * l1.b);

	if(x2 == 0 || y2 == 0)
	{
		inter.x = DBL_MAX;
		inter.y = DBL_MAX;
		return inter;
	}

	inter.x = x1 / x2;
	inter.y = y1 / y2;

	return inter;
}


void Solve(int n, line arr[])
{
	bool c1 = false, c2 = false, c3 = false;
	int numHit = 0;
	int numMiss = 0;

	for(int i=0; i<n; i++)
	{
		point out;
		for(int j=i; j<n; j++)
		{
			if(i != j)
			{
				out = getPoint(arr[i], arr[j]);
				
				cout << i << '-' << j << ":  ";
				if(out.x == DBL_MAX)
				{
					cout << "No Intersection" << endl;
					numMiss++;
				}
				else
				{
					cout << "(" << out.x << ", " << out.y << ")" << endl;
					numHit++;
				}
			}
		}
	}

	cout << endl;
	if(numMiss > 0)
	{
		c1 = true;
		cout << "Parallel line never meet" << endl;
	}

	if(numHit >= 1)
	{
		c2 = true;
		 cout << "Perpendicular lines always coincide" << endl;
	}

	if(numHit > 1)
	{
		c3 = true;
		cout << "3+ intersecting lines have 2+ intersecting points" << endl;
	}

	if(c1 && c2 && c3)
		cout << endl << "All three Statements are true" << endl << endl;
}


int main()
{
	int n;
	cout << "n: ";
	cin >> n;

	line arr[n];

	cout << "Line[a b c]: " << endl;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
	}

	cout << endl << "Intersection points: " << endl;
	Solve(n, arr);
}