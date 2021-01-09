#include <stdio.h>

int main()
	{
		int a[10], count = 0, scount = 0, i = 0;
		
		while(i<10)
			{
				printf("Enter No %d: ", i+1);
				scanf(" %d", &a[i]);
				i = i + 1;
			}
		
		i = 0;
		
		while(i<10)
			{
				if(a[9] == a[i])
					count = count + 1;
					
				if(a[9] > a[i])
					scount = scount + 1;
				
				i = i + 1;
			}
		
		printf("Last number (%d) is repeated %d times.\nThere are %d numbers smaller than %d.\n", a[9], count, scount, a[9]); 
		
		return 0;
	}
