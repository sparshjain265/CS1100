/*
Program Name: plot_fun.c
Programmer: Sparsh Jain
Description: generates a file with x adn y values of a sine wave
Date: 28-09-2016
*/

#include <stdio.h>
#include <math.h>

int main()
	{
		FILE *p;
		float x, y;
		int i;
		
		p = fopen("data03.txt", "w");
		if(p == 0)
			{
				printf("Error in opening file.\n");
				return 1;
			}
		
		for(i = 1; i <= 100; i++)
			{
				x = 2.0*3.14159265*i/100;
				//y = sin(x);
				//y = cos(x);
				//y = sin(x)*sin(x);
				//y = sin(x) + sin(2*x);
				y = sin(1/x);
				
				fprintf(p, "%f\t%f\n", x, y);
			}
		
		fclose(p);
		
		return 0;
	}
	
