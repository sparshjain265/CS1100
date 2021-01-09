#include <stdio.h>

int main()
	{
		int order = 0, a, b, n, i = 0;
		
		printf("Enter the number of numbers you want to enter: ");
		scanf(" %d", &n);
		
		order = n;
		
		printf("\nEnter Number 1: ");
		scanf(" %d", &a);
		b = a;
		i++;
		
		printf("\nEnter Number 2: ");
		scanf(" %d", &a);
		i++;
		
		if(a > b)
			{
				order++;
				while(i < n)
					{
						b = a;
						printf("\nEnter Number %d: ", i+1);
						scanf(" %d", &a);
						if(a > b)
							order++;
						i++;							
					}
			}
		else if(a < b)
			{
				order--;
				while(i < n)
					{
						b = a;
						printf("\nEnter Number %d: ", i+1);
						scanf(" %d", &a);
						if(a < b)
							order--;
						i++;
					}
			}
		else
			{
				while(i < n)
					{
						printf("\nEnter Number %d: ", i+1);
						scanf(" %d", &a);
						i++;
					}
			}
			
		if(order == (2*n - 1))
			printf("\nStrictly Ascending\n");
		else if (order == 1)
			printf("\nStrictly Decreasing\n");
		else
			printf("\nNeither Ascending Nor Descending\n");		
	
		return 0;
	}
