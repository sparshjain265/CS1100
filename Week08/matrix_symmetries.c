/*
Program Name		: matrix_symmetries.c
Programmer's Name	: Sparsh Jain
Description			: To read a matrix and decide whether it's a square, symmetric or skew symmetric matrix
Date					: 28/09/2016
*/

#include <stdio.h>

int main()
	{
		FILE *f;
		int r, c, rows, columns, m = 0;
		float matrix[100][100];
		char file[20];
		
		printf("Enter the name of the file containing matrix: ");
		scanf(" %s", file);
		
		f = fopen(file, "r");
		if(f == 0)
			{
				printf("Sorry, couldn't open file. Please check the file name again!\n");
				return 1;
			}		
		
		fscanf(f, "%d %d", &rows, &columns);
		
		if(rows != columns)
			{
				fclose(f);
				printf("Matrix contained in %s is not a square matrix.\n", file);
				return 0;
			}
		else
			printf("Matrix contained in %s is a square matrix.\n", file);
		
		for(r = 0; r < rows; r++)
			{
				for(c = 0; c < columns; c++)
					{
						fscanf(f, "%f", &matrix[r][c]);
					}
			}
			
		fclose(f);
		
		for(r = 0; r < rows; r++)
			{
				for(c = 0; c < r ; c++)
					{
						if(matrix[r][c] == matrix[c][r])
							m = 1;
						else
							{
								m = -1;
								break;
							}
					}
				if(m == -1)
					break;
			}
			
		if(m == 1)
			{
				printf("It is also a symmetric matrix.\n");
				return 0;
			}
			
		for(r = 0; r < rows; r++)
			{
				for(c = 0; c < r ; c++)
					{
						if(matrix[r][c] == -1*matrix[c][r])
							m = 1;
						else
							{
								m = -1;
								break;
							}
					}
				if(m == -1)
					break;
			}
			
		if(m == 1)
			{
				printf("It is also a skew symmetric matrix.\n");
				return 0;
			}
			
		printf("It is neither a symmetric nor a skew symmetric matrix.\n");
				
		return 0;
	}
