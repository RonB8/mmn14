#include "pre_assmbler.h"
#include "data.h"


FILE* mcrLabelsSpread(FILE* source){
    int mcrFlag=0;
    int i=0;
    char line[81];
    int labelsCounter=0;
    int fileCounter;
    FILE* result;
    result = fopen("C:\\filesForC\\afterPreAsm.am", "w");
    resetStr(line);
    Mcr* root;
    Mcr* temp;
    root=NULL; temp=NULL;
    while(!feof(source)) {
        scanLine(source, line);
        checkMcr(line, &mcrFlag);
        checkLabel(line, &labelsCounter);
        if(mcrFlag){
            Mcr* m;
            m = (Mcr*)malloc(sizeof(Mcr));
            resetMcr(m);
            char *mcrName;
            mcrName = malloc(sizeof(strtok(line+4," ")));
            strcpy(mcrName, strtok(line+4," "));
            m->name = mcrName;
            m->start = ftell(source);
            while(!feof(source) && mcrFlag){
                fileCounter = ftell(source);
                resetStr(line);
                scanLine(source, line);
                checkMcr(line, &mcrFlag);
                checkLabel(line, &labelsCounter);
                i++;
            }
            //אם אנחנו כאן סימן שהמאקרו הסתיים
            m->end = fileCounter;
            pushMcr(&root,m);
//            vars->mcrCounter++;
            continue;
        }
        else
            temp = idetifyMcr(root, line);
        if(temp != NULL)
            printMcr(result, source, temp);
        else
            fprintf(result, "%s", line);
        i++;
    }
}

void checkLabel(char* str, int* labelsCounter){
    int n;
    char temp[strlen(str)];
    strcpy(temp, str);
    char* s = strtok(temp," ");
    n = strlen(s)-1;
    if(s[n] == ':')
        (*labelsCounter)++;
}
Mcr* idetifyMcr(Mcr* root, char* str){ //recursive function
    if(root == NULL)
        return NULL;
    if(root->name != NULL && str != NULL && strcmp(root->name, str)==0)
        return root;
    else
        return idetifyMcr(root->nextMcr, str);
}
void checkMcr(char* str, int* mcrFlag){
    if(strnicmp(str, "mcr ", 4)==0)
        *mcrFlag=1;
    else if(stricmp(str, "endmcr\n")==0)
    *mcrFlag=0;
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