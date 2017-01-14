/**
 *  player_character.c - folly-mvp0
 *
 *  This module defines a player's character in the game.
 *
 */

#include "player_character.h"

/**
 * Initialize a new player character
 */
PlayerCharacter *initPlayerCharacter() {
    PlayerCharacter *player = malloc(sizeof(PlayerCharacter));
    
    player->token = '@';
    player->xPosition = 1;
    player->yPosition = 1;
    player->totalHealthPoints = 10;
    /*int currHealthPoints;
    int totalManaPoints;
    int currManaPoints;
    int swordLevel;
    int bowLevel;
    int armourLevel;
    int goldCarried;*/

    return player;
}

/**
 * Free mememory used for the player character
 */
void deletePlayerCharacter(PlayerCharacter **playerCharacterRef) {
    free(*playerCharacterRef);
    *playerCharacterRef = NULL;
}

/**
 * Move the player to a new relative position
 */
void movePlayerCharacter(PlayerCharacter *playerCharacter, int deltaX, int deltaY) {
    playerCharacter->xPosition += deltaX;
    playerCharacter->yPosition += deltaY;
}