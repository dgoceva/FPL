#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HI 300
#define NEXT 20

int main()
{
    int far;
    float cel;
    int lower,upper,step;

    printf("lower=");
    scanf("%d",&lower);
    printf("upper=");
    scanf("%d",&upper);
    printf("step=");
    scanf("%d",&step);

    if (!(lower<=upper && step > 0 || lower>=upper && step < 0) ||
        step==0){
        lower = LOW;
        upper = HI;
        step = NEXT;
    }

    printf("Far\t\t\tCel\n\n");
    for (far=lower;far<=upper;far+=step){
        cel = 5./9*(far-32);
        printf("%d\t\t\t%g\n",far,cel);
    }

//    printf("Hello world!\n");
    return 0;
}
