#include "student.h"

static void clean_buffer()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

static void clean_string(char* str)
{
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
}

TStudent input()
{
    TStudent student;

    printf("Faculty Number: ");
    scanf("%u",&student.fNum);

    printf("Name: ");
//    scanf("%s",student.name);
    clean_buffer();
    fgets(student.name,SIZE,stdin);
    clean_string(student.name);

    printf("Average Mark: ");
    scanf("%f",&student.avMark);

    return student;
}

void output(TStudent student)
{
    printf("(%u, %s, %g)\n",
           student.fNum,student.name,student.avMark);
}

void inputGroup(TStudent* group, unsigned len)
{
    for(int i=0; i<len; ++i){
        group[i] = input();
    }
}

void outputGroup(TStudent* group, unsigned len)
{
    for(int i=0; i<len; ++i){
        output(group[i]);
    }
}

float avrGroupMark(TStudent* group, unsigned len)
{
    float sum=0;

    for(int i=0; i<len; ++i){
        sum += group[i].avMark;
    }
    return (len) ? sum/len : 0;
}

unsigned maxGroupMark(TStudent* group, unsigned len)
{
    unsigned max=0;

    for(int i=1; i<len; ++i){
        if(group[i].avMark > group[max].avMark)
            max = i;
    }
    return max;
}
