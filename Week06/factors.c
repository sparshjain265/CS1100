/*
Program Name	: factors.c -o factors.out
Programmer		: Sparsh Jain
Description		: To output all the factors of a number n taken from the user
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int i, n;
		
		printf("Enter a positive number n: ");
		scanf(" %d", &n);
		if(n < 1)
			{
				printf("\nWrong Input! Program terminating!");
				return 0;
			}
			
		printf("\nFactors of %d are: ", n);				
		for(i = 1; i <= n; i++)
			{
				if( (n % i) == 0)
					printf("%d, ", i);
				
			}
		printf("\b\b.\n");
		
		return 0;
	}
