#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    printf("TYPE\t\t\tSIZE\tMIN\t\t\tMAX\n\n");
    printf("bool\t\t\t%d\t%s\t\t\t%s\n\n",sizeof(bool),"false","true");
    printf("char\t\t\t%d\t%d\t\t\t%d\n",sizeof(char),CHAR_MIN,CHAR_MAX);
    printf("signed char\t\t%d\t%d\t\t\t%d\n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
    printf("unsigned char\t\t%d\t%d\t\t\t%d\n\n",sizeof(unsigned char),0,UCHAR_MAX);
    printf("short\t\t\t%d\t%d\t\t\t%d\n",sizeof(short),SHRT_MIN,SHRT_MAX);
    printf("signed short\t\t%d\t%d\t\t\t%d\n",sizeof(signed short),SHRT_MIN,SHRT_MAX);
    printf("unsigned short\t\t%d\t%d\t\t\t%d\n\n",sizeof(unsigned short),0,USHRT_MAX);
    printf("int\t\t\t%d\t%d\t\t%d\n",sizeof(int),INT_MIN,INT_MAX);
    printf("signed\t\t\t%d\t%d\t\t%d\n",sizeof(signed),INT_MIN,INT_MAX);
    printf("unsigned \t\t%d\t%d\t\t\t%u\n\n",sizeof(unsigned),0,UINT_MAX);
    printf("long\t\t\t%d\t%d\t\t%d\n",sizeof(long),LONG_MIN,LONG_MAX);
    printf("signed long\t\t%d\t%d\t\t%d\n",sizeof(signed long),LONG_MIN,LONG_MAX);
    printf("unsigned long\t\t%d\t%d\t\t\t%u\n\n",sizeof(unsigned long),0,ULONG_MAX);
    printf("long long\t\t%d\t%lld\t%lld\n",sizeof(long long),LLONG_MIN,LLONG_MAX);
    printf("signed long long\t%d\t%lld\t%lld\n",sizeof(signed long long),LLONG_MIN,LLONG_MAX);
    printf("unsigned long long\t%d\t%d\t\t\t%llu\n\n",sizeof(unsigned long long),0,ULLONG_MAX);
    printf("float\t\t\t%d\n\n",sizeof(float));
    printf("double\t\t\t%d\n\n",sizeof(double));
    printf("long double\t\t%d\n\n",sizeof(long double));

    return 0;
}
