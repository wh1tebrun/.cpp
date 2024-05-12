// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#include "./Snake.h"
#include <ncurses.h>
#include <unistd.h>

int gameHeightMain, gameWidthMain;



int main() {

  initTerminal();
  initGame();

  getmaxyx(stdscr, gameHeightMain, gameWidthMain);

  float speed = 10.0;
  float acceleration = 0.0002;
  int score = 0;

  bool gameRunning = true;

  // Main game loop
  while (gameRunning) {
    int currentGameHeight, currentGameWidth;
    getmaxyx(stdscr, currentGameHeight, currentGameWidth);

    if (currentGameHeight != gameHeightMain || currentGameWidth != gameWidthMain) {
      gameHeightMain = currentGameHeight;
      gameWidthMain = currentGameWidth;

      clear();
    }


    if (score == 1001) {

      mvprintw(gameHeight / 2, (gameWidth / 2) - 22,
               "Congratulations, you won! Press ESC to exit.");
      refresh();
      timeout(-1);
      while (getch() != 27) {
      }
      gameRunning = false;
    }

    // Collect user input without blocking
    int key = getch();
    // Pause execution 
    usleep(40000);

    // Draw the snake at its current position

    
     
    drawSnake(COLOR_PAIR(2));

    // Draw the borders of the game arena
    drawBorder(COLOR_PAIR(1));

    // Draw the score box at the position of x = 5 and y = 5
    drawBox(COLOR_PAIR(1), score, speed);

    // Update the screen with the latest drawings
    refresh();

    if (key != ERR) {
      bool exit = handleKey(key);
      if (exit) {
        break;
      }
    }

    moveSnake();

    // Check if the snake has collided with the border
    if (collidesWithBorder()) {

      mvprintw(gameHeight / 2, (gameWidth / 2) - 12,
               "Game Over! Press ESC to exit.");
      refresh();
      timeout(-1);
      while (getch() != 27) {
      }
      gameRunning = false;
    }

    speed += acceleration;
    score++;
  }

  endNcurses();
  return 0;
}