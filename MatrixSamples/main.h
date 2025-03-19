#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ROWS 3
#define NO_OF_COLS 3
#define MIN -10
#define MAX 10
#define NL printf("\n")

void randomInput(int data[][NO_OF_COLS],unsigned rows,unsigned cols);
void printMatrix(int data[][NO_OF_COLS],unsigned rows,unsigned cols);
int sumMD(int data[][NO_OF_COLS],unsigned cols);
int minBelowMD(int data[][NO_OF_COLS],unsigned cols);
int maxAboveMD(int data[][NO_OF_COLS],unsigned cols);
void averageByCols(int data[][NO_OF_COLS],unsigned rows,unsigned cols,float avrs[]);
void printArray(float data[],unsigned cols);
void printUnsignedArray(unsigned data[],unsigned cols);

#endif // MAIN_H_INCLUDED
