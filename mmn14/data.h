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
    char* name;
    int start;
    int end;
    struct Mcr* nextMcr;
}Mcr;


//      -Functions-

//קבוצה 1 - {mov, cmp, add, sub, lea} מקבלות 2 אופרנדים
//קבוצה 2 - {not, clr, inc, dec, jmp, bne, red, prn, jsr} מקבלות אופרנד אחד, סיביות 4-5 חסרות משמעות
//קבוצה 3 - {rts, stop} אין אופרנדים, הקידוד מורכב ממילה אחת, סיביות 2-5 אינם בשימוש
//int typeIncSet(Vars*); //מחזיר מספר מ1-3 שמייצג לאיזו קבוצת הוראות שייכת ההוראה הנוכחית


void scanLine(FILE*, char*);
//void varsTodefaulte(Vars*);
FILE* mcrLabelsSpread(FILE* source);
void resetStr(char*);
void resetMcr(Mcr*);
void checkLabel(char* str, int* labelsCounter);
//void createLabelsTable(Vars* vars);
void pushMcr(Mcr** rootMcr, Mcr* newMcr);
Mcr* idetifyMcr(Mcr* root, char* str);
void fprintRange(FILE* destination, FILE* source, int from, int until);
void printMcr(FILE* destination, FILE* source, Mcr* mcr);
void checkMcr(char* str, int* mcrFlag);
//          ~~~~~~~~~~from global~~~~~~~~~~



#define IC_ADDRESS 100
#define MAX_LINE_LEN 82
typedef enum boolean{
    FALSE,
    TRUE
} boolean;

enum opcode {
    /*instructions with 2 operands */
    mov, cmp, add, sub, nit, clr, lea,
    /*instructions with 1 operand */
    inc, dec, jmp, bne, red, prn, jsr,
    /*instructions without operand */
    rts, stop};

enum registers {r0, r1, r2, r3, r4, r5, r6, r7};

enum adressing_methods {immediate, direct, jump, direct_register};

typedef struct{
    char label[82];
    int address;
} table;

//table label_table[12];

enum opcode opExists(char* operation);
