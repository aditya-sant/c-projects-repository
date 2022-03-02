#include <stdio.h>
#include <ctype.h>

//  HERE: Declare a global array of char called seq with capacity to hold
//  128 elements. AMS will insert data into this array prior to calling your function.
char seq[128];

//  HERE: Declare a global array of int called seq_len with capacity to hold
//  one element for each symbol in the designated character range.
//  AMS will read results from this array after calling your function.
//  The contents of this array will be overwritten by AMS before calling your
//  function, so you should not make any assumptions about it.
int seq_len[26];

void string_char_count_2() {
    //  Insert your solution here.
    for(int i = 0; i < sizeof(seq)/sizeof(seq[0]); i++)
    {
      seq_len[i] = 0;
    }

    for (int i = 0; seq[i] != 0; i++)
    {
      if ('a' <= seq[i] && seq[i] <= 'z')
      {
        int index = seq[i] - 'a';
        seq_len[index]++;
      }
    }
}

#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correctly even with this.
    srand( time( NULL ) );

    #define CHAR_SET_SIZE (1 + 'z' - 'a')

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        seq_len[i] = rand();
    }

    //  Read as much data from stdin as we can, and append each char to the
    //  buffer.
    int chars_read = 0;

    for ( chars_read = 0; chars_read < (128 - 1); chars_read++ ) {
        int scanf_result = scanf( "%c", &seq[chars_read] );

        if ( 1 != scanf_result ) break;
    }

    //  Terminate the string in the buffer.
    seq[chars_read] = 0;

    // Pad remainder of string with garbage to help with debugging.
    for ( int i = chars_read + 1; i < (128); i++ ) {
        seq[i] = 'a' + rand() % CHAR_SET_SIZE;
    }

    // Call submitted code.
    string_char_count_2();

    // Display contents of string, and number of occurrences of each symbol.
    printf( "Input string        = '%s'\n", seq );
    printf( "Input string length = %zu\n", strlen( seq ) );
    printf( "Array capacity      = %d\n", 128 );
    printf( "Symbol frequencies:\n" );

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        printf( "%c\t%d\n", 'a' + i, seq_len[i] );
    }

    return 0;
}
