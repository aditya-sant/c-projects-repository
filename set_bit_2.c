#include <stdio.h>
#include <stdlib.h>

// INSERT GLOBALS HERE.
unsigned char reg_01;
unsigned char reg_02;
unsigned char reg_03;
unsigned char reg_04;
unsigned char reg_05;
unsigned char reg_06;
unsigned char reg_07;
unsigned char reg_08;
unsigned char reg_09;
unsigned char reg_10;

void turn_on_bits () {
    // INSERT ASSIGNMENT OPERATIONS HERE.
    reg_01 |= (1 << 0);

    reg_02 |= (1 << 2);

    reg_03 |= (1 << 0) | (1 << 1);

    reg_04 |=  (1 << 1) | (1 << 3);

    reg_05 |= (1 << 0) | (1 << 5) | (1 << 6);

    reg_06 |= (1 << 2) | (1 << 4) | (1 << 7);

    reg_07 |= (1 << 0) | (1 << 3) | (1 << 5) | (1 << 7);

    reg_08 |= (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);

    reg_09 |= (1 << 0) | (1 << 1) | (1 << 4) | (1 << 5) | (1 << 7);

    reg_10 |= (1 << 1) | (1 << 3) | (1 << 5) | (1 << 6) | (1 << 7);
}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);

    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val & (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;

    if (argc > 1) init_val = atoi(argv[1]) & 255;

    reg_01 = init_val;
    reg_02 = init_val;
    reg_03 = init_val;
    reg_04 = init_val;
    reg_05 = init_val;
    reg_06 = init_val;
    reg_07 = init_val;
    reg_08 = init_val;
    reg_09 = init_val;
    reg_10 = init_val;


    turn_on_bits();

    print_bits("Initial", init_val);
    print_bits("reg_01", reg_01);
    print_bits("reg_02", reg_02);
    print_bits("reg_03", reg_03);
    print_bits("reg_04", reg_04);
    print_bits("reg_05", reg_05);
    print_bits("reg_06", reg_06);
    print_bits("reg_07", reg_07);
    print_bits("reg_08", reg_08);
    print_bits("reg_09", reg_09);
    print_bits("reg_10", reg_10);


    return 0;
}
