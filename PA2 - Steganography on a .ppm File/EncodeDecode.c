/*************************
* Jacob Martin
* Jackson Moore
* CPSC 2310 - 4
* jmart52@clemson.edu
* jmoor35@clemson.edu
*************************/

#include "ppm.h"
#include "EncodeDecode.h"

void removeNum(pixel_t** pix, header_t head)
{

    // traverse rows
    for(int i = 0; i < head.height; i++)
    {
        // traverse columns
        for(int j = 0; j < head.width; j++)
        {
            // remove number
            pix[i][j].r = (pix[i][j].r / 10) * 10;
            pix[i][j].g = (pix[i][j].g / 10) * 10;
            pix[i][j].b = (pix[i][j].b / 10) * 10;

        }
    }
}

void encode(FILE* input, FILE* output, char* message)
{
    int temp1, temp2;
    int pPos, bPos;
    int bin[9];
    header_t head;
    pixel_t** pix;

    // get header info
    head = read_header(input);

    // get pixel info and remove the specified num
    pix = read_pixels(input, head);

    removeNum(pix, head);

    pPos = 0;
    for(int i = 0; i <= strlen(message); i++)
    {
        // convert to binary
        charToBin(message[i], bin);

        bPos = 0;

        for(int j = 0; j < 3; j++)
        {
            // get position of pixels in the image
            temp1 = pPos % head.width;
            temp2 = pPos / head.width;

            // add bits for each color
            pix[temp2][temp1].r += bin[bPos++];
            pix[temp2][temp1].g += bin[bPos++];
            pix[temp2][temp1].b += bin[bPos++];

            // next position
            pPos++;
        }
    }


    // create the image
    write_header(output, head);
    writePixels(output, pix, head);

    // free everything
    free_data(pix, head);
}

void charToBin(char myChar, int *bin) {

  int asciiChar = (int)myChar;
  int binTemp[9];
  int var = 0;

  //calculates reverse binary number
  for(int i = 0; i < 9; ++i) {

    binTemp[var++] = asciiChar % 2;

    asciiChar = asciiChar / 2;

  }

  var = 7;

  //reverses backwards binary number to get the correct representation
  for(int i = 0; i < 8; ++i) {

      bin[i] = binTemp[var];
      var--;

  }
}

unsigned char binToChar(int* bin)
{
    int count = 0;

    for(int i = 0; i < 8; ++i) {

        count += bin[i];

    }

    //signal that the binary value is all zeroes
    if(count == 0) {

      return 0;

    }
    // first bit is 0
    unsigned char myChar = 0;

    // repeat for other 8 bits
    for(int i = 1; i < 8; i++)
    {

        myChar = (myChar << 1) | bin[i];

    }
    return myChar;
}

int print(int num, int* bin, int* temp)
{
    unsigned char mychar = 0;

    // save num
    bin[(*temp)++] = num;

    if(*temp >= 9)
    {
        // convert to char
        mychar = binToChar(bin);

        // print char
        if(mychar < 255 && mychar > 0)
        {
            printf("%c", mychar);
        }
        //signal to stop
        if(mychar == 0) {
            return 0;
        }

        // reset
        *temp = 0;
    }

    //signal to keep going
    return 1;
}

void decode(FILE* input)
{
    int bPos = 0;
    int bin[9];
    header_t head;
    pixel_t** pix;

    // get header info
    head = read_header(input);

    // get pixel info
    pix = read_pixels(input, head);

    int pixelVar;
    // traverse rows
    for(int i = 0; i < head.height; i++)
    {
        // traverse columns
        for(int j = 0; j < head.width; j++)
        {
            // get digit and pass to print
            pixelVar = print(pix[i][j].r % 10, bin, &bPos);
            pixelVar = print(pix[i][j].g % 10, bin, &bPos);
            pixelVar = print(pix[i][j].b % 10, bin, &bPos);

            //signal to stop decoding
            if (pixelVar == 0) {
              printf("\n");
              free_data(pix, head);
              return;
            }
        }
    }
}
