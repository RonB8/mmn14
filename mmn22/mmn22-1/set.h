#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#define MMN22_DATA_H

#define MAX_WORD_SIZE 15 /*The longest word in the command is 13 characters long (intersect_set)*/
#define ENTER 10
#define MAX_MEMBERS_IN_LINE 16 /*Corresponds to the printing method needed in the assignment*/
#define MAX_ITERATIONS 200 /*Prevent an infinite loop condition in the scanWord function*/
/*set is an array of 4 ints, which contains 128 bits, each bit represents a digit from the range [0-127], so if the ith bit is on, then the ith digit exists in the set*/
typedef unsigned int set[4];
/*The structure Vars - variables is designed to allow the transfer of addresses of variables and flags between functions, easily with a single address.*/
typedef struct {
    int commaRequired; /*A flag that indicates whether a comma is required before the next word*/
    int validInput; /*A flag that indicates if an incorrect input has been detected*/
    int isEOF; /*A flag that indicates whether an end-of-file character has been detected*/
    int stopSign; /*A flag that indicates whether the 'stop' command was received*/
    int endLine; /*A flag that indicates whether an end-of-line character has been detected*/
    char lastChar; /*Saves the last character at the end of a word scan*/
    int numOfArg; /*Saves the value of the number of arguments needed depending on the command type*/
    char* command; /*Stores the string that represents the command*/
    set *operandA, *operandB, *operandC; /*Pointers to sets will point to sets from {SETA,...,SETF} according to the received command*/
    set SETA, SETB, SETC, SETD, SETE, SETF;
    char str[MAX_WORD_SIZE]; /*Saves the string read from scanWord*/
    int emptyLine; /* Flag that sign if the current line is empty */
}Vars;
/*Strings to compare*/
static char readStr[]="read_set", printSetStr[]="print_set", emptySetStr[]="empty_set", unionSetStr[]="union_set", equalSetsStrStr[]="equal_sets", intersectSetStr[]="intersect_set", subSetStr[]="sub_set", symdiffSetStr[]="symdiff_set", stopStr[]="stop";

void read_set(set s, set nothing1, set nothing2, Vars* vars);
void print_set(set s, set nothing1, set nothing2, Vars* vars);
void union_set(set a, set b, set c, Vars* vars); /*Copies set b to set a*/
void intersect_set(set a, set b, set c, Vars* vars);
void sub_set(set a, set b, set c, Vars* vars);
void symdiff_set(set a, set b, set c, Vars* vars);
void resetTheSet(set);
int empty_set(set s);
void nMask(set s, int n);
void readCommandType(void** p, Vars*);
void getCommand(Vars*);
void readOperands(Vars*);
int commaDetected(Vars*);
int scanNumber(Vars*);
int strToInt(char *str, Vars*);
int scanNumber(Vars*);
void nextLine(Vars*);
int redundantChar(int, Vars* vars);
char* scanWord(Vars*);
void varsToDefaulte(Vars*);
