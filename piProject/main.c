#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-6

int main()
{
//    printf("Hello world!\n");
    double pi=1;
    int i;
    int denom=3;
    int nom=-1;
    float mem1=0,mem2=1;

    for (i=2;i<1000;++i)
    {
        pi += (float)nom/denom;
        nom *= -1;
        denom += 2;
    }
    printf("my pi=%g\n",pi*4);
    printf("lib pi=%g\n",M_PI);

    pi = 0;
    nom = -1;
    denom = 3;
    while(fabs(mem1-mem2)>=EPS)
    {
        pi += mem2;
        mem1 = mem2;
        mem2 = (float)nom/denom;
        nom *= -1;
        denom += 2;
     }
    printf("my pi=%g\n",pi*4);
    printf("lib pi=%g\n",M_PI);

    int x=1,y=2,z=0;
    z = x++ + ++y;
    printf("%d",z);
    return 0;
}
