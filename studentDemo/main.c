#include "student.h"

int main()
{
     TStudent *data;
     unsigned size;

     data = inputCSV("students.csv", &size);
     outputGroup(data,size);
     outputBin("students.bin",data,size);
     free(data);
     printf("-----------------------------------------------------------------------------\n");
     data = readBin("students.bin",&size);
     outputGroup(data,size);
     free(data);

     return EXIT_SUCCESS;
}
