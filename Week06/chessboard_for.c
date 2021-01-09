/*
Program Name	: chessboard_for.c -o forchess.out
Programmer		: Sparsh Jain
Description		: To print an n x n chessboard, taking integer n from user (Using only for loops)
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int n, i, j;
		printf("Enter the dimention \'n\' to print n x n chessboard: ");
		scanf(" %d", &n);
		
		printf("\n");
		for(i = 0; i < n; i = i + 1)						//Outer loop controling lines
			{
				for(j = 0; j < n; j = j + 1)				//Inner loop controling the printing
					{
						if( (i + j) % 2 == 0)				
							printf(" O ");
						else
							printf(" X ");

					}
				printf("\n");									//Going to new line after every completion of the inner loop
			}
			
		printf("\n");
		return 0;
	}
