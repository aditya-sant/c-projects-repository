#include <stdio.h>


int main(){
  int x, y; //asking the compiler, can the computer allocate a slot of memory for an integer?

  x = 10; //an integer is 4 bytes.
  y = 5;
  printf("x is: %d\n", x);
  printf("x is stored at: %p\n", &x);

  printf("y is: %d\n", x);
  printf("y is stored at: %p\n", &y);

  int *p;
  p = &x;

  printf("y is %p\n", p);
  printf("p is stored at: %p\n", %p);
  printf("p points to: %d\n", *p);

  printf("chunk is: %p\n", chunk);
  printf("value stored at chunk is: %d\n", *chunk);
  printf("Size of int is: %lu\n", sizeof(int));

  int i=0;
  while(i < 5){
    printf("chunk[%d] is %d\n", i, chunk[i]);
    i++;
  }
  // printf("chunk + 1 points to: %d\n", (chunk + 1));
  // printf("chunk + 2 points to: %d\n", (chunk + 2));
  // printf("chunk + 3 points to: %d\n", (chunk + 3));
  // printf("chunk + 4 points to: %d\n", (chunk + 4));

  return 0;
}
