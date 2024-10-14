#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000
int count;

void merge(int a[SIZE],int l,int r,int m)
{
   int i=l;
   int j=m+1;
   int k=l;
   int b[SIZE];
   
   while(i<=m&& j<=r)
   {
      if(a[i]<=a[j])
      {
      	b[k++]=a[i++];
      }
     else if(a[j]<a[i])
      {
      	b[k++]=a[j++];
      }
      count++;
   
   
   }
   while(i<=m)
   {
        b[k++]=a[i++];
   
   }
    while(j<=r)
   {
        b[k++]=a[j++];
   
   }
   
   for(i=l;i<=r;i++)
   {
   
       a[i]=b[i];
}
   
   
   
   
}





void  merges(int a[],int l,int r)
{
if(l<r)
{
    int m=(l+r)/2;
    merges(a,l,m);
    merges(a,m+1,r);
    merge(a,l,r,m);
    

}




}




int main()
{
   int a[1000];
   int n;
   int i;
   printf("Enter number of elements");
   scanf("%d",&n);
   printf("Enter elements");
   for( i=0;i<n;i++){
    scanf("%d",&a[i]);
   }
   
  
   
   merges(a,0,n-1);
   
   printf("Sorted array is \n");
   for(int i=0;i<n;i++)
   	printf("%d\t",a[i]);
   	
  printf("\n Count is %d",count);
  
  
  return 0;

}
