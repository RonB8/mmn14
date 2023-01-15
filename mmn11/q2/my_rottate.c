#include <stdio.h>

void printInAllBase(int num);
unsigned int my_rottate(unsigned int a, int b);

int main() {
    int steps;
    int num;
    printf("Hello, the program below performs a rotation of b bits on parameter a\n"
           "Enter a number:\n");
    scanf("%d", &num);
    printf("How many bits to shift?\npositive number - shift to the right\nnegative number - shift to the left\n");
    scanf("%d", &steps);
    printf("The original number: \n");
    printInAllBase(num);
    int res =  my_rottate(num, steps);
    printf("\nThe number after shift of %d bits to the %s: \n", ((steps<0)?(-steps): steps), ((steps<0)? "left": "right"));
    printInAllBase(res);
    return 0;
}
