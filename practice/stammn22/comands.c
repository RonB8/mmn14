#include <stdio.h>
#include <math.h>
#include "data.h"
#include <strings.h>

static Vars vars;
void getCommand()
{
    varsToDefaulte(&vars);
    while (!vars.stopSign) {
        while(vars.validInput) {
            vars.endLine=0;
            puts("Insert the desired command:");
            readCommandType(&vars);
            if(vars.stopSign || !vars.validInput || redundantChar(1/**/)) break;
            readOperands(&vars);
            if(!vars.validInput) break;
            readTheRest();
            if(!vars.validInput) break;
            vars.p_set(*vars.operandA, *vars.operandB, *vars.operandC);
//            puts("Check operation");
        }
        if(vars.stopSign) break;
        if(!vars.isEOF)nextLine();
        vars.validInput=1;
    }
    puts("The program is over");
}
void readSet(set s, set n1, set n2) {
    set setForMask={0};
    set temp = {0};
    int n = 0;
    while (n!=-1) {
        if(!commaDetected()){
            if(vars.isEOF) {
                puts("List of set members is not terminated correctly");
                vars.isEOF=0;
            }
            vars.validInput=0;
            return; // !!!
        }
        n = scanNumber(&vars);
        if(n==(int)NULL) return; // !!!
        if ((n < 0 || n > 127) && n!=-1) {
            vars.validInput=0;
            puts("Invalid set member - value out of range");
            break;
        }
        if (n==-1) {
//            puts("Minus 1");
//            nextLine();
            break;
            commaDetected();
        }
        subSet(setForMask, setForMask, setForMask); //Reset the set
        nMask(setForMask, n); //creating mask that just the n-th bit is 1
        unionSet(temp, setForMask, temp);
    }
    //Initialize s just if all the members are valid
    unionSet(temp,temp,s); //Copy temp to s
}
void printSet(set s, set n1, set n2)
{
    if(emptySet(s)) {
        puts("The set is empty");
        return;
    }
    int counter=0;
    set temp={0}, mask={0};
    int i=0;
    for(; i<128; i++){
        nMask(mask, i);
        intersectSet(s, mask, temp);
        if(!emptySet(temp)) {
            if(counter>0 && counter%16==0){ puts("");} //If 16 elements already printed, down line
            counter==0? printf("{%i", i): printf(", %i", i); //Checks if this is the first element
            counter ++;
        }
    }
    printf("}\n");
}
void nMask(set s, int n){ //Creates mask of 128 bits that just the n-th bit is 1
    if (n<0 || 127<n) //The range is [0-127]
        puts("nMask function gets only number in a range [0-127]!");
        //checkin if the number 'n' is in range [0-31], [32-63], [64-95] or [96-127]
    else if(n<=31)
        s[0]= pow(2, n);
    else if(n<=63)
        s[1] = pow(2,n-32);
    else if(n<=95)
        s[2] = pow(2, n-64);
    else //if 96 <= n <= 127
        s[3] = pow(2, n-96);
}
void unionSet(set a, set b, set c) //unites sets b and a
{
    int i=0;
    for(; i<4; i++) // separately unites each 32 bits
        *(c+i) = *(a+i) | *(b+i);
}
int equalSets(set a, set b, set c)
{
    int i=0;
    while(i<4) { //comparing separately each 32 bit range from 128 bits of the sets
        if (*(a + i) != *(b + i))
            return 0;
        i++;
    }
    return 1;
}
void intersectSet(set a, set b, set c)
{
    int i=0;
    for(; i<4; i++)
        *(c+i) = *(a+i) & *(b+i);
}
void subSet(set a, set b, set c)
{
    int i=0;
    for(; i<4; i++)
        *(c+i) = *(a+i) & (*(a+i)^*(b+i)); //Insert to c, elements that exist in a, and also not exist in a and b = in a that not exist in b
}
void symdiffSet(set a, set b, set c)
{
    int i=0;
    for(; i<4; i++)
        *(c+i) = *(a+i) ^ *(b+i); //Insert to c, elements that exist just in one from a and b, but not both
}
int emptySet(set s) //Returns 0 if the set is empty, and otherwise - 1
{
    int i=0;
    for(; i<4; i++)
        if(*(s+i) != 0)
            return 0;
    return 1;
}
void printAllSets(set a,set b,set c,set d,set e,set f)
{
    printSet(a,b,c); printSet(b,a,c); printSet(c,b,a); printSet(d,a,b); printSet(e,a,b); printSet(f,a,b);
}

void readTheRest()
{

}

int commaDetected()
{
    int result = (int)NULL; //The value for returning
    char ch; //Rhe char for
    if(vars.lastChar==',' || vars.isEOF) {
        result = vars.isEOF? 0: 1;
        goto label;
    }
    ch=getchar();
    if(ch==ENTER || ch==EOF || ch==94 || ch=='\n' ) vars.isEOF=1; //For redSet function - case that is last number but is not '-1'
    while(ch==' ' || ch=='\t')
        ch=getchar();
    if(ch==',') {
        vars.lastChar=ch;
        result = 1;
        goto label;
    }
    else if(!vars.isEOF) //For case that is the last number for redSet function but is not '-1'
        puts("Missing comma");
    label:
    return result;
}
void nextLine(){
    if(vars.lastChar == '\n') return;
    char ch=getchar();
    while(ch!='\n' && ch!=10) {
        ch = getchar();
    }
}
int redundantChar(int n/**/)
{
    if(vars.lastChar==' ' || vars.lastChar=='\t' || vars.lastChar=='\n')
        return 0;
    vars.validInput=0;
    n==2? puts("Extraneous text after end of command"): puts("Illegal comma");
    return 0;
}
void varsToDefaulte(Vars* vars)
{
    vars->commaRequired=0;
    vars->validInput=1;
    vars->lastChar=' ';
    vars->isEOF=0;
    vars->endLine=0;
    vars->numOfArg=0;
    vars->stopSign=0;
    resetTheSet(vars->SETA);
    resetTheSet(vars->SETB);
    resetTheSet(vars->SETC);
    resetTheSet(vars->SETD);
    resetTheSet(vars->SETE);
    resetTheSet(vars->SETF);
}
void resetTheSet(set s)
{
    int i=0;
    while(i<4)
        s[i++] = 0;
}