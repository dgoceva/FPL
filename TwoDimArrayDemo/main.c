#include <stdio.h>
#include <stdlib.h>

#define COL 10
#define NL putchar('\n')

void inputMatrix(int matrix[][COL],unsigned rows, unsigned cols);
void outputMatrix(int matrix[][COL],unsigned rows, unsigned cols);
void sumMatrixByRow(int matrix[][COL], unsigned rows, unsigned cols,int sum[]);
void output(int data[], unsigned len);
void avrMatrixByCol(int matrix[][COL], unsigned rows, unsigned cols,float avr[]);
void print(float data[], unsigned len);

int main()
{
//    printf("Hello world!\n");
    int data[5][COL];
    int sum[5];
    float avr[COL];

    inputMatrix(data,5,5);
    outputMatrix(data,5,5);
    sumMatrixByRow(data,5,5,sum);
    NL;NL;
    output(sum,5);
    avrMatrixByCol(data,5,5,avr);
    NL;
    print(avr,5);

    return 0;
}

void inputMatrix(int matrix[][COL],unsigned rows, unsigned cols)
{
    int i,j;

    for(i=0;i<rows;++i)
        for(j=0;j<cols;++j)
            matrix[i][j] = rand()%100-50;
}

void outputMatrix(int matrix[][COL], unsigned rows, unsigned cols)
{
    int i,j;

    for(i=0;i<rows;++i)
    {
        for(j=0;j<cols;++j)
            printf("%d\t",matrix[i][j]);
        NL;
    }
}

void sumMatrixByRow(int matrix[][COL], unsigned rows, unsigned cols,int sum[])
{
    int i,j;

    for(i=0;i<rows;++i)
        for(j=0,sum[i]=0;j<cols;++j)
            sum[i]+=matrix[i][j];
}

void output(int data[], unsigned len)
{
    int i;

    for(i=0;i<len;++i)
    {
        printf("%d\t",data[i]);
    }
    NL;
}

void avrMatrixByCol(int matrix[][COL], unsigned rows, unsigned cols,float avr[])
{
    int i,j;

    for(i=0;i<cols;++i)
    {
        for(j=0,avr[i]=0;j<rows;++j)
            avr[i]+=matrix[j][i];
        avr[i]/=rows;
    }
}

void print(float data[], unsigned len)
{
    int i;

    for(i=0;i<len;++i)
    {
        printf("%g\t",data[i]);
    }
    NL;
}
