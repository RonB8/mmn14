#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define SIZE_OF_BYTES 512
int my_bcmp (const void *b1, const void *b2, int len);
int getParamForBcmp(double*len, void **p1, void **p2);
int isValidInput(double len, double index1, double index2, char *str);

int main() {
    void *p;
    fgets(p,5,stdin);
    puts(p);
    return 0;
}

int my_bcmp (const void *b1, const void *b2, int len)
{
    int i=0;
    for(; i<len; i++)
    {
        if(*(i+(char*)b1) != *(i+(char*)b2))
            return 1;
    }
    return 0;
}

int getParamForBcmp(double *len , void **p1, void **p2)
{
    double ind1, ind2;
    char str[SIZE_OF_BYTES]={0};
    puts("Insert the folowing data:\nThe number of bytes to compare:");
    scanf("%lf", &(*len));
    puts("The first index:");
    scanf("%lf", &ind1);
    puts("The second index:");
    scanf("%lf", &ind2);
    *p1 = str + (int)ind1;
    *p2 = str + (int)ind2;
    puts("The string:");
    fgets(str, 512, stdin);
    return (isValidInput(*len, ind1, ind2, &str))? 1: 0;
}

int isValidInput(double len, double index1, double index2, char *str)
{
    char *part1, *part2;
    part1 = (char*)((char)index1+str);
    part2 = (char*)((char)index2+str);
    int valid=1;
    if(index1!=(int)index1 /*|| index2!=(int)index2 || len!=(int)len*/) {
        printf("Error!\nThe first index: %f is not valid!\nOnly natural numbers should be entered\n", index1);
        valid=0;
    }
    if(index2!=(int)index2) {
        if(valid) puts("Error");
        printf("The second index: %f is not valid!\nOnly natural numbers should be entered\n", index2);
        valid=0;
    }
    if(len!=(int)len) {
        if(valid) puts("Error");
        printf("The length: %f is not valid!\nOnly natural numbers should be entered\n", len);
        valid=0;
    }
    if(strlen(part1) < len) {
        if(valid) puts("Error");
        printf("The first segments who start from index: %d exceeds the bounds of the array\n",(int)index1);
        valid=0;
    }
    if(strlen(part2) < len) {
        if(valid) puts("Error");
        printf("The second segments who start from index: %d exceeds the bounds of the array\n",(int)index2);
        valid=0;
    }
    return valid;
}