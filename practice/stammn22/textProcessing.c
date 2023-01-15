#include "data.h"
#include <stdio.h>
#include <strings.h>

char* scanWord(Vars* vars)
{
    char ch;
    int i=0;
    int iteration=0;
    while(i<MAX_WORD_SIZE-1 && iteration<500)
    {
        iteration++;
        ch = getchar();
        if(ch==',' && i==0) { //If should be here comma is already detected by 'commaDetected' func
            if (vars->lastChar == ',') {
                puts("Multiple consecutive commas");
            }
            else {
                puts("Illegal comma");
            }
            vars->validInput=0;
            return NULL;
        }
        if(ch==' ' || ch=='\t' || ch==',') {
            if(i==0) //if str yet empty
            {
                continue;
            }
            else {
                if(ch==','){
                    if(!vars->commaRequired) {
                        vars->validInput=0;
                        puts("Illegal comma");
                        return NULL; // !!!
                    }
                    if(vars->endLine) {
                        vars->validInput=0;
                        puts("Extraneous text after end of command");
                        return NULL;
                    }
                }
                break;
            }
        }
        if(ch == '\n'){
            vars->endLine=1;
            vars->isEOF=1;
            *(vars->str+i)=ch;
            break;
        }
        *(vars->str+i)=ch;
        i++;
    }
    vars->lastChar=ch;
    *(vars->str+i)= '\0';
    vars->commaRequired=1;
    return vars->str;
}

int scanNumber(Vars *vars)
{
    char *strPointer;
    strPointer=scanWord(vars);
    //puts(strPointer);
    if(strPointer==NULL){ puts("Stacel!!");return NULL;}
    int result = (int)strToInt(strPointer, vars);
    return result;
}

int strToInt(char *strInp, Vars* vars)
{
    int result=0;
    int i=0;
    int sign = *(strInp+i)=='-' ? -1+(i++): 1;
    char currDigit;
    for(; i< strlen(strInp); i++) {
        result*=10;
        currDigit = *(strInp+i)-48;
        if(currDigit<0 || 9<currDigit){ //If is not digit
            puts("Invalid set member - not an integer");
            vars->validInput=0;
            return NULL;
        }
        result += currDigit;
    }
    return result*sign;
}