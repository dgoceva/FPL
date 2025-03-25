#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

struct TTStudent {
    unsigned fnom;
    char name[LEN];
    float avmark;
};

typedef struct TTStudent TStudent;

TStudent input();
void output(TStudent);
void inputGroup(TStudent *group, unsigned len);
void outputGroup(TStudent *group, unsigned len);
void inputGroupCSV(char *fname,TStudent *group, unsigned len);
TStudent parseStudent(char *buff);

#endif // STUDENT_H_INCLUDED
