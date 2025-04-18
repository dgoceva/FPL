#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50
#define SIZE 10

struct TTStudent {
    unsigned fNo;
    char name[LEN];
    float avMark;
};

typedef struct TTStudent TStudent;

TStudent  input();
void output(TStudent st);
unsigned inputCSV(char *fname,TStudent *group,unsigned size);
TStudent readStudent(FILE *fin);
unsigned countStudents(FILE *fin);
void outputGroup(TStudent *group, unsigned size);
float averageGroupMark(TStudent *group, unsigned size);

#endif // STUDENT_H_INCLUDED
