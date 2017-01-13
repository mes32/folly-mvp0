/**
 *  game_map.c - folly-mvp0
 *
 *  This module defines the game map.
 *
 */

#include <stdlib.h>
#include "game_map.h"
#include "map_tile.h"

/**
 * Initialize a new game map
 */
GameMap *initGameMap() {
    GameMap *map = malloc(sizeof(GameMap));

    map->xDim = 20;
    map->yDim = 10;
    map->tiles = (MapTile***)malloc(sizeof(MapTile**) * map->yDim);
    for (int y = 0; y < map->yDim; y++) {
        map->tiles[y] = (MapTile**)malloc(sizeof(MapTile*) * map->xDim);
        for (int x = 0; x < map->xDim; x++) {
            if (y == 0 || x == 0 || y == map->yDim - 1 || x == map->xDim - 1) {
                map->tiles[y][x] = initMapTile(1);
            } else {
                map->tiles[y][x] = initMapTile(0);
            }
        }
    }

    return map;
}

/**
 * Free mememory used for game map
 */
void deleteGameMap(GameMap **mapRef) {
    GameMap *map = *mapRef;
    for (int y = 0; y < map->yDim; y++) {
        for (int x = 0; x < map->xDim; x++) {
            deleteMapTile(&map->tiles[y][x]);
        }
    }

    free(map);
    map = NULL;
}