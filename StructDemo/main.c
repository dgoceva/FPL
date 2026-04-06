#include "student.h"

void main1()
{
    TStudent student;

    student = input();
    output(student);
}

void main2()
{
    const unsigned LEN=3;

    TStudent group[LEN];
    unsigned maxIdx;

    inputGroup(group,LEN);
    outputGroup(group,LEN);
    printf("Average Group Mark: %g\n",
           avrGroupMark(group,LEN));
    maxIdx = maxGroupMark(group,LEN);
    printf("The First Student with Max Average Mark: ");
    output(group[maxIdx]);
}

int main()
{
//    main1();
    main2();

    return 0;

}
