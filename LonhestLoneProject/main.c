#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
//    printf("Hello world!\n");
    unsigned maxSize=0;
    char s[MAX_SIZE],maxS[MAX_SIZE];

    while (fgets(s,sizeof(s),stdin)!=NULL){
        if (strlen(s)>maxSize){
            strcpy(maxS,s);
            maxSize = strlen(s);
        }
    }
    puts(maxS);
    printf("size=%u\n",maxSize);

    return 0;
}
