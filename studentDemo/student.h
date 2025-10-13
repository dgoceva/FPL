#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

typedef struct {
    unsigned fNom;
    char name[50];
    float avMark;
} TStudent;

typedef enum {false, true} TBoolean;

TStudent * inputCSV(char *fname, unsigned *size);
TBoolean parseStudent(char *buff, TStudent* st);
void outputGroup(TStudent *group,unsigned size);
TBoolean outputBin(char *fname,TStudent* group, unsigned size);
TStudent* readBin(char *fname,unsigned *size);

#endif // STUDENT_H_INCLUDED
