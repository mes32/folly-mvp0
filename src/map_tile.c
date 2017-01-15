/**
 *  map_tile.c - folly-mvp0
 *
 *  This module defines a single tile of the game map. See module 'game_map'.
 *
 */

#include <stdlib.h>
#include "map_tile.h"

static char DISPLAY_WALL_TILE = '#';
static char DISPLAY_FLOOR_TILE = ' ';

/**
 * Initialize a new map tile
 */
MapTile *initMapTile(int isWall) {
    MapTile *tile = malloc(sizeof(MapTile));
    tile->isWall = isWall;
    return tile;
}

/**
 * Free mememory used for the tile
 */
void deleteMapTile(MapTile **tileRef) {
    free(*tileRef);
    *tileRef = NULL;
}

/**
 * Returns the char used to display a given tile
 */
char getDisplayChar(MapTile *tile) {
    if (tile->isWall) {
        return DISPLAY_WALL_TILE;
    } else {
        return DISPLAY_FLOOR_TILE;
    }
}