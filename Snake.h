// Copyright 2024, University of Freiburg,
// 2nd Semester Computer Science Student
// Author: Hannah Bast <et130@students.uni-freiburg.de>
// Comment lines were written by gpt-4-turbo

#pragma once  // Ensures that the header file is included only once during compilation

// Declaring external variables to represent the position and size of the game:
extern int currentHeight;  // Current vertical position of the snake or box
extern int currentWidth;   // Current horizontal position of the snake or box
extern int gameWidth;      // Width of the game area (typically the terminal width)
extern int gameHeight;     // Height of the game area (typically the terminal height)
extern char currentDirection;  // Current direction of the snake or box

// Function declarations to organize game initialization and rendering:
void initTerminal();  // Initializes the terminal for gameplay (may involve setting up ncurses environment)
void initGame();      // Sets initial conditions for the game (e.g., reset positions and direction)

// Function to clean up and terminate the ncurses environment properly
void endNcurses();    

// Function to draw the snake in the game window with a given color
void drawSnake(int color);  

// Draws a "pixel" (a character block) at the specified position with a specified color
void drawPixel(int row, int col, int color); 

// Draws the border around the game area to delineate edges
void drawBorder(int color);  

// Takes input key and modifies game state based on user input
bool handleKey(int key); 

// Moves the snake based on its current direction
void moveSnake();  

// Checks whether the snake collides with any of the borders of the game area
bool collidesWithBorder();  

void drawBox(int color, int score, float speed);