#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class node
{
public:
    int x, y;
};

node n0;

void swap(node &n1, node &n2)
{
    node temp = n1;
    n1 = n2;
    n2 = temp;
}


node getSecond(stack<node> &stk)
{
    node temp = stk.top();
    stk.pop();
    node ret = stk.top();
    stk.push(temp);

    return ret;
}


int getDistSq(node n1, node n2)
{
    return (n1.x - n2.x)*(n1.x - n2.x) + (n1.y - n2.y)*(n1.y - n2.y);
}


int getDir(node n1, node n2, node n3)
{
    int ang = (n2.y - n1.y)*(n3.x - n2.x) - (n2.x - n1.x)*(n3.y - n2.y);

    if(ang == 0)
        return 0;
    return (ang > 0) ? 1 : 2;
}


int cmp(const void *vn1, const void *vn2)
{
    node *n1 = (node *)vn1;
    node *n2 = (node *)vn2;

    int ang = getDir(n0, *n1, *n1);

    if(ang == 0)
        return (getDistSq(n0, *n2) >= getDistSq(n0, *n1)) ? -1 : 1;

    return (ang == 2)? -1 : 1;
}


void grahamScan(int n, node nodes[])
{
    int low_y = nodes[0].y;
    int min = 0;
    for(int i=1; i<n; i++)
    {
        int y = nodes[i].y;

        if((y < low_y) || (low_y == y && nodes[i].x < nodes[min].x))
        {
            low_y = nodes[i].y;
            min = i;
        }
    }
    
    swap(nodes[0], nodes[min]);

    n0 = nodes[0];
    qsort(&nodes[1], n-1, sizeof(node), cmp);

    int m = 1;

    for(int i=1; i<n; i++)
    {

        while(i < n-1 && getDir(n0, nodes[i], nodes[i+1]) == 0)
            i++;


        nodes[m] = nodes[i];
        m++;
    }


    if(m < 3)
    {
        cout << "abort" << endl;
        return;
    }

    stack<node> stk;
    stk.push(nodes[0]);
    stk.push(nodes[1]);
    stk.push(nodes[2]);

    for(int i=3; i<n; i++)
    {
        while(stk.size() > 1 && getDir(getSecond(stk), stk.top(), nodes[i]) != 2)
        {
            stk.pop();
        }
        stk.push(nodes[i]);
    }

    while(!stk.empty())
    {
        node temp = stk.top();
        cout << "(" << temp.x << ", " << temp.y << ")" << endl;
        stk.pop();
    }
}


int main(void)
{
    int n;
    cout << "n: ";
    cin >> n;

    node nodes[n];

    cout << "Nodes: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nodes[i].x >> nodes[i].y;
    }

    grahamScan(n, nodes);
}

// 0 3
// 1 1
// 2 2
// 4 4
// 0 0
// 1 2
// 3 1
// 3 3
