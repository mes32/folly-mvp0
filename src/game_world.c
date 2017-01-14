/**
 *  game_world.c - folly-mvp0
 *
 *  This module defines a gaming session and the current state of the game.
 *
 */

#include <stdlib.h>
#include "game_world.h"
#include "gameplay_screen.h"

#include <stdio.h>
#include <ncurses.h>

typedef enum EvalStatusType {
    EXIT = -1,
    UPDATE = 0,
    NO_UPDATE = 1
} EvalStatus;

static EvalStatus evaluateKeyPress(GameWorld *gameWorld, int keyPress);
static void tryMovement(GameWorld *gameWorld, int deltaX, int deltaY);

/**
 * Initialize a new game world
 */
GameWorld *initGameWorld(WINDOW *window) {
    GameWorld *gameWorld = malloc(sizeof(GameWorld));
    gameWorld->window = window;
    gameWorld->map = initGameMap();
    // gameWorld->entities = initEntities();
    gameWorld->player = initPlayerCharacter();

    return gameWorld;
}

/**
 * Free mememory used for game world
 */
void deleteGameWorld(GameWorld **gameWorldRef) {
    GameWorld *game = *gameWorldRef;

    deleteGameMap(&game->map);
    deletePlayerCharacter(&game->player);

    free(*gameWorldRef);
    *gameWorldRef = NULL;
}

/**
 * Run a game until the player quits
 */
void runGame(GameWorld *gameWorld) {
    keypad(stdscr, TRUE);
    displayGameplayScreen(gameWorld->window, gameWorld);
    int keyPress;
    EvalStatus status;
    while (1) {
        // Read
        keyPress = wgetch(gameWorld->window);
        
        // Evaluate
        status = evaluateKeyPress(gameWorld, keyPress);
        if (status == EXIT) {
            break;
        } /*else if (status == UPDATE) {
            //incrementEntities(gameWorld);
        //}*/

        // Print
        displayGameplayScreen(gameWorld->window, gameWorld);
    }
}

/**
 * Load an existing game
 */
GameWorld *loadGame() {
    GameWorld *game = initGameWorld(NULL);
    return game;
}

/**
 * Returns 1 if the player may move to new relative coordinates. Otherwise returns 0.
 */
int isTraversable(GameWorld *gameWorld, int deltaX, int deltaY) {
    GameMap *map = gameWorld->map;
    int x = gameWorld->player->xPosition + deltaX;
    int y = gameWorld->player->yPosition + deltaY;
    if (map->tiles[y][x]->isWall || x < 0 || x >= map->xDim || y < 0 || y >= map->yDim) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * Evaluate the player's key press. Returns -1 for quit, returns 1 if should increment enemies 
 * in response, returns 0 otherwise.
 */
static EvalStatus evaluateKeyPress(GameWorld *gameWorld, int keyPress) {
    int deltaX = 0;
    int deltaY = 0;

    switch(keyPress) {
        case 'q':
            return EXIT;
        case KEY_UP:
            deltaY = -1;
            tryMovement(gameWorld, deltaX, deltaY);
            return UPDATE;
        case KEY_DOWN:
            deltaY = 1;
            tryMovement(gameWorld, deltaX, deltaY);
            return UPDATE;
        case KEY_LEFT:
            deltaX = -1;
            tryMovement(gameWorld, deltaX, deltaY);
            return UPDATE;
        case KEY_RIGHT:
            deltaX = 1;
            tryMovement(gameWorld, deltaX, deltaY);
            return UPDATE;
        default:
            return NO_UPDATE;
    }
}

static void tryMovement(GameWorld *gameWorld, int deltaX, int deltaY) {
    char *message;

    if (isTraversable(gameWorld, deltaX, deltaY)) {
        //if (isEnemy(gameWorld, deltaX, deltaY)) {
            // attack the enemy
        //} else {
            movePlayerCharacter(gameWorld->player, deltaX, deltaY);
            if (deltaX == 1) {
                message = "You walk right.";
            } else if (deltaX == -1) {
                message = "You walk left.";
            } else if (deltaY == 1) {
                message = "You walk down.";
            } else if (deltaY == -1) {
                message = "You walk up.";
            }
        //}
    } else {
        message = "You walked into a wall. [damage 1]";
        //damagePlayerCharacter(gameWorld->player, 1);
    }
}
