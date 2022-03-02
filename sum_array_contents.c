#include <stdio.h>

//  Declare Global variables here.
double seq[27];
int seq_len;
double seq_mean;
double seq_sum;
double seq_min;
double seq_max;

void arraystats() {
    //  Insert your solution here.
    seq_len = 0;
    while (seq_len < 27 && scanf("%lf", &seq[seq_len]) == 1)
    {
      seq_len++;
    }

    seq_mean = 0;
    seq_min = 0;
    seq_max = 0;
    seq_sum = 0;

    for (int i = 0; i < seq_len; i++)
    {
      seq_sum += seq[i];
    }

    seq_mean = (seq_sum/seq_len);

    seq_min = seq[0];
    for(int i = 1; i < seq_len; i++)
    {
      if (seq[i] < seq_min)
      {
        seq_min = seq[i];
      }
    }

    seq_max = seq[0];
    for(int i = 1; i < seq_len; i++)
    {
      if (seq[i] > seq_max)
      {
        seq_max = seq[i];
      }
    }

    if (seq_len == 0)
    {
      seq_mean = 0;
      seq_max = 0;
      seq_min = 0;
    }
}

#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correctly even with this.
    srand( time( NULL ) );

    for ( int i = 0; i < 27; i++ ) {
        double randVal = ((double) rand()) / RAND_MAX;
        seq[i] = randVal;

        if (randVal != seq[i]) {
            printf( "Incorrect numeric type appears to be in use.\n" );
            return 1;
        }
    }

    seq_len = rand();
    seq_mean = ((double) rand()) / RAND_MAX;
    seq_min = ((double) rand()) / RAND_MAX;
    seq_max = ((double) rand()) / RAND_MAX;

    // Call submitted code.
    arraystats();
    //arraystats();

    // Display contents of array seq.
    for (int i = 0; i < seq_len; i++) {
        printf("%f ", seq[i]);
    }

    printf("\n");
    printf("Item count: %d\n", seq_len);
    printf("Item mean : %f\n", seq_mean);
    printf("Item min  : %f\n", seq_min);
    printf("Item max  : %f\n", seq_max);

    return 0;
}
