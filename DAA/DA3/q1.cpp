#include <bits/stdc++.h>


using namespace std;


bool isOp(char op)
{
    return (op == '+' || op == '-');
}


int main()
{
    string expr;
    cout << "Expression: ";
    cin >> expr;

    vector<int> nums;
    vector<char> op;
    string temp = "";
 
    for (int i=0; i<expr.length(); i++)
    {
        if (isOp(expr[i]))
        {
            op.push_back(expr[i]);
            nums.push_back(atoi(temp.c_str()));
            temp = "";
        }
        else
        {
            temp += expr[i];
        }
    }

    nums.push_back(atoi(temp.c_str()));
 
    int l = nums.size();
    int minVal[l][l];
    int maxVal[l][l];
 
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            minVal[i][j] = INT_MAX;
            maxVal[i][j] = 0;
 
            if (i == j)
                minVal[i][j] = maxVal[i][j] = nums[i];
        }
    }
 

    for (int L = 2; L <= l; L++)
    {
        for (int i = 0; i < l - L + 1; i++)
        {
            int k = i + L - 1;
            for (int j = i; j < k; j++)
            {
                int minTemp = 0, maxTemp = 0;
 
                if(op[j] == '+')
                {
                    minTemp = minVal[i][j] + minVal[j + 1][k];
                    maxTemp = maxVal[i][j] + maxVal[j + 1][k];
                }
 

                else if(op[j] == '-')
                {
                    minTemp = minVal[i][j] - minVal[j + 1][k];
                    maxTemp = maxVal[i][j] - maxVal[j + 1][k];
                }
 
                if (minTemp < minVal[i][k])
                    minVal[i][k] = minTemp;
                if (maxTemp > maxVal[i][k])
                    maxVal[i][k] = maxTemp;
            }
        }
    }
 
    cout << "Min: " << minVal[0][l-1] << endl;
    cout << "Max: " << maxVal[0][l-1] << endl;;

    return 0;
}