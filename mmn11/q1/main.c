#include <stdio.h>
#include "data.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
void shortStr(char* str[]);

int main() {
    char str[SIZE]; //The string
    printf("Insert a string:\n");
    scanf("%s", &str);
    printf("The original string is: %s\n", str);
    shortStr(str);
    printf("The shortened string is: %s\n", str);
    return 0;
}

#pragma clang diagnostic pop