/*
Program Name				: roll_search.c
Programmer's Name			: Sparsh Jain
Programmer's Roll No.	: 111601026
Program Description		: to read a roll no, and print the name of the student from file rollodd.txt
Date							: 08/11/2016
*/

#include <stdio.h>

int main()
{
	//file pointer details to open the file rollodd.txt
	FILE *details;
	//string name to read the name from the file
	char name[35];
	//intger end to check the end of file, i for counter
	int end = 1, i;
	//long integers roll and roll_no to read the roll no from the file and user
	long int roll, roll_no;
	
	//opening the file, and printing error message if cannot be opened
	details = fopen("rollodd.txt", "r");
	if(details == 0)
	{
		printf("Cannot reach the student details! Try again later.\n");
		return 0;
	}
	
	//taking the roll no. as input from the user
	printf("Enter the Roll No: ");
	scanf(" %ld", &roll_no);
	
	//loop to go through the file 
	while(end > 0)
	{
		//reading roll no, and name
		end = fscanf(details, "%ld %34[^\n]", &roll, name);
		//if fscanf cannot read the 2, go out of the loop
		if(end < 2)
			break;
		
		//if roll matches with roll_no, print the name
		if(roll == roll_no)
		{
			printf("%s\n", name);
			fclose(details);
			return 0;
		}
	}
	
	//control will reach here if the roll no is not found. Printing Not Found, closing the file, and return
	printf("Not Found\n");
	fclose(details);
	
	return 0;
}
