/**
 *  save_screen.c - folly-mvp0
 *
 *  This module defines the savegame screen.
 *
 */

#include "save_screen.h"

void displaySaveScreen(WINDOW *window, GameWorld *gameWorld) {

    clearWindow(window);
    addTextbox(window, 0, 0, "Save Game");
    cursorToRestPosition(window);
    wgetch(window);

    // TODO: Should actually allow user to save the current game
    // Then set gameWorld->unsavedChanges = false;
}
