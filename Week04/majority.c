#include <stdio.h>

int main()
	{
		int a[100], n, temp, count, max, i, j, f;
		
		printf("Enter n: ");
		scanf(" %d", &n);
		
		i = 0;
		
		while(i<n)
			{
				printf("\nEnter element %d: ", i+1);
				scanf(" %d", &a[i]);
				i = i + 1;
			}
		
		i = 0;
		
		max = 0;
		
		while(i<n)
			{
				temp = a[i];
				count = 0;
				j = 0;
				
				while(j<n)
					{
						if(a[j] == temp)
							count = count + 1;
						j = j + 1;
					}
					
				if(count>max)
					{
						max = count;
						f = temp;
					}
					
				i = i + 1;
			}
			
			printf("\nThe most frequent number is %d and is occuring %d times in your list.\n", f, max);
			
			return 0;
	}
