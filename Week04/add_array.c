#include <stdio.h>

int main()
	{
		int a[5], b[5], c[5], i;
		
		printf("Enter a set of 5 numbers: ");
		
		i = 0;
		
		while(i<5)
			{
				scanf(" %d", &a[i]);
				i = i + 1;
			}
		
		printf("Enter next set of 5 numbers: ");
		
		i = 0;
		
		while(i<5)
			{
				scanf(" %d", &b[i]);
				i = i + 1;
			}
			
		i = 0;
		
		while(i<5)
			{
				c[i] = a[i] + b[i];
				i = i+1;
			}
			
		printf("Sum of the ith numbers from both the sets are: ");
		
		i = 0;
		
		while(i<5)
			{
				printf("%d   ", c[i]);
				i = i + 1;
			}
			
		printf("respectively.\n");
		
		return 0;
	}
