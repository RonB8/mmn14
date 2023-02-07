/*
15.1.2023
 * */
#define MAX_LINES 100
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#ifndef MMN14_DATA_H

#define MMN14_DATA_H

#endif //MMN14_DATA_H

typedef struct {
    char* name;  //  אולי לשנות לname[]
    int start;
    int end;
    struct Mcr* nextMcr;
}Mcr;
//מבנה שמכיל את כל הפרמטרים הנדרשים לפונקציות, מוגדר כמבנה כדי שיהיה אפשר להעביר את כל המשתנים בין הפונקציות ע"י כתובת אחת - של Vars
typedef struct { //לפצל!
    char line[81];
    char operation[5]; //The longest operation is 'stop' whose length is 4
    char operand1[12]; //points to the operand (label/register/immediate number)
    char operand2[12];
    char parameter1[12];
    char parameter2[12];
    char firstWord[14]; //Of the machine code
    char addWord1[14]; //first additional word
    char addWord2[14]; //second additional word
    char currentWord[14]; //לתוכה תיכנס המילה שניקראה, יתבצע העיבוד, ואז המילה תועתק למילה הרלוונטית (מתוך ה3 למעלה)
    //      -flags-
    //דלוק = 1, כבוי = 0
    int mcrFlag; //נדלק אם זוהתה פקודת מאקרו("mcr"), נכבה אם זוהתה סוף פקודת מאקרו ("endmcr")
    int IC; //מונה שורות הפקודה (instruction counter)
    char *comArr[MAX_LINES]; //מערך של שורות הפקודה בקובץ
    Mcr* mcr;
    int mcrCounter;
    int labelsCounter;
    int fileCounter;
    FILE* file1;
    FILE* file2;
}Vars; //variables (אם יש לך שם יותר טוב מוזמן להציע)

//      -Functions-
//קורא את הword (שזה כל השורה) הבאה ושומר אותה ב-currentWord, נעצר בתו '\n' או בEOF
void readWord(Vars*);

//קבוצה 1 - {mov, cmp, add, sub, lea} מקבלות 2 אופרנדים
//קבוצה 2 - {not, clr, inc, dec, jmp, bne, red, prn, jsr} מקבלות אופרנד אחד, סיביות 4-5 חסרות משמעות
//קבוצה 3 - {rts, stop} אין אופרנדים, הקידוד מורכב ממילה אחת, סיביות 2-5 אינם בשימוש
int typeIncSet(Vars*); //מחזיר מספר מ1-3 שמייצג לאיזו קבוצת הוראות שייכת ההוראה הנוכחית


void scanLine(FILE*, char*,int* IC);
void varsTodefaulte(Vars*);
void mcrLabelsSpread(Vars*);
void resetStr(char*);
void resetMcr(Mcr*);
void checkLabel(char* str, int* labelsCounter);
void createLabelsTable(Vars* vars);
void pushMcr(Mcr** rootMcr, Mcr* newMcr);
Mcr* idetifyMcr(Mcr* root, char* str);
void fprintRange(FILE* destination, FILE* source, int from, int until);
void printMcr(Mcr* mcr, Vars* vars);
void checkMcr(char* str, int* mcrFlag);