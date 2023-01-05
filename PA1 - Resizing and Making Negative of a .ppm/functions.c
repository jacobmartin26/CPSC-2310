/*************************
* Jacob Martin
* CPSC 2310 - 4
* jmart52@clemson.edu
*************************/

#include "functions.h"

image_t* read_ppm(FILE* image_file) 
{
	// call read_header function
	header_t header = read_header(image_file);

	// call read_pixels function
	image_t* image = read_pixels(image_file, header);

	return image;
}

header_t read_header(FILE* image_file) 
{
	// will hold the header info of input image
	header_t theHeader;

	// assigns values from input image to theHeader
	// then skips any comments after an operation
	fscanf(image_file, "%s\n", theHeader.magicNum);
	SkipComment(image_file);

	fscanf(image_file, "%d\n", &theHeader.width);
	SkipComment(image_file);

	fscanf(image_file, "%d\n", &theHeader.height);
	SkipComment(image_file);

	fscanf(image_file, "%d\n", &theHeader.maxVal);

	return theHeader;
}

void SkipComment(FILE* fp)
{
    	//Buffer
	char buff[200];

    	//Char to start at start of comment
    	char check1 = fgetc(fp);

    	//While at start of comment
    	while(check1 == '#')
    	{
        	//Read up to newline using scanset
        	fscanf(fp, "%[^\n] ", buff);

        	//Read final char
        	fscanf(fp, "%c", &check1);
    	}

    	//Go back one position w/ file pointer
    	fseek(fp, -1, SEEK_CUR);
}

image_t* read_pixels(FILE* image_file, header_t header) 
{
	int row = 0, col = 0;

	// serves as a copy of the input file
	image_t *image;

	unsigned char red, green, blue = 0;

	// call allocate_memory function
	image = allocate_memory(header);

	for(row = 0; row < header.height; row++) 
	{
		for(col = 0; col < header.width; col++) 
		{
			// assign pixel vals from input file to image
			fscanf(image_file, "%c%c%c", &red, &green, &blue);
			image->pixels[row][col].r = red;
			image->pixels[row][col].g = green;
			image->pixels[row][col].b = blue;
		}
	}

	return image;
}

image_t* allocate_memory(header_t header) 
{
	int row;

	/* 
	 * First allocate memory for the image_t. The image_t
	 * has a header and a double pointer for the pixels 
	 * */
	image_t* image = (image_t*) malloc(sizeof(image_t));

	/* 
	 * After you have allocated the memory for the image_t, 
	 * you can now set the header equal to the header passed in. 
	 */
	image->header = header;

	/*
	 * Now we need to allocate the memory for the actual pixels. 
	 * This is a 2d array so allocate for the 2D array. 
	 */
	
	// allocate space for the first part of image->pixels 
	image->pixels = 
		(pixel_t **) malloc(sizeof(pixel_t*) * image->header.height);


	// now allocate space for the pixels in each row of the image
	for(row = 0; row < image->header.height; row++)
	{
		image->pixels[row] = 
			(pixel_t*) malloc(sizeof(pixel_t) * image->header.width);
	}

	return image;
}

void resize(image_t* image, FILE* fp) 
{
	// displaye current dimensions
	print_dimensions(image);

	int userWidth = get_width(image);
	int userHeight = get_height(image);

	printf("\nResizing width by %d and height by %d\n", userWidth, userHeight);

	// temporary image_t to hold the desired header dimensions
        // not calling my allocate function as it will allocate
        // for pixels too which are not needed here
	image_t* temp = (image_t*)malloc(sizeof(image_t));
	temp->header = image->header;
	temp->header.height = image->header.height + userHeight;
	temp->header.width = image->header.width + userWidth;

	// newImg holds the malloc'd temp header and updated dimensions
	image_t* newImg = allocate_memory(temp->header);
	newImg->header.height = image->header.height + userHeight;
	newImg->header.width = image->header.width + userWidth;

	double relativeWidth = image->header.width / (double)newImg->header.width;
	double relativeHeight = image->header.height / (double)newImg->header.height;

	for(int i = 0; i < newImg->header.height; i++) 
	{
		for(int j = 0; j < newImg->header.width; j++) 
		{
			int row = i * relativeHeight;
			int col = j * relativeWidth;

			// sets appropriate pixel values to newImg from image
			newImg->pixels[i][j].r = image->pixels[row][col].r;
			newImg->pixels[i][j].g = image->pixels[row][col].g;
			newImg->pixels[i][j].b = image->pixels[row][col].b;
		}
	}

	// calls write function to create the finalized image	
	write_p6(fp, newImg);

	// free and close everything
	free_data(image);
	free_data(newImg);
	free(temp);
	fclose(fp);

	printf("\nFinished resizing the image\n");
}

