/*
Program Name: substring2.c
Programmer	: Sparsh Jain
Description : to check whether a given string is a substring of the other using string library functions
Date			: 12/10/2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char big[201], small[201], *p, c_big[201], c_small[201];
	int i, l_big, l_small;
	
	printf("Enter main string: ");
	scanf(" %200[^\n]", big);
	l_big = strlen(big);
	for(i = 0; i < l_big; i++)
		c_big[i] = tolower(big[i]);
	
	printf("Enter string you want to find: ");
	scanf(" %200[^\n]", small);
	l_small = strlen(small);
	for(i = 0; i < l_small; i++)
		c_small[i] = tolower(small[i]);
	
	p = strstr(c_big, c_small);
	
	if(p == 0)
		printf("%s is not a substring of %s.\n", small, big);
	else
		printf("%s is a substring of %s, starting from position %d.\n", small, big, (int)(p - c_big));
	
	return 0;
}
