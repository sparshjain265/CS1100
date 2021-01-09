#include <stdio.h>

int main()
	{
		int i = 1, j, num = 2, n;
		printf("Enter the number of primes required: ");
		scanf(" %d", &n);
		printf("\nThe first %d prime numbers are given below!\n", n);
		while(i <= n)
			{
				j = 2;
				while(j <= num/2)
					{
						if((num % j) == 0)
							break;
						i++;						
					}
				if(j > num/2)
					{
						printf("%d\t", num);
						i++;
					}
				num++;
			}
		
			
		
		printf("\n");
		return 0;		
	}
