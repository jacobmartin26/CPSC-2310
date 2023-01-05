/******************************
 *Jacob Martin
 *CPSC 2310 Fall 22 
 *Lab 8 
 *UserName: jmart52
 *Instructor: Dr. Yvon Feaster 
 ******************************/

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef struct header
{
    int w;
    int h;
    int max;
    char num[3];
}header_t;
 
typedef struct pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel_t;

/*Parameters: fp - file pointer that is to be read from (pooh)
 *
 *Return: Returns the completed header_t header (temp) back to driver
 *
 * This function takes in the input ppm image and reads through the header.
 * It will store each aspect of the header into a different part of the 
 * header struct and filter out any comments.
 */
header_t read_header(FILE* fp);

/*Parameters: fp - file pointer that is to be written to
 *            header - stores the header info that is written into
                       fp in order to give it correct properties
 *
 *Return: No return
 *
 * This function takes in the second file pointer and the previously
 * made header. It will write the header info into the file header.
 */
void write_header(FILE* fp, header_t header);

/*Parameters: fp - file that contains comments to be filtered out
 *
 *Return: No return
 *
 * This function will read at the start of a comment to the end of it.
 * This prevents the comments from being written into the 2nd file.
 */
void SkipComment(FILE* fp);

#endif