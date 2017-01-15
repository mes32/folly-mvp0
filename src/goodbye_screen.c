/**
 *  goodbye_screen.c - folly-mvp0
 *
 *  This module defines the goodbye screen shown after the player chooses to exit.
 *
 */

#include "goodbye_screen.h"

void displayGoodbyeScreen(WINDOW *window) {
    clearWindow(window);
    addTextbox(window, 0, 0, "Goodbye");
    printStrAt(window, 0, 5, "  Press any key to exit:");
    cursorToRestPosition(window);
    wgetch(window);
}
