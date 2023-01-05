/*******************************
 *Jacob Martin                 *
 *CPSC2310 Fall 2022           *
 *UserName: jmart52            *
 *Instructor: Dr. Yvon Feaster *
*******************************/

#include "functions.h"

int** readFile(FILE* fp, int *size)
{
    fscanf(fp, "%d", size);
    int num = *size;
    int index = 0;
    
    int** mat = (int**)malloc(num * sizeof(int*));
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); 

    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            fscanf(fp, "%d", &mat[row][col]);
        }
    }
    return mat;
}


void printMatrix (int** mat, int num)
{
    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }
    
}

int calculateVal(int** mat, int size)
{
    int sum = 0;
    int right = 0;
    int left = 0;

    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            if(isRightDiagonal(size, row, col))
            {
                right += mat[row][col];
            }
            else if(isLeftDiagonal(row, col))
            {
                left += mat[row][col];
            }
            sum += mat[row][col];
        }
    }
    sum = (sum - right) - left;
    return sum;
}

bool isRightDiagonal(int size, int row, int col)
{
    return ((col + row) == (size - 1) ? true : false);
}

bool isLeftDiagonal(int row, int col)
{
    return (col == row ? true : false);
}
