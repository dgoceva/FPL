#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50
#define SIZE 5
#define BUFSIZE 1000
#define DELIM ","

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
TStudent readFromCsv(FILE *f);
void readGroup(FILE *f,TStudent group[], unsigned lenGroup);
float averageGroupMark(TStudent group[], unsigned lenGroup);
int studentMinAvMark(TStudent group[], unsigned lenGroup);
int studentMaxAvMark(TStudent group[], unsigned lenGroup);
int compareAvMark(const void *a, const void *b);
int compareAvMarkDesc(const void *a, const void *b);
int findAVMark(TStudent group[], unsigned lenGroup, int start, float mark);
void writeToBin(char *fname,TStudent group[], unsigned lenGroup);
void readFromBin(char *fname,TStudent group[], unsigned lenGroup);

#endif // STUDENT_H_INCLUDED
