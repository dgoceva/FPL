#include "student.h"

int main()
{
 //   TStudent student;
    TStudent group[SIZE];
    unsigned len;

 //   student = input();
 //   output(student);
   len = inputCSV("students.csv",group,SIZE);
   outputGroup(group,len);
   printf("The average group mark is: %g",averageGroupMark(group,len));

    return 0;
}
