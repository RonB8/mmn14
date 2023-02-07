#ifndef __MASSAGES__H__
#define __MASSAGES__H__


/**
 * @brief: An enum used for handeling errors in the input.
 *         It's writen here and not just declaration because the comipler had
 *          problems. 
 */
typedef enum error_t {
    INVALID_COMMAND,
    INVALID_MAT,
    MISSING_MAT,
    ILLEGAL_NUMBER,
    MISSING_NUMBER,
    ILLEGAL_ENDING,
    MULTIPLE_COMMAS,
    MISSING_COMMA,
    ILLEGAL_COMMA,
    MISSING_WHITE,
    ILLEGAL_CHAR,
    ILLEGAL_LINE_LEN,
    ILLEGAL_EXIT,
    NULL_ARGUMENT,
    NONE
} Error;

/**
 * List of functions in this header:
 *
 *	invalid_command - prints an error message about command's name.
 *	invalid_mat - prints an error message about mat's name.
 *
 *	missing_mat - prints an error message about missing a mat's name.
 *
 *  illegal_number - prints an error message about entering a non-real number.
 *  missing_number -  prints an error message about not entering a real number.
 *
 *	illegal_ending - prints an error message about an illegal char at the end
 *              of the line.
 *
 *	multiple_commas - prints an error message about multiple consecutive commas.
 *	missing_comma - prints an error message about a missing comma.
 *	illegal_comma - prints an error message about a comma being in the wrong
 *              place.
 *
 *	missing_white - prints an error message about a missing space/tab.
 *	illegal_char - prints an error message about a char being in the wrong
 *              place.
 *	illegal_line_len - prints an error message about the line being too long.
 *
 *	illegal_exit - prints an error message about exiting the program without
 *              the use of stop function.
 *
 *  null_argument - prints an error message about getting a NULL as an argument.
 *
 *	intro - prints a message explaining how to use the program.
 *
 */


void invalid_command();

void invalid_mat();
void missing_mat();

void illegal_number();
void missing_number();

void illegal_ending();

void multiple_commas();
void missing_comma();
void illegal_comma();

void missing_white();
void illegal_char();
void illegal_line_len();

void illegal_exit();

void null_argument();

void intro();


#endif  /*!__MASSAGES__H__*/