#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LEN 10
#define MIN 0
#define MAX 20

#define NL printf("\n")

typedef enum {false,true} tboolean;

void randomData(int *array, unsigned size);
void printData(int *array, unsigned size);
int sumOddData(int *array, unsigned size);
tboolean isOdd(int data);

#endif // ARRAY_H_INCLUDED
