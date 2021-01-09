/*
Program Name: search_file2.c
Programmer	: Sparsh Jain
Description : to check whether a given word is contained in the given file exactly as it is
Date			: 12/10/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *file;
	char word[50], read[50], c_word[50], c_read[50], fname[50];
	int i, l1, l2, end = 1, f;
	
	printf("Enter the word: ");	
	for(i = 0; i < 49; i++)
	{
		word[i] = getchar();
		//if(!(('a' <= word[i] && word[i] <= 'z') || ('A' <= word[i] && word[i] <= 'Z')))
		if(!isalpha(word[i]))
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
		//l2 = strlen(read);
		for(i = 0; i < 49; i++)
		{
			//read[i] = getchar();
			end = fscanf(file, "%c", &read[i]);
			if(!isalpha(read[i]) || end == -1)
				break;
		}
		read[i] = '\0';
		l2 = i;
		for(i = 0; i < l2; i++)
			c_read[i] = tolower(read[i]);
		c_read[i] = '\0';
		f = strcmp(c_read, c_word);
		if(f == 0)
		{
			printf("%s is contained in file %s\n", word, fname);
			fclose(file);
			return 0;
		}
		
	}
	fclose(file);
	printf("%s is not contained in file %s\n", word, fname);
	return 0;
}
