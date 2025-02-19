#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bool int
#define false 0

void inputArray(int data[], unsigned size)
{
    for (unsigned i=0;i<size;++i){
        printf("A(%u)=",i+1);
        scanf("%d",&data[i]);
    }
}

void inputRandomArray(int data[], unsigned size, bool isunique)
{
    if (isunique)
        srand(time(NULL));

    for (unsigned i=0; i<size; ++i){
        data[i] = rand()%10+1;
    }
}

void outputArray(int data[], unsigned size)
{
    for (unsigned i=0; i<size; ++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
}

int sumArray(int data[], unsigned size)
{
    int sum=0;
    for (unsigned i=0; i<size; ++i){
        sum += data[i];                 // += -> sum = sum + data[i]
    }
    return sum;
}

unsigned countEven(int data[], unsigned size)
{
    unsigned counter=0;
    for (unsigned i=0; i<size; ++i){
        if (data[i]%2==0)
            counter++;
    }
    return counter;
}


double averageOdd(int data[], unsigned size)
{
    double sum=0;
    int counter=0;

    for (unsigned i=0; i<size; ++i){
        if (data[i]%2 != 0){
            sum += data[i];
            ++counter;
        }
    }
    return (counter!=0) ? sum/counter : 0;
}

int main()
{
    const unsigned SIZE=10;
    int array[SIZE];
    double average;

 //   inputArray(array, 3);
 //   outputArray(array, 3);
    inputRandomArray(array, SIZE, !false);
//    inputArray(array, SIZE);
    outputArray(array, SIZE);
    printf("The sum is %d\n",sumArray(array, SIZE));
    printf("The average is %g\n",(float)sumArray(array, SIZE)/SIZE);
    printf("The even counter: %u\n", countEven(array, SIZE));
    average = averageOdd(array, SIZE);
    if (average!=0)
        printf("The average of Odd data is %g\n", average);
    else
        printf("There is no odd data...\n");

    return 0;
}
