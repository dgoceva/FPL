#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct TTStudent {
    unsigned fNum;
    char name[SIZE];
    float avMark;
};

typedef struct TTStudent TStudent;

TStudent input();
void output(TStudent student);
void inputGroup(TStudent* group, unsigned len);
void outputGroup(TStudent* group, unsigned len);
float avrGroupMark(TStudent* group, unsigned len);
unsigned maxGroupMark(TStudent* group, unsigned len);

#endif // STUDENT_H_INCLUDED
