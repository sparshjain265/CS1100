/* 
 Program Name: average.c
 Description: It takes input of 2 integers and displays their average
 Programmer: Sparsh Jain
 Date: 10/08/2016
*/
 
#include <stdio.h>

int main()
{
 //a and b are 2 variables used to store inputs
 float a, b;
 
 //avg is a variable used to store the average
 float avg;
 
 //prompting the user to enter the first integer
 printf("Enter the first number: ");
 scanf("%f", &a);
 
 //prompting the user to enter the second integer
 printf("Enter the second number: ");
 scanf("%f", &b);
 
 //computing the average
 avg = (a+b)/2;
 
 //display the result
 printf("The average of %f and %f is %f\n", a, b, avg);
 
 //tell the operating system that everything went well
 return 0;
}
