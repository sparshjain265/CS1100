/*
Program Name: grade.c
Programmer	: Sparsh Jain
Description	: To output the grade from an input file to an output file
Date			: 02/11/2016
*/

#include <stdio.h>

float average(int *, int);
char grade(int, float);

int main()
{
	FILE *database;
	char fname[50], names[200][50], ch, g[4][200];
	int data[4][200], i, j, n, end;
	float avg[4];
	
	printf("Enter the file name which contains the name and marks of students: ");
	for(i = 0; i < 49; i++)
	{
		fname[i] = getchar();
		if(fname[i] == '\n')
			break;
	}
	fname[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	database = fopen(fname, "r");
	if(database == 0)
	{
		printf("Could not open the file, Try again!\n");
		return 0;
	}
	
	for(i = 0; i < 200; i++)
	{
		end = fscanf(database, " %49[^,]%c%d%c%d%c%d%c%d", names[i], &ch, &data[0][i], &ch, &data[1][i], &ch, &data[2][i], &ch, &data[3][i]);
		if(end < 9)
			break;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//printf(" %s %c %d %c %d %c %d %c %d", names[i], ch, data[0][i], ch, data[1][i], ch, data[2][i], ch, data[3][i]);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	n = i;
	fclose(database);
	
	for(j = 0; j < 4; j++)
		avg[j] = average(data[j], n);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 4; j++)
			g[j][i] = grade(data[j][i], avg[j]);
	}
	
	printf("Enter the output file name to contain grades: ");
	for(i = 0; i < 49; i++)
	{
		fname[i] = getchar();
		if(fname[i] == '\n')
			break;
	}
	fname[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	database = fopen(fname, "w");
	if(database == 0)
	{
		printf("Could not create the file, Try again!\n");
		return 0;
	}
	
	for(i = 0; i < n; i++)
		fprintf(database, "%s,\t%c,\t%c,\t%c,\t%c\n", names[i], g[0][i], g[1][i], g[2][i], g[3][i]);
	fclose(database);
	
	printf("File created successfully!!!\n");	
	return 0;
}

float average(int *marks, int n)
{
	int i;
	float avg = 0;
	
	for(i = 0; i < n; i++)
		avg = avg + marks[i];	
	avg = (float)avg/n;
		
	return avg;
}

char grade(int marks, float avg)
{
	if(marks < (avg/2))
		return 'F';
	else if(marks < (avg))
		return 'C';
	else if(marks < (2*avg))
		return 'B';
	else
		return 'A';
}
