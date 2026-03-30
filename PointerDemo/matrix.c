#include "matrix.h"

size_t input2D(int a[][SIZE]){
    size_t size;

    do {
        printf("Input the size: ");
        scanf("%llu",&size);
    } while(!size);

//    srand(time(NULL));
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            a[i][j] = rand()%SIZE;
        }
    }
    return size;
}

void output2D(int a[][SIZE],size_t size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            printf("%d\t",a[i][j]);
        }
        NL;
    }
}

int maxMD(int a[][SIZE],size_t size){
    int max = a[0][0];
    for(int i=1;i<size;++i){
        if(max<a[i][i]){
            max=a[i][i];
        }
    }
    return max;
}

int sumBelowMD(int a[][SIZE],size_t size){
    int sum=0;
    for(int i=1;i<size;++i){
        for(int j=0;j<i;++j){
            sum += a[i][j];
        }
    }
    return sum;
}

float averageAboveMD(int a[][SIZE],size_t size)
{
    float sum=0;
    int counter=0;

    for(int i=0;i<size-1;++i){
        for(int j=i+1;j<size;++j){
            sum += a[i][j];
            counter++;
        }
    }
    return counter ? sum/counter : 0;
}

int minSD(int a[][SIZE],size_t size)
{
    int min = a[0][size-1];

    for (int i=1;i<size-1;++i){
        if(min>a[i][size-1-i])
            min=a[i][size-1-i];
    }
    return min;
}

long multiplicationBelowSD(int a[][SIZE],size_t size)
{
    long multiplication=1;

    for(int i=1;i<size;++i){
        for(int j=size-i;j<size;++j){
            multiplication*=a[i][j];
        }
    }
    return multiplication;
}

int sumOddAboveSD(int a[][SIZE],size_t size)
{
    int sumOdd=0;

    for(int i=0;i<size-1;++i){
        for(int j=0;j<size-i;++j){
            if(a[i][j]%2)
                sumOdd+=a[i][j];
        }
    }
    return sumOdd;
}
