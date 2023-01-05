/*************************
 * Jacob Martin
 *
 * CPSC 2311 F22 Section 04
 *
 * jmart52@clemson.edu
 *
 **************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lab3Fscan.h"

int main(int argc, char* argv[])
{
    //Checks arguments
    assert(argc > 1);

    //Create and open file
    FILE* myFile = fopen(argv[1], "r");
    assert(myFile != NULL);

    //Start reading/modifying
    start(myFile);

    //Close file
    fclose(myFile);

    return 0;
}
