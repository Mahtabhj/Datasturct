#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 100

int n, e , capacity[100][100], flow[100][100],color[100],prev[100];
int start , end , queue[102];
void enque(int a)
{
    queue[end] = a;
    end++;
    color[a]=GRAY;
}
int deque ()
{
    int a = queue[start];
    start++;
    color[a]=BLACK;
    return a;
}
int bfs (int head, int point) {
    int u,v;
    for (u=0; u<n; u++) {
	color[u] = WHITE;
    }
    start = end = 0;
    enque(head);
    prev[head] = -1;
    while (start!=end) {
	u = deque();
	for (v=0; v<n; v++) {
	    if (color[v]==WHITE && capacity[u][v]-flow[u][v]>0) {
		enque(v);
		prev[v] = u;
	    }
	}
    }
    return color[point]==BLACK;
}
int min (int x, int y) {
    return x<y ? x : y;
}
int maximum_flow (int source, int sink) {
    int i,j,u;
    int maximum_flow = 0;
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    flow[i][j] = 0;
	}
    }
    while (bfs(source,sink)) {
    int inc = 100000000;
	for (u=n-1; prev[u]>=0; u=prev[u]) {
	    inc = min(inc,capacity[prev[u]][u]-flow[prev[u]][u]);
	}
	for (u=n-1; prev[u]>=0; u=prev[u]) {
	    flow[prev[u]][u] += inc;
	    flow[u][prev[u]] -= inc;
	}
	maximum_flow += inc;
    }
    return maximum_flow;
}
int main()
{
    int a,b,c;
    printf("Enter number of nodes and edges = ");
    scanf("%d %d",&n,&e);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            capacity[i][j]=0;
        }
    }
    printf("Enter capacities = ");
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        capacity[a][b]= c;
    }
    printf("\n Enter source and sink = ");
    int s=0,t=n-1;
    scanf("%d %d",&s,&t);
    int maxflow = maximum_flow(s,t);
    printf("Max flow = %d",maxflow);

}
