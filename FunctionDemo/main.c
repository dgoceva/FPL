#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void inputData(int data[], unsigned len){
    for (int i=0;i<len;++i){
        printf("Data[%d]=",i+1);
        scanf("%d",&data[i]);
    }
}

void randomData(int data[], unsigned len){
    for (int i=0;i<len;++i){
        data[i] = rand()%SIZE;
    }
}

void outputData(int data[], unsigned len){
    for (int i=0;i<len;++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
}

long sumData(int data[], unsigned len){
    long sum=0;
    for (int i=0;i<len;++i){
        sum += data[i];
    }
    return sum;
}

long sumEvenData(int data[], unsigned len){
    long sum=0;
    bool isEven=false;
    for (int i=0;i<len;++i){
        if (data[i]%2==0){
            isEven = true;
            sum += data[i];
        }
    }
    return isEven ? sum : -1;
}

int main()
{
    int a[SIZE];
    long evenSum;

/*    inputData(a,5);
    outputData(a,5);
*/
    randomData(a,SIZE);
    outputData(a,SIZE);

    printf("The sum is %ld\n",sumData(a,SIZE));

    evenSum = sumEvenData(a,SIZE);
    if (evenSum==-1)
        printf("No such data...\n");
    else
        printf("The even sum is %ld\n",evenSum);

    return 0;
}
