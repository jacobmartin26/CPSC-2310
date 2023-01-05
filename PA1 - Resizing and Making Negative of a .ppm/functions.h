/*************************
* Jacob Martin
* CPSC 2310 - 4
* jmart52@clemson.edu
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

// PPM Image representation
typedef struct image 
{
   header_t header;
   pixel_t** pixels;
} image_t;

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
 * called from write_p6() function
 */
void write_header(FILE* out_file, header_t header);

/* Parameters: image_file - input file pointer
 * 
 * Return: image - image_t* copy of input file
 *
 * called from the main() function
 * first calls read_header() to initialize header info
 * then forwards the header on to  read_pixels() where
 * space will be allocated for the entire image and 
 * the pixel data will be read
 */
image_t* read_ppm(FILE* image_file);

/* Parameters: image_file - file pointer to input image
 *	       header - header_t header that was previously created
 * 
 * Return: image - image_t* copy of input image
 *
 * function to allocate memory for the image
 * and read in the pixel data 
 */
image_t* read_pixels(FILE* image_file, header_t header);

/* Parameters: header - header_t from read_pixels()
 * 
 * Return: image - image_t* copy of input with ample space allocated
 *
 * will use the header info to allocate memory for the image
 */
image_t* allocate_memory(header_t header);

/* Parameters: image - image_t* copy of input image
 *	       fp - file pointer to output image
 * 
 * Return: none
 *
 * takes the copy of the input image, resizes the dimensions
 * to user specified measurments, and then passes it all to
 * write_p6() to create the resized output image
 */
void resize(image_t* image, FILE* fp);

/* Parameters: image - image_t* copy of input image
 *	       fp - file pointer to output image
 * 
 * Return: none
 *
 * takes the copy of the input image, makes a negative of the
 * color values of each pixel, and then passes it all to
 * write_p6() to create the negative output image
 */
void negative(image_t* image, FILE* fp);

/* Parameters: out_file - file pointer to output image
 * 	       image - image_t* pointer to image copy
 * 
 * Return: none
 *
 * writes the image to the output image file
 */
void write_p6(FILE* out_file, image_t* image1);

/* Parameters: image - image_t* copy of input image
 * 
 * Return: none
 *
 * frees all the memory allocated in allocate_memory()
 */ 
void free_data(image_t* image);

/* Parameters: fp - file pointer to input image
 * 
 * Return: none
 *
 * called after reading in a part of the header, detects
 * any comments following an operation and reads over them
 * without modifying the file itself
 */
void SkipComment(FILE* fp);

/* Parameters: image - image_t* copy of input image
 * 
 * Return: none
 *
 * prints the dimensions of the copy of the input image,
 * helps the user see the width and height so they know
 * the minimum/maximum values they are allowed to enter
 * in resize()
 */
void print_dimensions(image_t* image);

/* Parameters: image - image_t* copy of input image
 * 
 * Return: userWidth - int that holds the desired amount
 * that the width is to be resized by, returns back to resize()
 *
 * prompts the user for how much the width is to be resized by,
 * validates to make sure the width after resizing will not
 * be negative after resizing
 */
int get_width(image_t* image);

/* Parameters: image - image_t* copy of input image
 * 
 * Return: userHeight - int that holds the desired amount
 * that the height is to be resized by, returns back to resize()
 *
 * prompts the user for how much the height is to be resized by,
 * validates to make sure the height after resizing will not
 * be negative after resizing
 */
int get_height(image_t* image);

#endif
