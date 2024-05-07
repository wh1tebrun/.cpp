// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include <cstdio>
#include <cstdlib>

#include "./Gcd.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: ./Gcd <integer> <integer> \n");
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  int result = gcd(x, y, true);

  printf("gcd(%d,%d) = %d\n", x, y, result);

  return 0;
}
