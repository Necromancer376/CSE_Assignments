#include<iostream>

using namespace std;

int n = 1;
int mat[50][50];


template<typename F>
F getMax()
{
    int subSize;
    int offCount;
    F max = 0;

    for(subSize = n; subSize >= 1; subSize--)
    {
        offCount = n - subSize + 1;
        for(int ioff = 0; ioff < offCount; ioff++)
        {
            for(int joff = 0; joff < offCount; joff++)
            {
                int temp = mat[ioff][joff];
                int c = 0;
                for(int i=0; i<subSize; i++)
                {
                    for(int j=0; j<subSize; j++)
                    {
                        if(mat[i + ioff][j + joff] == temp)
                            c++;
                    }
                }
                if(c == subSize*subSize)
                {
                    if(subSize > max)
                        max = subSize;
                }
            }
        }
    }

    return max;
}


template<typename T>
void getInput(T n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << getMax<int>() << endl;
}


int main()
{
    cin >> n;
    getInput(n);
}