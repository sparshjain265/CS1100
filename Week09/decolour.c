/*
Program Name: decolor.c
Programmer's Name: Sparsh Jain
Program Description: To convert a ppm color image to pgm grayscale image
Date: 05/10/2016
*/

#include <stdio.h>

int main()
	{
		FILE *img, *gray;
		char image[25], magic[3], decolored[25];
		int width, height, w, h, i, IMG[3], max;
		
		printf("Enter the name of the color image file: ");
		scanf(" %s", image);
		
		img = fopen(image, "r");
		if(img == 0)
			{
				printf("Error #404: File not found!\n");
				return 1;
			}
		fscanf(img, " %s", magic);
		if(magic[0] != 'P' || magic[1] != '3' || magic[2] != '\0')
			{
				fclose(img);
				printf("File format not supported!\n");
				return 1;
			}
		fscanf(img, " %d %d %d", &width, &height, &max);
		if(width > 500 || height > 500)
			{
				fclose(img);
				printf("File too large!\n");
				return 1;
			}		
		
		printf("Enter the name of the grayscale image file: ");
		scanf(" %s", decolored);
		
		gray = fopen(decolored, "w");
		
		fprintf(gray, "P2\n%d %d\n%d\n", width, height, max);
				
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						for(i = 0; i < 3; i++)
							fscanf(img, " %d", &IMG[i]);
						
						fprintf(gray, "%d ", (IMG[0] + IMG[1] + IMG[2])/3);
					}
				fprintf(gray, "\n");
			}
		
		fclose(img);
		fclose(gray);
		
		printf("Operation Successful!\n");
		
		return 0;
	}
