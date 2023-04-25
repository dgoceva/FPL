#include "student.h"

int main()
{
    FILE *f;
    int index;
//    TStudent st;
    TStudent group[SIZE];
    TStudent group1[SIZE];

//    st = input();
//    print(st);

//    inputGroup(group,2);
//    printGroup(group,2);

//    if ((f=fopen("students.txt","r")) == NULL){
    if ((f=fopen("students.csv","r")) == NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }
//    st = readFromTxt(f);
//    print(st);

    readGroup(f,group,5);

    fclose(f);

    printGroup(group,5);
    printf("Average Mark is :%g\n",averageGroupMark(group,2));

    index = studentMinAvMark(group,5);
    printf("Student with minimum average mark is: ");
    print(group[index]);

    index = studentMaxAvMark(group,5);
    printf("Student with maximum average mark is: ");
    print(group[index]);

    qsort(group,5,sizeof(TStudent),compareAvMark);
    printGroup(group,5);

    qsort(group,5,sizeof(TStudent),compareAvMarkDesc);
    printGroup(group,5);

    index = findAVMark(group,5,0,5);
    if(index== -1)
        printf("No such data...\n");
    else
        print(group[index]);

    index = findAVMark(group,5,0,5.32);
    if(index== -1)
        printf("No such data...\n");
    else
        print(group[index]);

    index = findAVMark(group,5,index+1,5.32);
    if(index== -1)
        printf("No such data...\n");
    else
        print(group[index]);
    printf("-----BIN-------\n");
    writeToBin("students.bin",group,5);
    readFromBin("students.bin",group1,5);
    printGroup(group1,5);
//    printf("Hello world!\n");
    return 0;
}
