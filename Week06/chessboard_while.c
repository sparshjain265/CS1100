/*
Program Name	: chessboard_while.c -o chess.out
Programmer		: Sparsh Jain
Description		: To print an n x n chessboard, taking integer n from user (Using only while loops)
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int n, i = 0, j;
		printf("Enter the dimention \'n\' to print n x n chessboard: ");
		scanf(" %d", &n);
		
		printf("\n");
		while(i < n)											//Outer loop controling lines
			{
				j = 0;
				while(j < n)									//Inner loop controling the printing
					{
						if( (i + j) % 2 == 0)				
							printf(" O ");
						else
							printf(" X ");
						
						j = j + 1;
					}
				printf("\n");									//Going to new line after every completion of the inner loop
				
				i = i + 1;
			}
			
		printf("\n");
		return 0;
	}
