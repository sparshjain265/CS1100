#include <stdio.h>

int main()
	{
		 int i = 1, j = 1, a, b;
		 printf("Enter the number of rows you want in the Multiplication Matrix: ");
		 scanf("%d", &a);
		 printf("\nEnter the number of columns you want in the Multiplication Matrix: ");
		 scanf("%d", &b);
		 
		 printf("\n");
		 
		 while( j <= b)
		 	{
		 		printf("==========");
		 		j = j + 1;
		 	}
		 	
		 	j = 1;	
		 
		 while(i <= a)
		 	{
		 		printf("\n");
		 		while(j <= b)
		 			{
		 				printf("\t%3d", i*j);
		 				j = j + 1;
		 			}
		 		
		 		i = i + 1;
		 		j = 1;
		 	}
		 	
		 printf("\n");
		 
		 while( j <= b)
		 	{
		 		printf("==========");
		 		j = j + 1;
		 	}
		 	
		 printf("\n");
		 	
		 return 0;
	}
