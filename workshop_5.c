#include <stdio.h>

void print_array(int vals[], int n){
  printf("The length of values is %lu\n", sizeof(vals));

  for(int i=0; i<sizeof(vals)/sizeof(int); i++)
  {
    printf("%d", vals[i]);
  }
  printf("\n");
}

int main(){
  int vals[5];

  print_array(vals, 5000);

  return 0;
}
