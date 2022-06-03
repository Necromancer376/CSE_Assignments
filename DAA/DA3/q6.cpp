#include <iostream>

using namespace std;


bool Check(string t, string c)
{
	int l1 = t.size();
	int l2 = c.size();

	for(int i=0; i<l1-l2; i++)
	{
		bool flag = false;
		for(int j=0; j<l2; j++)
		{
			if(c[j] != t[i+j])
			{
				flag = true;
				break;
			}
		}

		if(!flag)
			return true;
	}

	return false;
}


int main()
{
	string c, t;

	cout << "Text: ";
	cin >> t;
	cout << "C: ";
	cin >> c;

	if(Check(t, c))
		cout << "Match Found" << endl;
	else
		cout << "No Match Found" << endl;
}