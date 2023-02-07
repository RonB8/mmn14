#include "mymat.h"
#include "analyze.h"
#include "messages.h"
#include <stdio.h>

/**
 * @brief: This program is a mat calculator. It has 6 mats for the user to use
 *          and 8 functions.
 *
 *         The mats names are: MATA, MATB, MATC, MATD, MATE and MATF. They are
 *          stored in an array. The mats have 4 rows and 4 columns and they cans
 *          store any real number.
 *
 *         The calculator functions are:
 *          1. read_mat - a function that resets the mat and sets it.
 *              It can be used the following way:
 *              "read_mat MATX, num1, num2, ..., last_num"
 *              # X can be A-F.
 *              # between the command and the mat name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the mat name and after each parameter (except after the last one).
 *              # the mat has 16 parameters, if you enter less than 16 then the rest will be set to 0.
 *              # if you enter more than 16 then only the first 16 will be counted.
 *          2. print_mat: This function prints the parameters of the given mat.
 *              It can be used the following way:
 *              "print_mat MATX"
 *              # X can be A-F.
 *              # between the command and the mat name must be at least 1 space or 1 tab.
 *              # after the mat name, there can only be spaces and tabs.
 *          3. add_mat: This function does addition on the first 2 mats and
 *              stores the result in the third mat.\n");
 *              It can be used the following way:
 *              "add_mat MATX, MATY, MATZ"
 *              # X can be A-F, Y can be A-F, Z can be A-F.
 *              # between the command and the first mat name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the first and second mats' names.
 *              # after the third mat name, there can only be spaces and tabs.
 *          4. sub_mat: This function subtract the second mat from the first mat
 *              and stores them in the third mat.
 *              It can be used the following way:
 *              "sub_mat MATX, MATY, MATZ"
 *              # X can be A-F, Y can be A-F, Z can be A-F.
 *              # between the command and the first mat name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the first and second mats' names.
 *              # after the third mat name, there can only be spaces and tabs.
 *          5. mul_mat: This function multiplie the first 2 mats and stores the
 *              result in the third mat.
 *              It can be used the following way:
 *              "mul_mat MATX, MATY, MATZ"
 *              # X can be A-F, Y can be A-F, Z can be A-F.
 *              # between the command and the first mat name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the first and second mats' names.
 *              # after the third mat name, there can only be spaces and tabs.
 *          6. mul_scalar: This function multiplie the first mat with the scalar and stores the
 *              result in the second mat.
 *              It can be used the following way:
 *              "mul_scalar MATX, Y, MATZ"
 *              # X can be A-F, Y can be A-F, Z can be A-F.
 *              # between the command and the mat name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the first mat name and the number.
 *              # after the second mat name, there can only be spaces and tabs.
 *          7. trans_mat: This function does transpose on the first mat and stores
 *              the result in the second mat.
 *              It can be used the following way:
 *              ""trans_mat MATX, MATY"
 *              # X can be A-F, Y can be A-F.
 *              # between the command and the first matt name must be at least 1 space or 1 tab.
 *              # there has to be a comma after the first mat name.
 *              # after the second set name, there can only be spaces and tabs.
 *          8. stop - a function that exits from the calculator.
 *              It can be used the following way:
 *              "stop"
 *              # after the command, there can only be spaces and tabs.
 *
 *         The structs that are used in this program are:
 *          mat - a struct that holds a 2 dim array of doubles.
 *
 *         Files used for this program are:
 *          mainmat.c - this file has the main function in it and some helping
 *                     functions.
 *          mymat.h - this file has some macro defined in it, the declarations
 *                      and definition of mat, the declarations of the
 *                      8 functions for the calculator and a couple of helping
 *                      functions.
 *          mymat.c - this file has the definition of the functions which are
 *                      declared in the mymat.h file.
 *          analyze.h - this file has the declarations and definition of the
 *                      Command and MatName enums and the declarations of the
 *                      some functions which are used to analyze the input.
 *          analyze.c - this file has the definition of the functions which are
 *                      declared in the analyze.h file.
 *          messages.h - this file has the declarations and definition of the
 *                      Error enum and the declarations of the some functions
 *                      which are used to print massages (mainly errors).
 *          messages.c - this file has the definition of the functions which are
 *                      declared in the messages.h file.
 *
 */

