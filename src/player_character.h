/**
 *  player_character.h - folly-mvp0
 *
 *  This module defines a player's character in the game.
 *
 */

#ifndef PLAYER_CHARACTER_H_
#define PLAYER_CHARACTER_H_

#include <stdlib.h>

/**
 * An object representing the player character
 */
typedef struct _PlayerCharacter {
    //CharacterStat *healthPoints;
    //CharacterStat *manaPoints;
    //Inventory *inventory;

    char token;
    int xPosition;
    int yPosition;

    int totalHealthPoints;
    int currHealthPoints;
    int totalManaPoints;
    int currManaPoints;
    int swordLevel;
    int bowLevel;
    int armourLevel;
    int goldCarried;
} PlayerCharacter;

/**
 * Initialize a new player character
 */
PlayerCharacter *initPlayerCharacter();

/**
 * Free mememory used for the player character
 */
void deletePlayerCharacter(PlayerCharacter **playerCharacterRef);

/**
 * Move the player to a new relative position
 */
void movePlayerCharacter(PlayerCharacter *playerCharacter, int deltaX, int deltaY);

#endif // PLAYER_CHARACTER_H_