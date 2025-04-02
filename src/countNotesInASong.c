#include "../include/givenA3.h"

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]){

    A3Song *currentNode = headLL;

    if (headLL == NULL) {
        printf("\n\nLIST IS EMPTY\n\n");
        return -1;  // List is empty
    }

    int numberOfOccurancesOfNote = 0; 
    // traverse over the linked list
    while (currentNode != NULL) {

        if (currentNode->songId == givenSongId)
        {

            for (int i = 0; i < 21; i++) {
                int result = strcmp(currentNode->songNotes[i], whichNote);

                if(result == 0){

                    numberOfOccurancesOfNote++; 
                }

            }
            
            if (numberOfOccurancesOfNote == 0)
            {
                return -1; 
            }

            return numberOfOccurancesOfNote; 
            
        }
        
        // go to next nide
        currentNode = currentNode->nextSong;
    }


    return -1; 

}
