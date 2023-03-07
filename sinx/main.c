#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sinx(double x);
void plot();

int main()
{
    double xrad;
    int x;

/*    printf("X=");
    scanf("%d",&x);
    xrad = x*M_PI/180;

    printf("sin(%d)=%f\n",x,sinx(xrad));
    printf("sin(%d)original=%f\n",x,sin(xrad));
    */
    plot();

//    printf("Hello world!\n");
    return 0;
}

double sinx(double x)
{
    double sum = x;
    double member = x;
    int i,cnt;

    for (i=0,cnt=3;i<10;++i,cnt+=2)
    {
        member *= (-1)*x*x/(cnt-1)/cnt;
        sum += member;
    }
    return sum;
}

void plot()
{
    FILE *pipe_gp = popen("D:\\BPL\\gnuplot\\bin\\wgnuplot -p", "w");
    fprintf(pipe_gp,"plot '-' sin(x) \n");
    //pclose(pipe_gp);
}
