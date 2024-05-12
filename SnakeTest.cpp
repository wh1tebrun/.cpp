// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <bast@cs.uni-freiburg.de>

#include "./Snake.h"
#include <gtest/gtest.h>
#include <ncurses.h>

TEST(Snake, initGame) {

  initGame();

  ASSERT_EQ(currentWidth, 0);
  ASSERT_EQ(currentHeight, 0);
  ASSERT_NE(currentDirection, 'N');
}

TEST(Snake, collidesWithBorder) {

  currentWidth = -5;

  bool isCollided = collidesWithBorder();

  ASSERT_EQ(isCollided, true);
}
TEST(Snake, moveSnake) {
  currentHeight = 10;
  currentWidth = 20;
  moveSnake();
  ASSERT_EQ(currentHeight, 10);
  ASSERT_EQ(currentWidth, 22);
}

TEST(Snake, handleKey) {
  currentDirection = 'N';

  bool isExitted = handleKey(KEY_LEFT);
  ASSERT_EQ(currentDirection, 'W');
  ASSERT_EQ(isExitted, false);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
