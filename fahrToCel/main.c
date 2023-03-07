#include <stdio.h>
#include <stdlib.h>

/*
#define LOWER 0
#define UPPER 200
#define STEP 20
*/

int main()
{
/*    int fahr;
    float cel;

    printf("Input F:");
    scanf("%d",&fahr);
    cel = 5./9*(fahr-32);
    printf("%d --> %f\n",fahr,cel);
//    printf("Hello world!\n");
*/
    float cel;
    int fahr;
    int lower,upper,step;

    printf("Lower=");
    scanf("%d",&lower);
    printf("Upper=");
    scanf("%d",&upper);
    printf("Step=");
    scanf("%d",&step);

    printf("F --> C\n");
    for(fahr=lower;fahr<=upper;fahr+=step)
    {
        cel = 5/9.*(fahr-32);
        printf("%d --> %g\n",fahr,cel);
    }

    return 0;
}
