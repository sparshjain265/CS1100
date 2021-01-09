/*
Program Name: flipud.c
Programmer's Name: Sparsh Jain
Program Description: To create a up to down flipped image of a given image
Date: 05/10/2016
*/

#include <stdio.h>

int main()
	{
		FILE *img;
		char image[25], magic_number[3];
		int width, height, w, h, maximum, IMG[500][500], temp;
		
		printf("Enter the name of the image file : ");
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
						fscanf(img, "%d", &IMG[h][w]);
					}
			}
		fclose(img);
		
		for(h = 0; h < (height/2); h++)
			{
				for(w = 0; w < width; w++)
					{
						temp = IMG[h][w];
						IMG[h][w] = IMG[height - (h + 1)][w];
						IMG[height - (h + 1)][w] = temp;
					}					
			}
		
		printf("Enter the name for the up to down flipped image file : ");
		scanf(" %s", image);		
		
		img = fopen(image, "w");
		if(img == 0)
			{
				printf("Unexpected error in creating file!\n");
				return 1;
			}
			
		fprintf(img, "P2\n%d %d\n%d\n", width, height, maximum);
		
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						fprintf(img, "%d ", IMG[h][w]);
					}
				fprintf(img, "\n");
			}
		fclose(img);
		printf("File %s is created!\n", image);
		
		return 0;
	}
