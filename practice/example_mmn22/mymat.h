#ifndef __SET__H__
#define __SET__H__

#include "messages.h"


/**
 * @brief: The max length of a line is 80 chars.
 */
#define MAX_LEN 80


/**
 * @brief: Amount of sets used in program.
 */
#define MAT_SIZE 4


/**
 * @brief: A set struct that's holds an array of SIZE (128) bits.
 *         It's writen here and not just declaration because the comipler had
 *          problems. 
 */
typedef struct mat_t {
    double parameters[MAT_SIZE][MAT_SIZE];
} mat;

typedef mat* Mat;

/**
 * List of functions in this header:
 *
 *	read_mat - initialize the given mat with the given parameters.                                                                              fdgfdgfdgdgdgd
 *	print_mat - prints mat's parameters.
 *	add_mat(A, B, C) -> C = A + B.
 *	sub_mat(A, B, C) -> C = A - B.
 *	mul_mat(A, B, C) -> C = A * B.
 *	mul_scalar(A, x, B) -> B = x*A.
 *  trans_mat(A, B) -> B = A transpose.
 *	stop - exits the program.
 *
 *	clean_mat - turns all the parameters in the mat to 0.
 *	copy_mat - copies the first mat to the second one.
 *
 */


/**
 * @brief: Enetrs parameters to mat.
 *          1. Creates a temporary mat and resets it.
 *          2. Goes through the array (nums) and add them by order.
 *          3. If nums is empty then return an error./TODO/
 * 
 * @param x - pointer to mat.
 * @param nums - array with doubles.
 *
 * @return: NULL_ARGUMENT - if the array (nums) or the pointer to the set are NULL.
 *          /TODO/
 *          NONE - otherwise.
 */
Error read_mat(Mat x, double nums[]);

/**
 * @brief: Prints the mat's parameters.
 *          prints 4*4 matrix.
 *          leaves space for at least 4 chars before the dot (including space for negative sign).
 *          2 digits after the dot.
 *
 *         NOTE: if x is null prints nothing.
 * 
 */
void print_mat(Mat x);

/**
 * @brief: z = x + y.
 *          1. Creates a temporary mat and resets it.
 *          2. Put inside the temp mat the sum of x and y parameters.
 *          3. When done copies the temporary mat to z.
 * 
 * @param x - pointer to the first mat.
 * @param y - pointer to the second mat.
 * @param z - pointer to the third mat.
 */
void add_mat(Mat x, Mat y, Mat z);

/**
 * @brief: z = x - y.
 *          1. Creates a temporary mat and resets it.
 *          2. Put inside the temp mat the result of x sub y parameters.
 *          3. When done copies the temporary mat to z.
 * 
 * @param x - pointer to the first mat.
 * @param y - pointer to the second mat.
 * @param z - pointer to the third mat.
 */
void sub_mat(Mat x, Mat y, Mat z);

/**
 * @brief: z = x * y.
 *          1. Creates a temporary mat and resets it.
 *          2. Put inside the temp mat the result of x * y parameters.
 *          3. When done copies the temporary mat to z.
 * 
 * @param x - pointer to the first mat.
 * @param y - pointer to the second mat.
 * @param z - pointer to the third mat.
 */
void mul_mat(Mat x, Mat y, Mat z);

/**
 * @brief: z = x * y.
 *          1. Creates a temporary mat and resets it.
 *          2. Put inside the temp mat the result of (x's parameters) * y.
 *          3. When done copies the temporary mat to z.
 * 
 * @param x - pointer to the first mat.
 * @param y - a scalar.
 * @param z - pointer to the third mat.
 */
void mul_scalar(Mat x, double y, Mat z);

/**
 * @brief: y = x transpose.
 *          1. Creates a temporary mat and resets it.
 *          2. Put inside the temp mat the x's parameters in new order.
 *          3. When done copies the temporary mat to z.
 * 
 * @param x - pointer to the first mat.
 * @param y - a scalar.
 * @param z - pointer to the third mat.
 */
void trans_mat(Mat x, Mat y);

/**
 * @brief: Exits the program with 0 as exit value after free.
 */
void stop();

/**
 * @brief: Turns all parameters to 0.
 * 
 * @param x - pointer to mat.
 */
void clean_mat(Mat);

/**
 * @brief: Copies every mat's paremeter in the first mat to the second mat.
 *         If one of the pointers is NULL, returns without doing anything.
 *
 */
void copy_mat(Mat, Mat);


#endif  /*!__SET__H__*/