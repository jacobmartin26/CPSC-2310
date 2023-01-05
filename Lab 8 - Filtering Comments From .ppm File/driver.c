/******************************
 *Jacob Martin
 *CPSC 2310 Fall 22 
 *Lab 8 
 *UserName: jmart52
 *Instructor: Dr. Yvon Feaster 
 ******************************/

#include "functions.h"
 
int main(int argc, char* argv[])
{
    //Create & open file pointers for the two needed files
    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "w");

    //Check for proper # of arguments
    assert(argc == 3);
 
    //Check that files opened correctly
    assert(fp1 != NULL);
    assert(fp2 != NULL);
 
    //Call function to read header of input file
    header_t myHeader = read_header(fp1);

    //Write header info to output file
    write_header(fp2, myHeader);
 
    //Calculate size of width * height for later use
    size_t size = myHeader.w * myHeader.h;
 
    //Allocate memory for all pixels in the image
    pixel_t* pixels = (pixel_t*)malloc(size * sizeof(pixel_t));
 
    //Read all pixel vals at once and store in memory
    fread(pixels, sizeof(pixel_t), size, fp1);
 
    //Write all pixel values to output file
    fwrite(pixels, sizeof(pixel_t), size, fp2);
 
    //Free allocated memory
    free(pixels);

    //Close file pointers
    fclose(fp1);
    fclose(fp2);
}