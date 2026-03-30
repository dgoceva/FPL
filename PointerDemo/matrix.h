#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10
#define NL printf("\n")

size_t input2D(int a[][SIZE]);
void output2D(int a[][SIZE],size_t size);
int maxMD(int a[][SIZE],size_t size);
int sumBelowMD(int a[][SIZE],size_t size);
float averageAboveMD(int a[][SIZE],size_t size);

int minSD(int a[][SIZE],size_t size);
long multiplicationBelowSD(int a[][SIZE],size_t size);
int sumOddAboveSD(int a[][SIZE],size_t size);

#endif // MATRIX_H_INCLUDED
