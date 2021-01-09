/*
Program Name: q1.c
Programmer	: Sparsh Jain
Description	: Takes n integers as input from the user and outputs the most frequently occuring element
Date			: 31/10/2016
*/

#include <stdio.h>

void inputArray(int *, int);
int getFrequency(int *, int, int);
int getMaxPosn(int *, int);

int main()
{
	int a[100], freq[100], n, i, maxFreq;
	
	printf("Enter the numbers you want to input (Max 100): ");
	scanf("%d", &n);
	inputArray(a, n);
	
	for(i = 0; i < n; i++)
		freq[i] = getFrequency(a, n, a[i]);
	
	maxFreq = getMaxPosn(freq, n);
	
	printf("%d is repeated most number of times in your input.\n", a[maxFreq]);
	
	return 0;
}

void inputArray(int *x, int n)
{
	int i;
	printf("Enter %d numbers\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &x[i]);
}

int getFrequency(int *x, int n, int k)
{
	int i, f = 0;
	for(i = 0; i < n; i++)
	{
		if(x[i] == k)
			f++;
	}
	return f;
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
