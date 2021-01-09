/*
Program Name: transpose.c
Programmer's Name: Sparsh Jain
Description: transpose a given image file
Date: 05/10/2016
*/

#include <stdio.h>

int main()
	{
		FILE *img;
		char image[25], magic_number[3];
		int width, height, w, h, maximum, temp, IMG[500][500];
		
		printf("Enter the name of the image file: ");
		scanf(" %s", image);
		img = fopen(image, "r");
		if(img == 0)
			{
				printf("Couldn't open the file. Kindly recheck the file name and try again.\n");
				return 1;
			}
		
		fscanf(img, " %3s", magic_number);
		if(magic_number[0] != 'P' || magic_number[1] != '2' || magic_number[2] != '\0')
			{
				fclose(img);
				printf("Invalid File Format! Try again!\n");
				return 1;
			}
		
		fscanf(img, " %d %d %d", &width, &height, &maximum);
		
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
				{
					fscanf(img, " %d", &IMG[h][w]);
				}
			}
		fclose(img);
		
		printf("Enter the name of the transposed image file: ");
		scanf(" %s", image);
		img = fopen(image, "w");
		
		fprintf(img, "%s\n%d %d\n%d\n", magic_number, height, width, maximum);
		
		for(h = 0; h < width; h++)
			{
				for(w = 0; w < height; w++)
					{
						fprintf(img, "%d ", IMG[w][h]);
					}
				fprintf(img, "\n");
			}
		fclose(img);
		
		printf("File created successfully.\n");				
		
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
