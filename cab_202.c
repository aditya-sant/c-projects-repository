#include <stdio.h>

void cab_202( void ) {
    for (int i = 94; i<=3622; i+=1){

      if (i % 3 == 0 && i % 17 == 0) printf("CAB202");
      else if (i % 17 == 0) printf("202");
      else if (i % 3 == 0) printf ("CAB");
      else printf("%d", i);
      printf("\n");
    }
}

int main( void ) {
	cab_202( );
	return 0;
}
