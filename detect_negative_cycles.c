#include<stdio.h>

typedef struct edge
{
  int source;
  int dest;
  int weight;
} edges;

int main()
{
  int n , e ;
  printf("Enter number of nodes and edges = ");
  scanf("%d %d",&n,&e);

  edges edge[e];

  printf("Enter edges with weight = ");

  int i;

  for(i=0;i<e;i++)
  {
      scanf("%d %d %d",&edge[i].source,&edge[i].dest,&edge[i].weight);

  }
  for(i=0;i<e;i++)
  {
      printf("\n%d %d %d",edge[i].source,edge[i].dest,edge[i].weight);

  }
  int dis[n];
  int par[n];
  dis[0]=0;

  for(i=1;i<n;i++)
  {
      dis[i]=9999;
  }

  //Relaxation

  int j=0;
  for(j=0;j<n-1;j++)
  {
      for(i=0;i<e;i++)
      {
          if(dis[edge[i].dest]>dis[edge[i].source]+ edge[i].weight)
          {
             dis[edge[i].dest] =  dis[edge[i].source]+ edge[i].weight ;
             par[edge[i].dest] = edge[i].source;
          }
      }
  }
  int cycle = 0;
  int keep = -1;
  for(i=0;i<e;i++)
  {
      if(dis[edge[i].dest]>dis[edge[i].source]+ edge[i].weight)
          {
             cycle++;
             keep = edge[i].dest;
             break;
          }
  }

  if(keep!=-1)
  {
      for(i=0;i<n;i++)
      {
          keep = par[keep];
      }

      vector<int> loop;
      for(int v = keep;;v=par[v])
      {
          loop.push_back(v);
          if(v==C && loop.size()>1)
          {
              break;
          }
          reverse(loop.begin(),loop.end());
          for(int v : loop)
          {
              printf("%d ",v);
          }
          printf("\n");
      }
  }
  else {
    printf("-1");
  }
  printf("Cycles = %d",cycle);
}
