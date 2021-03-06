/**
 *  game_world.c - folly-mvp0
 *
 *  This module defines a gaming session and the current state of the game.
 *
 */

#include <stdlib.h>
#include "game_world.h"
#include "gameplay_screen.h"
#include "help_screen.h"
#include "inventory_screen.h"
#include "save_screen.h"
#include "welcome_screen.h"

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
    gameWorld->narrative = initNarrativeStack();
    gameWorld->map = initGameMap();
    // TODO: gameWorld->entities = initEntities();
    gameWorld->player = initPlayerCharacter();
    gameWorld->unsavedChanges = false;

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
    WINDOW *window = gameWorld->window;
    displayGameplayScreen(window, gameWorld);

    int keyPress;
    EvalStatus status;
    while (1) {
        // Read
        keyPress = wgetch(window);
        
        // Evaluate
        status = evaluateKeyPress(gameWorld, keyPress);
        if (status == EXIT) {
            break;
        } else if (status == UPDATE) {
            gameWorld->unsavedChanges = true;
            //incrementEntities(gameWorld);
        }

        // Print
        if (!hasPlayerDied(gameWorld->player)) {
            displayGameplayScreen(window, gameWorld);
        } else {
            break;
        }
    }

    if (hasPlayerDied(gameWorld->player)) {
        pushNarrativeMessage(gameWorld->narrative, "You have died.");
        displayGameplayScreen(window, gameWorld);
        wgetch(window);
    }

    displayWelcomeScreen(window);
}

/**
 * Load an existing game
 */
GameWorld *loadGame() {
    GameWorld *game = initGameWorld(NULL);
    return game;
}

/**
 * Returns TRUE if the player may move to new relative coordinates, otherwise FALSE.
 */
bool isTraversable(GameWorld *gameWorld, int deltaX, int deltaY) {
    GameMap *map = gameWorld->map;
    int x = gameWorld->player->xPosition + deltaX;
    int y = gameWorld->player->yPosition + deltaY;
    if (map->tiles[y][x]->isWall || x < 0 || x >= map->xDim || y < 0 || y >= map->yDim) {
        return false;
    } else {
        return true;
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
        case 'a':
            scrollUp(gameWorld->narrative);
            return NO_UPDATE;
        case 'z':
            scrollDown(gameWorld->narrative);
            return NO_UPDATE;
        case 's':
            displaySaveScreen(gameWorld->window, gameWorld);
            return NO_UPDATE;
        case 'h':
            displayHelpScreen(gameWorld->window);
            return NO_UPDATE;
        case 'i':
            displayInventoryScreen(gameWorld->window, gameWorld->player);
            return NO_UPDATE;
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
    if (isTraversable(gameWorld, deltaX, deltaY)) {
        //if (isEnemy(gameWorld, deltaX, deltaY)) {
            // TODO: attack the enemy
        //} else {
            movePlayerCharacter(gameWorld->player, deltaX, deltaY);
            if (deltaX == 1) {
                pushNarrativeMessage(gameWorld->narrative, "You walk right.");
            } else if (deltaX == -1) {
                pushNarrativeMessage(gameWorld->narrative, "You walk left.");
            } else if (deltaY == 1) {
                pushNarrativeMessage(gameWorld->narrative, "You walk down.");
            } else if (deltaY == -1) {
                pushNarrativeMessage(gameWorld->narrative, "You walk up.");
            }
        //}
    } else {
        pushNarrativeMessage(gameWorld->narrative, "You walked into a wall. [damage 1]");
        damagePlayerCharacter(gameWorld->player, 1);
    }
}
