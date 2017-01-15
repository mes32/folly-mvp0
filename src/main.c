#include "welcome_screen.h"

int main() {
    WINDOW *window = initWindow();
    displayWelcomeScreen(window);
    deleteWindow(window);
}