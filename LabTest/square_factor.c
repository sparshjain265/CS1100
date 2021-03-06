/*
Program Name			: square_factor.c
Programmer's Name		: Sparsh Jain
Programmer's Roll No	: 111601026
Program Description	: To read a positive integer n, and check if n is divisible by a perfect square other than 1
Date						: 21/09/2016
*/

#include <stdio.h>

int main()
	{
		/*n to store the number entered by user, i to increase the counter of the loop, and check to store 1 if n is divisible by a perfect square other than 1*/
		int n, i, check = 0;	
		
		printf("Enter a Positive Number: ");
		scanf("%d", &n);
		
		/*Condition to check whether the entered number is positive or not. If not, then the program will terminate.*/
		if(n < 1)										
			{
				printf("\nWrong Input!\n");
				return 0;
			}
		
		/*
		Loop to check the divisibility by perfect squares of integers starting from the square of 2, since 1 is not required.
		The loop ends when the square of the counter 'i' exceeds the given number.
		*/
		for(i = 2; n >= i*i; i++)
			{
				/*If the number is divisible by the square of i, the loop terminates as our condition is fulfilled.*/
				if(n % (i*i) == 0)
					{
						check = 1;
						break;
					}
			}
		
		/*If the number was divisible, check would be 1. Using this to print the final message.*/	
		if(check == 1)
			printf("\nYes, %d is divisible by %d which is a perfect square.\n", n, i*i);
		else
			printf("\nNo, %d is not divisible by any perfect square other than 1.\n", n);
		
		return 0;
	}
