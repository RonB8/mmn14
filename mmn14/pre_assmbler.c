#include "pre_assmbler.h"
#include "data.h"
void mcrLabelsSpread(Vars* vars){
    int mcrFlag=0;
    int i=0;
    char line[81];
    resetStr(line);
    Mcr* temp=NULL;
    while(!feof(vars->file1)) {
        scanLine(vars->file1, line, &vars->IC);
        checkMcr(line, &mcrFlag);
        checkLabel(line, &vars->labelsCounter);
        if(mcrFlag){
            Mcr* m;
            m = (Mcr*)malloc(sizeof(Mcr));
            resetMcr(m);
            char *temp = malloc(sizeof(strtok(line+4," ")));
            strcpy(temp, strtok(line+4," "));
            m->name = temp;
            m->start = ftell(vars->file1);
            while(!feof(vars->file1) && mcrFlag){
                vars->fileCounter = ftell(vars->file1);
                resetStr(line);
                scanLine(vars->file1, line, &vars->IC);
                checkMcr(line, &mcrFlag);
                checkLabel(line, &vars->labelsCounter);
                i++;
            }
            //אם אנחנו כאן סימן שהמאקרו הסתיים
            m->end = vars->fileCounter;
            pushMcr(&vars->mcr,m);
            vars->mcrCounter++;
            continue;
        }
        else
            temp = idetifyMcr(vars->mcr, line);
        if(temp != NULL)
            printMcr(temp, vars);
        else
            fprintf(vars->file2, "%s", line);
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