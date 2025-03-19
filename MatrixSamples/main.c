#include "main.h"

int main()
{
    int matrix[NO_OF_ROWS][NO_OF_COLS];
    float array[NO_OF_COLS];
    unsigned counters[NO_OF_ROWS];

    randomInput(matrix,NO_OF_ROWS,NO_OF_COLS);
    printMatrix(matrix,NO_OF_ROWS,NO_OF_COLS);
    puts("=====================================");
    printf("Sum of MD is : %d\n",sumMD(matrix,NO_OF_COLS));
    printf("Min Below MD is: %d\n",minBelowMD(matrix,NO_OF_COLS));
    printf("Max Above MD is: %d\n",maxAboveMD(matrix,NO_OF_COLS));
    averageByCols(matrix,NO_OF_ROWS,NO_OF_COLS,array);
    puts("=====================================");
    printArray(array,NO_OF_COLS);
    countPosByRows(matrix,NO_OF_ROWS,NO_OF_COLS,counters);
    puts("=====================================");
    printUnsignedArray(counters,NO_OF_ROWS);

    return 0;
}

void randomInput(int data[][NO_OF_COLS],unsigned rows,unsigned cols)
{
    for (int i=0;i<rows;++i){
        for (int j=0;j<cols;++j){
            data[i][j] = rand()%(MAX-MIN+1)+MIN;
        }
    }
}

void printMatrix(int data[][NO_OF_COLS],unsigned rows,unsigned cols)
{
    for (int i=0;i<rows;++i){
        for (int j=0;j<cols;++j){
            printf("%d\t",data[i][j]);
        }
        NL;
    }
}

int sumMD(int data[][NO_OF_COLS],unsigned cols)
{
    int sum=0;

    for (int i=0;i<cols;++i){
        sum += data[i][i];
    }
    return sum;
}

int minBelowMD(int data[][NO_OF_COLS],unsigned cols)
{
    int min = data[1][0];

    for(int i=1;i<cols;++i){
        for(int j=0;j<i;++j){
            if (min>data[i][j])
                min = data[i][j];
        }
    }
    return min;
}

int maxAboveMD(int data[][NO_OF_COLS],unsigned cols)
{
    int max = data[0][1];

    for(int i=0;i<cols-1;++i){
        for(int j=i+1;j<cols;++j){
            if (max<data[i][j])
                max = data[i][j];
        }
    }
    return max;
}

void averageByCols(int data[][NO_OF_COLS],unsigned rows,unsigned cols,float avrs[])
{
    for (int j=0;j<cols;++j){
        avrs[j] = 0;
        for (int i=0;i<rows;++i){
            avrs[j] += data[i][j];
        }
        avrs[j] /= rows;
    }
}

void printArray(float data[],unsigned cols)
{
    for (int i=0;i<cols;++i){
        printf("%g\t",data[i]);
    }
    NL;
}

void printUnsignedArray(unsigned data[],unsigned cols)
{
    for (int i=0;i<cols;++i){
        printf("%u\t",data[i]);
    }
    NL;
}
void countPosByRows(int data[][NO_OF_COLS],unsigned rows,unsigned cols,unsigned cnts[])
{
    for (int i=0;i<rows;++i){
        cnts[i] = 0;
        for (int j=0;j<cols;++j){
            if (data[i][j]>0)
                cnts[i]++;
        }
    }
}
