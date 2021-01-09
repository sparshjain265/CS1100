#include <stdio.h>

int main()
	{
		int a = 1, b = 1, n;
		
		printf("Enter n: ");
		scanf(" %d", &n);
		if(n < 2 || n > 100)
			{
				printf("\nSorry! Wrong Input!\n");
				return 0;
			}		
		
		while(a <= (n/2))
			{		
				while((a + b) <= n)
					{
						printf("\n( %d, %d)", a, b);
						b++;							
					}
				a++;
				b = a;
			}
			
			
		
		printf("\n");
		return 0;
	}
