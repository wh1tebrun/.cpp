// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include <cstdio>
#include <cstdlib>

int gcd(int x, int y, bool verbose = false) {
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