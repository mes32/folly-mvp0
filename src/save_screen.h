/**
 *  save_screen.h - folly-mvp0
 *
 *  This module defines the savegame screen.
 *
 */

#ifndef SAVE_SCREEN_H_
#define SAVE_SCREEN_H_

#include "ncwindow.h"
#include "game_world.h"

void displaySaveScreen(WINDOW *window, GameWorld *gameWorld);

#endif // SAVE_SCREEN_H_