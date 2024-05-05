// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Ege Tekin <et130@students.uni-freiburg.de>

#pragma once

// Position and direction of the box.
extern int row;
extern int col;
extern char currentDirection;

/* Pixel's initial position (x, y) using an array of two integers. */
extern int pixelPosition[2];

/* Function to initialize the Ncurses terminal. */
void initTerminal();

/* Function to initialize game settings like initial pixel position and
direction. */
void initGame();

/* Function to draw a pixel at a specified position with a specified color. Each
pixel is rendered two characters wide. */
void drawPixel(int row, int column, int color);

/* Function to draw the borders of the playing field using drawPixel. */
void drawBorder(int color);

/* Function to draw the snake at its current position in the given color. */
void drawSnake(int color);

/* Function to check if the snake collides with the boundary of the playing
field. */
bool collidesWithBorder();

/* Function to move the snake in the current direction by exactly one pixel
position. */
void moveSnake();

/* Function to handle keyboard input; updates direction unless attempting to
reverse, and returns true on ESC key press to signal game end. */
bool handleKey(int key);