/*
Program Name	: fibonacci_sum.c -o fsum.out
Programmer		: Sparsh Jain
Description		: To output the sum of first n fibonacci numbers and (n+2)th fibonacci number
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int n, a = 0, b = 1, f = 1, sum = 1, i;
		
		printf("Enter a positive n: ");
		scanf(" %d", &n);
		
		if(n < 1)
			{
				printf("\nWrong Input! Program terminating!");
				return 0;
			}
		
		for(i = 1; i < n; i++)
			{
				f = a + b;
				a = b;
				b = f;
				sum = sum + f;
			}
		for(i = 0; i < 2; i++)
			{
				f = a + b;
				a = b;
				b = f;
			}
			
		printf("\nSum of first %d fibonacci numbers is %d.", n, sum);
		printf("\n%d-th Fibonacci Number is %d.", n + 2, f);
		
		printf("\n");
		return 0;
	}