/**
 * @brief: Declerations of helping functions.
 *         Discerption is above each function.
 */
void print_line(char*);
int get_line(char*, Error*);
void clean_line(char*);
void handle_error(Error error);
void do_command(Command, MatName, MatName, MatName, mat*, double, double*);


int main() {
    mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
    char line[MAX_LEN];
    int status = 0, i = 0;
    double scalar = 0;/* var for mul_scalar */
    double members[MAT_SIZE];/* array for vars in read_mat. */
    MatName x = EMPTY, y = EMPTY, z = EMPTY;
    Command command;
    Error error = NONE;

    mat mat_array[6];
    for (i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                mat_array[i] = MAT_A;
            case 1:
                mat_array[i] = MAT_B;
            case 2:
                mat_array[i] = MAT_C;
            case 3:
                mat_array[i] = MAT_D;
            case 4:
                mat_array[i] = MAT_E;
            case 5:
                mat_array[i] = MAT_F;
        }
        clean_mat(&mat_array[i]);
    }

    intro();

    while (status != -1) {
        printf(">>> ");/* prompt to indicate that the calculatour is ready for a new command.*/
        status = get_line(line, &error);/* 0 = good, -1 = EOF */
        print_line(line);
        handle_error(error);

        analyze(line, &command, &x, &y, &z, members, &scalar, &error);
        if (error != NONE) {
            handle_error(error);
        } else {/* error == NONE */
            do_command(command, x, y, z, mat_array, scalar, members);
        }
        error = NONE;
    }/* while */
    illegal_exit();
    stop();

    return 0;
}

/**
 * @brief: Prints the line.
 *         If line is NULL, prints nothing.
 *
 * @param line - array of chars, the size of MAX_LEN (80).
 */
void print_line(char* line) {
    int i = 0;

    if (!line) {
        return;
    }

    for (i = 0; i < MAX_LEN; i ++) {
        if (line[i] == '\0') {
            break;
        }
        putchar(line[i]);
    }
    putchar('\n');
}

/**
 * @brief: Gets the line from the user.
 *          1. Uses the clean_line function to reset the array (line).
 *          2. Uses the getchar function in a while loop to store the chars
 *              from the input in the array (line). Continues untill it gets an
 *              '\n' char or an EOF (and then return with -1).
 *          3. If stored MAX_LEN (80) amount of chars goes into a second while
 *              loop. Then checks to see if there is a non-'white char' in the
 *              rest of the line.
 *              If there is, stores ILLEGAL_LINE_LEN in error.
 *              If reaches EOF return -1.
 *
 *         NOTE: changes evey tab into a space before storing it in line.
 *         NOTE: even though it changes every tab to a space the program still
 *                checks for tabs later on.
 *
 * @param line - array of chars, the size of MAX_LEN (80).
 * @param error - pointer to an Error (enum).
 *
 * @return: -1, if getchar function got an EOF.
 *          0, otherwise.
 */
int get_line(char* line, Error* error) {
    int i = 0;
    char x;

    clean_line(line);
    while ((x = getchar()) != '\n') {
        if ((i == 0 || line[i-1] == ' ') && (x == ' ' || x == '\t')) {
            /* multiple white chars */
            continue;
        } else if  (x == EOF) {
            return -1;/* EOF */
        } else if (x == '\r') {
            break;
        } else if (i == MAX_LEN) {/* line length error */
            while ((x = getchar()) != '\n') {/* unusable data */
                if  (x == EOF) {
                    return -1;/* EOF */
                } else if (x != ' ' && x != '\t') {/* if a non-white char */
                    *error = ILLEGAL_LINE_LEN;
                }
            }
            break;
        }
        if (x == '\t') {
            x = ' ';
        }
        line[i] = x;
        i += 1;
    }
    return 0;
}

