#include <stdio.h>

int main()
	{
		unsigned int n, mafia[100000], mark = 0, i, j;
		
		printf("Input n: ");
		scanf("%u", &n);
				
		if(n > 100000)
			{
				printf("Wrong Input.\n");
				return 1;
			}
		
		for(i = 0; i < n; i++)
			scanf("%u", &mafia[i]);
		
		for(i = 1; i <= n; i++)	
			{
				for(j = 0; j < n; j++)
					{
						if(mafia[j] == i)
							{
								mark = 1;
								break;
							}
					}
				
				if(mark == 0)
					{
						printf("%u ", i);						
					}
				else
					mark = 0;
			}
		
		return 0;
	}
