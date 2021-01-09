/*
Program Name: cgpa.c
Programmer	: Sparsh Jain
Description	: to read grades from a file, and create a file including cgpa
Date			: 02/11/2016
*/

#include <stdio.h>

float CGPA(char, char, char, char);
int point(char);

int main()
{
	FILE *grade, *cgpa;
	char name[50], p, c, m, b, ch;
	int i, end;
	
	printf("Enter the file name containing grades: ");
	for(i = 0; i < 49; i++)
	{
		name[i] = getchar();
		if(name[i] == '\n')
			break;
	}
	name[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	grade = fopen(name, "r");
	if(grade == 0)
	{
		printf("Could not open File. Try Again!.\n");
		return 0;
	}
	
	printf("Enter the file name to store cgpa: ");
	for(i = 0; i < 49; i++)
	{
		name[i] = getchar();
		if(name[i] == '\n')
			break;
	}
	name[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	cgpa = fopen(name, "w");
	if(cgpa == 0)
	{
		printf("Cannot create file. Try Again!\n");
		fclose(grade);
		return 0;
	}
	
	while(1)
	{
		end = fscanf(grade, " %49[^,]%c %c%c %c%c %c%c %c", name, &ch, &p, &ch, &c, &ch, &m, &ch, &b);
		if(end < 5)
			break;
		fprintf(cgpa, "%s,\t%c,\t%c,\t%c,\t%c,\t%f\n", name, p, c, m, b, CGPA(p, c, m, b));
	}
	printf("File created successfully!\n");
	
	fclose(grade);
	fclose(cgpa);
	return 0;
}

float CGPA(char p, char c, char m, char b)
{
	int P, C, M, B;
	float cgpa;
	P = point(p);
	C = point(c);
	M = point(m);
	B = point(b);
	cgpa = P + C + M + B;
	cgpa = (float)(cgpa)/4;
	return cgpa;
}

int point(char grade)
{
	if(grade == 'A')
		return 10;
	else if(grade == 'B')
		return 8;
	else if(grade == 'C')
		return 6;
	else
		return 0;
}