/**
 * @brief: Resets all chars in the array (line) to '\0'.
 *
 * @param line  - array of chars, the size of MAX_LEN (80).
 */
void clean_line(char* line) {
    int i = 0;
    for (i = 0; i < MAX_LEN; i ++) {
        line[i] = '\0';
    }
}

/**
 * @brief: Prints the corresponding massage (through functions from messages.h)
 *          to the error the function got.
 *
 *         NOTE: incase error is ILLEGAL_EXIT, the funstion will also call the
 *                stop function.
 *
 * @param error  - an enum of Error type.
 */
void handle_error(Error error) {
    switch (error) {
        case INVALID_COMMAND:
            invalid_command();
            return;
        case INVALID_MAT:
            invalid_mat();
            return;
        case MISSING_MAT:
            missing_mat();
            return;
        case ILLEGAL_NUMBER:
            illegal_number();
            return;
        case MISSING_NUMBER:
            missing_number();
            return;
        case ILLEGAL_ENDING:
            illegal_ending();
            return;
        case MULTIPLE_COMMAS:
            multiple_commas();
            return;
        case MISSING_COMMA:
            missing_comma();
            return;
        case ILLEGAL_COMMA:
            illegal_comma();
            return;
        case MISSING_WHITE:
            missing_white();
            return;
        case ILLEGAL_CHAR:
            illegal_char();
            return;
        case ILLEGAL_LINE_LEN:
            illegal_line_len();
            return;
        case ILLEGAL_EXIT:
            illegal_exit();
            stop();
        case NULL_ARGUMENT:
            null_argument();
            return;
        default:/* NONE */
            return;
    }
}

/**
 * @brief: Operates the corresponding function (from mymat.h) according to the var in commmand.
 *         Incase of an error send it to the handle_error function.
 *
 * @param command - an enum of Command type.
 * @param x - an enum of MatName type. used for the first mat in the line.
 * @param y - an enum of MatName type. used for the second mat in the line.
 * @param z - an enum of MatName type. used for the third mat in the line.
 * @param mat_array - an array of mats, the size of 6.
 * @param scalar - a double that holds the scalar for mul_scalar func.
 * @param members - an array of doubles, the size of MAT_SIZE (16).
 */
void do_command(Command command, MatName x, MatName y, MatName z, mat mat_array[], double scalar, double members[]) {
    switch (command) {
        case STOP:
            stop();
        case READ:
            if (x == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                handle_error(read_mat(&mat_array[x], members));
            }
            return;
        case PRINT:
            if (x == EMPTY ) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                print_mat(&mat_array[x]);
            }
            return;
        case ADD:
            if (x == EMPTY || y == EMPTY || z == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME || z == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                add_mat(&mat_array[x], &mat_array[y], &mat_array[z]);
            }
            return;
        case SUB:
            if (x == EMPTY || y == EMPTY || z == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME || z == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                sub_mat(&mat_array[x], &mat_array[y], &mat_array[z]);
            }
            return;
        case MUL_MAT:
            if (x == EMPTY || y == EMPTY || z == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME || z == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                mul_mat(&mat_array[x], &mat_array[y], &mat_array[z]);
            }
            return;
        case MUL_SCALAR:
            if (x == EMPTY || y == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                mul_scalar(&mat_array[x], scalar, &mat_array[y]);
            }
            return;
        case TRANS:
            if (x == EMPTY || y == EMPTY) {
                handle_error(MISSING_MAT);
            } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME) {
                handle_error(INVALID_MAT);
            } else {
                trans_mat(&mat_array[x], &mat_array[y]);
            }
            return;
        default:/* EMPTY_LINE */
            return;
    }
}

