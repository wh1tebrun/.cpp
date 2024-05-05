// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include "./Snake.h"
#include <ncurses.h>

// Global variables
int row;
int col;
char currentDirection;
int pixelPosition[2] = {0, 0}; // Array of two integers: [x, y]

/* Initialize the terminal and playing field dimensions using ncurses */
void initTerminal() {
  initscr();
  curs_set(false);
  noecho();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
}

/* Initialize the game: set initial pixel position and direction */
void initGame() {
  pixelPosition = {screenWidth / 2, screenHeight / 2};
  currentDirection = KEY_UP;
}

/* Draw a pixel at the specified position with the given color */
void drawPixel(int row, int column, int color) {
  attron(COLOR_PAIR(color));
  mvprintw(row, 2 * column, "  "); // Each pixel is two characters wide
  attroff(COLOR_PAIR(color));
  refresh();
}

/* Draw the playing field border with the specified color using drawPixel */
void drawBorder(int color) {
  for (int col = 0; col < screenWidth / 2; ++col) {
    drawPixel(0, col, color);                // Top border
    drawPixel(screenHeight - 1, col, color); // Bottom border
  }

  for (int row = 0; row < screenHeight; ++row) {
    drawPixel(row, 0, color); // Left border
    drawPixel(row, screenWidth / 2 - 1,
              color); // Right border (for even number of columns)
  }
}

/* Draw the snake at its current position and in the specified color */
void drawSnake(int color) {
  for (const auto &position : snakePositions) {
    int row = position.first;
    int col = position.second;
    drawPixel(row, col, color);
  }
}

/* Check if the snake collides with the border */
bool collidesWithBorder() {
  for (const auto &position : snakePositions) {
    int row = position.first;
    int column = position.second;

    if (row < 1 || row >= screenHeight - 1 || column < 1 ||
        column >= screenWidth / 2 - 1) {
      return true; // A segment is outside of the allowed boundaries
    }
  }
  return false; // No collisions with the border
}

/* Move the snake in the current direction by exactly one pixel */
void moveSnake() {
  switch (currentDirection) {
  case KEY_LEFT:
    col--;
    break;
  case KEY_RIGHT:
    col++;
    break;
  case KEY_UP:
    row--;
    break;
  case KEY_DOWN:
    row++;
    break;
  }

  snakePositions.insert(snakePositions.begin(), std::make_pair(newRow, newCol));
  if (!isGrowing) {
    snakePositions.pop_back();
  }
}

bool isGrowing =
    false; // State variable indicating whether the snake is growing

/* Process the given keycode */
bool handleKey(int key) {
  switch (key) {
  case KEY_UP:
    if (currentDirection != KEY_DOWN) {
      currentDirection = KEY_UP; // Change direction to up (avoid reverse)
    }
    break;
  case KEY_DOWN:
    if (currentDirection != KEY_UP) {
      currentDirection = KEY_DOWN; // Change direction to down (avoid reverse)
    }
    break;
  case KEY_LEFT:
    if (currentDirection != KEY_RIGHT) {
      currentDirection = KEY_LEFT; // Change direction to left (avoid reverse)
    }
    break;
  case KEY_RIGHT:
    if (currentDirection != KEY_LEFT) {
      currentDirection = KEY_RIGHT; // Change direction to right (avoid reverse)
    }
    break;
  case 27:       // ASCII code for ESC
    return true; // End game
  default:
    return false; // No effect for other keys
  }
  return false; // Continue the game after processing a valid direction key
}