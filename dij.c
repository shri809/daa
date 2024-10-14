#include<stdio.h>
#include<stdlib.h>
 
 

void dij(int a[10][10],int d[10],int vis[10],int n,int src)
{
  int u;
   for(int i=1;i<=n;i++)
   {
       
     int min=999;
     
      	for(int j=1;j<=n;j++)
      	{
      	    if(d[j]<min)
      	    {
      	       min=d[j];
      	       u=j;
      	    }
      	}
      	
      	vis[u]=1;
      	
      	for(int j=1;j<=n;j++)
      	{
      	   if(vis[j]==0 && d[j]>d[u]+a[u][j] )
      	   d[j]=d[u]+a[u][j];
      	   
      	
      	}
   
   }

}



int main()
{ 
   int n,cost[10][10],sourceNode,v[10],d[10];
int i, j;
printf("Enter no of vertices: ");
scanf("%d",&n);
printf("Enter Cost Adjacency matrix:\n");
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf("%d",&cost[i][j]);
printf("Enter the source (%d to %d):\n",1,n);
scanf("%d",&sourceNode);
for(i=1; i<=n; i++)
{
d[i] = cost[sourceNode][i];
v[i] = 0;
}
dij(cost,d,v,n,sourceNode);
printf("Shortest distance from %d\n\n",sourceNode);
for(i=1; i<=n; i++)
printf("%d --> %d = %d\n\n",sourceNode,i,d[i]);
return 0;



}
