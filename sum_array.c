#include <stdio.h>
#include <stdlib.h>

//  HERE: Declare an array called term with capacity to hold 31 double
//  precision floating point values.
double term[31];
//  HERE: Declare an integer called term_count which will track the number of items
//  that have been appended to the list stored.
int term_count;
//  HERE: Declare a double precision floating point value called term_sum which will
//  be used to remember the total sum of the items stored in the list.
double term_sum;
void arraysum() {
    //  Initially the list is empty, so assign 0 to term_count.
    term_count = 0;
    //  Append items to the list by reading from standard input until either
    //  term_count >= 31, or the value returned by scanf is not 1.
    while( term_count < 31 && scanf("%lf", &term[term_count]) == 1)
    {
      term_count++;
    }
    //  Assign 0 to term_sum.
    term_sum = 0;
    //  Traverse the items that have been appended to the list, and accumulate
    //  the sum in term_sum.
    for (int i = 0; i < term_count; i++)
    {
      term_sum += term[i];
    }
}

#include <stdlib.h>
#include <time.h>

int main(void) {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correct even with this.
    for ( int i = 0; i < 31; i++ ) {
        double randVal = ((double) rand()) / RAND_MAX;
        term[i] = randVal;

        if (randVal != term[i]) {
            printf("Incorrect numeric type appears to be in use.\n");
            return 1;
        }
    }

    term_count = rand();
    term_sum = rand();

    // Call submitted code.
    arraysum();

    // Display contents of array term.
    for (int i = 0; i < term_count; i++) {
        printf("%f ", term[i]);
    }

    printf("\n");
    printf("Item count: %d\n", term_count);
    printf("Item sum  : %f\n", term_sum);

    return 0;
}
