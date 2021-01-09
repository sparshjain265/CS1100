/*
Program Name: q3.c
Programmer	: Sparsh Jain
Description	: Adds 4 square matrices
Date			: 31/10/2016
*/

#include <stdio.h>

void inputMatrix(int (*)[], int);
void printMatrix(int (*)[], int);
void addMatrices(int (*)[], int (*)[], int(*)[], int);

int main()
{
	int a[100][100], b[100][100], sum[100][100], n;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("Enter 1st %dx%d Matrix:\n", n, n);
	inputMatrix(a, n);
	printf("Enter 2nd %dx%d Matrix:\n", n, n);
	inputMatrix(b, n);
	addMatrices(a, b, sum, n);
	printf("Enter 3rd %dx%d Matrix:\n", n, n);
	inputMatrix(b, n);
	addMatrices(sum, b, sum, n);
	printf("Enter 4th %dx%d Matrix:\n", n, n);
	inputMatrix(b, n);
	addMatrices(sum, b, sum, n);
	
	printf("Sum of the 4 matrices:\n");
	printMatrix(sum, n);
	printf("\n");
	
	return 0;
}

void inputMatrix(int (*x)[100], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &x[i][j]);
	}
}

void printMatrix(int (*x)[100], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("   %3d", x[i][j]);
		printf("\n");
	}
}

void addMatrices(int (*x)[100], int (*y)[100], int (*z)[100], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			z[i][j] = x[i][j] + y[i][j];
	}
}
