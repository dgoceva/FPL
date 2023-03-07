#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NL putchar('\n')

void read(int data[], unsigned len);
void input(int data[], unsigned len);
void output(int data[], unsigned len);
long sum(int data[], unsigned len);
double average(int data[], unsigned len);
int maxNeg(int data[], unsigned len);
bool isEven(int element);
int squeze(int data[], unsigned len);
int min(int data[],int start,unsigned len);
void selectionSort(int data[],unsigned len);
int compare(const void* a,const void* b);
int binSearch(int find,int data[],unsigned len);
int linearSearch(int find,int data[],unsigned len);

int main()
{
    int myarray[20];
    double avr;
    int index;
    int size;
    int *data;

    srand((unsigned)time(NULL));
//    read(myarray,5);
//    output(myarray,5);

    input(myarray,20);
    output(myarray,20);
    printf("Find of 20: %d\n",linearSearch(20,myarray,20));
    selectionSort(myarray,20);
    output(myarray,20);
    printf("Find of 20: %d\n",binSearch(20,myarray,20));
    qsort(myarray,20,sizeof(int),compare);
    output(myarray,20);
    printf("The sum of my array is %ld\n",sum(myarray,20));
    avr = average(myarray,20);
    if(avr==-1)
    {
        printf("No such data...\n");
    } else
        printf("The average of positive data is %g\n",avr);

    index = maxNeg(myarray,20);
    if(index==-1)
        printf("No such data...\n");
    else
        printf("Max negative is %d. It's index is: %d\n",myarray[index],index);

    size = squeze(myarray,20);
    output(myarray,size);
    NL;NL;


    data = (int*)malloc(10*sizeof(int));
    if(data==NULL)
    {
        perror("malloc() error: ");
        exit(EXIT_FAILURE);
    }
    input(data,10);
    output(data,10);
    selectionSort(data,10);
    output(data,10);
    data = (int*)realloc(data,15*sizeof(int));
    if(data==NULL)
    {
        perror("malloc() error: ");
        exit(EXIT_FAILURE);
    }
    output(data,15);
    input(data+10,5);
    output(data,15);

    free(data);
//    printf("Hello world!\n");
    return 0;
}

void read(int data[], unsigned len)
{
    int i;

    for(i=0;i<len;++i)
    {
        printf("Data(%d)=",i+1);
        scanf("%d",&data[i]);
    }
}
void input(int data[], unsigned len)
{
    int i;

    for(i=0;i<len;++i)
    {
        data[i] = rand()%100-50;
    }
}

void output(int data[], unsigned len)
{
    int i;

    for(i=0;i<len;++i)
    {
        printf("%d\t",data[i]);
    }
    NL;
}

long sum(int data[], unsigned len)
{
    int i;
    long sum=0;

    for(i=0;i<len;++i)
    {
        sum += data[i];
    }
    return sum;
}

double average(int data[], unsigned len)
{
    int i;
    long sum;
    unsigned count;

    for(sum=count=i=0;i<len;++i)
    {
        if(data[i]>0)
        {
            count++;
            sum += data[i];
        }
    }
    return count?(double)sum/count:-1;
}

int maxNeg(int data[], unsigned len)
{
    int i;
    int idx;

    for(idx=-1,i=0;i<len;++i)
    {
        if(data[i]<0)
        {
            if(idx==-1)
                idx=i;
            else if(data[idx]<=data[i])
                idx=i;
        }
    }
    return idx;
}

int squeze(int data[], unsigned len)
{
    int i,j;

    for(j=i=0;i<len;++i)
    {
        if(isEven(data[i]))
            data[j++]=data[i];
    }

    return j;
}

bool isEven(int element)
{
    return element%2==0;
}

int min(int data[],int start,unsigned len)
{
    int i;
    int minIdx;

    for(minIdx=i=start;i<len;++i)
        if(data[minIdx]>data[i])
            minIdx=i;

    return minIdx;
}

void selectionSort(int data[],unsigned len)
{
    int i;
    int minIdx;
    int temp;

    for(i=0;i<len;++i)
    {
        minIdx=min(data,i,len);
        temp=data[i];
        data[i]=data[minIdx];
        data[minIdx]=temp;
    }
}

int compare(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}

int binSearch(int find,int data[],unsigned len)
{
    int low=0,high=len-1,mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(data[mid]==find){
            return mid;
        } else if(data[mid]<find){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

int linearSearch(int find,int data[],unsigned len)
{
    int i;

    for(i=0;i<len;++i)
        if(data[i]==find)
            return i;
    return -1;
}
