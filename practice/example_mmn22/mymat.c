#include "mymat.h"
#include "messages.h"
#include <stdio.h>
#include <stdlib.h>


Error read_mat(Mat x, double nums[]) {
    int i = 0, j = 0, k = 0;

    if (!nums || !x) {
        return NULL_ARGUMENT;
    }

    clean_mat(x);
    i = 0;
    for (j = 0; j < MAT_SIZE; j++) {
        for (k = 0; k < MAT_SIZE; k++) {
            x->parameters[j][k] = nums[i++];
        }
    }
    return NONE;
}

void print_mat(Mat x) {
    int i = 0, j = 0;/* i, j for loop */

    if (x) {
        for (i = 0; i < MAT_SIZE; i++) {
            for (j = 0; j < MAT_SIZE; j++) {
                printf("%7.2f", x->parameters[i][j]);
                if (j != MAT_SIZE - 1) {
                    putchar('\t');
                }
            }
            putchar('\n');
        }
    }
}

void add_mat(Mat x, Mat y, Mat z) {
    int i = 0, j = 0;
    mat g;

    if (!x || !y || !z) {
        return;
    }

    clean_mat(&g);
    /* incase z is the same as x or y, we don't want to lose data so will put
        everything in g and then copy it to z */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            g.parameters[i][j] = x->parameters[i][j] + y->parameters[i][j];
        }
    }
    copy_mat(&g, z);/* z = g */
}

void sub_mat(Mat x, Mat y, Mat z) {
    int i = 0, j = 0;
    mat g;

    if (!x || !y || !z) {
        return;
    }

    clean_mat(&g);
    /* incase z is the same as x or y, we don't want to lose data so will put
        everything in g and then copy it to z */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            g.parameters[i][j] = x->parameters[i][j] - y->parameters[i][j];
        }
    }
    copy_mat(&g, z);/* z = g */
}

void mul_mat(Mat x, Mat y, Mat z) {
    int i = 0, j = 0, k = 0;
    mat g;

    if (!x || !y || !z) {
        return;
    }

    clean_mat(&g);
    /* incase z is the same as x or y, we don't want to lose data so will put
        everything in g and then copy it to z */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            for (k = 0; k < MAT_SIZE; k++) {
                g.parameters[i][j] += x->parameters[i][k] * y->parameters[k][j];
            }
        }
    }
    copy_mat(&g, z);/* z = g */
}

void mul_scalar(Mat x, double y, Mat z) {
    int i = 0, j = 0;
    mat g;

    if (!x || !z) {
        return;
    }

    clean_mat(&g);
    /* incase z is the same as x or y, we don't want to lose data so will put
        everything in g and then copy it to z */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            g.parameters[i][j] = x->parameters[i][j] * y;
        }
    }
    copy_mat(&g, z);/* z = g */
}

void trans_mat(Mat x, Mat y) {
    int i = 0, j = 0;
    mat g;

    if (!x || !y) {
        return;
    }

    clean_mat(&g);
    /* incase y is the same as x or y, we don't want to lose data so will put
        everything in g and then copy it to y */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            g.parameters[i][j] = x->parameters[j][i];
        }
    }
    copy_mat(&g, y);/* y = g */
}

void stop() {
    exit(0);
}

void clean_mat(Mat x) {
    int i = 0, j = 0;
    if (x) {
        for (i = 0; i < MAT_SIZE; i++) {
            for (j = 0; j < MAT_SIZE; j++) {
                x->parameters[i][j] = 0;
            }
        }
    }
}

void copy_mat(Mat original, Mat destination) {
    int i = 0, j = 0;

    if (!original || !destination) {
        return;
    }

    if (original && destination) {/* og and dest aren't NULL */
        for (i = 0; i < MAT_SIZE; i++) {
            for (j = 0; j < MAT_SIZE; j++) {
                destination->parameters[i][j] = original->parameters[i][j];
            }
        }
    }
}

