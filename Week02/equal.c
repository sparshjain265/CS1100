/*
	Program Name: equal.c
	Description: Checks whether any 2 of the given numbers are equal or not
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
			printf("\nYES\n");
		else if(b == c)
			printf("\nYES\n");
		else if(c == a)
			printf("\nYES\n");
		else
			printf("\nNO\n");
		
		return 0;
	}
