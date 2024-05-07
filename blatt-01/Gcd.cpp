#include <cstdio>
#include <cstdlib>

#include "./Gcd.h"

int gcd(int x, int y, bool verbose) {
  while (x != 0 && y != 0) {
    if (x > y) {
      x = x % y;
    }

    else {
      y = y % x;
    }

    if (verbose) {
      if (x > y) {
        printf("gcd(%d,%d)\n", y, x);
      } else {
        printf("gcd(%d,%d)\n", x, y);
      }
    }
  }

  if (x > y) {
    return x;
  }

  else {
    return y;
  }
}