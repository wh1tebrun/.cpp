// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include "./Gcd.cpp"

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: ./Gcd <integer> <integer> <bool> \n");
    exit(1);
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  int result = gcd(x, y, true);

  printf("gcd(%d,%d) = %d\n", x, y, result);

  return 0;
}
