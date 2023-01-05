/*************************
* Jacob Martin
* Jackson Moore
* CPSC 2310 - 4
* jmart52@clemson.edu
* jmoor35@clemson.edu
*************************/


#include "ppm.h"

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

pixel_t** read_pixels(FILE* image_file, header_t header)
{
	pixel_t** pix;

	// allocate for rows
	pix = (pixel_t**)malloc(header.height * sizeof(pixel_t*));

	// traverse rows
	for(int i = 0; i < header.height; i++){
		// allocate for columns
	pix[i] = (pixel_t*)malloc(header.width * sizeof(pixel_t));
	fread(pix[i], sizeof(pixel_t), header.width, image_file);
	}

	return pix;
}

void write_header(FILE* out_file, header_t header)
{
   	// writes the header info to output image file
	fprintf(out_file, "%s %d %d %d\n",
	header.magicNum, header.width, header.height, header.maxVal);
}

void free_data(pixel_t** pix, header_t head)
{
	// free rows
	for(int i = 0; i < head.height; i++)
	{
		free(pix[i]);
	}
	// free everything else
	free(pix);
}

void writePixels(FILE* fp, pixel_t** pix, header_t head)
{
	// traverse rows
	for(int i = 0; i < head.height; i++){
		// traverse columns
		fwrite(pix[i], sizeof(pixel_t), head.width, fp);
	}
}

char* printMenu(char* message) {

	printf("Enter P for the provided message or any other key to create a uniqu");
	printf("e message\n");

	char ans;

	scanf("%c", &ans);
	//if user chooses P then default message is encoded
	if(toupper(ans) == 'P') {

		message = "This is the provided message to be encoded!";

	}

	//otherwise, user decides message to be encoded
	else {

		printf("Please enter your unique message to be encoded\n");

		scanf(" %[^\n]%*c", message);

		printf("Thank you for the unique message!\n");

	}


	return message;

}
