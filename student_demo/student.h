#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LEN 50
#define SIZE 5

struct TNStudent {
    unsigned fnumber;
    char name[LEN];
    float avmark;
};

typedef struct TNStudent TStudent;

TStudent input();
void print(TStudent student);
void inputGroup(TStudent group[], unsigned lenGroup);
void printGroup(TStudent group[], unsigned lenGroup);
TStudent readFromTxt(FILE *f);
void readGroup(FILE *f,TStudent group[], unsigned lenGroup);
float averageGroupMark(TStudent group[], unsigned lenGroup);

#endif // STUDENT_H_INCLUDED
