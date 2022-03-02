#include <stdio.h>
#include <ctype.h>

//  HERE: Declare a global array of char called char_data with capacity to hold 100 elements.
//  AMS will insert data into this array prior to calling your function.
char char_data[100];
//  HERE: Declare a global array of int called input_count with capacity to hold 3 elements.
//  AMS will read results from this array after calling your function.
//  The contents of this array will be overwritten by AMS before calling your
//  function, so you should not make any assumptions about it.
int input_count[3];

void string_char_count() {
    //  Assign all elements of input_count to zero.
    for (int i = 0; i < sizeof(char_data) / sizeof(char_data[0]); i++)
    {
      input_count[i] = 0;
    }
    //  Traverse char_data with a counted loop which visits each valid char in
    //  succession, stopping when it reaches the end of the string.
    for (int i = 0; char_data[i] != 0; i++)
    {
      char ch = tolower(char_data[i]);

      if ('x'<= ch && ch <= 'z')
      {
        int index = ch - 'x';
        input_count[index] ++;
      }
    }
            //  Get current character from char_data and convert it to lower case.
            //  If the current character is between 'x' and 'z' inclusive, increment
            //  the element of input_count which corresponds to the character.
            //  Otherwise, ignore the current character.

    //  End loop
}

#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correctly even with this.
    srand( time( NULL ) );

    for ( int i = 0; i < 3; i++ ) {
        input_count[i] = rand();
    }

    //  Read as much data from stdin as we can, and append each char to the
    //  buffer.
    int chars_read = 0;

    for (chars_read = 0; chars_read < (100-1); chars_read ++) {
        int scanf_result = scanf( "%c", &char_data[chars_read] );

        if ( 1 != scanf_result ) break;
    }

    //  Terminate the string in the buffer.
    char_data[chars_read] = 0;

    // Pad remainder of string with garbage to help with debugging.
    for ( int i = chars_read + 1; i < (100); i++ ) {
        char_data[i] = 'x' + rand() % (1 + 'z' - 'x');
    }

    // Call submitted code.
    string_char_count();

    // Display contents of string, and number of occurrences of each symbol.
    printf("Input string        = '%s'\n", char_data);
    printf("Input string length = %zu\n", strlen(char_data));
    printf("Array capacity      = %d\n", 100);
    printf("Symbol frequencies:\n");

    for ( int i = 0; i < 3; i++ ) {
        printf("%c\t%d\n", 'x'+i, input_count[i]);
    }

    return 0;
}
