#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main1()
{
    FILE *fin;
    int ch;

    fin = fopen("demo.txt","r");
    if(fin==NULL){
        printf("Error: %d\n",errno);
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    while(true){
        ch = fgetc(fin);
        if(ch==EOF)
            break;
        putchar(ch);
    }
    fclose(fin);

    return 0;
}

void main2()
{
    const unsigned MAXSIZE = 1000;
    char line[MAXSIZE];
    FILE *f;
    char *token;
    struct tm date;

    if((f=fopen("example.csv","r"))==NULL){
        perror("Error with csv:");
        exit(-1);
    }

    while(true){
        if(fgets(line,MAXSIZE,f)==NULL){
            if(feof(f))
                break;
            else {
                perror("Reading Error:");
                fclose(f);
                exit(-2);
            }
        }
        puts(line);
        strcpy(line,line+5);
        token=strtok(line,",");
        bool isFirstToken=true;
        while(token!=NULL){
            if(isFirstToken){
                sscanf(token,"%d-%d-%d %d:%d:%d",
                   &date.tm_year,
                   &date.tm_mon,
                   &date.tm_mday,
                   &date.tm_hour,
                   &date.tm_min,
                   &date.tm_sec
                   );
                date.tm_year-=1900;
                date.tm_mon--;
                puts(asctime(&date));
                isFirstToken=false;
            }else
                printf("%s\n",token);
            token = strtok(NULL,",");
        }
    }
    fclose(f);
}
int main()
{
    //main1();
    main2();
    return EXIT_SUCCESS;
}
