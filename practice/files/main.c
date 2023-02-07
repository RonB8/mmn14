#include "data.h"
#include <sys/stat.h>
typedef struct{
    int n;
}P;
typedef struct{
    int a,b,c,d;
    P** p;
}Vars;
int main()
{
    struct stat stats;
    int i=0;
    FILE *file1;
    file1 = fopen("C:\\filesForC\\stamtext.txt", "r");

    char temp;
    while(i<27) {
            fseek(file1, 2*i, SEEK_SET);
        fprintf(file1,"%c", 'a'+i);
        i++;
    }
    return 0;
}
