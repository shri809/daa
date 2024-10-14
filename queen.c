#include<stdio.h>
#include<stdlib.h>

 
int x[10];
int place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
       if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
       {
          return 0;
       }
    
    }
    return 1;
}

void printQueen(int n)
{
   int i,j;
   static int b=1;
        printf("\n\nSolution %d\n\n",b++);
        
   for(int i=1;i<=n;i++)
   printf("\t%d",i);
   
   for(int i=1;i<=n;i++)
   {
     printf("\n\n%d",i);
      
     for(int j=1;j<=n;j++)
     {
        if(x[i]==j)
        {
          printf("\tQ");
        }
        else {
            printf("\t-");
        }
     }
    
     
      
   }
   printf("\n");

}

void nqueen(int k, int n)
{
   for(int i=1;i<=n;i++)
   {
      if(place(k,i))
      {
         x[k]=i;
         if(k==n)
         {
            printQueen(n);
             
         }
         else
           nqueen(k+1,n);
      }
         
   }

}

int main()
{
    int n;
    printf("\nN-QUEEN PROBLEM\n");
    printf("\nEnter the number of queens to be placed - ");
    scanf("%d", &n);
    if (n == 2 || n == 3 || n == 0)
        printf("\nNo solutions possible!!");
    else
        nqueen(1, n);
    return (0);
}



