//Author: Ron Bar

//Date: 11/12/2022
//Description:  The function compares the len bytes, starting from the place to which b1 points, to the len bytes,
//              starting from the place to which b2 points.
//              The returned value: 0 if the two memory segments are found to contain identical content,
//              otherwise some value other than 0
#include <stdio.h>
#include <strings.h>
#define SIZE_OF_BYTES 512 //Max of bytes of array
int my_bcmp (const void *b1, const void *b2, int len); //Compares between the segments
int getParamForBcmp(double*len, void **p1, void **p2, char*str); //Function that get parameter to variables
int isValidInput(double len, double index1, double index2, char *str); //Checks if the received parameters are valid
void printPartialStrings(int len,void *p1, void *p2); //shows the bytes segment as characters

int main() {
    char str[SIZE_OF_BYTES]; //The array for the full part of the bytes
    double len; //Length of the memory segment for compare
    void *p1, *p2; //The pointers that will point to beginning of the segments
    int valid; //Will hold the truth value about the input integrity, 1 if valid, 0 if not
    valid = getParamForBcmp(&len, &p1, &p2, str); //getParamForBcmp function returns value as described above
    if (valid) {
        printf("The segments are ");
        my_bcmp((p1), (p2), (int)len) ? puts("various."): puts("identical."); //If my_bcmp returned 1 are various, if 0 - identical.
    }
    return 0;
}
/*
 * Compares between the 'len' bytes that b1 point to and 'len' bytes that b2 point to
 * 'b1' - pointer to the first segment
 * 'b2' - pointer to the second segment
 * 'len' - the length of each segments
 * Returns 0 if the segment are identical, otherwise - 1
*/
int my_bcmp (const void *b1, const void *b2, int len)
{
    int i=0;
    char c1 , c2;
    //The loop goes through the 'len' bytes of each segment
    for(; i<len; i++)
    {
        c1 = *(char*)(i+b1); //The i-th byte of segment 1
        c2 = *(char*)(i+b2); //The i-th byte of segment 2
        if(c1 != c2)
            return 1;
    }
    return 0; //If the loop arrived to here - all 'len' bytes are identical so the returned value is '0'
}
/*
* Function that get pointers to variables for comparing and puts a value in it
* 'len' - pointer to the length of desired length to compare
* 'p1' - pointer to the pointer to segment 1
* 'p2' - pointer to the pointer to segment 2
* 'str' - pointer to the array of full bytes, in this case are characters ('str' = string of characters)
 * Returns 1 if the parameters are valid, otherwise - 0
 */
int getParamForBcmp(double *len, void **p1, void **p2, char* str)
{
    double ind1, ind2; //The indexes in relation to beginning of array
    puts("Insert the folowing data:\nThe number of bytes to compare:");
    scanf("%lf", len);
    puts("The first index:");
    scanf("%lf", &ind1);
    puts("The second index:");
    scanf("%lf", &ind2);
    puts("The string:");
    scanf("%s",str);
    *p1 = str + (unsigned int)ind1; //p1 pointing to 'ind1' addresses of bytes after the beginning of 'str' (the ind1-th byte of str)
    *p2 = str + (unsigned int)ind2; //p2 pointing to 'ind2' addresses of bytes after the beginning of 'str' (the ind2-th byte of str)
    if(isValidInput(*len, ind1, ind2, str)){
        printPartialStrings(*len, *p1, *p2); //Prints the value of segments
        return 1;
    }
    return 0;
}
/*
 * Checks if the parameters that received are valid
 * 'len' - length of each segment
 * 'str' - the full array of the bytes
 * Returns 1 if the parameters are valid, otherwise - 0
*/
int isValidInput(double len, double index1, double index2, char *str)
{
    char *part1, *part2;
    part1 = (unsigned char*)((unsigned char)index1+str);
    part2 = (unsigned char*)((unsigned char)index2+str);
    int valid=1; //Truth value about input integrity, of is valid - 1, otherwise - 0.
    //Checks if the indexes or the length are not naturals number
    if(index1!=(unsigned int)index1 || index1<0) {
        printf("Error!\nThe first index: %f is not valid!\nOnly natural numbers should be entered\n", index1);
        valid=0;
    }
    if(index2!=(unsigned int)index2 || index1<0) {
        if(valid) puts("Error"); //If valid=0 it means that 'Error' message is already printed
        printf("The second index: %f is not valid!\nOnly natural numbers should be entered\n", index2);
        valid=0;
    }
    if(len!=(int)len || index1<0) {
        if(valid) puts("Error");
        printf("The length: %f is not valid!\nOnly natural numbers should be entered\n", len);
        valid=0;
    }
    //Checks if the segments are exceeds the bounds of 'str'
    if(strlen(part1) < len) {
        if(valid) puts("Error");
        printf("The first segments that start from index: %d exceeds the bounds of the array\n",(int)index1);
        valid=0;
    }
    if(strlen(part2) < len) {
        if(valid) puts("Error");
        printf("The second segments that start from index: %d exceeds the bounds of the array\n",(int)index2);
        valid=0;
    }
    return valid;
}
/*
 * Prints the partial segments of bytes as strings
 * 'len' - length of each segment
 * 'p1' and 'p2' - pointers to the segments
*/
void printPartialStrings(int len,void *p1, void *p2)
{
    printf("The first segment: %.*s\n", len, p1); //Prints the 'len' characters starting from p1
    printf("The second segment: %.*s\n", len, p2); //Prints the 'len' characters starting from p2
}