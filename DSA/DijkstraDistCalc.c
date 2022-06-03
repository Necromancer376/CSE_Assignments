#include <stdio.h>
#include <stdlib.h>




int minDist(int nodes, int dist[nodes], bool set[nodes])
{
    int min = INT_MAX, minIndex;

    for(int i=0; i<nodes; i++)
    {
        if(!set[i] && dist[i] <= min)
            min = dist[i], minIndex;
    }

    return minIndex;
}


void Dijkstra(int nodes, int graph[nodes][nodes], start)
{
    int distance[nodes];
    bool set[nodes];

    for(int i=0; i<nodes; i++)
    {
        distance[i] = INT_MAX, set[i] = false;
        distance[start] = 0;
    }

    for(int i=0; i<nodes; i++)
    {
        int temp = minDist(nodes, distance, set);
        set[temp] = true;
        for(int j=0; j<nodes; j++)
            if(!set[j] && graph[i][j] && distance[temp] != INT_MAX && distance[temp] + graph[temp][j] < distance[j])
                distance[j] = distance[temp] + graph[i][j];
    }
}


void Print(int nodes, int dist[nodes])
{
    for(int i=0; i<nodes; i++)
        printf("%d\t%d\n", i, dist[i]);
}


int main(void)
{

}