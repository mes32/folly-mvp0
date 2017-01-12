/**
 *  game_map.h - folly-mvp0
 *
 *  This module defines the game map.
 *
 */

#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include <stdlib.h>
#include "game_map.h"

/**
 * An object representing the game map
 */
typedef struct _GameMap {
    
} GameMap;

/**
 * Initialize a new game map
 */
GameMap *initGameMap();

/**
 * Free mememory used for game map
 */
void deleteGameMap(GameMap **mapRef);

#endif // GAME_MAP_H_