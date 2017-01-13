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
    int col = getCol(window);

    // Display Map
    GameMap *map = gameWorld->map;
    for (int y = 0; y < map->yDim; y++) {
        for (int x = 0; x < map->xDim; x++) {
            char tileCharacter = getDisplayChar(map->tiles[y][x]);
            printCharAt(window, x, y, tileCharacter, COLOR_PAIR_WHITE_ON_BLACK);
        }
    } 
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

    // Display Game Dialog Stack



    //printStrAt(window, 0, 5, "  Press any key to exit:");
    cursorToRestPosition(window);
    wgetch(window);
}
