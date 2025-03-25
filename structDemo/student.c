#include "student.h"

TStudent input()
{
    TStudent st;

    printf("Faculty Number: ");
    scanf("%u",&st.fnom);
    printf("Name: ");
//    scanf("%s",st.name);
//    scanf("%s",st.name+strlen(st.name)+1);
//    st.name[strlen(st.name)]=' ';
    fflush(stdin);
    fgets(st.name,LEN,stdin);
    st.name[strlen(st.name)-1]='\0';
    printf("Average Mark: ");
    scanf("%f",&st.avmark);

    return st;
}

void output(TStudent st)
{
    printf("(%u, %s, %g)\n",st.fnom,st.name,st.avmark);
}

void inputGroup(TStudent *group, unsigned len)
{
    for (int i=0;i<len;++i){
        group[i] = input();
    }
}

void outputGroup(TStudent *group, unsigned len)
{
    for (int i=0;i<len;++i){
        output(group[i]);
    }
}

void inputGroupCSV(char *fname,TStudent *group, unsigned len)
{
    FILE *fin;
    char buff[1000];

    fin  = fopen(fname,"r");
    if (fin==NULL){
        perror("Error open file: ");
        exit(EXIT_FAILURE);
    }
// "%u,%[^\n]s,%f"
    for (int i=0;i<len;++i){
        if (fgets(buff,1000,fin)==NULL){
            perror(NULL);
            exit(EXIT_FAILURE);
        }
        group[i] = parseStudent(buff);
    }
    fclose(fin);
}

TStudent parseStudent(char *buff)
{
    TStudent st;
    char *first,*last;
    char tmp[1000];

    last = strchr(buff,',');
    memcpy(tmp,buff,last-buff);
    tmp[last-buff]='\0';
    st.fnom = atoi(tmp);
    first = last+1;

    last = strchr(last+1,',');
    memcpy(st.name,first,last-first);
    st.name[last-first]='\0';
    first = last+1;

    st.avmark = atof(first);

    return st;
}
