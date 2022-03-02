#include <stdio.h>

/*
 *  This program does not produce the desired results. Rearrange the
 *  instructions to fix the logic error.
 *
 *  Original question:
 *      Chapman, Stephen J. Matlab Programming For Engineers 4th Ed, p183.
 *
 *  Updated temperature information:
 *      https://medlineplus.gov/ency/article/001982.htm, accessed 28 Feb 2020.
 */

void test_temperature(void) {

    //  Prompt the user to enter the temperature in Celsius degrees.
    printf( "Please enter the temperature in Celsius degrees:\n" );

    //  Scan a double precision floating point value from standard input.
    //  Store the value in a variable called temp.
    double temp;
    scanf( "%lf", &temp );

    // Rewrite this test so that it is consistent with the commentary from
    // the Medline Plus Encyclopedia (link above).
    if ( temp < 36.1 ) {
        printf( "Temperature below normal\n" );
    }
    else if ( temp > 38.0 ) {
        printf( "Temperature dangerously high\n" );
    }
    else if ( temp > 37.2 ) {
        printf( "Temperature above normal\n" );
    }
    else {
        printf( "Temperature normal\n" );
    }

}


int main() {
	test_temperature();
	return 0;
}
