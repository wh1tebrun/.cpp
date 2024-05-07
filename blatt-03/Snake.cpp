// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include "./Snake.h"
#include <ncurses.h>

int gameHeight, gameWidth;
int currentWidth, currentHeight;
char currentDirection;

// Initialize terminal settings to prepare for ncurses-based display
void initTerminal() {
  initscr();
  curs_set(false);
  noecho();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  start_color();
}

// Set up initial game environment and attributes
void initGame() {
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  getmaxyx(stdscr, gameHeight, gameWidth);

  currentWidth = gameWidth / 2;
  currentHeight = gameHeight / 2;
  currentDirection = 'E';
}

// Terminate ncurses environment properly
void endNcurses() { endwin(); }

// Function to draw a pixel (a square block in this context) on the screen
void drawPixel(int row, int column, int color) {
  attron(color | A_REVERSE);
  mvprintw(row, column, "  ");
  attroff(color | A_REVERSE);
  refresh();
}

// ____________________________________________________________________________
void drawBox(int color, int score, float speed) {
  attron(color);
  mvprintw(5, 5, "Score: %3d", score);
  mvprintw(5, 100, "Speed %3f", speed);
  attroff(color);
  refresh();
}

// Draw borders along the edges of the terminal window
void drawBorder(int color) {
  getmaxyx(stdscr, gameHeight, gameWidth);
  for (int col = 0; col < gameWidth; col += 2) {
    drawPixel(0, col, color);
    drawPixel(gameHeight - 1, col, color);
  }
  for (int row = 0; row < gameHeight; row++) {
    drawPixel(row, 0, color);
    drawPixel(row, gameWidth - 2, color);
  }
}
// Draw the snake at its current position
void drawSnake(int color) { drawPixel(currentHeight, currentWidth, color); }

// Check if the snake collides with the border of the game field
bool collidesWithBorder() {
  return currentWidth <= 0 || currentWidth >= gameWidth - 2 ||
         currentHeight <= 0 || currentHeight >= gameHeight - 1;
}

// Update the snake's position based on the current movement direction
void moveSnake() {
  switch (currentDirection) {
  case 'W':
    currentWidth = currentWidth - 2;
    break;
  case 'E':
    currentWidth = currentWidth + 2;
    break;
  case 'N':
    currentHeight--;
    break;
  case 'S':
    currentHeight++;
    break;
  }
}

// Handle user input and control game flow
bool handleKey(int key) {
  switch (key) {
  case KEY_LEFT:
    if (currentDirection != 'E') {
      currentDirection = 'W';
      return false;
    }
    break;
  case KEY_RIGHT:
    if (currentDirection != 'W') {
      currentDirection = 'E';
      return false;
    }
    break;
  case KEY_UP:
    if (currentDirection != 'S') {
      currentDirection = 'N';
      return false;
    }
    break;
  case KEY_DOWN:
    if (currentDirection != 'N') {
      currentDirection = 'S';
      return false;
    }
    break;
  case 27:
    return true;
  }
  return false;
}