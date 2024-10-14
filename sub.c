#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int x[10];
int w[10];
int count;
int r;
int d;

clock_t start, end;
void sumSubset(int k,int s,int r)
{  x[k]=1;
   static int b=1;
if(w[k]+s==d)
{

 printf("Subset %d\n",b++);
      for(int i=1;i<=k;i++)
      {
               if(x[k]==1)
               {
                 printf("%d\t",w[i]);
               }
      }
      printf("\n");

}
else if( s+w[k]+w[k+1]<=d)
{   count++;
    sumSubset(k+1,s+w[k],r-w[k]);
}

else if( (s+r-w[k]>=d ) && (s+w[k+1]<=d))
{
   x[k]=0;
   count++;
   sumSubset(k+1,s,r-w[k]);
}
}

int main()
{
    int n, i, sum = 0;
    printf("\nSUBSET PROBLEM\n");
    printf("\nEnter the number of elements - ");
    scanf("%d", &n);
    printf("\nEnter the elements (in increasing order) - ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("\nEnter the subset sum  value required - ");
    scanf("%d", &d);
    if (sum < d || w[1] > d)
    {
        printf("\nNo subsets possible!!\n");
        exit(0);
    }
    start = clock();
    sumSubset(1, 0, sum);
    end = clock();
    printf("\nTime=%.8fs Count=%d", (double)(end - start) / CLOCKS_PER_SEC, count);
    return (0);
}





