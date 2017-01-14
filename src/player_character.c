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
    player->currHealthPoints = 10;
    player->totalManaPoints = 5;
    player->currManaPoints = 5;
    player->swordLevel = 1;
    player->bowLevel = 1;
    player->armourLevel = 1;
    player->goldCarried = 5;

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

/**
 * Reduce the player character's health points due to damage
 */
void damagePlayerCharacter(PlayerCharacter *playerCharacter, int damage) {
    playerCharacter->currHealthPoints -= damage;
    if (playerCharacter->currHealthPoints < 0) {
        playerCharacter->currHealthPoints = 0;
    }
}