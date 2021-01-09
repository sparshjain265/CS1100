/*
Program Name: statistics.c
Programmer: Sparsh Jain
Description: Read name and marks from file data01.txt and print Average Mark, Highest Mark, Names of all those students with highest marks
Date: 21-09-2016
*/

#include <stdio.h>

int main()
	{
		FILE *p;
		char name[200][30];
		int marks[200], i, j, success, highest;
		float sum = 0, average;
		
		p = fopen("data01.txt", "r");
		
		if(p == 0)
			{
				printf("Error in opening file.\n");
				return 1;
			}
			
		for(i = 0; i < 200; i++)
			{
				success = fscanf(p, "%s %d", name[i], &marks[i]);
				if(success == -1)
					break;
			}
		fclose(p);
		
		highest = marks[0];
		for(j = 0; j < i; j++)
			{
				sum = sum + marks[j];
				if(marks[j] > highest)
					highest = marks[j];
			}	
		average = sum/i;
		
		printf("\nAverage Marks: %f\nHighest Marks: %d\nNames of Students with Highest Marks: ", average, highest);
		for(j = 0; j < i; j++)
			if(marks[j] == highest)
				printf("%s ", name[j]);
		printf("\b\b.\n");
				
					
		return 0;
	}
