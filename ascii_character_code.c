#include <stdio.h>

void echo_char() {
    //  Prompt the user to enter a single character.
    //
    //  Use the text "Please enter a char value:" followed by a single
    //  colon, and nothing else (either visible or invisible).
    //  The message should appear on a line by itself.
    //
    //  Hint: printf.
		printf("Please enter a char value:\n");
    //  Fetch a character code from standard input.
    //
    //  Hint: scanf(" %c", &some_var_of_type_char) will skip spaces and get the
    //        first non-space character.
		char ch;
		scanf(" %c", &ch); // The space before %c is IMPORTANT.
    //        scanf("%c", &some_var_of_type_char) i.e. without the leading space
    //        symbol in the format string, will fetch any character, including
    //        space, tab, form-feed, or line-feed symbols.
    //
    //        AMS will use the first form, to skip over spaces and newlines.

    //  Send the character entered by the user to the standard output
    //  stream. Your message should take the form "You entered the character 'X'.",
    //  where X is replaced by the character read earlier. The message should
    //  be followed by a single linefeed symbol, and nothing else (either
    //  visible or invisible).
    //
    //  Hint: printf, %c.
		printf("You entered the character '%c'.\n", ch);
    //  Send the character entered by the user to the standard output
    //  stream, along with its character code. Your message should take the
    //  form "The code for character 'X' is Y.", where X is replaced by the
    //  character read earlier, and Y is replaced by the integer value of the
    //  character. The message should be followed by a single linefeed symbol,
    //  and nothing else (either visible or invisible).
    //
    //  Hint: printf, %c, %d.
		printf ("The code for character '%c' is %d.\n", ch, ch);
}


int main() {
	echo_char();
	return 0;
}

//My comments
//1. Ensure that there is a space before %c (line 17)
