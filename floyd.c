#include<stdio.h>
#include<stdlib.h>

void print(int d[10][10],int n)
{
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         if(d[i][j]>=999)
          printf("INF ");
          
          else 
          printf("%d\t",d[i][j]);
      
      }
      printf("\n");
   }
}
void floyd(int g[10][10],int d[10][10],int n)
{
    for(int k=1;k<=n;k++)
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    		   if(d[i][k]+d[k][j]<d[i][j])
    		   {
    		       d[i][j]=d[i][k]+d[k][j];
    		   }
    		
    		}
    	}
    }



print(d,n);


}



 int main() {
    int n;
    int g[10][10];
    int d[10][10];

    // Input the number of vertices
    printf("Enter the number of vertices (n <= 10): ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (use 999 for INF):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            d[i][j] = g[i][j];  // Copy input matrix to distance matrix
        }
    }

    // Run Floyd-Warshall algorithm
    floyd(g, d, n);

    return 0;
}



