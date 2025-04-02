#include "../include/givenA3.h"


int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    
    // List is empty, exit
    if (*headLL == NULL) {
        return -1;  
    }

    A3Song *currentNode = *headLL;
    A3Song *prevNode = NULL;

    // Check if the head node is the one to be deleted
    if (currentNode->songId == givenSongId) {
        *headLL = currentNode->nextSong; // Move head to the next node
        free(currentNode);  // Free the memory
        return 1;  // Success
    }

    // Traverse the list to find the node to delete
    // this while loop will run through the entire list until the list ends, or until 
    // the node with the matching songID is found, in the case the match occurs, we move onto this line:
    // prevNode->nextSong = currentNode->nextSong;

    while (currentNode != NULL && currentNode->songId != givenSongId) {
        prevNode = currentNode;
        currentNode = currentNode->nextSong;
    }

    // If not found
    // here we just existed the while loop, however we don't know yet if we exited because we couldn't
    // find the node (and we reached the end), or because we found the node
    if (currentNode == NULL) {
        return -1;  // Song not found
    }

    // if node is found and that was the reason we existed the while loop
    // Bypass the node to delete
    prevNode->nextSong = currentNode->nextSong;

    // Free the memory of the deleted node
    free(currentNode);

    return 1;  // Successfully deleted
}
