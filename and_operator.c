#include <stdio.h>

void point_3d( void ) {
    //request for 2 inputs.
    printf("Please enter X and Y:\n");

    //declare the inputs as variables.
    double x;
    scanf("%10lf", &x);

    double y;
    scanf("%10lf", &y);

    //conditions.
    if (x >= 0 && y >= 0) {
      double z = ((4.51576 * x) + (4.02501 * y));
      printf("(%.6f, %.6f) -> %.6f.\n", x, y, z);
    }

    else if (x >= 0 && y < 0) {
      double z = ((4.51576 * x) + (y * y));
      printf("(%.6f, %.6f) -> %.6f.\n", x, y, z);
    }

    else if (x < 0 && y >= 0) {
      double z = ((x * x) + (4.02501 * y));
      printf("(%.6f, %.6f) -> %.6f.\n", x, y, z);
    }

    else {
      double z = ((x * x) + (y * y));
      printf("(%.6f, %.6f) -> %.6f.\n", x, y, z);
    }
}


int main() {
	point_3d();
	return 0;
}
