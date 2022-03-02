#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

INSERT_RESULT_TYPE_HERE create_hist( INSERT_FORMAL_PARAMETERS_HERE ) {
	// TODO: INSERT CODE HERE
}

void call_function( const char * label, double x[], int count ) {
	int hist[25 + 1];
	create_hist( x, count, hist );
	printf( "%s\n", label );
	printf( "\tInput data:\n" );

	for ( int i = 0; i < count; i++ ) {
		printf( "\t%d\t%f\n", i, x[i] );
	}

	printf( "\tHistogram:\n" );

	for ( int i = 0; i <= 25; i++ ) {
		printf( "\t%d\t%d\n", i, hist[i] );
	}

	printf( "\n" );
}

int main( void ) {
	srand( time( NULL ) );

	double x1[] = { 0 };
	call_function( "Count == 0", x1, 0 );

	double x2[] = { 0, 0, 0 };
	call_function( "Three equal values", x2, 3 );

	double x3[25 + 1];
	for ( int i = 0; i <= 25; i++ ) {
		x3[i] = i;
	}
	call_function( "One value in each bucket", x3, 25 + 1 );

	double x4[25 * 2 + 1];
	for ( int i = 0; i <= 25 * 2; i++ ) {
		x4[i] = (25+1) * ( double ) rand() / RAND_MAX;
	}
	call_function( "Random values", x4, 25 * 2 + 1 );

	return 0;
}
