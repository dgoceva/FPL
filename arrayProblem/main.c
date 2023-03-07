// dgoceva@tu-sofia.bg
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
#define NL putchar('\n')

void generateArray(int *array, unsigned len);
void printArray(int *array, unsigned len);
unsigned countNegElements(int *array, unsigned len);
int sumPosEvenElements(int *array, unsigned len);
bool isEven(int data);
int compare(const void *a, const void *b);
void sortArray(int *array, unsigned len);

int main()
{
    int data[MAXSIZE];
    int sum;

    int *p=data;

    generateArray(data,MAXSIZE);
    printf("%d\t%d\t%d\t%d\n",p,*p,*(p+1),*p+1);
    printArray(data,MAXSIZE);
    printf("Count of neg elem: %u\n",countNegElements(data,MAXSIZE));
    sum = sumPosEvenElements(data,MAXSIZE);
    if (sum == -1)
        printf("No such data...\n");
    else
        printf("Sum of pos even elem: %d\n",sum);
    sortArray(data,MAXSIZE);
    printArray(data,MAXSIZE);
//    printf("Hello world!\n");
    return 0;
}

void generateArray(int *array, unsigned len)
{
    int i;

    for(i=0;i<len;++i){
        array[i] = rand()%20-10;
    }
}

void printArray(int *array, unsigned len)
{
    int i;

    for(i=0;i<len;++i)
        printf("%d\t",array[i]);
    NL;
}

unsigned countNegElements(int *array, unsigned len)
{
    unsigned counter=0;
    int i;

    for(i=0;i<len;++i){
        if(array[i]<0)
            counter++;
    }
    return counter;
}

bool isEven(int data)
{
    return data%2==0;
}

int sumPosEvenElements(int *array, unsigned len)
{
    bool found=false;
    int i;
    int sum;

    for(i=sum=0;i<len;++i){
        if(array[i]>=0 && isEven(array[i])){
            found = true;
            sum += array[i];
        }
    }
    return found ? sum : -1;
}

int compare(const void *a, const void *b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;

//    return bb-aa;
    return *(int*)a-*(int*)b;
}

void sortArray(int *array, unsigned len)
{
    qsort(array,len,sizeof(int),compare);
}
