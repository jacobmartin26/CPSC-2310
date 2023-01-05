/*************************
* Jacob Martin
* Jackson Moore
* CPSC 2310 - 4
* jmart52@clemson.edu
* jmoor35@clemson.edu
*************************/


#ifndef PPM_H
#define PPM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

// First meaningful line of the PPM file
typedef struct header
{
   char magicNum[3];
   int width, height, maxVal;
} header_t;

// Represents an RGB pixel with integer values between 0-255
typedef struct pixel
{
   unsigned char r, g, b;
} pixel_t;

// prototypes

/* Parameters: image_file - file pointer of the original input file
 *
 * Return: theHeader - header_t that holds all of the header info
 * of the input file
 *
 * will create a header object, read in the header info from the file
 * into the header object, and return the header object back to read_ppm()
 */
header_t read_header(FILE* image_file);

/* Parameters: out_file - file pointer to output image
 *	       header - header_t that holds header info
 *
 * Return: none
 *
 * will write the header info to the output image file
 */
void write_header(FILE* out_file, header_t header);

/* Parameters: image_file - file pointer to input image
 *	       header - header_t header that was previously created
 *
 * Return: image - pix** holding all pixel values from image_file
 *
 * function to allocate memory for the image
 * and read in the pixel data
 */
pixel_t** read_pixels(FILE* image_file, header_t header);

/* Parameters: pixel_t** holding copy of the input image
 *             header_t holding the header information of the input image
 *
 * Return: none
 *
 * frees all the memory allocated in allocate_memory()
 */
void free_data(pixel_t**, header_t);

/* Parameters: fp - file pointer to input image
 *
 * Return: none
 *
 * called after reading in a part of the header, detects
 * any comments following an operation and reads over them
 * without modifying the file itself
 */
void SkipComment(FILE* fp);

/* Parameters: FILE* - file pointer to the image being written to
 *             pixel_t** - holding the pixels value to be written
 *             header_t - holding the header information of the image
 *
 *Return: none
 *
 * Used to write pixels back to an output image once they have been copied
 * or manipulated
 */

void writePixels(FILE*, pixel_t**, header_t);

/* Parameters: none
 *
 *Return: char* - the message to be encoded
 *
 * Used to get input from the user on whether or not they want to create
 * a unique message, and asks them for that message if so
 */

char* printMenu();

#endif
