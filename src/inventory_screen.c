/**
 *  inventory_screen.c - folly-mvp0
 *
 *  This module defines the in game inventory screen.
 *
 */

#include "inventory_screen.h"

void displayInventoryScreen(WINDOW *window, PlayerCharacter *player) {

    clearWindow(window);
    addTextbox(window, 0, 0, "Inventory");
    cursorToRestPosition(window);
    wgetch(window);

    // TODO: Should actually display items and allow the user to select them for use
}
