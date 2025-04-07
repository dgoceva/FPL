#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define LEN 50
#define SIZE 10

typedef enum {false,true} TBoolean;

struct TTStudent {
    unsigned fNo;
    char name[LEN];
    float avMark;
};

typedef struct TTStudent TStudent;

TStudent* inputCSV(char *fname,unsigned *size);
TStudent* readStudent(FILE *fin, TStudent *st);
void outputGroup(TStudent *group, unsigned size);

#endif // STUDENT_H_INCLUDED
