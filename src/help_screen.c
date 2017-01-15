/**
 *  help_screen.c - folly-mvp0
 *
 *  This module defines the in game help screen.
 *
 */

#include "help_screen.h"

void displayHelpScreen(WINDOW *window) {

    clearWindow(window);
    addTextbox(window, 0, 0, "Help");

    char *gameControls = "\
  Controls:\n\n\
     Arrow Keys - move character\n\
    Number Keys - target a visible enemy with special attack\n\
              i - show inventory screen\n\
              s - save game\n\
              a - scroll narrative text up\n\
              z - scroll narrative text down\n\
              h - show this help screen\n\
              q - quit\n\
";

    printStrAt(window, 0, 5, gameControls);
    cursorToRestPosition(window);
    wgetch(window);

    // TODO: Should be able to go to other screens from this screen without returning to gameplay screen
}
