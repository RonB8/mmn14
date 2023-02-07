#include "data.h"
//כיוון שהקבצים לקריאה ולכתיבה נמצאים על המחשב ולא בגיטהאב, אצל כל אחד כתובת הנתיב של הקובץ היא שונה, לכן הגדרתי header -paths שלא נמצא בגיטהאב, והוא מכיל את הקבועים שמייצגים את הכתובות של הקבצים לפי המחשב שלי, תיצור גם header כזה
#include "paths.h"
//tr

static char emptyStr[81];

int main() {
    Vars vars;
    varsTodefaulte(&vars);
    mcrLabelsSpread(&vars);
    return 0;
}

//Need to move to another file!!!
void varsTodefaulte(Vars* vars){
    char emptyStr[80]={0};
    strcpy(vars->operation, emptyStr);
    strcpy(vars->addWord1, emptyStr);
    strcpy(vars->addWord2, emptyStr);
    strcpy(vars->currentWord, emptyStr);
    strcpy(vars->line, emptyStr);
    strcpy(vars->operand1, emptyStr);
    strcpy(vars->operand2, emptyStr);
    strcpy(vars->parameter1, emptyStr);
    strcpy(vars->parameter2, emptyStr);
    vars->mcrFlag=0;
    vars->IC=0;
    vars->mcrCounter=0;
    vars->labelsCounter=0;
    vars->fileCounter=0;
    vars->mcr=NULL;
    vars->file1 = fopen(PATH1, "r"); //PATH1/2 defined in paths.h
    vars->file2 = fopen(PATH2, "w");
    int i=0;
    for(;i<80;i++)
        vars->line[i]=0;
        emptyStr[i]=0;
}
void resetStr(char* str){
    char t[81]={0};
    strncpy(str,t,81);
}
void resetMcr(Mcr* mcr){
    char emptyStr[8]={0};
    mcr->name = malloc(sizeof(emptyStr));
    strcpy(mcr->name, emptyStr);
    mcr->start=0;
    mcr->end=0;
    mcr->nextMcr = NULL;
}
void pushMcr(Mcr** rootMcr, Mcr* newMcr){
    Mcr* m;
    if(*rootMcr == NULL) {
        *rootMcr = newMcr;
        (*rootMcr)->nextMcr = NULL;
    }
    else
        pushMcr(&((*rootMcr)->nextMcr), newMcr);
}