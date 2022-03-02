#include <stdio.h>
#include <stdlib.h>

//  Declare a global variable named reg_01 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_01;
//  Declare a global variable named reg_02 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_02;
//  Declare a global variable named reg_03 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_03;
//  Declare a global variable named reg_04 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_04;
//  Declare a global variable named reg_05 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_05;
//  Declare a global variable named reg_06 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_06;
//  Declare a global variable named reg_07 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_07;
//  Declare a global variable named reg_08 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_08;
//  Declare a global variable named reg_09 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_09;
//  Declare a global variable named reg_10 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned reg_10;

void clear_bits () {
    //  Modify the value of global variable reg_01, clearing
    //  bit 0, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_01 &= ~(( 1 << 0));
    //  Modify the value of global variable reg_02, clearing
    //  bit 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_02 &= ~((1 << 6));
    //  Modify the value of global variable reg_03, clearing
    //  bits 0, 1, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_03 &= ~((1 << 0) | (1 << 1));
    //  Modify the value of global variable reg_04, clearing
    //  bits 3, 5, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_04 &= ~((1 << 3) | (1 << 5));
    //  Modify the value of global variable reg_05, clearing
    //  bits 0, 5, 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_05 &= ~((1 << 0) | (1 << 5) | (1 << 6));
    //  Modify the value of global variable reg_06, clearing
    //  bits 4, 5, 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_06 &= ~((1 << 4) | (1 << 5) | ( 1<< 6));
    //  Modify the value of global variable reg_07, clearing
    //  bits 0, 1, 2, 3, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_07 &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));
    //  Modify the value of global variable reg_08, clearing
    //  bits 2, 3, 5, 6, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_08 &= ~((1 << 2) | (1 << 3) | (1 << 5) | (1 << 6));
    //  Modify the value of global variable reg_09, clearing
    //  bits 0, 1, 2, 3, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_09 &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 7));
    //  Modify the value of global variable reg_10, clearing
    //  bits 1, 2, 3, 4, 7, and leaving all other bits unaltered.

    // INSERT CODE HERE.
    reg_10 &= ~((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 7));

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


    clear_bits();

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
