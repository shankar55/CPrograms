#include <stdio.h>
#include <stdlib.h>
int adj[20][20],visited[20];
int n;
void depth_first_search(int v)
{
    int stack[20],top=-1,i;
    printf("%c->",v+64);
    stack[++top]=v;
    visited[v]=1;
    while(top!=-1)
    {
        v=stack[top];
        for(i=1;i<n+1;i++)
        {
            if(adj[v][i]&&!visited[i])
            {
                stack[++top]=i;
                visited[i]=1;
                printf("%c->",i+64);
                break;
            }
        }
        if(i==n+1)
            top--;
    }
}
int main()
{
    int v;
    printf("Enter no of vertices in a Graph: ");
    scanf("%d",&n);
    printf("\n Enter Graph Matrix: ");
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n Enter starting vertex: ");
    scanf("%d",&v);
    depth_first_search(v);
    return 0;
}
