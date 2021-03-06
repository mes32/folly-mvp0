/**
 *  welcome_screen.c - folly-mvp0
 *
 *  This module defines the first screen the player sees after starting the game.
 *
 */

#include <ncurses.h>
#include "game_world.h"
#include "gameplay_screen.h"
#include "goodbye_screen.h"
#include "load_screen.h"
#include "ncwindow.h"
#include "welcome_screen.h"

void displayWelcomeScreen(WINDOW *window) {

    char *options[] = {
        "Start a new game", 
        "Load a previous game", 
        "Exit"
    };

    int c;
    while (1) {
        clearWindow(window);
        addTextbox(window, 0, 0, "Welcome to Folly");
        printStrAt(window, 0, 5, "  Enter a number to make a selection:");
        addList(window, 0, 7, 3, options);

        // TODO: display command stack

        cursorToRestPosition(window);
        c = wgetch(window);

        if (c == '1') {
            // TODO: Initialize game world from JSON file configuration
            //GameWorld *gameWorld = initGameWorld(window, savedGamesDir, configuration);
            //startGame(gameWorld);
            GameWorld *gameWorld = initGameWorld(window);
            runGame(gameWorld);
            break;
        } else if (c == '2') {
            displayLoadScreen(window);
            break;
        } else if (c == '3') {
            displayGoodbyeScreen(window);
            break;
        }
    }
}
