/*
Program Name: find_replace.c
Programmer	: Sparsh Jain
Description : to find and replace a word with another word from a file to another file
Date			: 12/10/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *input, *output;
	char fname[50], find[50], c_find[50], replace[50], read[50], c_read[50], rest[50], ch;
	int i, l, c_l, end = 1;
	
	printf("Enter the Input File Name: ");
	for(i = 0; i < 49; i++)
	{
		fname[i] = getchar();
		if(fname[i] == '\n')
			break;
	}
	fname[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	input = fopen(fname, "r");
	if(input == 0)
	{
		printf("File not found. Try again!\n");
		return 0;
	}
	
	printf("Enter the Output File Name: ");
	for(i = 0; i < 49; i++)
	{
		fname[i] = getchar();
		if(fname[i] == '\n')
			break;
	}
	fname[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	
	output = fopen(fname, "w");
	if(output == 0)
	{
		fclose(input);
		printf("Cannot create new file. Try again!\n");
		return 0;
	}
	
	printf("Enter the word you want to find: ");
	for(i = 0; i < 49; i++)
	{
		find[i] = getchar();
		if(find[i] == '\n')
			break;
	}
	find[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
	l = i;
	for(i = 0; i < l; i++)
		c_find[i] = tolower(find[i]);
	c_find[i] = '\0';
	
	printf("Enter the word you want to replace with: ");
	for(i = 0; i < 49; i++)
	{
		replace[i] = getchar();
		if(replace[i] == '\n')
			break;
	}
	replace[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
		
	while(1)
	{
		end = fscanf(input, "%c", &ch);
		if(end == -1)
			break;
		if(isalpha(ch))
			fseek(input, -1, SEEK_CUR);
		else
			fprintf(output, "%c", ch);
		
		end = fscanf(input, "%49s%c", read, &ch);
		if(end == -1)
			break;
		l = strlen(read);
		
		for(i = 0; i < l; i++)
		{
			if(isalpha(read[i]))
				c_read[i] = tolower(read[i]);
			else
				break;
		}
		c_l = i;
		c_read[i] = '\0';
		for(;i < l; i++)
			rest[i - c_l] = read[i];
		rest[i - c_l] = '\0';		
		
		if(strcmp(c_find, c_read))
			fprintf(output, "%s%c", read, ch);
		else
			fprintf(output, "%s%s%c", replace, rest, ch);
		
	}
	
	fclose(input);
	fclose(output);
	return 0;
}
