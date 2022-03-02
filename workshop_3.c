#include<stdio.h>
#include<stdlib.h>

int main(){
  int count = 0;
  while(count < 10){
    printf("Hello World %d\n", count);
    count += 1;
  }

  for(int i = 0; i <= 10; i++){
    printf("Hello World %d\n", i);
  }
  return 0;
}
