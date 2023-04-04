#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned nl_char;
    unsigned chars;
} TInfo;

TInfo readinfo(char *fname)
{
    FILE *f = fopen(fname,"r");
    char sym;
    TInfo info = {0,0};

    if(f==NULL){
        perror(NULL);
        exit(-2);
    }

    while((sym=fgetc(f))!=EOF){
        switch(sym){
            case '\n': info.nl_char++; break;
            default: info.chars++; break;
        }
    }
    fclose(f);
    return info;
}
void print(TInfo info)
{
    printf("NL: %u, ALL: %u\n",info.nl_char,info.chars);
}
int main()
{
    TInfo info;
    info = readinfo("D:\\BPL\\Samples\\text_demo\\text.txt");
    print(info);
//    printf("Hello world!\n");
    return 0;
}
