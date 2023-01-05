/*******************************
 *Jacob Martin                 *
 *CPSC2310 Fall 2022           *
 *UserName: jmart52            *
 *Instructor: Dr. Yvon Feaster *
*******************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int** readFile(FILE* fp, int *size);
int calculateVal(int** mat, int size);
bool isRightDiagonal(int size, int row, int col);
bool isLeftDiagonal(int row, int col); 
void printMatrix (int** mat, int num);

#endif
