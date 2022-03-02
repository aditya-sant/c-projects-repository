#include <stdio.h>
#include <stdlib.h>

//  Here: Declare a global array called fib with capacity to hold 29 elements
//  of the default signed integer type.
int fib[29];

int x;
int y;

void compute_seq( void ) {
    //  Here: Insert code to populate the array with a generalised Fibonacci
    //  sequence here.
    scanf("%d", &x);
    fib[0] = x;
    scanf("%d", &y);
    fib[1] = y;

    for (int i = 2; i < 29; i++)
    {
      fib[i] = fib[i-1] + fib[i-2];
    }
}

int main(void) {
    //  Fill array with distinctive data pattern to help identify bugs. If you
    //  see the number 13283842 in your output there must a bug in your code.
    for ( int i = 0; i < 29; i++ ) {
        fib[i] = 0xCAB202;
    }

    //  Run your code.
    compute_seq();

    //  Display contents of array fib.
    for (int i = 0; i < 29; i++) {
        printf("%d\n", fib[i]);
    }

    return 0;
}
