/**
 *  narrative_stack.c - folly-mvp0
 *
 *  This module defines the sequence of narrative events written to the player during the game.
 *
 */

#include <stdlib.h>
#include "narrative_stack.h"

static NarrativeNode *initNarrativeNode(char *message);
static void deleteNarrativeNode(NarrativeNode **node);

/**
 * Initialize a new narrative stack
 */
NarrativeStack *initNarrativeStack() {
    NarrativeStack *stack = malloc(sizeof(NarrativeStack));

    stack->length = 0;
    stack->startIndex = 0;
    stack->head = NULL;
    stack->start = NULL;

    return stack;
}

/**
 * Free mememory used for narrative stack
 */
void deleteNarrativeStack(NarrativeStack **stackRef) {
    // TODO: Actually delete this object
}

/**
 * Push a new event onto the narrative stack
 */
void pushNarrativeMessage(NarrativeStack *stack, char *message) {
    stack->length += 1;
    stack->startIndex = 0;

    NarrativeNode *node = initNarrativeNode(message);
    if (stack->head == NULL) {
        stack->head = node;
    } else {
        node->previous = stack->head;
        stack->head = node;
    }
    stack->start = stack->head;
}

/**
 * Scroll up to display older narrative events
 */
void scrollUp(NarrativeStack *stack) {
    if (stack->startIndex < stack->length - 1) {
        stack->startIndex += 1;
        stack->start = stack->start->previous;
    }
}

/**
 * Scroll down to display newer narrative events
 */
void scrollDown(NarrativeStack *stack) {
    if (stack->startIndex > 0) {
        stack->startIndex -= 1;

        // TODO: Nodes would benefit from a 'next' pointer for forward traversal
        NarrativeNode *node = stack->head;
        for (int i = 0; i < stack->startIndex; i++) {
            node = node->previous;
        }
        stack->start = node;
    }
}

/**
 * Initialize a new narrative node
 */
static NarrativeNode *initNarrativeNode(char *message) {
    NarrativeNode *node = malloc(sizeof(NarrativeNode));
    node->message = message;
    node->previous = NULL;
    return node;
}

/**
 * Free mememory used for narrative node
 */
static void deleteNarrativeNode(NarrativeNode **node) {
    // TODO: Actaully delete this object
}