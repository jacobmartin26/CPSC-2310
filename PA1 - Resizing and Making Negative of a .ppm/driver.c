/*************************
* Jacob Martin
* CPSC 2310 - 4
* jmart52@clemson.edu
*************************/

#include "functions.h"

int main(int argc, char* argv[]) 
{
	// declare 3 file pointers
	FILE* input = fopen(argv[1], "r");
	FILE* resizedImg = fopen(argv[2], "w");
	FILE* negativeImg = fopen(argv[3], "w");
	
	// check for correct number of arguments entered on the command-line
	assert(argc == 4);

	// check that the files opened successfully
	assert(input != NULL);
	assert(resizedImg != NULL);
	assert(negativeImg != NULL);

	// make a copy of input image
	image_t* copyForResize = read_ppm(input);
	resize(copyForResize, resizedImg);

	// reset file pointer to start of input file
	rewind(input);	

	// another copy of input image
	image_t* copyForNegative = read_ppm(input);
	negative(copyForNegative, negativeImg);


	fclose(input);
	return 0;
}
