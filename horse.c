#include<stdio.h>
#include<string.h>
int table[256];


void shift( char pat[])
{
   int m=strlen(pat);
   
   for(int i=0;i<256;i++)
     table[i]=m;
     
     for(int i=0;i<m;i++)
     table[(unsigned char)pat[i]]=m-i-1;

}

int hosrse(char pat[],char src[])
{

 int n=strlen(src);
 int m=strlen(pat);
 
int i=m-1;
int k;

while(i<n)
{
    int k=0;
    while(k<m && pat[m-1-k]== src[i-k] )
    k++;
    
    if(k==m)
    return (i-m+1);
    
    
     int shift_value = table[(unsigned char)src[i]];
        if (shift_value <= 0)  // Avoid zero or negative shifts
            shift_value = 1;

        i += shift_value;



}
return -1;

}



int main()
{
   char src[100];
   char pat[10];
   
   printf("Enter text \n");
   
   scanf(" %[^\n]", src);
    printf("Enter pattern\n");
    scanf(" %[^\n]", pat);
    
    
    shift(pat);
    
    int pos=hosrse(pat,src);
    
   
   if (pos >= 0) 
   {
printf("Pattern found at position %d\n", pos + 1);
 
} else {
printf("String match failed\n");
}
return 0;
   
   
   
   
   
   
   
   



}
