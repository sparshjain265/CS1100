#include<stdio.h>
#include<stdlib.h>
int main()
{

   int *a, *b;
   int n,i;

   printf("enter number of elements\n");
   scanf("%d",&n);
   
   a=(int *) malloc(n*sizeof(int));
   if(a==NULL)
   { 
      printf("\nalloc failed\n");
      return 0;
   }
   printf("enter elements\n");
   for(i=0; i<n; i++)
     scanf("%d",&a[i]);
   
   b=a;
   printf("\nlist entered in reverse is \n"); 
   for(i=n-1; i>=0; i--)
     printf("%d ",b[i]);
   printf("\n");

   free(b);
}
