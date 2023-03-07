#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char str[MAX];

    if(fgets(str,MAX,stdin)==NULL)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    puts(str);
    printf("Chars=%d\n",strlen(str));
//    printf("Hello world!\n");
    return 0;
}
