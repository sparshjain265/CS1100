/*
Program Name: substring1.c
Programmer	: Sparsh Jain
Description : to check whether a given string is a substring of the other without using string library functions
Date			: 12/10/2016
*/

#include <stdio.h>

int main()
{
	char str1[100], str2[100];
	int l1, l2, i, found = -100;
	
	printf("Enter first string: ");	
	for(i = 0; i < 99; i++)
	{
		str1[i] = getchar();
		if(str1[i] == '\n')
			break;
	}
	str1[i] = '\0';
	l1 = i;
	if(i == 99)
		while(getchar() != '\n');
		
	printf("Enter second string: ");	
	for(i = 0; i < 99; i++)
	{
		str2[i] = getchar();
		if(str2[i] == '\n')
			break;
	}
	str2[i] = '\0';
	l2 = i;
	if(i == 99)
		while(getchar() != '\n');
	
	if(l1 > l2)
		printf("%s is not a substring of %s.\n", str1, str2);
	else
	{
		for(i = 0; i < 99; i++)
		{
			if(str2[i] == str1[0])
			{
				for(found = i; (i - found) < l1; i++)
				{
					if(str2[i] != str1[i - found])
					{
						found = -100;
						break;
					}
				}				
			}
			if((i - found) == l1)
				break;			
		}
		if((i - found) == l1)
			printf("%s is a substring of %s, starting from position %d\n", str1, str2, found);
		else
			printf("%s is not a substring of %s.\n", str1, str2);
	}
		
	return 0;
}
