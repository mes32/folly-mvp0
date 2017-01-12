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
    int row = getRow(window);

    // Display Map
    // Display gameWorld->map
    // Display gameWorld->entities
    // Display gameWorld->player

    // Display Status Bar
    char hpBuffer[32];
    char mpBuffer[32];
    char swordBuffer[32];
    char bowBuffer[32];
    char armourBuffer[32];
    char goldBuffer[32];

    sprintf(hpBuffer, "HP: %i/%i", 10, 10);
    sprintf(mpBuffer, "MP: %i/%i", 5, 5);
    sprintf(swordBuffer, "sword: lvl-%i", 1);
    sprintf(bowBuffer, "bow: lvl-%i", 1);
    sprintf(armourBuffer, "armour: lvl-%i", 1);
    sprintf(goldBuffer, "gold: %i", 5);

    char *strArray[] = { hpBuffer, mpBuffer, swordBuffer, bowBuffer, armourBuffer, goldBuffer };
    addMultipleTextbox(window, 0, row-8, 6, strArray);

    // Display Game Dialog

    printStrAt(window, 0, 5, "  Press any key to exit:");
    cursorToRestPosition(window);
    wgetch(window);
}
