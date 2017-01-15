/**
 *  gameplay_screen.c - folly-mvp0
 *
 *  This module defines the main gameplay screen.
 *
 */

#include "game_world.h"
#include "ncwindow.h"

static const int NUM_LINES = 5;

void displayGameplayScreen(WINDOW *window, GameWorld *gameWorld) {
    clearWindow(window);
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
    PlayerCharacter *player = gameWorld->player;
    int playerX = player->xPosition;
    int playerY = player->yPosition;
    int playerToken = player->token;
    printCharAt(window, playerX, playerY, playerToken, COLOR_PAIR_WHITE_ON_BLACK);

    // Display Status Bar
    char hpBuffer[32];
    char mpBuffer[32];
    char swordBuffer[32];
    char bowBuffer[32];
    char armourBuffer[32];
    char goldBuffer[32];

    int currHealthPoints = player->currHealthPoints;
    int totalHealthPoints = player->totalHealthPoints;
    sprintf(hpBuffer, "HP: %i/%i", currHealthPoints, totalHealthPoints);

    int currManaPoints = player->currManaPoints;
    int totalManaPoints = player->totalManaPoints;
    sprintf(mpBuffer, "MP: %i/%i", currManaPoints, totalManaPoints);
    
    int swordLevel = player->swordLevel;
    sprintf(swordBuffer, "sword: lvl-%i", swordLevel);
    
    int bowLevel = player->bowLevel;
    sprintf(bowBuffer, "bow: lvl-%i", bowLevel);
    
    int armourLevel = player->armourLevel;
    sprintf(armourBuffer, "armour: lvl-%i", armourLevel);
    
    int gold = player->goldCarried;
    sprintf(goldBuffer, "gold: %i", gold);

    char *strArray[] = { hpBuffer, mpBuffer, swordBuffer, bowBuffer, armourBuffer, goldBuffer };
    addMultipleTextbox(window, 0, row - NUM_LINES - 3, 6, strArray);

    // Display narrative stack
    for (int j = 1; j <= NUM_LINES; j++) {
        for (int x = 0; x < col - 1; x ++) {
            printCharAt(window, x, row-j, ' ', COLOR_PAIR_WHITE_ON_BLACK);
        }
    }
    NarrativeStack *stack = gameWorld->narrative;
    if (stack->length > 0) {
        int numVisible = stack->length - stack->startIndex;
        if (numVisible > NUM_LINES) numVisible = NUM_LINES;

        NarrativeNode *node = stack->start;
        int currentRow = row - (NUM_LINES - numVisible);
        for (int i = 0; i < numVisible; i++) {
            currentRow -= 1;
            printStrAt(window, 0, currentRow, node->message);
            node = node->previous;
        }
    }

    cursorToRestPosition(window);
}
