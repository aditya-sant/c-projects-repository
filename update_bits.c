#include <stdio.h>
#include <stdlib.h>

void update_bits(
  unsigned char out_bit,
  unsigned char *out_reg,
  unsigned char input_mask,
  unsigned char input_reg
) {
  unsigned char output_mask = (1<<out_bit);

  if ((input_reg & input_mask) == input_mask)
  {
    (*out_reg) |= output_mask;
  }
  else
  {
    (*out_reg) &= ~output_mask;
  }
}

//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_01 and out_reg_01.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_01, out_reg_01;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_02 and out_reg_02.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_02, out_reg_02;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_03 and out_reg_03.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_03, out_reg_03;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_04 and out_reg_04.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_04, out_reg_04;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_05 and out_reg_05.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_05, out_reg_05;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_06 and out_reg_06.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_06, out_reg_06;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_07 and out_reg_07.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_07, out_reg_07;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_08 and out_reg_08.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_08, out_reg_08;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_09 and out_reg_09.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_09, out_reg_09;
//  Declare two global variables, each of them suitable to store a single byte.
//  The names of the variables should be input_reg_10 and out_reg_10.
//  *  DO NOT ASSIGN VALUEs TO THESE VARIABLES AT THE POINT OF DECLARATION.

// INSERT CODE HERE.
unsigned char input_reg_10, out_reg_10;

void change_bits () {
    //  Modify the value of bit 0 of global variable out_reg_01,
    //  such that it is equal to 1 if and only if bit 0
    //  of input_reg_01 is set. Leave all other bits unaltered.
    //  Do not alter input_reg_01.

    // INSERT CODE HERE.
    update_bits(0, &out_reg_01, (1<<0), input_reg_01);
    //  Modify the value of bit 6 of global variable out_reg_02,
    //  such that it is equal to 1 if and only if bit 5
    //  of input_reg_02 is set. Leave all other bits unaltered.
    //  Do not alter input_reg_02.

    // INSERT CODE HERE.
    update_bits(6, &out_reg_02, (1<<5), input_reg_02);
    //  Modify the value of bit 7 of global variable out_reg_03,
    //  such that it is equal to 1 if and only if bits 0, 6
    //  of input_reg_03 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_03.

    // INSERT CODE HERE.
    update_bits(7, &out_reg_03, (1<<0) | (1<<6), input_reg_03);
    //  Modify the value of bit 0 of global variable out_reg_04,
    //  such that it is equal to 1 if and only if bits 1, 4
    //  of input_reg_04 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_04.

    // INSERT CODE HERE.
    update_bits(0, &out_reg_04, (1<<1) | (1<<4), input_reg_04);
    //  Modify the value of bit 4 of global variable out_reg_05,
    //  such that it is equal to 1 if and only if bits 0, 3, 6
    //  of input_reg_05 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_05.

    // INSERT CODE HERE.
    update_bits(4, &out_reg_05, (1<<0) | (1<<3) | (1<<6), input_reg_05);
    //  Modify the value of bit 3 of global variable out_reg_06,
    //  such that it is equal to 1 if and only if bits 2, 5, 6
    //  of input_reg_06 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_06.

    // INSERT CODE HERE.
    update_bits(3, &out_reg_06, (1<<2) | (1<<5) | (1<<6), input_reg_06);
    //  Modify the value of bit 7 of global variable out_reg_07,
    //  such that it is equal to 1 if and only if bits 0, 1, 2, 7
    //  of input_reg_07 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_07.

    // INSERT CODE HERE.
    update_bits(7, &out_reg_07, (1<<0) | (1<<1) | (1<<2) | (1<<7), input_reg_07);
    //  Modify the value of bit 6 of global variable out_reg_08,
    //  such that it is equal to 1 if and only if bits 1, 3, 4, 7
    //  of input_reg_08 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_08.

    // INSERT CODE HERE.
    update_bits(6, &out_reg_08, (1<<1) | (1<<3) | (1<<4) | (1<<7), input_reg_08);
    //  Modify the value of bit 4 of global variable out_reg_09,
    //  such that it is equal to 1 if and only if bits 0, 1, 5, 6, 7
    //  of input_reg_09 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_09.

    // INSERT CODE HERE.
    update_bits(4, &out_reg_09, (1<<0) | (1<<1) | (1<<5) | (1<<6) | (1<<7), input_reg_09);
    //  Modify the value of bit 6 of global variable out_reg_10,
    //  such that it is equal to 1 if and only if bits 1, 2, 3, 6, 7
    //  of input_reg_10 are all set. Leave all other bits unaltered.
    //  Do not alter input_reg_10.

    // INSERT CODE HERE.
    update_bits(6, &out_reg_10, (1<<1) | (1<<2) | (1<<3) | (1<<6) | (1<<7), input_reg_10);

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
    unsigned char out_init = 0;

    if (argc > 1) init_val = atoi(argv[1]) & 255;
    if (argc > 2) out_init = atoi(argv[2]) & 255;

    input_reg_01 = init_val;
    out_reg_01 = out_init;

    input_reg_02 = init_val;
    out_reg_02 = out_init;

    input_reg_03 = init_val;
    out_reg_03 = out_init;

    input_reg_04 = init_val;
    out_reg_04 = out_init;

    input_reg_05 = init_val;
    out_reg_05 = out_init;

    input_reg_06 = init_val;
    out_reg_06 = out_init;

    input_reg_07 = init_val;
    out_reg_07 = out_init;

    input_reg_08 = init_val;
    out_reg_08 = out_init;

    input_reg_09 = init_val;
    out_reg_09 = out_init;

    input_reg_10 = init_val;
    out_reg_10 = out_init;

    change_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 0:\n");
    print_bits("out_reg_01", out_reg_01);

    printf("\nSearch for bit 5.\n");
    printf("Set or clear bit 6:\n");
    print_bits("out_reg_02", out_reg_02);

    printf("\nSearch for bits 0, 6.\n");
    printf("Set or clear bit 7:\n");
    print_bits("out_reg_03", out_reg_03);

    printf("\nSearch for bits 1, 4.\n");
    printf("Set or clear bit 0:\n");
    print_bits("out_reg_04", out_reg_04);

    printf("\nSearch for bits 0, 3, 6.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_reg_05", out_reg_05);

    printf("\nSearch for bits 2, 5, 6.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_reg_06", out_reg_06);

    printf("\nSearch for bits 0, 1, 2, 7.\n");
    printf("Set or clear bit 7:\n");
    print_bits("out_reg_07", out_reg_07);

    printf("\nSearch for bits 1, 3, 4, 7.\n");
    printf("Set or clear bit 6:\n");
    print_bits("out_reg_08", out_reg_08);

    printf("\nSearch for bits 0, 1, 5, 6, 7.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_reg_09", out_reg_09);

    printf("\nSearch for bits 1, 2, 3, 6, 7.\n");
    printf("Set or clear bit 6:\n");
    print_bits("out_reg_10", out_reg_10);

    return 0;
}
