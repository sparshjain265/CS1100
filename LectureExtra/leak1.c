#include<stdlib.h>
#include<stdio.h>
void main()
{
   int *p, i=0;
   
   while(i<10)
    { 
      p=(int *) malloc (sizeof(int)); //memory leak here
      *p=i;
      printf("%d ",*p);
      i=i+1;
    }
    
    free(p);
}
