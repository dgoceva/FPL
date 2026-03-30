#include "matrix.h"

int* inputData(unsigned* size){
    int *a=NULL;
    int temp;

    *size = 0;
    while(true){
        printf("Enter data: ");
        scanf("%d",&temp);
        if(temp==0)
            return a;
        a = realloc(a,++*size*sizeof(int));
        if(a==NULL)
            return NULL;
        a[*size-1]=temp;
    }
}

void output(int* data, unsigned size){
    for(int i=0;i<size;++i){
        printf("%d\t",data[i]);
    }
    NL;
}

int main()
{
    int a = 6;
    int *p = &a;

    printf("a=%d\t*p=%d\tp=%p\n",a,*p,p);

    *p++;
    printf("a=%d\t*p=%d\tp=%p\n",a,*p,p);

    p = &a;
    *++p;
    printf("a=%d\t*p=%d\tp=%p\n",a,*p,p);

    p = &a;
    ++*p;
    printf("a=%d\t*p=%d\tp=%p\n",a,*p,p);

    p = &a;
    (*p)++;
    printf("a=%d\t*p=%d\tp=%p\n",a,*p,p);


    unsigned len;
    int *data = inputData(&len);
    if (data==NULL)
        exit(EXIT_FAILURE);

    output(data,len);
    free(data);

    int matrix[SIZE][SIZE];
    size_t size = input2D(matrix);
    output2D(matrix,size);

    printf("Max of MD: %d\n",maxMD(matrix,size));
    printf("Sum of Below MD: %d\n",sumBelowMD(matrix,size));
    printf("Average of Above MD: %g\n",averageAboveMD(matrix,size));

    printf("Min of SD: %d\n",minSD(matrix,size));
    printf("Multiplication of Below SD: %ld\n",
           multiplicationBelowSD(matrix,size));
    printf("Sum of Odd Above SD: %d\n",sumOddAboveSD(
        matrix,size));

    return 0;
}
