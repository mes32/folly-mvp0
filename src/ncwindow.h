/**
 *  ncwindow.h - folly-mvp0
 *
 *  This module defines functionality for the ncurses terminal window.
 *
 */

#ifndef NCWINDOW_H_
#define NCWINDOW_H_

#include <ncurses.h>

// Pairs of colors available for drawing
const typedef enum ColorPairType {
    COLOR_PAIR_WHITE_ON_BLACK = 0,
    COLOR_PAIR_GREEN_ON_BLACK = 1
} ColorPairs;

/**
 * Initialize the ncurses window
 */
WINDOW *initWindow();

/**
 * Clear the window contents and reset the dimensions to handle resizing 
 */
void resetWindow(WINDOW *window);

/**
 * Delete the window and clean up
 */
void deleteWindow(WINDOW *window);

/**
 * Return the number of rows in the current window
 */
int getRow(WINDOW *window);

/**
 * Return the number of columns in the current window
 */
int getCol(WINDOW *window);

/**
 * Moves the cursor to the bottom of the screen 
 */
void cursorToRestPosition(WINDOW *window);

/**
 * Moves the cursor to a given screen location
 */
void moveCursor(WINDOW *window, int xloc, int yloc);

/**
 * Print a character at a given screen location
 */
void printCharAt(WINDOW *window, int xloc, int yloc, char c, ColorPairs color);

/**
 * Print a string at a given screen location
 */
void printStrAt(WINDOW *window, int xloc, int yloc, char *str);

/**
 * Print a string centered inside a box that spans the width of the terminal window
 */
void addTextbox(WINDOW *window, int xloc, int yloc, char *str);

/**
 * Print multiple strings in left aligned cells inside a box that spans the width of the terminal window
 */
void addMultipleTextbox(WINDOW *window, int xloc, int yloc, int num, char *strArray[]);

/**
 * Print several strings as a list
 */
void addList(WINDOW *window, int xloc, int yloc, int n, char *strArray[]);

#endif // NCWINDOW_H_