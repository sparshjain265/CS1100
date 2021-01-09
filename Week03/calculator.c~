#include <stdio.h>

int main()
	{
		float x, y, ans = 0;
		
		char op, ch = 'y';
		
		while(ch == 'y')
			{
				printf("\nI can add, subtract, multiply or divide! \nEnter your calculation statement in the format - \"<value> <operator> <value>\" \nfor eg: 5 + 5 \n");
				scanf("%f %c %f", &x, &op, &y);
				
				if(op == '+')
					ans = x + y;
				else if(op == '-')
					ans = x - y;
				else if(op == '*')
					ans = x*y;
				else if(op == '/')
					{
						if(y == 0)
							printf("\nCannot Divide by Zero!\n");
						else
							ans = x/y;
					}
				else 
					printf("\nSyntax Error!!!\n");
					
				printf("\n=\t %f\n", ans);
				
				printf("\nDo you want to perform another calculation?\n");
				printf("Enter your choice - y/n ");
				scanf(" %c",&ch);
				if(ch == 'Y')
					ch = 'y';
			}
		printf("\nThank You!\n");		
		return 0;
	}
