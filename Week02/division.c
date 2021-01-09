/*
	Program Name: division.c
	Description: The program divides the 2 given numbers and rounds it off to the nearest integer
	Programmer: Sparsh Jain
	Date: 10/08/2016
*/

#include <stdio.h>

int main()
	{
		int a, b, q, r, ans;
		printf("Enter the dividend: ");
		scanf("%d", &a);
		printf("\nEnter the divisor: ");
		scanf("%d", &b);
		q = a/b;
		r = a%b;
		if((b%2) == 0)
			{
				if(r >= (b/2))
					ans = q + 1;
				else
					ans = q;				
			}
		else
			{
				if(r > (b/2))
					ans = q + 1;
				else
					ans = q;
			}
		printf("\n%d divided by %d gives %d as rounded off to the nearest integer.\n", a, b, ans);
		
		return 0;
	}
