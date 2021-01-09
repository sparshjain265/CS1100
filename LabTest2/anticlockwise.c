/*
Program Name			: anticlockwise.c
Programmer's Name		: Sparsh Jain
Programmer's Roll No.: 111601026
Description				: reads an image file, and creates a new "anticlockwise" version of it
Date						: 26/10/2016
*/

#include <stdio.h>

int main()
	{
		//File pointer img to read/write an image file
		FILE *img;
		
		//string image to store the name of the image file, magic_number to store the magic number of the image file
		char image[50], magic_number[3];
		
		//width and height to store the width and height of the image file, w and h to be used as counter in loops corresponding to width and height
		//maximum to store the maximum value a pixel can store
		//arrays IMG and R, one to store values of the image file, other to rotate it, then original one to rotate it further, and so on
		//array NEW to store the values of the final image file
		int width, height, w, h, maximum, IMG[500][500], R[500][500], NEW[1000][1000];
		
		//opening an image file
		printf("Enter the name of the image file: ");
		scanf(" %s", image);
		img = fopen(image, "r");
		
		//condition to check whether the file was successfully opened! To print an error message if not!
		if(img == 0)
			{
				printf("Couldn't open the file. Kindly recheck the file name and try again.\n");
				return 1;
			}
		
		//reading the magic_number of the file. If the file is not a .pgm image, to print an error message
		fscanf(img, " %3s", magic_number);
		if(magic_number[0] != 'P' || magic_number[1] != '2' || magic_number[2] != '\0')
			{
				fclose(img);
				printf("Invalid File Format! Try again!\n");
				return 1;
			}

		//reading width, height, and maximum value of a pixel
		fscanf(img, " %d %d %d", &width, &height, &maximum);
		
		//loop for storing the image file in a 2D Array (IMG) to process it; then closing the image file as it will no longer be required
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						fscanf(img, " %d", &IMG[h][w]);
					}
			}
		fclose(img); 		
		
		//loop for placing the IMG into 3rd quadrant; rotating IMG by 90 deg anticlockwise and storing it in R
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						NEW[width + h][w] = IMG[h][w];
						R[width - (w+1)][h] = IMG[h][w];
					}
			}		
		
		//loop for placing the R into 4th quadrant; rotating R by 90 deg anticlockwise and storing it in IMG
		for(w = 0; w < width; w++)
			{
				for(h = 0; h < height; h++)
					{
						NEW[height + w][width + h] = R[w][h];
						IMG[height - (h+1)][w] = R[w][h];
					}
			}
			
		//loop for placing the IMG into 2nd quadrant; rotating IMG by 90 deg anticlockwise and storing it in R
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						NEW[h][height + w] = IMG[h][w];
						R[width - (w+1)][h] = IMG[h][w];
					}
			}
		
		//loop for placing the R into 1st quadrant
		for(w = 0; w < width; w++)
			{
				for(h = 0; h < height; h++)
					{
						NEW[w][h] = R[w][h];
					}
			}		
		
		//changing height and width to new dimensions
		height = height + width;
		width = height;
		
		//opening an image file to store the processed image file
		printf("Enter the name of the processed image file: ");
		scanf(" %s", image);
		img = fopen(image, "w");
		
		//adding proper magic_number, width, height, and maximum value of a pixel in the image file
		fprintf(img, "%s\n%d %d\n%d\n", magic_number, width, height, maximum);
		
		//loop to add the values of processed image (NEW) in the image file; then closing the image file as it will no longer be required
		for(h = 0; h < height; h++)
			{
				for(w = 0; w < width; w++)
					{
						fprintf(img, "%d ", NEW[h][w]);
					}
				fprintf(img, "\n");
			}
		fclose(img);
		
		//printing the success message
		printf("File created successfully.\n");		
		
		return 0;
	}
