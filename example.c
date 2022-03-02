 // #include <stdio.h>
// #include <stdlib.h>
//
// void process(uint8_t b);
//
// int main(void) {
//      int x; //declare x
//      while (1 == scanf("%d", &x)) { //while the program is able to scan an integer value
//          if (x & 255) process(x & 255); //if x = 255, process both values x & 255.
//      }
//      return 0;
// }
//
//  void process(uint8_t b) { //process requires unsigned 8-bit integer b
//      printf("%d ->", b); //print unsigned integer b
//      for (int i = 0; i < 8; i++) { //until i does not equal to 7
//          if (!((b >> i) & 1)) printf(" %d", i); // if b's division by squared i does not return 1, print i.
//      }
//      printf("\n");
// }
//
// #include <stdio.h>
//
// int main(int argc, char * argv[]) {
//      printf("Hello World.\n");
//      return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
//  #include <ctype.h>
//
//  void process(char ch);
//  int n = 0;
//
// int main(void) {
//     char x;
//      while (1 == scanf("%c", &x)) {
//          process(x);
//      }
//     printf("n = %d\n", n);
//     return 0;
//  }
//
//  void process(char ch) {
//     static int p = 0;
//     int q = isalnum(ch);
//     if( p && (!q) ) n++;
//     p = q;
//  }

// int foo(int x){
//
//         return x++;
//
// }
// int main(){
//
//     int x = 67 << 6;
//
//     // x = foo(x);
//     printf("%d\n", x);
//
// return 0;
//
// }

 // #include <stdio.h>
 // #include <stdlib.h>
 //
 // uint8_t process(void);
 // uint8_t reg = 0;
 //
 // int main(void) {
 //     int x;
 //     int d = 0;
 //     while (1 == scanf("%d", &x)) {
 //        reg = x & 255;
 //       uint8_t b = process();
 //        printf("%s%d", (d ? " " : ""), b);
 //         d = 1;
 //    }
 //    printf("\n");
 //     return 0;
 // }
 //
 // uint8_t process(void) {
 //     #define B (3)
 //    static uint8_t p = 0;
 //   uint8_t q = reg & (1<<B);
 //   uint8_t r = !(p^q);
 //   p = q;
 //    return r;
 // }

#include <stdio.h>
#include <stdlib.h>

 #define M (100)
 void print(double x[], int n);
 void process(double x[], int n, int w, double y[]);

 int main(void) {
    double x, a[M], b[M];
    int n = 0;
    int w;
    scanf("%d", &w);
     while (1 == scanf("%lf", &x)) {
         if (n < M) a[n++] = x;
    }
     process(a, n, w, b);
     print(b, n);
     return 0;
 }

 void print(double x[], int n) {
     for (int i = 0; i < n; i++) printf("%3.2f ", x[i]);
     printf("\n");
 }

 void process(double x[], int n, int w, double y[]) {
     for (int i = 0; i < n; i++) {
        y[i] = 0;
        int m = 0;
        for (int j = 1-w; j <= 0; j++) {
            int k = i - j;
            if (k < 0 || k >= n) continue;
            y[i] += x[k];
            m++;
        }
        y[i] /= m;
    }
 }
