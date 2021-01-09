/*
Program Name				: math_marks_functions.c
Programmer's Name			: Sparsh Jain
Programmer's Roll No.	: 111601026
Program Description		: to read part of a name, and print the details of all the matching students from file rollodd.txt along with their maths marks from the file math.txt using functions
Date							: 08/11/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

float average(int *, int);							//function to compute average
int roll_search(long int *, int, long int);	//function to search for the index of a roll no

int main()
{
	//file pointer details, and maths to open files rollodd.txt and math.txt
	FILE *details, *maths;
	//strings name, and part to store name read from file, and input from the user
	//character pointer found to check if part is a part of the name, char ch for extra characters
	char name[35], part[35], *found, ch;
	//integers endD, endM, for end of file checks, i for counters, array marks to store marks from file math.txt, n to store number of data, index to store index of matching data
	int endD = 1, endM = 1, i, marks[200], n, index;
	//long integer roll to store roll no from file rollodd.txt, array mroll, to store roll from math.txt
	long int roll, mroll[200];
	
	//opening the file rollodd.txt, and printing error message if cannot be opened
	details = fopen("rollodd.txt", "r");
	if(details == 0)
	{
		printf("Cannot reach the student details! Try again later.\n");
		return 0;
	}
	
	//opening the file math.txt, and printing error message if cannot be opened
	maths = fopen("math.txt", "r");
	if(maths == 0)
	{
		printf("Cannot reach the maths marks! Try again later.\n");
		fclose(details);
		return 0;
	}
	
	//reading math.txt, and storing its data in arrays mroll and marks
	for(i = 0; endM > 0; i++)
	{
		//reading roll no., the space, and marks from math.txt
		endM = fscanf(maths, "%ld %c %d", &mroll[i], &ch, &marks[i]);		
		//if fscanf cannot read the 3, go out of the loop
		if(endM < 3)
			break;
	}
	//storing the number of data in n
	n = i;
	//closing math.txt as it is no longer required
	fclose(maths);
	
	//taking part of the name as input from the user while making sure it does not go beyond the limit
	printf("Enter the name (or part of the name): ");
	for(i = 0; i < 34; i++)
	{
		scanf("%c", &part[i]);
		if(part[i] == '\n')
			break;
	}
	part[i] = '\0';	//placing the null character at the end
	if(i == 34)
		while(getchar() != '\n');	//reading till newline character to empty buffer
	
	//converting all the letters to upper case, since rollodd.txt contains names in upper case
	while(i > 0)
	{
		part[i-1] = toupper(part[i-1]);
		i--;
	}
	//here, i becomes 0
	
	//loop to go through the file rollodd.txt, i remembers the number of matching names
	while(endD > 0)
	{
		//reading roll no, and name
		endD = fscanf(details, "%ld %34[^\n]", &roll, name); 
		//if fscanf cannot read the 2, go out of the loop
		if(endD < 2)
			break;
		
		//found will be 0 if part is not a part of name
		found = strstr(name, part);
		
		//checking mroll if part matches with the name
		if(found != 0)
		{
			//calculating the index of the matching roll no in mroll. It will be -1 if the roll no is not found
			index = roll_search(mroll, n, roll);
			//if roll no is matched, print the roll no, name, and marks
			if(index != -1)
			{	
				printf("%ld %s, %d\n",roll, name, marks[index]);
				i++;	//incrementing the number of matches
			}
		}
	}
	//closing rollodd.txt as it is no longer required
	fclose(details);

	//if no match is found, printing Not Found
	if(i == 0)
		printf("Not Found\n");
	//else print the class average
	else
		printf("Class Average: %g\n", average(marks, n));
	
	//return from main after successful execution
	return 0;
}



float average(int *data, int n)
//takes the starting address of an integer array of marks, and n, the number of data, and returns the average
{
	//float avg (set to 0.0) to compute average, int i to use as counter
	float avg = 0.0;
	int i;
	
	//loop to first add all the data to avg
	for(i = 0; i < n; i++)
		avg = avg + data[i];
	
	//now dividing the sum (stored in avg) by n, to get the average in avg
	avg = avg/n;
	
	//returning the average
	return avg;	
}



int roll_search(long int *data, int n, long int search)
//takes the starting address of a long integer array of roll numbers, the number of data, and the roll no to search. returns the index of the roll no in the array.
//returns -1 if not found
{
	//int i to use as counter
	int i;
	
	//loop to go through the array
	for(i = 0; i < n; i++)
	{
		//if search is found in data, return the index
		if(search == data[i])
			return i;
	}
	
	//control will reach here if search is not found. return -1
	return -1;
}
