/**
 *  inventory_screen.h - folly-mvp0
 *
 *  This module defines the in game inventory screen.
 *
 */

#ifndef INVENTORY_SCREEN_H_
#define INVENTORY_SCREEN_H_

#include "ncwindow.h"
#include "player_character.h"

void displayInventoryScreen(WINDOW *window, PlayerCharacter *player);

#endif // INVENTORY_SCREEN_H_