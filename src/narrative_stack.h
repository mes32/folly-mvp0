/**
 *  narrative_stack.h - folly-mvp0
 *
 *  This module defines the sequence of narrative events written to the player during the game.
 *
 */

#ifndef NARRATIVE_STACK_H_
#define NARRATIVE_STACK_H_

/**
 * An object representing a single narrative event
 */
typedef struct _NarrativeNode NarrativeNode;
struct _NarrativeNode {
    char *message;
    NarrativeNode *previous;
};

/**
 * An object representing all narrative events in the game
 */
typedef struct _NarrativeStack {
    int length;
    int startIndex;
    NarrativeNode *head;
    NarrativeNode *start;
} NarrativeStack;


/**
 * Initialize a new narrative stack
 */
NarrativeStack *initNarrativeStack();

/**
 * Free mememory used for narrative stack
 */
void deleteNarrativeStack(NarrativeStack **stackRef);

/**
 * Push a new event onto the narrative stack
 */
void pushNarrativeMessage(NarrativeStack *stack, char *message);

#endif // NARRATIVE_STACK_H_