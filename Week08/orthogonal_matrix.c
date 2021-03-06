/*
Program name		: orthogonal_matrix.c
Programmer's name	: Sparsh Jain
Description			: To find whether a given matrix is orthogonal or not
Date					: 28/09/2016
*/

#include <stdio.h>

int main()
	{
		FILE *f;
		int r, c, rows, columns, m = 0, i, j, k, orth = 0;
		float A[100][100], P[100][100];
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
				printf("No, the given matrix is not orthogonal!\n");
				return 0;
			}
		
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < columns; j++)
					{
						fscanf(f, "%f", &A[i][j]);
					}
			}
		fclose(f);
		
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < columns; j++)
					{
						P[i][j] = 0;
						for(k = 0; k < rows; k++)
							{
								P[i][j] = P[i][j] + A[i][k]*A[k][j];
							}	
					}
			}
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < columns; j++)
					{
						if(i == j)
							{
								if(((1-0.001) < P[i][j]) && (P[i][j] < (1+0.001)))
									orth = 1;
								else
									{
										orth = -1;
										break;
									}
							}
						else
							{
								if((-0.001 < P[i][j]) && (P[i][j] < 0.001))
									orth = 1;
								else
									{
										orth = -1;
										break;
									}
							}
							
													
					}
				if(orth == -1)
					break;
			}
		if(orth == -1)
			{
				printf("No, the given matrix is not orthogonal!\n");
				return 0;
			}
		
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < i; j++)
				{
					k = A[i][j];
					A[i][j] = A[j][i];
					A[j][i] = k;
				}
			}
		
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < columns; j++)
					{
						P[i][j] = 0;
						for(k = 0; k < rows; k++)
							{
								P[i][j] = P[i][j] + A[i][k]*A[k][j];
							}	
					}
			}
		for(i = 0; i < rows; i++)
			{
				for(j = 0; j < columns; j++)
					{
						if(i == j)
							{
								if(((1-0.001) < P[i][j]) && (P[i][j] < (1+0.001)))
									orth = 1;
								else
									{
										orth = -1;
										break;
									}
							}
						else
							{
								if((-0.001 < P[i][j]) && (P[i][j] < 0.001))
									orth = 1;
								else
									{
										orth = -1;
										break;
									}
							}
													
					}
				if(orth == -1)
					break;
			}
		if(orth == -1)
			{
				printf("No, the given matrix is not orthogonal!\n");
				return 0;
			}
		
		printf("The matrix is orthogonal!\n");
				
		return 0;
	}
