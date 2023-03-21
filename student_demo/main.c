#include "student.h"

int main()
{
    FILE *f;
//    TStudent st;
    TStudent group[SIZE];

//    st = input();
//    print(st);

//    inputGroup(group,2);
//    printGroup(group,2);

    if ((f=fopen("students.txt","r")) == NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }
//    st = readFromTxt(f);
//    print(st);

    readGroup(f,group,2);

    fclose(f);

    printGroup(group,2);
    printf("Average Mark is :%g\n",averageGroupMark(group,2));

    printf("Hello world!\n");
    return 0;
}
