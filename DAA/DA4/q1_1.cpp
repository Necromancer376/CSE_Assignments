#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 10007;
const int INF = 1000000000;
 
vector <int> G[MAXN];
map <pii,int> M;
int col[MAXN];
 
struct max_flow
{
    
    struct edge
    {
        int a, b, cap, flow;
    };
 
    int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
    vector<edge> e;
    vector<int> g[MAXN];
 
    void add_edge (int a, int b, int cap) 
    {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back ((int) e.size());
        e.push_back (e1);
        g[b].push_back ((int) e.size());
        e.push_back (e2);
    }
 
    bool bfs()
    {
        int qh=0, qt=0;
        q[qt++] = s;
        memset (d, -1, n * sizeof d[0]);
        d[s] = 0;
        while (qh < qt && d[t] == -1)
        {
            int v = q[qh++];
            for (size_t i=0; i<g[v].size(); ++i)
            {
                int id = g[v][i],
                    to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap)
                {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }
 
    int dfs (int v, int flow)
    {
        if (!flow)  return 0;
        if (v == t)  return flow;
        for (; ptr[v]<(int)g[v].size(); ++ptr[v])
        {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1)  continue;
            int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
            if (pushed)
            {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
 
    int dinic()
    {
        int flow = 0;
        for (;;)
        {
            if (!bfs()) break;
            memset (ptr, 0, n * sizeof ptr[0]);
            while (int pushed = dfs (s, INF))
                flow += pushed;
        }
        return flow;
    }
};


void dfs(int pos)
{
    for (int i = 0; i < G[pos].size(); ++i)
    {
        if(col[G[pos][i]] == -1)
        {
            col[G[pos][i]] = 1 - col[pos];
            dfs(G[pos][i]);
        }
    }
}


int main(int argc, char const *argv[])
{
    int n,d;
    cout << "n: ";
    cin>>n;
    cout << "d: ";
    cin >>d;
    vector <pii> triplets;
    for (int i = -d; i <= d; ++i)
    {
        for (int j = -d; j <= d; ++j)
        {
            if(i*i + j*j == d*d)
            {
                triplets.push_back(pii(i,j));
            }
        }
    }

    cout << "Coordinates: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int x,y;
        cin>>x>>y;
        M[pii(x, y)] = i;
        for (int j = 0; j < triplets.size(); ++j)
        {
            int nx = x + triplets[j].first, ny = y + triplets[j].second;
            if(M.find(pii(nx,ny)) != M.end())
            {
                int id = M[pii(nx,ny)];
                G[i].push_back(id);
                G[id].push_back(i);
            }
        }
    }
    memset(col, -1, sizeof col);
    for (int i = 0; i < n; ++i)
    {
        if(col[i] == -1)
        {
            col[i] = 0;
            dfs(i);
        }
    }
 
    max_flow flow_graph;
    
    flow_graph.n = n + 2;
    flow_graph.s = n;
    flow_graph.t = n + 1;
 
    for (int i = 0; i < n; ++i)
    {
        if(col[i] == 0)
        {
            flow_graph.add_edge(flow_graph.s, i, 1);
            for (int j = 0; j < G[i].size(); ++j)
            {
                flow_graph.add_edge(i, G[i][j], 1);
            }
        }
        else
            flow_graph.add_edge(i, flow_graph.t, 1);
        
    }
    cout << endl << "Ans: " << flow_graph.dinic()<<"\n";
    return 0;
}