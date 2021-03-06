/*
Program Name	: number_palindrome.c -o pnum.out
Programmer		: Sparsh Jain
Description		: To check whether a user entered number is palindrome or not
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int a, b = 0, temp, rem, i = 10;
		
		printf("\nEnter a positive integer: ");
		scanf("%d", &a);
		temp = a;
		
		if(a < 0)
			{
				printf("\nWrong Input! Program terminating!");
				return 0;
			}
		
		do	{
				rem = temp % i;
				b = b*10 + rem;
				temp = temp / i;		
			}while(temp != 0);
			
		if(a == b)
			printf("\nCongratulations! %d is a palindrome.!\n", a);
		else
			printf("\nSorry, %d is not a palindrome.!\n", a);
				
		
		return 0;
	}

