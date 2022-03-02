#include <stdio.h>
#include <stdlib.h>

//  Declare a global variable named Reg_01 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_01;

//  Declare a global variable named Reg_02 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.


// INSERT CODE HERE.
unsigned char Reg_02;

//  Declare a global variable named Reg_03 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_03;
//  Declare a global variable named Reg_04 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_04;
//  Declare a global variable named Reg_05 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_05;
//  Declare a global variable named Reg_06 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_06;
//  Declare a global variable named Reg_07 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_07;
//  Declare a global variable named Reg_08 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_08;
//  Declare a global variable named Reg_09 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_09;
//  Declare a global variable named Reg_10 which is suitable to
//  store a single byte.
//  *  DO NOT ASSIGN A VALUE TO THIS VARIABLE AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char Reg_10;

void init_vars () {
    //  Create a bit mask which can be used to access or change bit 0.
    //  Store the bit mask in global variable Reg_01.
    // INSERT CODE HERE.
    Reg_01 = (1 << 0);

    //  Create a bit mask which can be used to access or change bit 2.
    //  Store the bit mask in global variable Reg_02.

    // INSERT CODE HERE.
    Reg_02 = (1 << 2);

    //  Create a bit mask which can be used to access or change bits 0, 7.
    //  Store the bit mask in global variable Reg_03.

    // INSERT CODE HERE.
    Reg_03 = (1 << 0) | (1 << 7);
    //  Create a bit mask which can be used to access or change bits 1, 5.
    //  Store the bit mask in global variable Reg_04.

    // INSERT CODE HERE.
    Reg_04 =  (1 << 0) | (1 << 5);
    //  Create a bit mask which can be used to access or change bits 0, 1, 4.
    //  Store the bit mask in global variable Reg_05.

    // INSERT CODE HERE.
    Reg_05 = (1 << 0) | (1 << 1) | (1 << 4);
    //  Create a bit mask which can be used to access or change bits 2, 3, 4.
    //  Store the bit mask in global variable Reg_06.

    // INSERT CODE HERE.
    Reg_06 = (1 << 2) | (1 << 3) | (1 << 4);
    //  Create a bit mask which can be used to access or change bits 0, 1, 4, 5.
    //  Store the bit mask in global variable Reg_07.

    // INSERT CODE HERE.
    Reg_07 = (1 << 0) | (1 << 1) | (1 << 4) | (1 << 5);
    //  Create a bit mask which can be used to access or change bits 1, 3, 5, 7.
    //  Store the bit mask in global variable Reg_08.

    // INSERT CODE HERE.
    Reg_08 = (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7);
    //  Create a bit mask which can be used to access or change bits 0, 3, 5, 6, 7.
    //  Store the bit mask in global variable Reg_09.

    // INSERT CODE HERE.
    Reg_09 = (1 << 0) | (1 << 3) | (1 << 5) | (1 << 6) | (1 << 7);
    //  Create a bit mask which can be used to access or change bits 1, 3, 4, 5, 7.
    //  Store the bit mask in global variable Reg_10.

    // INSERT CODE HERE.
    Reg_10 = (1 << 1) | (1 << 3) (1 << 4) | (1 << 5) | (1 << 7);
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

    Reg_01 = init_val;
    Reg_02 = init_val;
    Reg_03 = init_val;
    Reg_04 = init_val;
    Reg_05 = init_val;
    Reg_06 = init_val;
    Reg_07 = init_val;
    Reg_08 = init_val;
    Reg_09 = init_val;
    Reg_10 = init_val;


    init_vars();

    print_bits("Initial", init_val);
    print_bits("Reg_01", Reg_01);
    print_bits("Reg_02", Reg_02);
    print_bits("Reg_03", Reg_03);
    print_bits("Reg_04", Reg_04);
    print_bits("Reg_05", Reg_05);
    print_bits("Reg_06", Reg_06);
    print_bits("Reg_07", Reg_07);
    print_bits("Reg_08", Reg_08);
    print_bits("Reg_09", Reg_09);
    print_bits("Reg_10", Reg_10);


    return 0;
}
