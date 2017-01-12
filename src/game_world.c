/**
 *  game_world.c - folly-mvp0
 *
 *  This module defines a gaming session and the current state of the game.
 *
 */

#include "game_world.h"

/**
 * Initialize a new game world
 */
GameWorld *initGameWorld(WINDOW *window) {
    GameWorld *game = malloc(sizeof(GameWorld));
    game->window = window;
    game->dummy = 'X';
    return game;
}

/**
 * Free mememory used for game world
 */
void deleteGameWorld(GameWorld **gameWorldRef) {
    free(*gameWorldRef);
    *gameWorldRef = NULL;
}

/**
 * Run a game until the player quits
 */
void runGame(GameWorld *gameWorld) {
    displayGameplayScreen(gameWorld->window, gameWorld);
    //int quit = 0;
    //while (quit != 0) {
        // get player input
        // evaluate player action
        // tic entities if needed
        // displayGame();
    //}
}

/**
 * Load an existing game
 */
GameWorld *loadGame() {
    GameWorld *game = initGameWorld(NULL);
    return game;
}