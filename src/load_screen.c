/**
 *  load_screen.c - folly-mvp0
 *
 *  This module defines the load game prompt screen.
 *
 */

#include "load_screen.h"

void displayLoadScreen(WINDOW *window) {

    char *options[] = {
        "(cancel)", 
        "Saved Game 1", 
        "Saved Game 2", 
        "Saved Game 3", 
        "Saved Game 4", 
        "Saved Game 5"
    };

    int c;
    while (1) {
        clear();
        addTextbox(window, 0, 0, "Load Game");
        printStrAt(window, 0, 5, "  Select game to load:");
        addList(window, 0, 7, 6, options);

        // TODO: display command stack

        cursorToRestPosition(window);
        c = wgetch(window);
        break;
    }
}
