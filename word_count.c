#include <stdio.h>
#include <ctype.h>

void word_count() {
    //  Insert your solution here.
    int chars = 0;
    int words = 0;
    int lines = 0;

    char ch;
    char previous = '\n';

    while(1){

      int scanf_result = scanf("%c", &ch);
      if (scanf_result <= 0) break;

      if (ch == '\n'){
        lines++;
      }

      else if (isspace(previous) && !isspace(ch)){
        words++;
      }

      chars++;
      previous = ch;
    }
    printf("There are %d lines, %d words, and %d characters.\n", lines, words, chars);
}


int main() {
	word_count();
	return 0;
}
