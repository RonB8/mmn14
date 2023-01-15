#include "analyze.h"
#include "messages.h"
#include "mymat.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void analyze(char* line, Command* command, MatName* x, MatName* y, MatName* z,
             double* members, double* scalar, Error* error) {
    int i = 0, comma = 0;
    char* ptr;
    *error = NONE;/* resets it for later use. */
    *y = EMPTY;/* resets it for later use. */
    *z = EMPTY;/* resets it for later use. */

    *command = get_command(line, &i);
    if (*command == EMPTY_LINE) {
        return;
    } else if (*command == ERROR) {
        *error = INVALID_COMMAND;
        return;
    } else if (line[i] != ' ' && line[i] != '\t') {
        if (line[i] == ',') {
            *error = ILLEGAL_COMMA;
        } else if (line[i] == '\0' || line[i] == '\r') {
            if (*command != STOP) {
                *error = MISSING_MAT;
            }
        } else {
            *error = ILLEGAL_CHAR;
        }
        return;
    }
    /* command is OK and has a white char after it */
    if (*command != STOP) {
        *x = get_name(line, &i);
        if (*x == ILLEGAL_NAME) {
            *error = INVALID_MAT;
            return;
        }
        if (*command != PRINT) {/* needs a comma now */
            if (*command == MUL_SCALAR) {
                comma = 0;
                while (line[i]) {
                    if (line[i] == ',') {
                        if (!comma) {
                            comma = 1;
                            i++;
                        } else {
                            *error = MULTIPLE_COMMAS;
                        }
                    } else if (line[i] == ' ' || line[i] == '\t') {
                        i++;
                    } else {
                        if (comma) {
                            if (isdigit(line[i]) || (line[i] == '-' && isdigit(line[i+1]))) {
                                break;
                            }
                            *error = ILLEGAL_NUMBER;
                        } else {
                            *error = MISSING_COMMA;
                        }
                        return;
                    }
                }
                *scalar = strtod(&line[i], &ptr);
                while (&line[i] != ptr) {
                    i++;
                }
            }
            if (*command == READ) {
                *error = get_members(line, i, members);
                return;
            } else {/* add/sub/mul_mat/mul_scalar/trans*/
                comma = 0;
                while (*y == EMPTY) {
                    if ((line[i] == ' ') || (line[i] == '\t')) {
                        i++;
                    } else if (line[i] == ',') {
                        if (!comma) {
                            comma = 1;
                            i++;
                        } else {
                            *error = MULTIPLE_COMMAS;
                            return;
                        }
                    } else if (line[i] == '\0' || line[i] == '\r') {/* cutting line short */
                        *error = MISSING_MAT;
                        return;
                    } else {
                        if (comma) {
                            *y = get_name(line, &i);
                            if (*y == ILLEGAL_NAME) {
                                *error = INVALID_MAT;
                                return;
                            }
                        } else {/* illegal char */
                            *error = MISSING_COMMA;
                            return;
                        }
                    }
                }
                if (*command != MUL_SCALAR && *command != TRANS) {
                    comma = 0;
                    while (*z == EMPTY) {
                        if ((line[i] == ' ') || (line[i] == '\t')) {
                            i += 1;
                        } else if (line[i] == ',') {
                            if (!comma) {
                                comma = 1;
                                i++;
                            } else {
                                *error = MULTIPLE_COMMAS;
                                return;
                            }
                        } else if (line[i] == '\0' || line[i] == '\r') {/* cutting line short */
                            *error = MISSING_MAT;
                            return;
                        } else {
                            if (comma) {
                                *z = get_name(line, &i);
                                if (*z == ILLEGAL_NAME) {
                                    *error = INVALID_MAT;
                                    return;
                                }
                            } else {/* illegal char */
                                *error = MISSING_COMMA;
                                return;
                            }
                        }
                    }/* while */
                }/* command = add/sub/mul_mat */
            }/* command = add/sub/mul_mat/mul_scalar/trans */
        }/* command != print */
    }/* command != stop */

    /* all commands but read */
    while (i < MAX_LEN) {
        if (line[i] == '\0' || line[i] == '\r') {
            return;
        } else if (line[i] == ' ' || line[i] == '\t') {
            i += 1;
        } else {
            *error = ILLEGAL_ENDING;
            return;
        }
    }/* while */
}

