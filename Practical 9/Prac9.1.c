#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int v){
    printf("%d ",v);
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && visited[i]==0)
            DFS(i);
    }
}
void BFS(int start){
    int queue[MAX];
    int front=0,rear=0;
    for(int i=0;i<n;i++)
        visited[i]=0;
    queue[rear++]=start;
    visited[start]=1;
    while(front<rear){
        int v=queue[front++];
        printf("%d ",v);
        for(int i=0;i<n;i++){
            if(graph[v][i]==1 && visited[i]==0){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}
int main(){
    int edges,u,v,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        scanf("%d%d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("DFS: ");
    DFS(start);
    printf("\nBFS: ");
    BFS(start);
    return 0;
}