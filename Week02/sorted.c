/*
  Program Name: sorted.c
  Description: Finds if the given 3 numbers are in Asceding Order, Descending Order or Not in any order
  Programmer: Sparsh Jain
  Date: 10/08/2016
*/

#include <stdio.h>

int main()
{
 int a, b, c;
 printf("Enter 3 numbers: ");
 scanf("%d %d %d", &a, &b, &c);
 
 if(a == b)
 {
  if(b == c)
   printf("All are equal\n");
 }
 else
 {
  if(a>=b)
  {
   if(b>=c)
   printf("DESCENDING\n");
   else 
   printf("NEITHER\n");
  }
  else
  {
   if(b<=c)
   printf("ASCENDING\n");
   else
   printf("NEITHER\n");
  }
 }
 
 return 0;
}
