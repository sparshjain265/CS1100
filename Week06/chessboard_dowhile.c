/*
Program Name	: chessboard_dowhile.c -o dochess.out
Programmer		: Sparsh Jain
Description		: To print an n x n chessboard, taking integer n from user (Using only dowhile loops)
Date				: 07/09/2016
*/

#include <stdio.h>

int main()
	{
		int n, i = 0, j;
		printf("Enter the dimention \'n\' to print n x n chessboard: ");
		scanf(" %d", &n);
		
		printf("\n");																	
		do{														//Outer loop controling lines
				j = 0;													
				do{												//Inner loop controling the printing
						if( (i + j) % 2 == 0)				
							printf(" O ");
						else
							printf(" X ");
						
						j = j + 1;
					}while(j < n);
				printf("\n");									//Going to new line after every completion of the inner loop
				
				i = i + 1;
			}while(i < n);
			
		printf("\n");
		return 0;
	}
