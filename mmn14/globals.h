//
// Created by אלישיב הורדן on 02/02/2023.
//

#define IC_ADDRESS 100
#define MAX_LINE_LEN 82

typedef enum boolean{
    FALSE,
    TRUE
} boolean;

enum opcode {
    /*instructions with 2 operands */
    mov, cmp, add, sub, nit, clr, lea,
    /*instructions with 1 operand */
    inc, dec, jmp, bne, red, prn, jsr,
    /*instructions without operand */
    rts, stop};

enum registers {r0, r1, r2, r3, r4, r5, r6, r7};

enum adressing_methods {immediate, direct, jump, direct_register};

typedef struct{
    char label[82],
    int address
} table;

table label_table[12];