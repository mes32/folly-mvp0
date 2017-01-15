/**
 *  gameplay_screen.h - folly-mvp0
 *
 *  This module defines the main gameplay screen.
 *
 */

#ifndef GAMEPLAY_SCREEN_H_
#define GAMEPLAY_SCREEN_H_

#include "game_world.h"
#include "ncwindow.h"

void displayGameplayScreen(WINDOW *window, GameWorld *gameWorld);

#endif // GAMEPLAY_SCREEN_H_