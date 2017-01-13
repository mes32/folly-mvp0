/**
 *  map_tile.h - folly-mvp0
 *
 *  This module defines a single tile of the game map. See module 'game_map'.
 *
 */

#ifndef MAP_TILE_H_
#define MAP_TILE_H_

#include <stdlib.h>

/**
 * An object representing the game map
 */
typedef struct _MapTile {
    int isWall;
} MapTile;

/**
 * Initialize a new map tile
 */
MapTile *initMapTile(int isWall);

/**
 * Free mememory used for the tile
 */
void deleteMapTile(MapTile **tileRef);

/**
 * Returns the char used to display a given tile
 */
char getDisplayChar(MapTile *tile);

#endif // MAP_TILE_H_