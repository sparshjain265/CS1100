/*
Program Name	: prime_factors.c -o pfactors.out
Programmer		: Sparsh Jain
Description		: To output all the prime factors of a number n taken from the user
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int i = 2, n, f = 1;
		
		printf("\nEnter a positive number n: ");
		scanf(" %d", &n);
		
		if(n < 1)
			{
				printf("\nWrong Input! Program terminating!");
				return 0;
			}
			
		printf("\nPrime factors of %d are:  ", n);	
					
		while(n != 1)
			{
				if( (n % i) == 0)
					{
						if(f != i)												//To remove repitition of prime factors
							printf("%d, ", i);
						n = n / i;
						f = i;
					}
				else
					i++;		
			}
		printf("\b\b.\n\n");
		
		return 0;
	}
	
	// place i++
