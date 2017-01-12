/**
 *  gameplay_screen.c - folly-mvp0
 *
 *  This module defines the main gameplay screen.
 *
 */

#include <ncurses.h>
#include "game_world.h"
#include "gameplay_screen.h"
#include "ncwindow.h"

void displayGameplayScreen(WINDOW *window, GameWorld *gameWorld) {
    clear();

    // Display Map
    // Display gameWorld->map
    // Display gameWorld->entities
    // Display gameWorld->player

    // Display Status Bar

    // Display Game Dialog
    addTextbox(window, 0, 0, "GAME PLAY SCREEN");
    printStrAt(window, 0, 5, "  Press any key to exit:");
    cursorToRestPosition(window);
    wgetch(window);
}
