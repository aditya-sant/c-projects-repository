#include <stdio.h>

void list_integers( void ) {
    // Display the title message.
    printf("The integer sub-range from 62 to 305...\n");

    //  Enter a counter-controlled loop which will start at 62 and
    //  continues up to and including 305, advancing by increments of 1.
    for (int i = 62; i<=305; i+=1){

      //  Print the current value of the counter variable.
      printf("%d\n", i);

    }
    // End the loop.
}

int main( void ) {
	list_integers( );
	return 0;
}
