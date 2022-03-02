#include <stdio.h>

void flag_multiples( void ) {
    //  Enter a counter controlled loop which starts at 94 and
    //  advances by increments of 1 up to and including 3622
        //  Send the current value of the counter to standard output as a
        //  decimal formatted integer.
    for (int i = 94; i<=3622; i+=1){
      printf("%d", i);

      //  If the current value of the counter is divisible by 3 then
      //  highlight the current line by sending the pattern " <===" to
      //  standard output.
      if (i % 3 == 0) printf(" <===");

      //  Send a linefeed to standard output.
      printf("\n");

      //  End loop.
    }
}

int main( void ) {
	flag_multiples( );
	return 0;
}
