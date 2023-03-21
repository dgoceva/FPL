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

void print(TStudent student)
{
    printf("%u, %s, %g\n",student.fnumber,student.name,student.avmark);
}

void readGroup(FILE *f,TStudent group[], unsigned lenGroup)
{
    int i;

    for(i=0;i<lenGroup;++i)
        group[i] = readFromTxt(f);
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
