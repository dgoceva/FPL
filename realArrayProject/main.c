#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10
#define MIN -10
#define MAX 10
#define BOOL int
#define FALSE 0
#define TRUE !FALSE

void inputRandom(double *data, unsigned len, BOOL customseed)
{
    if (customseed)
        srand(time(NULL));

    for (unsigned i=0;i<len;++i){
        data[i] = rand()%(MAX-MIN+1)+MIN;
    }
}

void outputArray(double *data, unsigned len)
{
    for (unsigned i=0;i<len;++i){
        printf("%g\t",data[i]);
    }
    printf("\n");
}

int maxNegative(double data[], unsigned len)
{
    int index=-1;
    for (int i=0;i<len;++i){
        if (data[i]<0){
            if (index == -1)
                index = i;
            else if (data[index]<data[i])
                index = i;
        }
    }
    return index;
}
double minValue(double data[], unsigned len)
{
    double min=data[0];
    for (int i=1;i<len;++i){
        if (min>data[i])
            min = data[i];
    }
    return min;
}
double maxValue(double data[], unsigned len)
{
    double max=data[0];
    for (int i=1;i<len;++i){
        if (max<data[i])
            max = data[i];
    }
    return max;
}
unsigned countValue(double data[], unsigned len, double value)
{
    unsigned counter=0;
    for (int i=0;i<len;++i){
        if (data[i]==value)
            counter++;
    }
    return counter;
}
unsigned removeNegatives(double *data, unsigned len)
{
    unsigned i,j;

    for (i=j=0;i<len;++i){
        if (data[i]>=0)
            data[j++] = data[i];
    }
    return j;
}
void moveData(double *data, unsigned len)
{
    for (int i=0;i<len;++i)
        data[i+len] = data[i];
}

unsigned insertNegatives(double *data, unsigned len)
{
    unsigned j=0;
    moveData(data,len);
    for (unsigned i=len;i<len*2;++i){
        data[j++] = data[i];
        if (data[i]>0)
            data[j++]=data[i]*(-1);
    }
    return j;
}
unsigned copyNegatives(double *source, unsigned src_len, double *dest)
{
        unsigned dest_index=0;

        for (int i=0;i<src_len;++i)
            if (source[i]<0)
                dest[dest_index++] = source[i];

        return dest_index;
}
int main()
{
    double data[LEN*2],output[LEN];
    int index;
    double max;
    unsigned size,output_size;

    inputRandom(data,LEN,!TRUE);
    outputArray(data,LEN);
    index = maxNegative(data,LEN);
    if (index == -1)
        printf("No such data...\n");
    else
        printf("Max negative: %g\n",data[index]);
    printf("Min value is %g\n",minValue(data,LEN));
    max = maxValue(data,LEN);
    printf("Max value is %g. It\'s %u times in the array.\n",
           max,countValue(data,LEN,max));

    size = insertNegatives(data,LEN);
    outputArray(data,size);

    output_size = copyNegatives(data,size,output);
    outputArray(output,output_size);

    size = removeNegatives(data,size);
    if (size==0)
        printf("Empty array\n");
    else
        outputArray(data,size);

    return 0;
}
