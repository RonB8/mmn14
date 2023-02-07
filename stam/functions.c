#include <stdio.h>
void printBits(size_t const size, void const * const ptr);

unsigned int my_rottate(unsigned int a, int b)
{
    /*Without limiting the generality, the description will refer to the situation where the rotation is to the right.*/
    int steps = b;
    int res = a; /*result*/
    /*Turns the right 'steps' bits to '1' */
    int helper = ~((~0)<<steps);
    /*The right 'steps' bits of 'res'*/
    int rightestStepsBits = (res&helper);
    /*The right 'steps' bits are shifted to the left edge*/
    rightestStepsBits =  rightestStepsBits<<(sizeof(steps)*8-steps);
    res = res>>steps;
    /*Adds to 'res' the 'steps' bits that "disappeared" from the right side, to the left side*/
    res = res|rightestStepsBits;
    return res;
}

void printInAllBase(int num)
{
    printf("By decimal base: %i\n", num); /* 10 */
    printBits(sizeof(num), &num); /* 2 */
    printf("By octal base: %o\n", num); /* 8 */
    printf("By hexadecimal base: %X\n", num); /* 16 */
}
