#include "student.h"

int main()
{
    unsigned size;
    TStudent *group;

    group = inputCSV("C:\\Samples\\FPL\\structExample\\students.csv",&size);
    if (group == NULL){
        return -1;
    }
    outputGroup(group,size);
    free(group);

    return 0;
}
