#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int i;
    long fact=1;

    printf("N=");
    scanf("%d",&N);

    if (N<0)
    {
        printf("N>=0...");
        return EXIT_FAILURE;
    }
    for(i=2;i<=N;i++)
    {
        fact *= i;
    }
    printf("%d!=%ld\n",N,fact);
//    printf("Hello world!\n");
    return 0;
}
