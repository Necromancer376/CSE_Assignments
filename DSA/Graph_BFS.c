#include<stdio.h>
#include <stdlib.h>

int *bfs;
int c = -1, f = 0;
int queue[100];
int pointer = 0;
int current = -1;


void Enqueue(int n)
{
    queue[pointer] = n;
    pointer++;
}


void BFS(int nodes, int graph[nodes][nodes], int visited[nodes], int start)
{
    visited[start] = 1;
    Enqueue(start);
    current++;
    while(pointer > current)
    {
        start = queue[current];
        *(bfs + ++c) = start;
        for(int i=0; i<nodes; i++)
        {
             if(graph[start][i] && !visited[i])
            {
                visited[i] = 1;
                Enqueue(i);
            }
        }
        current++;
    }
}


int main()
{
    int nodes, start;
    printf("Number of Nodes: ");
    scanf("%d", &nodes);
    int graph[nodes][nodes];
    int visited[nodes];
    bfs = (int*)malloc((nodes+1) * sizeof(int));

    printf("Adjecency Matrix: \n");
    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            scanf("%d", &graph[i][j]);

    for(int i=1; i<=nodes; i++)
    {
        visited[i] = 0;
        *(bfs + i) = 0;
    }

    printf("Starting Node: ");
    scanf("%d", &start);

    BFS(nodes, graph, visited, start);

    printf("\n-----------------------\n" );
    printf("BFS: ");
    for(int i = 0; i <= c; i++)
    {
        printf("%d", *(bfs + i));
    }

    printf("\n-----------------------\n" ); 

    return 0;
}


// 0 1 1 0 0 0 
// 1 0 1 1 0 0
// 1 1 0 1 1 0
// 0 1 1 0 1 1
// 0 0 1 1 0 0
// 0 0 0 1 0 0
// 0 1 2 3 


// 0 1 1 1 0 0
// 1 0 0 1 1 0
// 1 0 0 1 0 1
// 1 1 1 0 1 1
// 0 1 0 1 0 1
// 0 0 1 1 1 0
// 
// dfs 0 1 3 4 2 5
// 1 0 3 4 2 5

// 0 1 1 0 0 0
// 1 0 0 1 1 0
// 1 0 0 0 1 0
// 0 1 0 0 1 1
// 0 1 1 1 0 1
// 0 0 0 1 1 0