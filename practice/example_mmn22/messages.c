#include "messages.h"
#include <stdio.h>


void invalid_command() {
    printf("ERROR: invalid command - the program do not have such command.\n");
    printf("The commands are: read_mat, print_mat, add_mat, sub_mat,");
    printf(" mul_mat, mul_scalar, trans_mat and stop.\n");
}

void invalid_mat() {
    printf("ERROR: invalid mat - program do not have a mat with that name.\n");
    printf("The mat are: MATA, MATB, MATC, MATD, MATE and MATF.\n");
}

void missing_mat() {
    printf("ERROR: missing mat - program did not get all mats which are");
    printf(" necessary for the command.\n");
}

void illegal_number() {
    printf("ERROR: illegal number - program received a non-real number.\n");
}

void missing_number() {
    printf("ERROR: missing number - program did not get at least 1 real number.\n");
}

void illegal_ending() {
    printf("ERROR: illegal ending - extraneous text after end of command.\n");
}

void multiple_commas() {
    printf("ERROR: multiple commas - multiple consecutive commas.\n");
}

void missing_comma() {
    printf("ERROR: missing comma.\n");
}

void illegal_comma() {
    printf("ERROR: illegal comma.\n");
}

void missing_white() {
    printf("ERROR: a space or a tab must be after the command.\n");
}

void illegal_char() {
    printf("ERROR: illegal char.\n");
}

void illegal_line_len() {
    printf("ERROR: illegal line length - program does not accept lines so long.\n");
}

void illegal_exit() {
    printf("ERROR: illegal exit - program did not terminate with stop function.\n");
}

void null_argument() {
    printf("ERROR: NULL argument - program sent function a NULL as an argument.\n");
}

void intro() {
    printf("This is a matrix calculator.\n\n");
    printf("It has 6 mats stored in it and they are:\n");
    printf("MATA, MATB, MATC, MATD, MATE and MATF.\n");
    printf("The function in this calculator are:\n");
    printf("read_mat, print_mat, add_mat, sub_mat, mul_mat, mul_scalar,");
    printf(" trns_mat and stop.\n\n");
    printf("* lines can not be longer than 80 chars.\n\n");

    printf("Functions explanation:\n\n");

    printf("1. read_mat: This function resets the mat and stores parameters in it.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'read_mat MATX, param1, param2, ..., paramn'\n");
    printf("* X can be A-F\n");
    printf("* between the command and the mat name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the mat name and after each parameter (except after the last one).\n");
    printf("* the mat has 16 parameters, if you enter less than 16 then the rest will be set to 0.\n");
    printf("*   if you enter more than 16 then only the first 16 will be counted.\n");

    printf("2. print_mat: This function prints the parameters of the given mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'print_mat MATX'\n");
    printf("* X can be A-F\n");
    printf("* between the command and the mat name must be at least 1 space or 1 tab.\n");
    printf("* after the mat name, there can only be spaces and tabs.\n\n");

    printf("3. add_mat: This function does addition on the first 2 mats and");
    printf(" stores the result in the third mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'add_mat MATX, MATY, MATZ'\n");
    printf("* X can be A-F, Y can be A-F, Z can be A-F\n");
    printf("* between the command and the first mat name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the first and second mats' names.\n");
    printf("* after the third mat name, there can only be spaces and tabs.\n\n");

    printf("4. sub_mat: This function subtract the second mat from the first mat");
    printf("  and stores them in the third mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'sub_mat MATX, MATY, MATZ'\n");
    printf("* X can be A-F, Y can be A-F, Z can be A-F\n");
    printf("* between the command and the first mat name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the first and second mats' names.\n");
    printf("* after the third mat name, there can only be spaces and tabs.\n\n");

    printf("5. mul_mat: This function multiplie the first 2 mats and stores the");
    printf(" result in the third mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'mul_mat MATX, MATY, MATZ'\n");
    printf("* X can be A-F, Y can be A-F, Z can be A-F\n");
    printf("* between the command and the first mat name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the first and second mats' names.\n");
    printf("* after the third mat name, there can only be spaces and tabs.\n\n");

    printf("6. mul_scalar: This function multiplie the first mat with the scalar and stores the");
    printf(" result in the second mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'mul_scalar MATX, Y, MATZ'\n");
    printf("* X can be A-F, Y can be any real number, Z can be A-F\n");
    printf("* between the command and the first mat name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the first mat name and the number.\n");
    printf("* after the second mat name, there can only be spaces and tabs.\n\n");

    printf("7. trans_mat: This function does transpose on the first mat and stores");
    printf(" the result in the second mat.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'trans_mat MATX, MATY'\n");
    printf("* X can be A-F, Y can be A-F\n");
    printf("* between the command and the first matt name must be at least 1 space or 1 tab.\n");
    printf("* there has to be a comma after the first mat name.\n");
    printf("* after the second set name, there can only be spaces and tabs.\n\n");

    printf("8. stop: This function exits from the calculator.\n");
    printf("To use it, you'll need to enter the following:\n");
    printf("'stop'\n");
    printf("* after the command, there can only be spaces and tabs.\n\n");
}
