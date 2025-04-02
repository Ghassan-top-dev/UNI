#include "../include/givenA3.h"



void deletePlayList(A3Song **headLL){

    A3Song *currentNode = *headLL;
    A3Song *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->nextSong;  // Save the next node
        free(currentNode);                 // Free the currentNode node
        currentNode = nextNode;             // Move to the next node
    }

    *headLL = NULL;  // Set the head pointer to NULL to indicate the list is empty

}
