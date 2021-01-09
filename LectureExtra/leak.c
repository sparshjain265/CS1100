#include<stdlib.h>
#include<stdio.h>
void main()
{
   int *p;
   long long int i=0;
   
   while(1)
    { 
      p=(int *) malloc (10000*sizeof(long long int)); //memory leak here
      printf("%lld %p\n", i, p);
      i=i+1;
    }
    
    free(p); 
}
