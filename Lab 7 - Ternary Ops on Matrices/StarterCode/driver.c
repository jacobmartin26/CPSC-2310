/*******************************
 *Jacob Martin                 *
 *CPSC2310 Fall 2022           *
 *UserName: jmart52            *
 *Instructor: Dr. Yvon Feaster *
*******************************/
#include "functions.h"
int main(int argc, char** argv)
{

    if (argc < 2) 
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did nto open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);
    int total = calculateVal(mat, size);
    printf("Total = %d", total);
    printf("\n");

    return 0;
}
