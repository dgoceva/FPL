#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

int main()
{
    char name[LEN];
    fgets(name,LEN,stdin);
    name[strlen(name)-1]='\0';
    puts(name);
    printf("Hello world,%s!\n",name);
    return 0;
}
