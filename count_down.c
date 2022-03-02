#include <stdio.h>

void count_down( void ) {
    for (int i = 3933; i>=5; i-=7){
      printf("%d", i);
      printf("\n");
    }
}

int main( void ) {
	count_down( );
	return 0;
}
