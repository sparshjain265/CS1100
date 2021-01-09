/*
Program Name: search_file1.c
Programmer	: Sparsh Jain
Description : to check whether a given string is contained in the given file
Date			: 12/10/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *file;
	char word[100], read[100], c_word[100], c_read[100], fname[50], *f;
	int i, l1, l2, end = 1;
	
	printf("Enter the string: ");	
	for(i = 0; i < 99; i++)
	{
		word[i] = getchar();
		if(!(('a' <= word[i] && word[i] <= 'z') || ('A' <= word[i] && word[i] <= 'Z') || word[i] == ' '))
		//if(!isalpha(word[i]))
			break;
	}
	if(word[i] != '\n')
		while(getchar() != '\n');
	word[i] = '\0';
	l1 = i;
	for(i = 0; i < l1; i++)
		c_word[i] = tolower(word[i]);
	c_word[i] = '\0';
	
	printf("Enter the filename: ");
	for(i = 0; i < 49; i++)
	{
		fname[i] = getchar();
		if(fname[i] == '\n')
			break;
	}
	fname[i] = '\0';
	if(i == 49)
		while(getchar() != '\n');
		
	file = fopen(fname, "r");
	if(file == 0)
	{
		printf("Unable to open file!\nTry again!\n");
		return 0;
	}
		
	while(end != -1)
	{
		//end = fscanf(file, " %s", read);
		for(i = 0; i < 99; i++)
		{
			end = fscanf(file, "%c", &read[i]);
			if(end == -1)
				break;
		}
		read[i] = '\0';
		
		//l2 = strlen(read);
		for(i = 0; i < 99; i++)
			c_read[i] = tolower(read[i]);
		c_read[i] = '\0';
		f = strstr(c_read, c_word);
		if(f != 0)
		{
			printf("%s is contained in file %s\n", word, fname);
			fclose(file);
			return 0;
		}
		
		fseek(file, -98, SEEK_CUR);
	}
	fclose(file);
	printf("%s is not contained in file %s\n", word, fname);
	return 0;
}
