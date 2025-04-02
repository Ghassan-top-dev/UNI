#include "../include/givenA3.h"


int playSongGivenId(A3Song *headLL, int givenSongId){

    if (headLL == NULL) {
        printf("\n\nLIST IS EMPTY\n\n");
        return -1;  // List is empty
    }

    A3Song *currentNode = headLL;
    
    // traverse over the linked list
    while (currentNode != NULL) {

        if (currentNode->songId == givenSongId)
        {
            // Print Song id and Song Name
            printf("Song ID: %d\n", currentNode->songId);
            printf("Song Name: %s\n", currentNode->songName);
            
            // Print the notes on one line 
            printf("Notes:\n");
            for (int i = 0; i < 21; i++) {
                printf("%s", currentNode->songNotes[i]);
                if (i < 20) {  // Print a period after every note 
                    printf(".");
                }
            }
            printf("\n\n"); 
            
            return 1; 
        }
        
        // go to next nide
        currentNode = currentNode->nextSong;
    }

    return -1; 
}