/*
 * זיהוי שורה
 * טיפול בפסיקים בין מילים
 *
 *
 * */
#include "data.h"

void scanLine(FILE* source, char* destination){
    char delim[6] = " \n\t";
    char st[81];
    char* p;
    char ch;
    int i=0;
    resetStr(st);
    ch = fgetc(source);
    while(ch!=10 && ch!=0 && ch!=-1){
        st[i]=ch;
        ch = fgetc(source);
        i++;
    }
    st[i]=10;
    strcpy(destination, st);
//    *IC++;
}
void printMcr(FILE* destination, FILE* source, Mcr* mcr){
    fprintRange(destination, source, mcr->start, mcr->end);
}
void fprintRange(FILE* destination, FILE* source, int from, int until){
    int currentPointer = ftell(source);
    int i=from;
    fseek(source, from, 0);
    while(i<until-2){
        fputc(fgetc(source), destination);
        i++;
    }
    fseek(source, currentPointer, 0);

}
void resetStr(char* str){
    char t[81]={0};
    strncpy(str,t,81);
}