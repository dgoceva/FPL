#include "array.h"

void randomData(int *array, unsigned size)
{
    for (int i=0;i<size;++i){
        array[i] = rand()%(MAX-MIN+1)+MIN;
    }
}
void printData(int *array, unsigned size)
{
    for (int i=0;i<size;++i){
        printf("%d\t",array[i]);
    }
    NL;
}

int sumOddData(int *array, unsigned size)
{
    int sum=0;
    for(int i=0;i<size;++i){
        if (isOdd(array[i]))
            sum += array[i];
    }
    return sum;
}

tboolean isOdd(int data)
{
    return data%2!=0 ? true : false;
}
