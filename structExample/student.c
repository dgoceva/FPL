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

unsigned inputCSV(char *fname,TStudent *group,unsigned size)
{
    FILE *fin;
    unsigned len;

    fin = fopen(fname,"r");
    if (fin == NULL){
        perror(NULL);
        exit(errno);
    }

    len = countStudents(fin);
    if (len > size)
        len = size;

    for (int i=0;i<len;++i){
        group[i] = readStudent(fin);
    }
    fclose(fin);
    return len;
}

TStudent readStudent(FILE *fin)
{
    TStudent st;
    char buff[1000];
    char *token;

    if (fgets(buff,sizeof(buff),fin)==NULL){
        perror(NULL);
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    token = strtok(buff,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    sscanf(token,"%u",&st.fNo);

    token = strtok(NULL,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    strcpy(st.name,token);

    token = strtok(NULL,",");
    if (token==NULL){
        printf("Error in data\n");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
    sscanf(token,"%f",&st.avMark);

    return st;
}

unsigned countStudents(FILE *fin)
{
    unsigned counter=0;
    char buff[1000];

    while (fgets(buff,sizeof(buff),fin)!=NULL){
        counter++;
    }
    rewind(fin);
    return counter;
}

void outputGroup(TStudent *group, unsigned size)
{
    for (int i=0;i<size;++i){
        output(group[i]);
    }
}

float averageGroupMark(TStudent *group, unsigned size)
{
    float sum = 0;

    for (int i=0;i<size;++i){
        sum += group[i].avMark;
    }

    return (size>0) ? sum/size : 0;
}
