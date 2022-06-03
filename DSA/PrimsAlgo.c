#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int nodes;
    int c = 1, mCount = 0;
    int min, x1, y1, x2, y2;
    int total = 0;

    printf("Number of Nodes: ");
    scanf("%d", &nodes);

    int graph[nodes][nodes];
    int visited[nodes];
    int MST[nodes];
    MST[mCount] = 0;

    printf("Graph: \n");
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = 999;
        }
        visited[i] = 0;
    }

    visited[0] = 1;
    printf("\nEdge\tCost\n");

    while(c < nodes)
    {
        for(int i=0, min=999; i<nodes; i++)
        {
            for(int j=0; j<nodes; j++)
            {
                if(graph[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = graph[i][j];
                        x1 = x2 = i;
                        y1 = y2 = j;
                    }
                }
                if(visited[x2] == 0 || visited[y2] == 0)
                {
                    printf("\n%d: %d-%d\t%d", c++, x1, y1, min);
                    total += min;
                    visited[y1] = 1;
                    MST[++mCount] = y1;
                }
            }
        }
        graph[x1][y1] = 999;
        graph[y1][x1] = 999;
    }
    printf("\nMinimum Cost: %d\n\nMST: ", total);

    for(int i=0; i<nodes; i++)
        printf("%d, ", MST[i]);

    printf("\n");
}




// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6
// 0 0 4 2 6 0