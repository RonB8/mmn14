#include "data.h"
#include <strings.h>
#include <stdio.h>

void readCommandType(Vars* vars)
{
    vars->commaRequired=0; //There shouldn't be a comma here
    vars->command = scanWord(vars);
    if(vars->command==NULL) return; // !!! (exit)
    if((strcmp(vars->command, readStr))==0) {
        vars->p_set = readSet;
        vars->numOfArg=1;
    }
    else if(strcmp(vars->command, printSetStr)==0){
        vars->p_set = printSet;
        vars->numOfArg=1;
    }
    else if(strcmp(vars->command, unionSetStr)==0) {
        vars->p_set = unionSet;
        vars->numOfArg=3;
    }
    else if(strcmp(vars->command, intersectSetStr)==0){
        vars->p_set = intersectSet;
        vars->numOfArg=3;
    }
    else if(strcmp(vars->command, symdiffSetStr)==0){
        vars->p_set = symdiffSet;
        vars->numOfArg=3;
    } else if(strcmp(vars->command, subSetStr)==0){
        vars->p_set = subSet;
        vars->numOfArg=3;
    } else if(strcmp(vars->command, stopStr)==0){
        vars->stopSign=1;
    }
    else{
        vars->validInput=0;
        puts("Undefined command name");
    }
}
void readOperands(Vars* vars)
{
    char *SETStr="SET";
    vars->isEOF=0;
    int sum = vars->numOfArg;
    set **p;
    int i=0;
    char *op;
    p = &vars->operandA;
    while(i<sum){
        if (i==1) {
            if(!commaDetected()){
                if(vars->isEOF) puts("Missing parameter");
                vars->validInput=0;
                return;
            } //Required comma before the second operand
            p = &vars->operandB;
        }
        else if (i==2){
            if(!commaDetected()) {
                if(vars->isEOF) puts("Missing parameter");
                vars->validInput = 0;
                return;
            }//Required comma before the third operand
            p=&vars->operandC;
        }
        if(i+1 == sum && strcmp(vars->command,readStr) != 0) vars->endLine=1; //Putting a sign if is the last operand
        op = scanWord(vars);
        if(op==NULL) return;
        if(strncmp(op,SETStr,3)==0 && 'A' <= *(op+3) && *(op+3)<='F' ) {
            if (*(op+3) == 'A') *p = vars->SETA;
            else if (*(op+3) == 'B') *p = vars->SETB;
            else if (*(op+3) == 'C') *p = vars->SETC;
            else if (*(op+3) == 'D') *p = vars->SETD;
            else if (*(op+3) == 'E') *p = vars->SETE;
            else if (*(op+3) == 'F') *p = vars->SETF;
        }
        else{ //If the operand is not exist
            vars->validInput=0;
            puts("Undefined set name");
            return;
        }
        i++;
    }
}