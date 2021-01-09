#include<stdio.h>
#include<stdlib.h>

int * input_elements(int );
int main()
{

   int *a, *b;
   int n,i;

   printf("enter number of elements\n");
   scanf("%d",&n);
   a=input_elements(n);
      
   printf("\nlist entered in reverse is \n"); 
   for(i=n-1; i>=0; i--)
       printf("%d ",a[i]);
   printf("\n");

   free(a);
}

int * input_elements(int k)
{  
   int *x, i;
   printf("enter elements\n");
   x=(int *) malloc(k*sizeof(int));
   if(x==NULL)
   { 
         printf("\nalloc failed\n");
         return 0;
   }
   for(i=0; i<k; i++)
     scanf("%d",x+i);
   return x;
}
