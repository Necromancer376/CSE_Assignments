#include<stdio.h>
#include<stdlib.h>


int *dfs;
int c = -1;

void DFS(int nodes, int graph[nodes][nodes], int visited[nodes], int start)
{
    *(dfs + ++c) = start;
    visited[start] = 1;

    for(int i=0; i<nodes; i++)
        if(!visited[i] && graph[start][i] == 1)
            DFS(nodes, graph, visited, i);
}


int main()
{
    int nodes, start;
    printf("Number of Nodes: ");
    scanf("%d", &nodes);
    int graph[nodes][nodes];
    int visited[nodes];
    dfs = (int*)malloc(nodes * sizeof(int));

    printf("Adjecency Matrix: \n");
    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            scanf("%d", &graph[i][j]);

    printf("Starting node: ");
    scanf("%d", &start);

    for(int i=0; i<nodes; i++)
        visited[i] = 0;

    DFS(nodes, graph, visited, start);

    printf("\n-----------------------\n" );
    
    printf("DFS: ");
    for(int i=0; i <= c; i++)
        printf("%d, ", *(dfs + i));

    printf("\n-----------------------\n" );

    return 0;
}