void print_dimensions(image_t* image)
{
	// prints the dimensions of the original image
	// now user can see the dimensions to assist in validation
	printf("Current header dimensions are:\n");
	printf("Width: %d\nHeight: %d\n\n", image->header.width, 
					    image->header.height);

	printf("How much do you want to resize the image by?\n");
}

int get_width(image_t* image)
{
	int userWidth = 0;

	// prompt for amount to resize by
	printf("Resize width by: ");
	scanf("%d", &userWidth);

	// input validation
	while(image->header.width + userWidth <= 0) 
	{
		printf("Invalid resize choice, please try again\n");
		printf("Resize width by: ");
		scanf("%d", &userWidth);
	}
	return userWidth;
}

int get_height(image_t* image)
{
	int userHeight = 0;

	// prompt for amount to resize by
	printf("Resize height by: ");
	scanf("%d", &userHeight);

	// input validation
	while(image->header.height + userHeight <= 0) 
	{
		printf("Invalid resize choice, please try again\n");
		printf("Resize height by: ");
		scanf("%d", &userHeight);
	}
	return userHeight;
}

void negative(image_t* image, FILE* fp)
{
	printf("Creating a negative of the image\n");
	
	// temporary image_t to hold the desired header dimensions
	// not calling my allocate function as it will allocate
	// for pixels too which are not needed here
	image_t* temp = (image_t*)malloc(sizeof(image_t));
	temp->header = image->header;
	temp->header.height = image->header.height;
	temp->header.width = image->header.width;

	// newImg holds the malloc'd temp header
	image_t* newImg = allocate_memory(temp->header);
	newImg->header.height = image->header.height;
	newImg->header.width = image->header.width;

	for(int i = 0; i < newImg->header.height; i++) 
	{
		for(int j = 0; j < newImg->header.width; j++) 
		{
			// assigns the negative colors to newImg pixels
			newImg->pixels[i][j].r = 255 - image->pixels[i][j].r;
			newImg->pixels[i][j].g = 255 - image->pixels[i][j].g;
			newImg->pixels[i][j].b = 255 - image->pixels[i][j].b;
		}
	}

	// calls write function to create the finalized image	
	write_p6(fp, newImg);

	// free and close everything
	free_data(image);
	free_data(newImg);
	free(temp);
	fclose(fp);

	printf("\nFinished creating the negative\n");
}

void write_p6(FILE* out_file, image_t* image) 
{
	int row = 0;
	int col = 0;

	// temporary header from copied image header
	header_t header = image->header;

	write_header(out_file, header);

	//Loop through the image and print each pixel
	for(row = 0; row < header.height; row++) 
	{
		for(col = 0; col < header.width; col++) 
		{ 
			fprintf(out_file, "%c%c%c",
			image->pixels[row][col].r,
			image->pixels[row][col].g,
			image->pixels[row][col].b);
		}
	}
}

void write_header(FILE* out_file, header_t header) 
{
   	// writes the header info to output image file
	fprintf(out_file, "%s %d %d %d ", 
	header.magicNum, header.width, header.height, header.maxVal);
}

void free_data(image_t* image)
{
	// free the data in the array first
	for(int i = 0; i < image->header.height; i++)
	{
		free(image->pixels[i]);
	}

	// then free data pointing to the array
	free(image->pixels);
}
