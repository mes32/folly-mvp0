/**
 *  ncwindow.c - folly-mvp0
 *
 *  This module defines functionality for the ncurses terminal window.
 *
 */

#include <assert.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include <string.h>
#include "ncwindow.h"

// Dimensions of the window
static int row, col;

/**
 * Initialize the ncurses window
 */
WINDOW *initWindow() {



initscr();
    noecho();
    curs_set(FALSE);
    cbreak();   // Line buffering disabled. Pass on everything

    struct winsize terminalWindow;
    ioctl(0, TIOCGWINSZ, &terminalWindow);
    int rows = terminalWindow.ws_row;
    int columns = terminalWindow.ws_col;

    WINDOW *window;
    window = newwin(rows, columns, 0, 0);

    keypad(window, TRUE);
    wclear(window);

    start_color();
    init_pair(COLOR_PAIR_WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_PAIR_GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
    wbkgd(window, COLOR_PAIR(COLOR_PAIR_WHITE_ON_BLACK));

    return window;
}

/**
 * Clear the window contents
 */
void clearWindow(WINDOW *window) {
    wclear(window);
}

/**
 * Clear the window contents and reset the dimensions to handle resizing 
 */
void resetWindow(WINDOW *window) {
    endwin();
    refresh();
    clear();
    getmaxyx(window, row, col);
}

/**
 * Delete the window and clean up
 */
void deleteWindow(WINDOW *window) {
    curs_set(1);
    clear();
    endwin();
}

/**
 * Return the number of rows in the current window
 */
int getRow(WINDOW *window) {
    getmaxyx(window, row, col);
    return row;
}

/**
 * Return the number of columns in the current window
 */
int getCol(WINDOW *window) {
    getmaxyx(window, row, col);
    return col;
}

/**
 * Moves the cursor to the bottom of the screen 
 */
void cursorToRestPosition(WINDOW *window) {
    wmove(window, row - 1, col - 1);
}

/**
 * Moves the cursor to a given screen location
 */
void moveCursor(WINDOW *window, int xloc, int yloc) {
    wmove(window, yloc, xloc);
}

/**
 * Print a character at a given screen location
 */
void printCharAt(WINDOW *window, int xloc, int yloc, char c, ColorPairs color) {
    //attron(COLOR_PAIR(color));
    mvwaddch(window, yloc, xloc, c);
    //attroff(COLOR_PAIR(color));
}

/**
 * Print a string at a given screen location
 */
void printStrAt(WINDOW *window, int xloc, int yloc, char *str) {
    //attron(COLOR_PAIR(color));
    mvwprintw(window, yloc, xloc, str);
    //attroff(COLOR_PAIR(color));
}

/**
 * Print a string centered inside a box that spans the width of the terminal window
 */
void addTextbox(WINDOW *window, int xloc, int yloc, char *str) {
    ColorPairs colorPair = COLOR_PAIR_WHITE_ON_BLACK;

    getmaxyx(stdscr, row, col);

    printCharAt(window, xloc, yloc, '+', colorPair);
    printCharAt(window, xloc, yloc+1, '|', colorPair);
    printCharAt(window, xloc, yloc+2, '+', colorPair);
    for (int i = xloc+1; i < col-1; i++) {
        printCharAt(window, i, yloc, '-', colorPair);
        printCharAt(window, i, yloc+2, '-', colorPair);
    }
    printCharAt(window, col-1, yloc, '+', colorPair);
    printCharAt(window, col-1, yloc+1, '|', colorPair);
    printCharAt(window, col-1, yloc+2, '+', colorPair);

    int len = strlen(str);
    int xStart = (col - len) / 2;
    printStrAt(window, xStart, yloc+1, str);
}

/**
 * Print multiple strings in left aligned cells inside a box that spans the width of the terminal window
 */
void addMultipleTextbox(WINDOW *window, int xloc, int yloc, int num, char *strArray[]) {
    ColorPairs colorPair = COLOR_PAIR_WHITE_ON_BLACK;
    getmaxyx(stdscr, row, col);

    int strLengths[num];
    for (int i = 0; i < num; i++) {
        strLengths[i] = strlen(strArray[i]);
    }

    printCharAt(window, xloc, yloc, '+', colorPair);
    printCharAt(window, xloc, yloc+1, '|', colorPair);
    printCharAt(window, xloc, yloc+2, '+', colorPair);
    for (int i = xloc+1; i < col; i++) {
        printCharAt(window, i, yloc, '-', colorPair);
        printCharAt(window, i, yloc+2, '-', colorPair);
    }

    int xEndBox = xloc + 2;
    for (int i = 0; i < num; i++) {
        xEndBox += strLengths[i] + 1;
        printCharAt(window, xEndBox, yloc, '+', colorPair);
        printCharAt(window, xEndBox, yloc+1, '|', colorPair);
        printCharAt(window, xEndBox, yloc+2, '+', colorPair);
        xEndBox += 2;
    }

    int xStartStr = xloc + 2;
    for (int i = 0; i < num; i++) {
        printStrAt(window, xStartStr, yloc+1, strArray[i]);
        xStartStr += strLengths[i] + 3;
    }
}

/**
 * Print several strings as a list
 */
void addList(WINDOW *window, int xloc, int yloc, int num, char *strArray[]) {
    int index;
    char strBuffer[128];
    for (int i = 0; i < num; i++) {
        index = i + 1;
        int numInBuffer = sprintf(strBuffer, "    %i. %s", index, strArray[i]);
        assert(numInBuffer > 0);
        printStrAt(window, xloc, yloc+i, strBuffer);
    }
}
