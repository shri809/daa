#include<stdio.h>
#include<stdlib.h>
int count;
int cycle=0;
int topo[10];
int k=0;
void dfs(int a[10][10],int vis[10],int src,int n)
{
    vis[src]=1;
    for(int i=0;i<n;i++)
    {
        if(a[src][i]==1)
         {
            if(vis[i]==1)
            {
                   cycle=1;
                   return;
            }
            if(vis[i]==0)
            {
                   dfs(a,vis,i,n);
                   if(cycle==1)
                   return;
            }
         }
    }

    vis[src]=2;
    topo[++k]=src;

}


int main()
{
    int a[10][10];
    int vis[10];
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacentcy matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    vis[i]=0;
      for(int i=0;i<n;i++)
      {
        if(vis[i]==0)
        {
            dfs(a,vis,i,n);
            if(cycle==1)
            break;
        }
      }

      if(cycle==1)
      printf("Cycle detected\n");

      else
      {
        for(int i=k;i>=1;i--)
        {
            printf("%d\t",topo[i]);
        }
      }




}
