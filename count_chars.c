#include <stdio.h>

void count_chars() {
    //  Declare an integer variable which will be used to count characters.
    //  Initialise the variable to zero.
    int num_chars = 0;

    //  Enter a loop which continues indefinitely.
    while (1) {

      // Try to read a single character code from standard input.
      char ch;
      int scanf_result = scanf("%c", &ch);
      //one percent sign (%c) means one variable in being parsed.
      //one 'c' means exactly one character (byte)
      //returns 1 if 1 successful conversion is complete.
      //returns <= 0 if there are no bytes left to read.

      // If you have reached end of input, break out of the loop.
      if (scanf_result <= 0) break;

      // Increment the counter by 1.
      num_chars++;

      // End the body of the loop.
    }

    // Display the number of characters processed.
    printf("The document contains %d characters.\n", num_chars);
}


int main() {
	count_chars();
	return 0;
}
