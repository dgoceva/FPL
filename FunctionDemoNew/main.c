#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define SIZE 10

unsigned copyData(const int* source, int* dest, unsigned len);
unsigned removeEvenData(int* data, unsigned len);
unsigned insertEvenData(int* data, int start, unsigned len);

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

void randomDataStart(int data[], int start, unsigned len){
    for (int i=start;i<len;++i){
        data[i] = rand()%SIZE;
    }
}

void outputData(int data[], unsigned len){
    for (int i=0;i<len;++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
}

void outputDataStart(int data[], int start, unsigned len){
    for (int i=start;i<len;++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
}

void outputVaData(int data[], unsigned len,...){
    va_list ap;
    va_start(ap,len);
    int start = va_arg(ap,int);

    for (int i=start;i<len;++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
    va_end(ap);
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

bool averageOddData(int data[], unsigned len, float* res){
    int cnt=0;
    *res = 0;
    for (int i=0;i<len;++i){
        if (data[i]%2!=0){
            ++cnt;
            *res += data[i];
        }
    }
    *res = cnt>0 ? *res/cnt : 0;
    return cnt>0;
}

long multiplyData(int data[], unsigned len){
    long mult=1;
    bool nonZero = false;
    for (int i=0;i<len;++i){
        if (data[i]) {
            mult *= data[i];
            nonZero = true;
        }
    }
    return nonZero ? mult : 0;
}
int main()
{
    int a[SIZE*2],b[SIZE];
    long evenSum;
    float averageOdd;

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

    if (averageOddData(a,SIZE,&averageOdd)){
        printf("Average Odd is: %g\n",averageOdd);
    }else
        printf("No such data...\n");

    printf("Multiplication is %ld\n",multiplyData(a,SIZE));

    unsigned len = copyData(a,b,SIZE);
    if (len)
        outputData(b,len);
    else
        printf("No such data...\n");

    unsigned newlen = removeEvenData(a,SIZE);
    if (newlen)
        outputData(a,newlen);
    else
        printf("No odd data...\n");

    randomDataStart(a,SIZE,SIZE*2);
    outputDataStart(a,SIZE,SIZE*2);
    newlen = insertEvenData(a,SIZE,SIZE*2);
    outputData(a,newlen);

    outputVaData(a,newlen);
    outputVaData(a,newlen,4);

    return 0;
}

unsigned copyData(const int* source, int* dest, unsigned len){
    unsigned destLen = 0;
    for(int i=0;i<len;++i){
        if(source[i]>5)
            dest[destLen++] = source[i];
    }
    return destLen;
}

unsigned removeEvenData(int* data, unsigned len){
    unsigned newLen = 0;
    for(int i=0;i<len;++i){
        if(data[i]%2)
            data[newLen++] = data[i];
    }
    return newLen;
}

unsigned insertEvenData(int* data, int start, unsigned len){
    unsigned newLen = 0;
    for(int i=start;i<len;++i){
        data[newLen++] = data[i];
        if(data[i]%2)
            data[newLen++] = data[i]+1;
    }
    return newLen;
}

