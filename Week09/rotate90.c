/*
Program Name: rotate90.c
Programmer's Name: Sparsh Jain
Description: rotate an image by 90 deg
Date: 05/10/2016
*/

#include <stdio.h>
#include <string.h>

int main()
	{
		FILE *img;
		char image[25], magic_number[3];
		int width, height, w, h, c, l, maximum, temp, IMG[500][500][3], R[500][500][3];
		
		printf("Enter the name of the image file: ");
		scanf(" %s", image);
		img = fopen(image, "r");
		if(img == 0)
			{
				printf("Couldn't open the file. Kindly recheck the file name and try again.\n");
				return 1;
			}
		
		fscanf(img, " %3s", magic_number);
		if(magic_number[0] != 'P' || magic_number[1] != '3' || magic_number[2] != '\0')
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
						for(c = 0; c < 3; c++)
							{
								fscanf(img, " %d", &IMG[h][w][c]);
							}
					}
			}
		fclose(img);
		
		
		
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						for(c = 0; c < 3; c++)
						{
							R[width - (w+1)][h][c] = IMG[h][w][c];
						}
					}
			}		
		
		printf("Enter the name of the rotated image file: ");
		scanf(" %s", image);
		img = fopen(image, "w");
		temp = height;
		height = width;
		width = temp;
		l = strlen(image);
		if(image[l-2] == 'p')
		{		
			fprintf(img, "%s\n%d %d\n%d\n", magic_number, width, height, maximum);
		
			for(h = 0; h < height; h++)
				{
					for(w = 0; w < width; w++)
						{
							for(c = 0; c < 3; c++)
								{
									fprintf(img, "%d ", R[h][w][c]);
								}
						}
					fprintf(img, "\n");
				}
		}
		else
		{		
			strcpy(magic_number, "P2");
			fprintf(img, "%s\n%d %d\n%d\n", magic_number, width, height, maximum);
		
			for(h = 0; h < height; h++)
				{
					for(w = 0; w < width; w++)
						{
							fprintf(img, "%d ", (R[h][w][0] + R[h][w][1] + R[h][w][2])/3);
						}
					fprintf(img, "\n");
				}
		}		
		
		fclose(img);
		
		printf("File created successfully.\n");		
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
