#include "student.h"

TStudent input()
{
    TStudent student;

    printf("Faculty number: ");
    scanf("%u",&student.fnumber);
    printf("Name: ");
    scanf("%s",student.name);
    printf("Average mark: ");
    scanf("%f",&student.avmark);

    return student;
}
TStudent readFromTxt(FILE *f)
{
    TStudent student;

    if (fscanf(f,"%u",&student.fnumber) != 1){
        if (!feof(f)){
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
        }
    }
    if (fscanf(f,"%s",student.name) != 1){
        if (!feof(f)){
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
        }
   }
    if (fscanf(f,"%f",&student.avmark) != 1){
        if (!feof(f)){
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
        }
    }

    return student;
}

TStudent readFromCsv(FILE *f)
{
    char line[BUFSIZE];
    char *token;
    TStudent student;

    if (fgets(line,BUFSIZE,f)==NULL){
        if (!feof(f)){
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
        }
    }
    token = strtok(line,DELIM);
    if (token==NULL){
        perror(NULL);
        fclose(f);
        exit(EXIT_FAILURE);
    }
    student.fnumber = atoi(token);

    token = strtok(NULL,DELIM);
    if (token==NULL){
        perror(NULL);
        fclose(f);
        exit(EXIT_FAILURE);
    }
    strcpy(student.name,token);

    token = strtok(NULL,DELIM);
    if (token==NULL){
        perror(NULL);
        fclose(f);
        exit(EXIT_FAILURE);
    }
    student.avmark = atof(token);

    return student;
}
void print(TStudent student)
{
    printf("%u, %s, %g\n",student.fnumber,student.name,student.avmark);
}

void readGroup(FILE *f,TStudent group[], unsigned lenGroup)
{
    int i;

    for(i=0;i<lenGroup;++i)
//        group[i] = readFromTxt(f);
        group[i] = readFromCsv(f);
}
void inputGroup(TStudent group[], unsigned lenGroup)
{
    int i;

    for(i=0;i<lenGroup;++i)
        group[i] = input();
}

void printGroup(TStudent group[], unsigned lenGroup)
{
    int i;

    for(i=0;i<lenGroup;++i)
        print(group[i]);
    puts("-------------------\n\n");
}

float averageGroupMark(TStudent group[], unsigned lenGroup)
{
    int i;
    float sum;

    for(i=sum=0;i<lenGroup;++i){
        sum += group[i].avmark;
    }

    return (lenGroup) ? sum/lenGroup : 0;
}

int studentMinAvMark(TStudent group[], unsigned lenGroup)
{
    int minIndex=0,i;

    for(i=1;i<lenGroup;++i){
        if (group[i].avmark<group[minIndex].avmark){
            minIndex = i;
        }
    }

    return minIndex;
}
int studentMaxAvMark(TStudent group[], unsigned lenGroup)
{
    int maxIndex=0,i;

    for(i=1;i<lenGroup;++i){
        if (group[i].avmark>group[maxIndex].avmark){
            maxIndex = i;
        }
    }

    return maxIndex;
}

int compareAvMark(const void *a, const void *b)
{
    TStudent sta = *(TStudent*)a;
    TStudent stb = *(TStudent*)b;

    if(sta.avmark<stb.avmark)
        return -1;
    else if(sta.avmark==stb.avmark)
        return 0;
    else
        return 1;
}

int compareAvMarkDesc(const void *a, const void *b)
{
    TStudent sta = *(TStudent*)a;
    TStudent stb = *(TStudent*)b;

    if(sta.avmark>stb.avmark)
        return -1;
    else if(sta.avmark==stb.avmark)
        return 0;
    else
        return 1;
}

int findAVMark(TStudent group[], unsigned lenGroup, int start, float mark)
{
    int i;

    for(i=start;i<lenGroup;++i){
        if(group[i].avmark==mark)
            return i;
    }
    return -1;
}
