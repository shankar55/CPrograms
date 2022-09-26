#include <stdio.h>
#include <stdlib.h>
int n,rear=-1,front=-1;
int i,j;
int adj[20][20],visited[20],queue[20];
void bfs(int v)
{
    queue[++rear]=v;
    visited[v]=1;
    while(rear!=front)
    {
        v=queue[++front];
        printf("%c\t",v+64);
        for(i=1;i<n+1;i++)
        {
            if(adj[v][i]&&!visited[i])
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int v;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    for(i=1;i<n+1;i++)
    {
        queue[i]=0;
        visited[i]=0;
    }
    printf("\n Enter adjacency matrix: ");
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    bfs(v);
    return 0;
}
