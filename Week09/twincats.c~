/*
Program Name: decolor.c
Programmer's Name: Sparsh Jain
Program Description: To superimpose a flipped image on the given image file
Date: 05/10/2016
*/

#include <stdio.h>

int main()
	{
		FILE *img;
		char image[25], magic[3];
		int width, height, w, h, i, IMG[500][500][3], n[500][500][3], max;
		
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
				
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						for(i = 0; i < 3; i++)
							fscanf(img, " %d", &IMG[h][w][i]);						
					}
			}
		
		fclose(img);
		
		printf("Enter the name of the new image file: ");
		scanf(" %s", image);
		
		img = fopen(image, "w");
		
		fprintf(img, "P3\n%d %d\n%d\n", width, height, max);
		
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						for(i = 0; i < 3; i++)
							{
								n[h][w][i] = IMG[h][width - (w + 1)][i];					
							}
					}
				for(w = 0; w < width; w++)
					{
						n[h][w][2] = max - n[h][w][2];
						n[h][w][0] = max - IMG[h][w][0];
						n[h][w][1] = 0;				
					}
			}
		
				
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						for(i = 0; i < 3; i++)
							{
								fprintf(img, "%d ", n[h][w][i]);
							}
					}
				fprintf(img, "\n");				
			}
		
		fclose(img);

		printf("Operation Successful!\n");
		
		return 0;
	}
