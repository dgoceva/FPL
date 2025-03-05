#include <stdio.h>
#include <stdlib.h>

enum BOOL{FALSE,TRUE} ;

void printData(int data[], unsigned len)
{
    for(int i   =0;i<len;++i){
        printf("%d\t",data[i]);
    }
    printf("\n");
}
int findMin(int data[], unsigned len, int start)
{
    int index=start;
    for (int i=start+1;i<len;++i){
        if (data[i]<data[index]){
            index = i;
        }
    }
    return index;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectSort(int data[], unsigned len)
{
    int index;
    for (int i=0;i<len-1;++i){
        index = findMin(data,len,i);
//        printf("%d\n",data[index]);
        swap(&data[index],&data[i]);
 //       printData(data,len);
    }
 }
void bubbleSort(int data[], unsigned len)
{
    enum BOOL isSwap;
    int j;

    for (int i=0;i<len-1 && isSwap;++i){
        for (isSwap=FALSE,j=i;j<len-1;++j){
            if (data[j]>data[j+1]){
                swap(&data[j],&data[j+1]);
                isSwap = TRUE;
            }
        }
 //       printData(data,len);
    }
}

int compare(const void *a, const void *b){
    int *adata = (int*)a;
    int *bdata = (int*)b;
    return *bdata-*adata;
}

int main()
{
    static int array1[] = {3,0,1,8,2,5,4,9,6};
    static int array2[] = {3,0,1,8,7,2,5,4,6,9};
    const unsigned LEN1=sizeof(array1)/sizeof(int);
    const unsigned LEN2=sizeof(array2)/sizeof(int);

    printData(array1,LEN1);
    selectSort(array1,LEN1);
    printData(array1,LEN1);
    puts("--------------------------------------------------------\n");
    printData(array2,LEN2);
    bubbleSort(array2,LEN2);
    printData(array2,LEN2);
    puts("--------------------------------------------------------\n");
    printData(array2,LEN2);
    qsort(array2,LEN2,sizeof(int),compare);
    printData(array2,LEN2);

    return 0;
}
