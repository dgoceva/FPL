#include <stdio.h>
#include <stdlib.h>
/*
#define START 0
#define END 100
#define STEP 12
*/
double celToFar(int cel)
{
    return /* this is comment */ cel*9./5+32;
}

int inputCel(char prompt[])
{
    int temp;
    printf(prompt);
    scanf("%d",&temp);
    return temp;
}
int main()
{
//    const int START=0,END=100;
//    const int STEP=12;
    int start=0,end,step=0;
    int cel;
//    double far;
//    printf("Enter C: ");
//    scanf("%d",&cel);
/*
    printf("START=");
    scanf("%d",&start);
    printf("END=");
    scanf("%d",&end);
    printf("STEP=");
    scanf("%d",&step);
    */
    start = inputCel("START:");
    end = inputCel("END:");
//    while (step<=0)
//        step = inputCel("STEP:");
    do {
        step = inputCel("STEP:");
    } while (step<=0);
    for (cel=start;cel<=end;cel+=step){
            printf("%d C\t%g F\n",cel,celToFar(cel));
    }
 //   far = celToFar(cel);
 //   printf("%d C = %lf F\n",cel,far);

    return 0;
}
