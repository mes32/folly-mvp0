/**
 *  game_world.h - folly-mvp0
 *
 *  This module defines a gaming session and the current state of the game.
 *
 */

#ifndef GAME_WORLD_H_
#define GAME_WORLD_H_

#include <stdlib.h>

/**
 * An object representing the game world
 */
typedef struct _GameWorld {
    char dummy;
    //PlayerCharacter *player;
    //GameMap *map;
    //EntitiesList *entities;
} GameWorld;

/**
 * Initialize a new game world
 */
GameWorld *initGameWorld();

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

#endif // GAME_WORLD_H_