Command get_command(char* line, int* iterator) {
    Command command = ERROR;
    char* read_mat = "read_mat";
    char* print_mat ="print_mat";
    char* add_mat = "add_mat";
    char* sub_mat = "sub_mat";
    char* mul_mat = "mul_mat";
    char* mul_scalar = "mul_scalar";
    char* trans_mat = "trans_mat";
    char* stop = "stop";

    while (line[*iterator] == ' ' || line[*iterator] == '\t') {
        *iterator += 1;
    }
    if (line[*iterator] == '\0' || line[*iterator] == '\r') {
        command = EMPTY_LINE;
    } else if (check(&line[*iterator], read_mat, strlen(read_mat))) {
        *iterator += strlen(read_mat);
        command = READ;
    } else if (check(&line[*iterator], print_mat, strlen(print_mat))) {
        *iterator += strlen(print_mat);
        command = PRINT;
    } else if (check(&line[*iterator], add_mat, strlen(add_mat))) {
        *iterator += strlen(add_mat);
        command = ADD;
    } else if (check(&line[*iterator], sub_mat, strlen(sub_mat))) {
        *iterator += strlen(sub_mat);
        command = SUB;
    } else if (check(&line[*iterator], mul_mat, strlen(mul_mat))) {
        *iterator += strlen(mul_mat);
        command = MUL_MAT;
    } else if (check(&line[*iterator], mul_scalar, strlen(mul_scalar))) {
        *iterator += strlen(mul_scalar);
        command = MUL_SCALAR;
    } else if (check(&line[*iterator], trans_mat, strlen(trans_mat))) {
        *iterator += strlen(trans_mat);
        command = TRANS;
    } else if (check(&line[*iterator], stop, strlen(stop))) {
        *iterator += strlen(stop);
        command = STOP;
    }

    return command;
}

MatName get_name(char* line, int* iterator) {
    char* mat_a = "MAT_A";
    char* mat_b = "MAT_B";
    char* mat_c = "MAT_C";
    char* mat_d = "MAT_D";
    char* mat_e = "MAT_E";
    char* mat_f = "MAT_F";
    int i = *iterator;

    while (i < MAX_LEN) {
        if (line[i] == ' ' || line[i] == '\t') {
            i += 1;
            continue;
        } else if (line[i] == '\0' || line[i] == '\r') {
            return ILLEGAL_NAME;
        } else if (check(&line[i], mat_a, strlen(mat_a))) {
            *iterator = i + strlen(mat_a);
            return MATA;
        } else if (check(&line[i], mat_b, strlen(mat_b))) {
            *iterator = i + strlen(mat_b);
            return MATB;
        } else if (check(&line[i], mat_c, strlen(mat_c))) {
            *iterator = i + strlen(mat_c);
            return MATC;
        } else if (check(&line[i], mat_d, strlen(mat_d))) {
            *iterator = i + strlen(mat_d);
            return MATD;
        } else if (check(&line[i], mat_e, strlen(mat_e))) {
            *iterator = i + strlen(mat_e);
            return MATE;
        } else if (check(&line[i], mat_f, strlen(mat_f))) {
            *iterator = i + strlen(mat_f);
            return MATF;
        } else {
            break;
        }
    }
    return ILLEGAL_NAME;
}

Error get_members(char* line, int iterator, double members[]) {
    int i = 0;
    int comma = 0;/* chacks for a comma */
    char* ptr;
    double num;

    for (i = 0; i < MAT_SIZE*MAT_SIZE; i++) {
        members[i] = 0;/* reset */
    }

    i = 0;
    while ((iterator < MAX_LEN) && (line[iterator] != '\0')) {
        if (line[iterator] == ' ' || line[iterator] == '\t') {
            iterator++;
        } else if (line[iterator] == ',') {
            if (!comma) {/* the comma after the mat name */
                comma = 1;
                iterator++;
            } else {/* multiple consecutive commas */
                return MULTIPLE_COMMAS;
            }
        } else if (isdigit(line[iterator]) || (line[iterator] == '-' && isdigit(line[iterator+1]))) {/* if char is a digit or a sign */
            if (!comma) {/* missing a comma after the mat name */
                return MISSING_COMMA;
            }
            num = strtod(&line[iterator], &ptr);
            while ((&line[iterator]) != ptr) {
                iterator++;
            }
            comma = 0;
            if (i < MAT_SIZE*MAT_SIZE) {
                members[i++] = num;
            }
        } else {
            return ILLEGAL_NUMBER;
        }
    }/* while */
    if (comma) {
        return ILLEGAL_ENDING;
    } else if (!i) {
        return MISSING_NUMBER;
    }
    return NONE;
}

int check(char* first, char* second, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (first[i] != second[i]) {
            return 0;
        }
    }
    return 1;
}



