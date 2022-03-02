#include <stdio.h>
#include <math.h>

void cylinder_vol(void) {
  // (a) Prompt user to enter value.
  printf("Please enter the radius:\n");
  // (b) Declare local variable to hold input value.
  double r;
  // (c) Read radius input value.
  scanf("%10lf", &r);
  // (a) Prompt user to enter value.
  printf("Please enter the height:\n");
  // (b) Declare local variable to hold input value.
  double h;
  // (c) Read height input value.
  scanf("%10lf", &h);
  // (d) Compute output value.
  double v = (M_PI*(r*r))*h;
  // (e) Display the result.
  printf("When the radius is %.6f units and the height is %.6f units then the volume will be %.6f cubic units.\n", r, h, v);
}

int main(void) {
	cylinder_vol();
	return 0;
}
