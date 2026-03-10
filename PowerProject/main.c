#include <stdio.h>
#include <stdlib.h>

long power(int x, unsigned int y);

int main()
{
//    printf("Hello world!\n");
    for (int i=0; i<=10; ++i){
        printf("2**%2d = %ld\n",i,power(2,i));
    }
    return 0;
}

long power(int x, unsigned int y) {
    long result = 1;

    for (int i=y; i>0; --i){
        result *= x;
    }
    return result;
}
