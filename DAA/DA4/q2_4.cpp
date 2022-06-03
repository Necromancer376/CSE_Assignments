#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> sets[100];
int c = 0;

void Subsets(int n, vector<int> arr)
{    
    int num = 0;
    while(num<pow(2,n))
    {
        for(int i=0;i<n;++i)
        {
            if((num&(1<<i))!=0)
            {
                sets[c].push_back(arr[i]);
            }
        }
        ++num;
        c++;
    }            
}


void Solve(int n, int d, vector<int> arr)
{
    Subsets(n, arr);

    cout << endl << "Answer: " << endl;
    for(int i=0; i<c; i++)
    {
        int sum = 0;
        for(int j=0; j<sets[i].size(); j++)
        {
            sum += sets[i][j];
        }

        if(sum == d)
        {
            cout << "( ";
            for(int j=0; j<sets[i].size(); j++)
                cout << sets[i][j] << " ";
            cout << ")" << endl;
        }
    }
}


int main()
{
    int n, d;
    cout << "n: ";
    cin >> n;
    vector<int> arr;

    cout << "Set: ";
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "d: ";
    cin >> d;

    Solve(n, d, arr);
}
