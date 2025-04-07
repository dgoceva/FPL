#include "student.h"

TStudent* inputCSV(char *fname,unsigned *size)
{
    FILE *fin;
    TStudent *group=NULL;

    fin = fopen(fname,"r");
    if (fin == NULL){
        perror(NULL);
        exit(errno);
    }

    *size = 0;
    do {
        group = realloc(group,*size+1);
        if (group==NULL){
            perror(NULL);
            fclose(fin);
            exit(-1);
        }
        if (readStudent(fin,&group[*size])==NULL)
            break;
        ++*size;
    } while(true);

    fclose(fin);
    return group;
}

TStudent* readStudent(FILE *fin, TStudent *st)
{
    char buff[1000];
    char *token;

    if (fgets(buff,sizeof(buff),fin)==NULL){
        return NULL;
    }

    token = strtok(buff,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    sscanf(token,"%u",&st->fNo);

    token = strtok(NULL,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    strcpy(st->name,token);

    token = strtok(NULL,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    sscanf(token,"%f",&st->avMark);

    return st;
}

void outputGroup(TStudent *group, unsigned size)
{
    for (int i=0;i<size;++i){
       printf("[%u, %s, %.2f]\n",group[i].fNo,group[i].name,group[i].avMark);
    }
}
