#include<stdio.h>
#include<stdlib.h>

void heapify(int n,int h[])
{
   int k,  i, j,v;
   int heap=0;
   
     for(int i=n/2;i>=1;i--)
     {
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
           j=2*k;
           if(j<n)
           {
              if(h[j]<h[j+1])
                j=j+1;
           
           }
           if(v>=h[j])
           {
             heap=1;
           }
           else{
               h[k]=h[j];
               k=j;
           }
        }
        h[k]=v;
     
         
     }

}



void heapsort(int n,int h[])
{
         heapify(n,h);
    for(int i=n;i>=1;i--)
    {
        int temp=h[i];
        h[i]=h[1];
        h[1]=temp;
        heapify(i-1,h);
        
    }


}

 int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int h[100];

    printf("Enter the elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    heapsort(n, h);

    printf("Sorted elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");

   
    return 0;
}
