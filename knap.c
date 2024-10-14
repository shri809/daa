#include<stdio.h>
#include<stdlib.h>

int p[10];
int w[10];
int a[10][10];

int big(int a,int b)
{

  if(a>=b)
  return a;
  else
  return b;
}


int knap(int n,int m)
{
     for(int i=1;i<=n;i++)
     {
     
     	for(int j=1;j<=m;j++)
     	{
     	   if(j-w[i]<0)
     	    a[i][j]=a[i-1][j];
     	    
     	    else
     	    a[i][j]=big(a[i-1][j],p[i]+a[i][j-w[i]]);
     	
     	
     	   
     	}
     }
     return a[n][m];

}


int main()
{
int i, j, n, m, profit;
printf("Enter the number of items: ");
scanf("%d", &n);
printf("Enter the knapsack capacity: ");
scanf("%d", &m);
printf("Enter the weights and profits (weight profit) for each item:\n");
for (i = 1; i <= n; i++) {
printf("Item %d: ", i);
scanf("%d %d", &w[i], &p[i]);
}
for (i = 0; i <= n; i++) {
a[i][0] = 0;
}
for (j = 0; j <= m; j++) {
a[0][j] = 0;
}
profit = knap(n, m);
printf("Optimal profit = %d\n", profit);
return 0;




}
