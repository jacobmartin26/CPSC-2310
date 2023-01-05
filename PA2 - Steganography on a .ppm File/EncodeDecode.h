/*************************
* Jacob Martin
* Jackson Moore
* CPSC 2310 - 4
* jmart52@clemson.edu
* jmoor35@clemson.edu
*************************/


#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ppm.h"


/* Parameters: int* - the binary number to be coverted
 *
 * Return: unsigned char - the char that the binary number coverts to
 *
 * converts binary number to char
 */
unsigned char binToChar(int*);

/* Parameters: char - char to be converted
 * 	           int* - pointer to memory location of binary number
 *
 * Return: none
 *
 * converts char to binary number
 */
void charToBin(char, int *);

/* Parameters: int - pixel value to be manipulated
 * 	           int* - the binary number of that pixel value
 *             int* - binary representation of the char in the array
 *
 * Return: int - 1 or 0 to determine if we have reached the end of the message
 *
 * calls binToChar to convert num to a char, then prints that char
 */
int print(int, int*, int*);

/* Parameters: pixel_t** - the pixel values of the input image
 * 	           header_t - the header information of the input image
 *
 * Return: none
 *
 * strips the last digit from each pixel value
 */
void removeNum(pixel_t**, header_t);

/* Parameters: input - the file to be encoded
 * 	           output - a pointer to the location of the encoded image
 *             message - the message to be encoded into the image
 *
 * Return: none
 *
 * encodes message into the input image, puts encoded image into output
 * calls functions to encode the binary representation of each character in the
 * message to the image
 */
void encode(FILE* input, FILE* output, char* message);

/* Parameters: FILE* - the image to be decoded
 *
 * Return: none
 *
 * decodes a message from an image; prints each char in the decoded message
 * by coverting its binary representation to its ascii value
 */
void decode(FILE*);

#endif
