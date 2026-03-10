#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 3

int main1()
{
    int a[SIZE1];
    int sum = 0;

    // input data
    for(int i=0; i<SIZE1; ++i){
        printf("A[%d]=",i+1);
        scanf("%d",&a[i]);
    }

    // output data
    for(int i=0; i<SIZE1; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    // sum
    for(int i=0; i<SIZE1; ++i){
        sum += a[i];   // sum = sum + a[i];
    }
    printf("Sum = %d\n",sum);

    return 0;
}

int main()
{
    const int SIZE = 10;

    int a[SIZE*2],b[SIZE];
    int sum = 0;
    unsigned count = 0;
    long mult = 1;
    int indexB = 0;
    int len = 0;
    int minIdx, temp;

    // random generator init
    // srand(time(NULL));

    // input data with random generator
    for(int i=0;i<SIZE;++i){
        a[i] = rand()%SIZE;  // [0,SIZE-1]
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    // sum
    for(int i=0; i<SIZE; ++i){
        sum += a[i];   // sum = sum + a[i];
    }
    printf("Sum = %d\n",sum);

    // sum of even elements
    sum = 0;
    for(int i=0; i<SIZE; ++i){
        if (!(a[i]%2))     // a[i]%2==0
            sum += a[i];   // sum = sum + a[i];
    }
    printf("Even Sum = %d\n",sum);

    // sum & count of odd elements
    sum = 0;
    for(int i=0; i<SIZE; ++i){
        if (a[i]%2) {       // a[i]%2!=0
            sum += a[i];   // sum = sum + a[i];
            count++;
        }
    }
    if (!count){
        printf("No such data...\n");
    } else
        printf("Average = %g\n",(float)sum/(float)count);

    // multiplication
    for(int i=0; i<SIZE; ++i){
        if (!a[i])
            continue;
        mult *= a[i];   // mult = mult * a[i];
    }
    printf("Mult = %ld\n",mult);

    // copy data > 5 into new array
    for(int i=0;i<SIZE;++i){
        if(a[i]>5){
            b[indexB++] = a[i];
        }
    }

    // output result
    if (indexB) {
        for(int i=0; i<indexB; ++i){
            printf("%d\t",b[i]);
        }
        printf("\n");
    } else
        puts("No such data\n");

    // remove all even
    for (int i=0; i<SIZE; ++i){
        if (a[i]%2){
            a[len++] = a[i];
        }
    }

    // output data
    if (len){
        for(int i=0; i<len; ++i){
            printf("%d\t",a[i]);
        }
        printf("\n");
    }else {
        printf("Empty array\n");
    }

    for(int i=0;i<SIZE;++i){
        a[i] = rand()%SIZE;  // [0,SIZE-1]
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    // after each odd X insert X+1
    len = SIZE;
    for (int i=0; i<SIZE; ++i,++len){
        a[len] = a[i];
    }
    len = 0;
    for (int i=SIZE; i<SIZE*2; ++i){
        a[len++] = a[i];
        if (a[i]%2){
            a[len++] = a[i]+1;
        }
    }

    // output data
    for(int i=0; i<len; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    for(int i=0;i<SIZE;++i){
        a[i] = rand()%SIZE;  // [0,SIZE-1]
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    // selection sort
    for (int i=0;i<SIZE-1; ++i){
        minIdx = i;
        for (int j=i+1;j<SIZE;++j){
            if (a[minIdx]>a[j]){
                minIdx = j;
            }
        }
        temp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = temp;
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    for(int i=0;i<SIZE;++i){
        a[i] = rand()%SIZE;  // [0,SIZE-1]
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    // bubble sort
    for (int i=0;i<SIZE;++i){
        for (int j=0;j<SIZE-i-1;++j){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // output data
    for(int i=0; i<SIZE; ++i){
        printf("%d\t",a[i]);
    }
    printf("\n");

    return 0;
}
