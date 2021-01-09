/* 
  Program name: max_min.c
  Description: The program takes 3 numbers from the user and gives the maximum and the minimum of the 3
  Programmer: Sparsh Jain
  Date: 10/08/2016
*/

#include <stdio.h>

int main()
{
 int a, b, c, min, max;
 
 printf("Enter the 3 numbers: ");
 scanf("%d %d %d", &a, &b, &c);
 
 if(a>=b)
 {
  max = a;
  min = b;
 }
 else
 {
  min = a;
  max = b;
 }
 
 if(c>max)
  max = c;
  
 else if(c<min)
  min = c;
  
 printf("Maximum and Minimum of %d, %d and %d are %d and %d respectively.\n", a, b, c, max, min);
 
 return 0;
 
}
