#include<stdio.h>
#include<stdlib.h>


void prims(int a[10][10],int n)
{

  int i,j,min,mincost,e;
  int v,u;
  int vis[n];
  mincost=0;
  for(int i=1;i<=n;i++)
  {
     vis[i]=0;
  }
  
  vis[1]=1;
  e=0;
  while(e<n-1)
  {
     min=999;
     for(int i=1;i<=n;i++)
     {
         if(vis[i])
         {
            for(int j=1;j<=n;j++)
            {
               if(!vis[j] && a[i][j]<min)
               {
                  min=a[i][j];
                  u=i;
                  v=j;
               
               }
            
            
            }
         
         
         
         }
     
     
     }
     if(!vis[v])
     {
        mincost+=min;
        printf("edge %d -> %d , cost =%d",u,v,min);
        e++;
        vis[v]=1;
     }
     a[v][u]=a[u][v]=999;
  }
  printf("\n\ncost %d",mincost);


}

int main()
{
    int n, i, j, cost[10][10];
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n Enter the elements of row %d\n", i);
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
             
        }
    }
    prims(cost,n);
    return 0;
}


