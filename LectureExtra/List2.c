#include<stdio.h>
#include<stdlib.h>
int main()
{

   int *a;
   int n,i;

   printf("enter number of elements\n");
   scanf("%d",&n);
   
   
   printf("enter elements\n");
   for(i=0; i<n; i++)
   {
     a=(int *) malloc(sizeof(int));
     if(a==NULL)
     { 
         printf("\nalloc failed\n");
         return 0;
     }
     printf("\nvalue of a is %p\n", a);
     printf("\n a+1 is %p \n", a+1);
     scanf("%d",a);
    // printf("Value in memory pointed to by a is %d",*a);
   }
  
   printf("\nlist entered in reverse is \n"); 
   for(i=n-1; i>=0; i--)
   {
     printf("%d ",*a);
    
     a--;

   }
   
   printf("\n");

   
}
