#include "student.h"

TStudent  input()
{
    TStudent st;

    printf("Faculty number: ");
    scanf("%u",&st.fNo);
    printf("Name: ");
    fflush(stdin);
    fgets(st.name,LEN,stdin);
    if (strlen(st.name)<LEN-1)
        st.name[strlen(st.name)-1] = '\0';
    printf("Average Mark: ");
    scanf("%f",&st.avMark);

    return st;
}

void output(TStudent st)
{
    printf("(%u, %s, %.2f)\n",st.fNo,st.name,st.avMark);
}

void inputCSV(char *fname,TStudent *group,unsigned size)
{
    FILE *fin;

    fin = fopen(fname,"r");
    if (fin == NULL){
        perror(NULL);
        exit(errno);
    }
}
