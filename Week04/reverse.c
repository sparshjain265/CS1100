#include <stdio.h>

int main()
	{
		int i, n, pal = 1;
		float a[100], b[100];
		
		printf("Enter n: ");
		scanf(" %d", &n);
		
		if(n>100)
			{
				printf("Wrong Input!\nAborting\n");
				return 0;
			}
		
		i = 0;
		
		while(i < n)
			{
				printf("Enter number: ");
				scanf(" %f", &a[i]);
				i = i + 1;
			}
			
		i = 0;
		
		while(i < n)
			{
				b[i] = a[n-(i+1)];
				i = i + 1;
			}
			
		printf("Your list in reverse order is: ");
		
		i = 0;
		
		while(i < n)
			{
				printf("%f ", b[i]);
				i = i + 1;
			}
		
		i = 0;
		
		while(i < n)
			{
				if(a[i] != b[i])
					pal = 0;
				i = i + 1;
			}
		
		if(pal == 1)
			printf("\nPalindrome.");
			
		printf("\n");
		
		return 0;
	}	
