#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

void upperCase(char str[])
{
    for (unsigned i=0;i<strlen(str);++i){
        str[i] = toupper(str[i]);
    }
}
void lowerCase(char str[])
{
   for (unsigned i=0;i<strlen(str);++i){
        str[i] = tolower(str[i]);
   }
}
void sentenceCase(char str[])
{
    str[0] = toupper(str[0]);
    for (unsigned i=1;i<strlen(str);++i){
        str[i] = tolower(str[i]);
   }
}
void workWithNames()
{
    char name[LEN];
    fgets(name,LEN,stdin);
    name[strlen(name)-1]='\0';
    puts(name);
    upperCase(name);
    printf("Hello world,%s!\n",name);
    sentenceCase(name);
    printf("Hello world,%s!\n",name);
    lowerCase(name);
    printf("Hello world,%s!\n",name);
}

void fillWithZero(unsigned counter[],unsigned len)
{
    for (unsigned i=0;i<len;++i){
        counter[i] = 0;
    }
}

void count(char line[], unsigned counter[])
{
    char temp[strlen(line)];
    strcpy(temp,line);
    upperCase(temp);
    for (unsigned i=0;i<strlen(line);++i){
        if (isalpha(temp[i])){
            ++counter[temp[i]-'A'];
        }
    }
}

void outputCounter(unsigned counter[],unsigned len)
{
    for (unsigned i=0;i<len;++i){
        printf("%c->%u\t",'A'+i,counter[i]);
    }
    printf("\n");
}

unsigned countWords(char line[])
{
    const unsigned IN=1,OUT=0;
    unsigned state=OUT;
    unsigned words=0;

    for (unsigned i=0;i<strlen(line);++i){
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++words;
        }
    }
    return words;
}

unsigned countLines(char line[])
{
    unsigned lines=1;

    for (unsigned i=0;i<strlen(line);++i){
        if (line[i]=='\n')
            ++lines;
    }
    return lines;
}

void workWithLines()
{
    const unsigned SIZE=10000,LETTERS=26;
    char buffer[LEN], line[SIZE];
    unsigned counter[LETTERS];
    unsigned lines;

    fillWithZero(counter,LETTERS);
//    outputCounter(counter,LETTERS);
    while (fgets(buffer,LEN,stdin)!=NULL){
            strcat(line,buffer);
 //           buffer[strlen(buffer)-1]='\0';
    }
 //    line[strlen(line)-1]='\0';
    printf("\n");
    lowerCase(line);
    printf("\n");
    upperCase(line);
    puts(line);
    printf("\n");
    sentenceCase(line);
    puts(line);
    lines = countLines(line);
    printf("\n%l
           u bytes in a text\n",strlen(line)+1-lines);
    printf("%u words in a text\n",countWords(line));
    printf("%u paragraphs in a text\n\n",lines/2);

    count(line,counter);
    outputCounter(counter,LETTERS);
}
int main()
{
//    workWithNames();
    workWithLines();
    return 0;
}
