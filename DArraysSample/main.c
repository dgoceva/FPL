#include "array.h"

int main()
{
    int a=10;
    int *pa = &a;
    int *parray;

    printf("a=%d, pa=%p, *pa=%d\n",a,pa,*pa);

    parray = malloc(LEN*sizeof(int));
    if (parray==NULL){
        perror("Memory error: ");
        exit(EXIT_FAILURE);
    }

    randomData(parray,LEN);
    printData(parray,LEN);
    printf("Sum of OddData: %d\n",sumOddData(parray,LEN));

    free(parray);

    return 0;
}
