/**
 *  game_world.h - folly-mvp0
 *
 *  This module defines a gaming session and the current state of the game.
 *
 */

#ifndef GAME_WORLD_H_
#define GAME_WORLD_H_

#include <ncurses.h>
#include "game_map.h"
#include "narrative_stack.h"
#include "player_character.h"

/**
 * An object representing the game world
 */
typedef struct _GameWorld {
    WINDOW *window;
    NarrativeStack *narrative;
    GameMap *map;
    // TODO: EntitiesList *entities;
    PlayerCharacter *player;
    bool unsavedChanges;
} GameWorld;

/**
 * Initialize a new game world
 */
GameWorld *initGameWorld(WINDOW *window);

/**
 * Free mememory used for game world
 */
void deleteGameWorld(GameWorld **gameWorldRef);

/**
 * Run a game until the player quits
 */
void runGame(GameWorld *gameWorld);

/**
 * Load an existing game
 */
GameWorld *loadGame();

/**
 * Returns TRUE if the player may move to new relative coordinates, otherwise FALSE.
 */
bool isTraversable(GameWorld *gameWorld, int deltaX, int deltaY);

#endif // GAME_WORLD_H_