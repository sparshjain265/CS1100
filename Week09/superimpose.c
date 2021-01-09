/*
Program Name: superimpose.c
Programmer's Name: Sparsh Jain
Program Description: To create a new image by superimposing the two given images
Date: 05/10/2016
*/

#include <stdio.h>

int main()
	{
		FILE *img;
		char image[25], magic_number[3];
		int width, height, w, h, maximum, IMG[500][500], temp[3];
		
		printf("Enter the name of first image file : ");
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
		
		printf("Enter the name of second image file : ");
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
		
		fscanf(img, " %d %d %d", &temp[0], &temp[1], &temp[2]);
		if(temp[0] != width || temp[1] != height)	
			{
				fclose(img);
				printf("The two images are not of same size.\n");
				return 1;
			}
		else if(temp[2] > maximum)
			maximum = temp[2];
		
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						fscanf(img, "%d", &temp[2]);
						IMG[h][w] = (IMG[h][w] + temp[2])/2;
					}
			}
		fclose(img);
					
		printf("Enter the name for the superimposed image file : ");
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
