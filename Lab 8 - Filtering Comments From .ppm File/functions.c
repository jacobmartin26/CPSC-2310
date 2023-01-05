/******************************
 *Jacob Martin
 *CPSC 2310 Fall 22 
 *Lab 8 
 *UserName: jmart52
 *Instructor: Dr. Yvon Feaster 
 ******************************/

#include "functions.h"
 
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
 
header_t read_header(FILE* fp)
{
    //Variable to act as temporary header
    header_t temp;
 
    //Read in the P6 and then skip comments
    fscanf(fp, "%s\n", temp.num);
    SkipComment(fp);
 
    //Read in the width and then skip comments
    fscanf(fp, "%d ", &temp.w);
    SkipComment(fp);
 
    //Read in the height and then skip comments
    fscanf(fp, "%d\n", &temp.h);
    SkipComment(fp);
 
    //Read in the max val (255)
    fscanf(fp, "%d\n", &temp.max);
 
    //Return the temp header to driver
    return temp;
}
 
void write_header(FILE* fp, header_t header)
{
    //Writes the previously made header to the output file
    fprintf(fp, "%s\n%d\n%d\n%d\n", 
    header.num, header.w, header.h, header.max);
}
