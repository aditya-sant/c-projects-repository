#include <stdio.h>

void celsius_to_fahrenheit(void) {
  // (a) Prompt user to enter value.
  printf("Please enter the temperature, measured in degrees Celsius:\n");
  // (b) Declare local variable to hold input value.
  double f;
  // (c) Read input value.
  scanf("%10lf", &f); //
  // (d) Compute output value.
  double c = ((9.0/5.0)*f)+32.0;
  // (e) Display the result.
  printf("%.5f Celsius is the same as %.5f Fahrenheit.\n",f,c);
}

int main(void) {
	celsius_to_fahrenheit();
	return 0;
}
