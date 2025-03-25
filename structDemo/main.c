#include "student.h"

int main()
{
    TStudent group[5];
//    TStudent st = input();
//    output(st);
//    inputGroup(group,sizeof(group)/sizeof(TStudent));
    inputGroupCSV("students.csv",group,5);
    outputGroup(group,5);

    return 0;
}
