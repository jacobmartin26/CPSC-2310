/*************************
* Jacob Martin
* Jackson Moore
* CPSC 2310 - 4
* jmart52@clemson.edu
* jmoor35@clemson.edu
*************************/


#include "ppm.h"
#include "EncodeDecode.h"

int main(int argc, char* argv[])
{
	// declare 3 file pointers
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");

	// check for correct number of arguments entered on the command-line
	assert(argc == 3);

	// check that the files opened successfully
	assert(input != NULL);
	assert(output != NULL);

	// creates and gets message
	char* message = malloc(sizeof(char) * 1000);

	message = printMenu(message);

	// encode the message
	encode(input, output, message);

	// file pointer to aid in decode
	FILE* newFP = fopen(argv[2], "r");

	// decode the message from output file
	decode(newFP);

	// close everything
	fclose(input);
	fclose(output);
	fclose(newFP);
	return 0;
}
