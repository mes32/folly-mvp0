/**
 *  welcome_screen.c - folly-mvp0
 *
 *  This module defines the first screen the player sees after starting the game.
 *
 */

#include <ncurses.h>
#include "load_screen.h"
#include "ncwindow.h"
#include "welcome_screen.h"

void displayWelcomeScreen(WINDOW *window) {

    char *options[] = {"Start a new game", "Load a previous game", "Exit"};

    int c;
    while (1) {
        clear();
        addTextbox(window, 0, 0, "Welcome to Folly");
        printStrAt(window, 0, 5, "Enter a number to make a selection:");
        addList(window, 0, 7, 3, options);

        // display command stack

        cursorToRestPosition(window);
        c = wgetch(window);

        if (c == '1') {
            // New game
            break;
        } else if (c == '2') {
            // Load game
            displayLoadScreen(window);
            break;
        } else if (c == '3') {
            // Exit
            break;
        }
    }
}