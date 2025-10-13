#include "student.h"

TStudent * inputCSV(char *fname, unsigned *size)
{
    FILE *f;
    TStudent *group = NULL;
    const unsigned BUFF_SIZE = 1024;
    char buff[BUFF_SIZE];

    if ((f = fopen(fname,"r"))==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fgets(buff,BUFF_SIZE,f)!=NULL) {
        group = realloc(group,(*size+1)*sizeof(TStudent));
        if (group == NULL){
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
        }
        if (parseStudent(buff, &group[*size])==false){
            free(group);
            fclose(f);
            exit(EXIT_FAILURE);
        }
        ++*size;
    }
    fclose(f);
    return group;
}

TBoolean parseStudent(char *buff, TStudent* st)
{
    char *token;

    token = strtok(buff,",");
    if (token == NULL){
        printf("No FNom\n");
        return false;
    }
    sscanf(token,"%u",&st->fNom);

    token = strtok(NULL,",");
    if (token == NULL){
        printf("No Name\n");
        return false;
    }
    strcpy(st->name,token);

    token = strtok(NULL,",");
    if (token == NULL){
        printf("No AvMark\n");
        return false;
    }
    sscanf(token,"%f",&st->avMark);

    return true;
}

void outputGroup(TStudent *group,unsigned size)
{
    for (int i=0;i<size;++i){
        printf("(%u, %s, %.2f)\n", group[i].fNom,group[i].name,group[i].avMark);
    }
}

TBoolean outputBin(char *fname,TStudent* group, unsigned size)
{
    FILE *f;

    if ((f=fopen(fname,"wb"))==NULL){
        perror(NULL);
        return false;
    }

    if (fwrite(&size,sizeof(unsigned),1,f)!=1){
        perror(NULL);
        fclose(f);
        return false;
    }

    if (fwrite(group,sizeof(TStudent),size,f)!=size){
        perror(NULL);
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

TStudent* readBin(char *fname,unsigned *size)
{
    FILE *f;
    TStudent *group;

    if ((f=fopen(fname,"rb"))==NULL){
        perror(NULL);
        return NULL;
    }

    if (fread(size,sizeof(unsigned),1,f)!=1){
        perror(NULL);
        fclose(f);
        return NULL;
    }

   group = (TStudent*)malloc(*size * sizeof(TStudent));
   if (group == NULL){
        perror(NULL);
        fclose(f);
        return NULL;
   }

   if (fread(group,sizeof(TStudent),*size,f)!=*size){
        perror(NULL);
        fclose(f);
        free(group);
        return NULL;
   }

   fclose(f);
   return group;
}
