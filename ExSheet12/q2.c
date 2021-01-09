/*
Program Name: q2.c
Programmer	: Sparsh Jain
Description	: Selection sort using functions
Date			: 31/10/2016
*/

#include <stdio.h>

void inputArray(int *, int);
void printArray(int *, int);
int getMaxPosn(int *, int);
void swap(int *, int *);
void selectionSort(int *, int);

int main()
{
	int a[100], n;
	
	printf("Enter the numbers you want to input (Max 100): ");
	scanf("%d", &n);
	inputArray(a, n);
	
	selectionSort(a, n);
	
	printf("Sorted Array: ");
	printArray(a, n);
	
	return 0;
}

void inputArray(int *x, int n)
{
	int i;
	printf("Enter %d numbers\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &x[i]);
}

void printArray(int *x, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
}

int getMaxPosn(int *x, int n)
{
	int i, max = 0;
	for(i = 1; i < n; i++)
	{
		if(x[i] > x[max])
			max = i;
	}
	return max;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int *x, int n)
{
	int posn;
	if(n > 1)
	{
		posn = getMaxPosn(x, n);
		swap(&x[posn], &x[n-1]);
		selectionSort(x, n-1);
	}
}
