/*
Program Name: spell_checker.c
Programmer	: Sparsh Jain
Description : to output all the wrongly spelt words in a given input file
Date			: 12/10/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *file, *spell;
	char word[50], read[50], c_word[50], c_read[50], fname[50];
	int i, l1, l2, endspell = 1, endfile = 1, f;
	
	printf("Enter the filename for spell check: ");
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
		
	spell = fopen("spell.words", "r");
	if(spell == 0)
	{
		printf("Spelling database cannot be opened, Try again!\n");
		fclose(file);
		return 0;
	}
	
	//printf("Wrongly spelt words are:-\n");
	while(endfile != -1)
	{
		for(i = 0; i < 49; i++)
		{
			endfile = fscanf(file, "%c", &word[i]);
			if(!isalpha(word[i]) || endfile == -1)
				break;
		}
		word[i] = '\0';
		l1 = i;
		for(i = 0; i < l1; i++)
			c_word[i] = tolower(word[i]);
		c_word[i] = '\0';

			////////////////////////////////////////
			//printf("%s, %s.\n", word, c_word);
			////////////////////////////////////////

		fseek(spell, 0, SEEK_SET);
		endspell = 1;
		while(endspell != -1)
		{	
			
			for(i = 0; i < 49; i++)
			{
				endspell = fscanf(spell, "%c", &read[i]);
				if(!isalpha(read[i]) || endspell == -1)
					break;
			}
			read[i] = '\0';
			l2 = i;
			
			
			//endspell = fscanf(spell, " %s", read);
			//l2 = strlen(read);
			
			for(i = 0; i < l2; i++)
				c_read[i] = tolower(read[i]);
			c_read[i] = '\0';

			f = strcmp(c_read, c_word);
			if(f == 0)
				break;	
		}
		
		if(f != 0)
			printf("%s\n", word);
	}
	
	fclose(file);
	fclose(spell);
	return 0;
}
