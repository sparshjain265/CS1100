/*
  Program Name: sum_even_odd.c
  Description: Finds out that whether the sum of 2 numbers will be even or odd
  Programmer: Sparsh Jain
  Date: 10/08/2016
*/

#include <stdio.h>

int main()
{
 int a, b;
 
 printf("Enter 2 numbers: ");
 scanf("%d %d", &a, &b);
 
 if((a%2) == 0)
  {
   if((b%2) == 0)
    printf("EVEN\n");
   else
    printf("ODD\n");
  }
 else
  {
   if((b%2) == 1)
    printf("EVEN\n");
   else
    printf("ODD\n");
  }
 return 0;
}
