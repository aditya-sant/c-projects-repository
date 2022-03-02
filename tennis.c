#include <stdio.h>


void tennis_dialog( void ) {
    printf("How does the weather look?\n1 - sunny\n2 - overcast\n3 - rainy\n");

    double w;
    scanf("%lf", &w);

    if (w == 1){
      printf("How does the humidity feel?\n1 - high\n2 - normal\n");

      double h;
      scanf("%lf", &h);

      if (h == 1){
        printf("Boo hoo, we cannot play tennis because it is too sticky!!!\n");
      }

      else if (h == 2){
        printf("Woo hoo, we get to play tennis!!!\n");
      }

      else{
        printf("Invalid choice for humidity: '%.f'\nValid options are '1', and '2'.\n", h);
      }
    }

    else if (w == 2){
      printf("Woo hoo, we get to play tennis!!!\n");
    }

    else if (w == 3){
      printf("What is the wind level?\n1 - windy\n2 - calm\n");

      double i;
      scanf("%lf", &i);

      if (i == 1){
        printf("Boo hoo, we cannot play tennis because it is too wet and windy!!!\n");
      }

      else if (i == 2){
        printf("Woo hoo, we get to play tennis!!!\n");
      }

      else{
        printf("Invalid choice for wind: '%.f'\nValid options are '1', and '2'.\n", i);
      }
    }
    else{
      printf("Invalid choice for outlook: '%.f'\nValid options are '1', '2', and '3'.\n", w);
    }
}

int main(void) {
	tennis_dialog();
	return 0;
}
