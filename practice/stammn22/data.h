//
// Created by user on 14/12/2022.
//
#include <stdlib.h>
#ifndef MMN22_DATA_H
#define MMN22_DATA_H

#endif //MMN22_DATA_H
#define MAX_WORD_SIZE 15
#define ENTER 10
typedef unsigned int set[4]; //16 bytes = 128 bits, every single bit is organ from the set

static char setAStr[]="SETA",setBStr[]="SETB", setCStr[]="SETC", setDStr[]="SETD", setEStr[]="SETE", setFStr[]="SETF";
static char readStr[]="read_set", printSetStr[]="print_set", emptySetStr[]="empty_set", unionSetStr[]="union_set", equalSetsStrStr[]="equal_sets", intersectSetStr[]="intersect_set", subSetStr[]="sub_set", symdiffSetStr[]="symdiff_set", stopStr[]="stop";


void readSet(set a, set, set);
void printSet(set s, set, set);
void unionSet(set a, set b, set); //Copies set b to set a
void intersectSet(set a, set b, set c);
void subSet(set a, set b, set c);
void symdiffSet(set a, set b, set c);
void resetTheSet(set);
void printAllSets(set,set,set,set,set,set);
int emptySet(set a);
int equalSets(set a, set b, set c);
void printBits(size_t const size, void const * const ptr);
void nMask(set s, int n);
typedef struct {
    int commaRequired;
    int validInput;
    char lastChar;
    int isEOF;
    int endLine;
    int numOfArg;
    int stopSign;
    char *command;
    void (*p_set)(set a, set b, set c);
    set *operandA, *operandB, *operandC;
    set SETA, SETB, SETC, SETD, SETE, SETF;
    char str[MAX_WORD_SIZE];
}Vars;
void scanSets(set**,set**,set**);
void readCommandType(Vars*);
void getCommand();
void readOperands(Vars*);
void readTheRest();
int commaDetected();
int scanNumber(Vars*);
static char firstArg[15], secondArg[15], thirdArg[15];
static char instruction[15]={0};
int strToInt(char *str, Vars*);
int scanNumber(Vars*);
void nextLine();

int redundantChar(int/**/);

char* scanWord(Vars*);
void varsToDefaulte(Vars*);
