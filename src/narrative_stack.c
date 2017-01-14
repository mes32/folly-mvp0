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
    stack->head = NULL;
    return stack;
}

/**
 * Free mememory used for narrative stack
 */
void deleteNarrativeStack(NarrativeStack **stackRef) {

}

/**
 * Push a new event onto the narrative stack
 */
void pushNarrativeMessage(NarrativeStack *stack, char *message) {
    /*NarrativeNode *node = initNarrativeNode(message);
    if (stack->head == NULL) {
        stack->head = node;
    } else {
        node->previous = stack->head;
        stack->head = node;
    }*/
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

}