#include<stdio.h>
#include<stdlib.h>

int partition(int l, int r,int a[])
{
   int pivot=a[l];
   int i=l+1;
   int j=r;
   
   while(1)
   {
       while(pivot >=a[i])
       {
         i++;
         
       }
       
       while(pivot<a[j])
       {
          j--;
       }
       
       if(i<j)
       {
         int temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
       else
       {
          int temp=a[l];
          a[l]=a[j];
          a[j]=temp;
          return j;
       }   
   
   }
   
   
   


}



void quick(int a[],int l,int r)
{
if(l<r)
{
  int s=partition(l,r,a);
  
  quick(a,l,s-1);
  quick(a,s+1,r);
}

}



int main()
{
int a[100];
int n;
printf("Enter n");
scanf("%d",&n);

printf("Enter ele \n");

for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

quick(a,0,n-1);

printf("Sorted array\n");


for(int i=0;i<n;i++)
 printf("%d\t",a[i]);

return 0;



}
