#include <stdio.h>

int main()
	{
		int a[20], i;
		
		a[0] = 1;
		a[1] = 1;
		
		i = 2;
		
		while(i < 20)
			{
				a[i] = a[i-1] + a[i-2];
				i = i + 1;
			}
		
		i = 19;
		
		while(i >= 0)
			{
				printf("%d  ", a[i]);
				i = i - 1;
			}
		printf("\n");
		return 0;
	}
