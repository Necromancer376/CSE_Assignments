#include <stdio.h>
#include <stdlib.h>


int Find(int nodes, int parents[nodes], int z)
{
    while(parents[z])
        z = parents[z];

    return z;
}


int isUnique(int nodes, int parents[nodes], int i, int j)
{
    if(i != j)
    {
        parents[j] = i;
        return 1;
    }

    return 0;
}


int main(void)
{
    int c = 1, total = 0, mCount = 0;
    int min, x1, y1, x2, y2;
    int nodes;

    printf("Number of Nodes: ");
    scanf("%d", &nodes);

    int graph[nodes][nodes];
    int parents[nodes], MST[nodes];

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
        parents[i] = 0;
    }

    printf("\nEdge\tCost\n");
    while(c < nodes)
    {
        min = 999;
        for(int i=0; i<nodes; i++)
        {
            for(int j=0; j<nodes; j++)
            {
                if(graph[i][j] < min)
                {
                    min = graph[i][j];
                    // printf("\nm0: %d,%d,%d\n", min, i, j);
                    x1 = x2 = i;
                    y1 = y2 = j;
                }
                // printf("\nm1: %d\n", min);
            }
        }
        // printf("\nm2: %d\n", min);

        x2 = Find(nodes, parents, x2);
        y2 = Find(nodes, parents, y2);

        // printf("\nm2: %d\n", min);
        if(isUnique(nodes, parents, x2, y2))
        {
            // printf("\nm3: %d\n", min);
            printf("\n%d: %d-%d\t%d", c++, x1, y1, min);
            total += min;
            MST[++mCount] = y1;
        }
        graph[x1][y1] = 999;
        graph[y1][x1] = 999;
    }

    printf("\nMinimum Cost: %d\n\nMST: ", total);

    for(int i=0; i<nodes; i++)
        printf("%d, ", MST[i]);

    printf("\n");
}



// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0