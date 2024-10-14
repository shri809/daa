#include<stdio.h>
#include<stdlib.h>

void bfs(int vis[10],int a[10][10],int src,int n)
{
  int q[10];
  int f=0;
  int r=-1;
  
   vis[src]=1;
   q[++r]=src;
   while(f<=r)
   {
    int node=q[f++];
      for(int i=1;i<=n;i++)
      {
         if(!vis[i] && a[node][i]==1)
         {
            vis[i]=1;
            q[++r]=i;
         }
      }
   
   }
   
}

 int main()
{
    int n, a[10][10], i, v[10] = {}, j, count = 0;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // the printing of the graph is optional
    printf("\nThe grpah is as follows :\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n"); 
    }

    for (i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            bfs(v,a,i,n);
            count++;
        }
    }
    if (count == 1)
        printf("\nThe graph is connected\n");
    else
        printf("\nThe graph is not connected and has %d componenets\n", count);
    return 0;
}
