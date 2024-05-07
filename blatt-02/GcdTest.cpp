// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include "./Gcd.h"
#include <gtest/gtest.h>

TEST(GcdTest, gcd) {
  // Two numbers that are prime between them
  ASSERT_EQ(gcd(7, 11), 1);
  // There is only one common multiplier
  ASSERT_EQ(gcd(6, 15), 3);
  // Multiplication of (48) by 2 is (96)
  ASSERT_EQ(gcd(48, 96), 48);
  // There are multiple common multipliers : (2, 3)
  ASSERT_EQ(gcd(12, 30), 6);
  // The behaivour with big numbers
  ASSERT_EQ(gcd(870, 2430), 30);
}
int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
