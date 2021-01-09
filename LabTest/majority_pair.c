/*
Program Name			: majority_pair.c
Programmer's Name		: Sparsh Jain
Programmer's Roll No	: 111601026
Program Description	: To read a single word string and find a two letter pattern that is repeated most number of times in the string.
Date						: 21/09/2016
*/

#include <stdio.h>

int main()
	{
		/*str to store the string, pair to store a 2 letter pattern, mpair to store the answer pattern.*/
		char str[51], pair[3], mpair[3];
		/*f to store the frequency of pair; max to store the frequency of mpair; i, j and k are counters to be used in loops.*/
		int f, max = 0, i, j, k;
		
		printf("Enter a single word string.\n");
		/*scanf reads till first blankspace, hence it will read only the first word if user enters multiple words in the string.*/
		scanf(" %s", str);
		
		/*setting the first pair as the answer pattern*/
		for(k = 0; k < 2 ; k++)
			mpair[k] = str[k];

		/*Entering the null character at the end of strings mpair and pair. Need not be done again.*/
		mpair[2] = '\0';
		pair[2] = '\0';
		
		/*Looping through the string*/
		for(i = 0; str[i + 1] != '\0'; i++)
			{
				/*Setting pair as next 2 letter pattern in the string, and its frequency to be 0.*/
				for(k = 0; k < 2 ; k++)
					pair[k] = str[i + k];
				f = 0;
					
				/*Checking for instances of pair in the string and inceasing its frequency.*/
				for(j = 0; str[j + 1] != '\0'; j++)
					{
						if(pair[0] == str[j] && pair[1] == str[j + 1])
							f++;
					}
				
				/*Checking whether the frequency of pair is more than that of mpair, if so, changing mpair and max.*/
				if(f > max)
					{
						max = f;
						for(k = 0; k<2 ; k++)
							mpair[k] = pair[k];
					}
			}	
		
		/*Printing the final result and its frequency.*/
		printf("\nThe most frequent two letter pattern in %s is %s.\nIt is repeated %d times.\n", str, mpair, max);
		
		
		return 0;
	}
