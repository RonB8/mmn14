/*
 * Author: Ron Bar
 * Date: 04/01/2023
    Program description:
 *  The program works as an interactive "pocket computer" for performing operations on groups.
    The program reads commands from the standard input, decodes and executes them. The commands deal with operations on groups.
    In the data file, a set type variable is defined that represents a group.
    set is built from 4 ints, i.e. 128 bits, and each bit represents a number from the range [0-127], so the i-th bit represents the i-number.
    If in set the i bit is on, it means that the number i is in the set group.
    Since a set is built from 4 ints, the functions that use bitwise operations, perform the operations on each of the 4 ints separately.

 *  In the data file, a 'vars' structure is defined that contains all the flags and variables for the program's operations.
    An explanation of each variable appears in the data file.

    The command files:
 *  commands.c - contains the functions called from the user and additional auxiliary functions.
    readFields.c - contains functions that accept each of the command fields: ~command type~, ~sets~, ~initialization values~.
    textProcessing.c - contains functions that receive text input and process it.
 */
#include "set.h"
void (*p_set)(set a, set b, set c, Vars* vars); /*A pointer to a function*/

int main() {
    Vars vars; /*vars(variables) is a structure that contains all the variables and flags that the function from the commands use*/
    varsToDefaulte(&vars); /*Initializes the vars variables to the diplative values*/
    getCommand(&vars);
    return 0;
}
/*Reads a command, field by field*/
void getCommand(Vars* vars){
    void* pToFunc;
    while (!vars->stopSign) { /*If it needs to stop, stopSign will be initialized to 1, otherwise the function continues reading command lines*/
        while(vars->validInput) {
            /*If validInput=0, an input error has probably been detected, and we'll skip to the next command line, otherwise we'll continue reading the current command line */
            vars->endLine=0; /* Reset the flag before the new line*/
            if(!vars->emptyLine) /* If the previous line is empty, the request for input has already been printed */
                puts("Insert the desired command:");
            vars->emptyLine=0; /* Reset the flag before the new line*/
            readCommandType(&pToFunc, vars);
            if(vars->stopSign || !vars->validInput || redundantChar(1,vars)){
                break;
            }
            readOperands(vars); /*Reads the sets to operandA, operandB, and operandC.*/
            if(!vars->validInput || redundantChar(2, vars)) break;
            p_set = pToFunc;
            p_set(*vars->operandA, *vars->operandB, *vars->operandC, vars); /*p_set is pointing to the function that initialize in 'readCommandType', operands a,b, and c is the operands that initialize in 'readOperands'*/
        }
        if(vars->stopSign || vars->isEOF) break; /*If stopSign != 0 so the command 'stop' was received, then exits from the while and finishing the program*/
        if(!vars->endLine )nextLine(vars); /*If the readings are finished but there are still characters left in the line (due to an input error), we will skip to the next line*/
        vars->validInput=1; /*Resets the flag for the next command*/
    }/*End of two loops*/
    puts("The program is over");
}