#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define LEN 10

void print(int *array,int len)
{
    int i;

    for(i=0;i<len;++i){
        printf("%d\t",array[i]);
    }
    putchar('\n');
}

void extend(int *array, int begin, int end)
{
    int i;

    for(i=end-2;i>=begin;--i){
        array[i+1] = array[i];
    }
}

int* input(int len)
{
    int *array;
    int i;

    srand(time(NULL));

    // 3
    array = (int*)malloc(LEN*sizeof(int));

    if(array==NULL)
        return NULL;

    for(i=0;i<LEN;++i)
        array[i] = rand()%10-5;

    return array;
}

int main()
{
    int *array;
    int i,len;

    array = input(LEN);
    if(array==NULL){
        perror("array malloc:");
        exit(EXIT_FAILURE);
    }


    // 4
    print(array,LEN);

    // 6-11
    for(i=0,len=LEN;i<len;++i){
        if(array[i]%2==0){
            array = realloc(array,++len*sizeof(int));
            if(array==NULL){
                perror("array realloc:");
                exit(EXIT_FAILURE);
            }
            extend(array,i+1,len);
            array[i+1] = array[i]+1;
            ++i;
        }
    }
    print(array,len);

    free(array);

//    printf("Hello world!\n");
    return 0;
}
